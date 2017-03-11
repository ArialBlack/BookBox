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

    //dsm($form); <svg preserveAspectRatio="xMaxYMax"><use xlink:href="/sites/all/themes/bookbox_ui/images/svg-icons-sprite.svg#icon-search"></use></svg>

    if ($form['#id'] == 'user-register-form') {
       // $form['name'] = $form['field_name'];
       // $form['email'] = $form['account']['mail'];
        //unset($form['field_name']);
       // unset($form['account']['mail']);

        $form['field_name']['#weight'] = -10;
        $form['field_sirname']['#weight'] = -9;
        //$form['email']['#weight'] = -8;

        $form['mail'] = $form['account']['mail'];
        unset($form['account']['mail']);
        $form['mail']['#weight'] = -8;
        $form['mail']['#title'] = 'Email <span>(Ваш Email буде вашим логіном)</span>';
        $form['mail']['#description'] = '';


        $form['pass'] = $form['account']['pass'];
        unset($form['account']['pass']);
        $form['field_company']['#weight'] = -7;
        $form['pass']['#weight'] = -6;

        //dsm($form);
    }

    if ($form['#id'] == 'user-login') {
        $form['submitзфіі'] = array(
            '#type' => 'markup',
            '#markup' => '<a id="userlostpass" href="/user/password">Забули пароль?</a>',
            '#weight' => 8
        );

        $form['submitlogin'] = array(
            '#type' => 'markup',
            '#markup' => '<a id="userreglink btn" href="/user/register">Зарееструватись</a>',
            '#weight' => 9
        );
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
            form_set_error('mail', 'Ваш email не співпадає з обранною компанією');
        }
    }
}
