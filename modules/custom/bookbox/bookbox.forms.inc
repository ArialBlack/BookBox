<?php
function bookbox_form_alter(&$form, &$form_state, $form_id){

    if ($form['#id'] == 'user-register-form') {
        $form['#validate'][] = 'bookbox_registeruser_validate';
    }
    
    if(isset($form['#node_edit_form']) && $form['#node_edit_form'] && $form['type']['#value'] == 'book') {
        $form['field_bookfields']['und']['form']['commerce_price']['und'][0]['amount']['#default_value'] = 0;
        $form['field_bookfields']['und']['form']['commerce_price']['#access'] = false;
    }

    if ($form['#id'] == 'views-exposed-form-booksearch-page') {
        $form['search-trigger'] = array(
            '#type' => 'markup',
            '#markup' => '<svg class="svg-icon icon-search" preserveAspectRatio="xMaxYMax"><use xlink:href="/sites/all/themes/bookbox_ui/images/svg-icons-sprite.svg#icon-search"></use></svg>',
        );
    }

    if ($form['#id'] == 'user-register-form') {
        $query = db_select('node', 'n');
        $query->fields('n', array('nid', 'title'));
        $query->condition('n.type', 'company');
        $result = $query->execute();

        $domainslist = '<ul id="clist" class="hidden">';
        foreach ($result as $node) {
            $query2 = db_select('field_data_field_maildomain', 'm');
            $query2->fields('m', array('field_maildomain_value'));
            $query2->condition('m.entity_id', $node->nid);
            $result2 = $query2->execute();

            $domainslist = $domainslist . '<li data-d="';
            foreach ($result2 as $d) {
                $domainslist = $domainslist . $d->field_maildomain_value . '; ';
            }
            $domainslist = $domainslist .'">' . $node->nid . '</li>';
        }
        $domainslist = $domainslist . '</ul>';

        $form['clist'] = array(
            '#type' => 'markup',
            '#markup' => $domainslist,
        );

        $form['field_name']['#weight'] = -10;
        $form['field_sirname']['#weight'] = -9;

        $form['pass'] = $form['account']['pass'];
        unset($form['account']['pass']);
        $form['field_company']['#weight'] = -8;

        $form['mail'] = $form['account']['mail'];
        unset($form['account']['mail']);
        $form['mail']['#weight'] = -6;
        $form['mail']['#title'] = 'Email <span>(Корпоративний email)</span>';
        $form['mail']['#description'] = '';
        
        $form['field_tel']['#weight'] = -7;

        $form['pass']['#weight'] = -5;
    }

    if ($form['#id'] == 'user-login') {
        $form['submitpass'] = array(
            '#type' => 'markup',
            '#markup' => '<a id="userlostpass" href="/user/password">Забули пароль?</a>',
            '#weight' => 8
        );

        $form['submitlogin'] = array(
            '#type' => 'markup',
            '#markup' => '<a id="userreglink" class="btn" href="/user/register">Зарееструватись</a>',
            '#weight' => 9
        );
    }

    if ($form['#id'] == 'user-pass') {
        $form['actions']['submit']['#value'] = 'Відновити пароль';
    }
}

function bookbox_registeruser_validate($form, &$form_state) {
    $company_id = $form_state['values']['field_company']['und'][0]['target_id'];
    $usermail = $form_state['values']['mail'];

    if ($usermail && $company_id) {
        $usermail_domain = substr(strrchr($usermail, "@"), 1);
        $node = node_load($company_id);
        $domains = $node->field_maildomain['und'];
        $in_list = false;

        for($i = 0; $i < count($domains); $i++) {
            if ($domains[$i]['value'] == $usermail_domain) {
                $in_list = true;
            }
        }

        if (!$in_list) {
            ife_errors('set', 'edit-mail--2', 'Введіть адресу корпоративної електронної пошти');
            form_set_error('mail', 'Введіть адресу корпоративної електронної пошти');
        }
    }

    $usertel = $form_state['values']['field_tel']['und'][0]['value'];

    $pattern = "/^\+380\d{3}\d{2}\d{2}\d{2}$/";
    if(!preg_match($pattern, $usertel))  {
        ife_errors('set', 'edit-tel-und-0-value', 'Номер має бути у форматі +380ххххххххх');
        form_set_error('tel', 'Номер має бути у форматі +380ххххххххх');
    }
}

function bookbox_form_commerce_cart_add_to_cart_form_alter(&$form, &$form_state) {
    global $user;
    $uid = $user->uid;
    $max_books = variable_get('varMaxBooks') - bookbox_count_in_confirm($uid) - bookbox_count_in_reading_now($uid);
    // можно добавить максимум 3

    $form['submit']['#value'] = 'Замовити';

    $in_cart = 0;

    if (isset($form['product_id'])) {
        $form_product = $form['product_id']['#value'];
        $can_add2cart = true;
    } else {
        $form_product = null;
        $can_add2cart = false;
    }

    $wrapper = _bookbox_get_cart_items();

    //что-то есть в корзине
    if ($wrapper) {
        foreach ($wrapper->commerce_line_items as $delta => $line_item_wrapper) {
            $cart_product = $line_item_wrapper->commerce_product->value()->product_id;
            $in_cart = $in_cart + 1;

            //todo
            //если эта книга есть в заказе или читаю сейчас
            if($form_product == $cart_product) {
                $can_add2cart = false; // если эта книга уже в корзине, то нечего ее добавлять, ок, да?
                break;
            }
        }
    }

    if ($in_cart >= $max_books) {
        $can_add2cart = false;
    }

    if (!$can_add2cart) {
        $form['submit']['#attributes']['disabled'] = TRUE;
    }
}

function bookbox_admin_delivery_form ($form, &$form_state) {
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => 'Ми все доставили!',
    );
    
    return $form;
}

function bookbox_admin_delivery_form_submit($form, &$form_state) {
    $result = db_select('commerce_order', 'o')
        ->fields('o', array('order_id', 'status', 'changed'))
        ->condition('o.status', 'completed')
        ->orderBy('o.order_id', 'DESC')
        ->execute()->fetchAll();

    foreach ($result as $item) {
        if ($item->status == 'completed') {
            $order = commerce_order_load($item->order_id);
            commerce_order_status_update($order, 'delivered', $skip_save = FALSE, $revision = NULL, $log = '');
        }
    }

    bookbox_equal_stocks();

    drupal_set_message(t('Статуси замовлень змінено!'));
}
