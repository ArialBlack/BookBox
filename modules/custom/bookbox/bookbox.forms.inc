<?php
function bookbox_form_alter(&$form, &$form_state, $form_id){

    //При редагуванні книги, нам не потрібна ціна
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

    //Форма реєстрації юзера
    if ($form['#id'] == 'user-register-form') {
        $form['#validate'][] = 'bookbox_registeruser_validate';

        $form['mail'] = $form['account']['mail'];
        unset($form['account']['mail']);

        $form['mail']['#weight'] = -10;
        $form['mail']['#title'] = 'Корпоративний email</span>';
        $form['mail']['#description'] = '';
        $form['mail']['#attributes']['placeholder'] = 'oskar123@bookbox.ua';

        $form['field_name']['#weight'] = -9;
        $form['field_name']['und'][0]['value']['#attributes']['placeholder'] = 'Оскар';

        $form['field_sirname']['#weight'] = -8;
        $form['field_sirname']['und'][0]['value']['#attributes']['placeholder'] = 'Уайльд';

        $form['field_company']['#disabled']= TRUE;

        $form['field_tel']['#weight'] = -7;
        $form['field_tel']['und'][0]['value']['#attributes']['placeholder'] = '+380';

        $form['pass'] = $form['account']['pass'];
        unset($form['account']['pass']);
        $form['pass']['#weight'] = -5;
    }

    if ($form['#id'] == 'user-pass') {
        $form['actions']['submit']['#value'] = 'Відновити пароль';
    }

    if ($form['form_id']['#id'] == 'edit-book-node-form') {
        $nid = $form['nid']['#value'];
        $node = node_load($nid);
        $in_orders = 'В замовленнях ' . bookbox_get_in_orders($node) . 'шт.';

        $form['field_bookfields']['und']['form']['commerce_stock']['und'][0]['value']['#disabled'] = TRUE;
        $form['field_bookfields']['und']['form']['commerce_stock']['und'][0]['value']['#attributes']['title'] = $in_orders;
    }

    if ($form['#id'] == 'user-pass-reset') {
        unset($form['help']);
        $form['message']['#markup'] = '<p>Це одноразове посилання для входу на сайт та встановлення нового паролю.</p>';
    }
}

//Валідація форми реєстрації юзера
function bookbox_registeruser_validate ($form, &$form_state) {
    $usermail = $form_state['values']['mail'];

    if ($usermail) {
        $usermail_domain = substr(strrchr($usermail, "@"), 1);

        //Є сутність - Компанія. Є мультіполе 'мейл-домени компанії'
        //Мейл користувача, що реєструється, має належать компанії
        $company_nid = db_select('field_data_field_maildomain', 'md')
            ->fields('md', array('entity_id'))
            ->condition('md.field_maildomain_value', $usermail_domain)
            ->execute()
            ->fetchField();

        $email = db_select('users', 'u')
            ->fields('u', array('mail'))
            ->condition('u.mail', $usermail)
            ->execute()
            ->fetchField();

        if($email) {
            ife_errors('set', 'edit-mail--2', 'Вибачте, але такий email вже існує. <a href="/user/login">Бажаєте ввійти?</a>');
            form_set_error('mail', 'Вибачте, але такий email вже існує. <a href="/user/login">Бажаєте ввійти?</a>');
        }

        if($company_nid) {
            $form['field_company']['#parents'] = array('field_company');
            form_set_value($form['field_company'], array('und' => array(0 => array('target_id' => $company_nid))), $form_state);
        } else {
            ife_errors('set', 'edit-mail--2', 'Невірний email або ваша компанія не є клієнтом Book Box. Перевірте введену інформацію або <a href="https://bookbox.ua/contacts">зв’яжіться з нами</a>');
            form_set_error('mail', 'Невірний email або ваша компанія не є клієнтом Book Box. Перевірте введену інформацію або <a href="https://bookbox.ua/contacts">зв’яжіться з нами</a>');
        }
    }

    $usertel = $form_state['values']['field_tel']['und'][0]['value'];


    $pattern = "/^\+380\d{3}\d{2}\d{2}\d{2}$/";
    if(!preg_match($pattern, $usertel))  {
        ife_errors('set', 'edit-field-tel-und-0-value', 'Номер має бути у форматі +380ххххххххх');
        //form_set_error('field_tel[und][0][value]', 'Номер має бути у форматі +380ххххххххх');
    }
}

//Логіка кнопки замовлення книги http://prntscr.com/i8e357
function bookbox_form_commerce_cart_add_to_cart_form_alter(&$form, &$form_state) {
  global $user;
  $uid = $user->uid;
  $max_books = variable_get('varMaxBooks') - bookbox_count_in_confirm($uid) - bookbox_count_in_reading_now($uid);
  // можно добавить максимум 3, например
  $destination = request_path();
  $form['submit']['#attributes']['disabled'] = TRUE;
  $form['submit']['#type'] = 'hidden';
  $can_order = true;
  $date = time();

  if (isset($form['product_id'])) {
    $form_product = $form['product_id']['#value'];
    $product_display = _bookbox_get_product_display_by_product_id($form_product);
    $book_authors = $product_display->field_book_author['und'];
    $author_count = count($book_authors);
    $authors = '';

    $uri = $product_display->field_nni['und'][0]['uri'];

    for($i = 0; $i < $author_count; $i++) {
      $authors = $authors . '<span class="popup-author">' . $product_display->field_book_author['und'][$i]['taxonomy_term']->name . '</span> ';
    }

    $modal = '<div class="modal fade order" tabindex="-1" role="dialog" id="confirm-orders">
                                      <div class="modal-dialog" role="document">
                                        <div class="modal-content">
                                          <div class="modal-header">
                                            <a class="close" data-dismiss="modal" href="#">×</a>
                                          	<img src="/sites/all/themes/bookbox_ui/images/read-now.png" alt="">
                                          </div>
                                          <div class="modal-body">
                                          	<h4>Ви підтверджуєте замовлення?</h4>
                                          	<!--<div class="modal-book-block">
                                          	<img class="modal-book-img" src="' . image_style_url("bookcover", $uri) . '"/>
                                          	</div>-->
                                          </div>
                                          <div class="modal-footer">
                                          	<div class="btn-block">
                                          		 <a class="btn btn-outline red" href="/confirm/' . $uid . '/' . $form_product . '/book?destination=' . $destination . '">Так, замовити</a>
                                            	 <button type="button" class="btn cancel red" data-dismiss="modal">Ні, скасувати</button>
                                          	</div>
                                           ' . verbose_period4popup($date) . '
                                          </div>
                                        </div>
                                      </div>
                                    </div>';

  } else {
    $form_product = null;
    $can_order = false;
  }

  $button_disabled = '<button disabled="1" type="button" id="edit-submit-book" class="btn btn-default form-submit">Замовити</button>';
  $button = '<button type="button" id="edit-submit-book" class="btn btn-default form-submit" data-toggle="modal" data-target="#confirm-orders">Замовити</button>';

  $overslots_button = '<button type="button" id="edit-submit-book" class="btn btn-default form-submit" data-toggle="modal" data-target="#over-slots">Замовити</button>';
  $overslots_modal = '<div class="modal fade" tabindex="-1" role="dialog" id="over-slots">
                                      <div class="modal-dialog" role="document">
                                        <div class="modal-content">
                                          <div class="modal-header">
                                            <a class="close" data-dismiss="modal" href="#">×</a>
                                            <img src="/sites/all/themes/bookbox_ui/images/alert-mark.png" alt="">
                                          </div>
                                          <div class="modal-body">
                                            <p>Три книжки – максимальна кількість на руках в один момент часу. <br> Коли ви повернете одну з прочитаних книжок – відкриється можливість замовити наступну.</p>
                                          </div>
                                          <div class="modal-footer">
                                            <button type="button" class="btn btn-outline red" data-dismiss="modal">Зрозуміло</button>
                                          </div>
                                        </div>
                                      </div>
                                    </div>';
  //если я уже читаю или я уже заказал эту книгу, то отключать кнопку.
  // если я уже читаю 3 книги, то отключать кнопку
  //если я читаю + я заказал = 3шт, то отключать кнопку
  $is_in_order = is_in_order($form_product, $uid);
  $is_in_readingnow = is_in_redingnow($form_product, $uid);
  $is_in_archive = is_in_archive($form_product, $uid);
  $product = commerce_product_load($form_product);
  $stock = 0;

  if($product) {
    $stock = $product->commerce_stock['und'][0]['value'];
  }

  if ($is_in_order > 0 || $is_in_readingnow > 0 || $max_books < 1) {
    $can_order = false;
  }

  $disabled_reason = '';

  //Якщо книг всього 10 і 10 людей їх розібрали, тобто в товарних запасах 0, то замовить не можна
  if ($stock < 1) {
    $disabled_reason = 'Читається зараз';
    $can_order = false;
  }

  if ($is_in_order > 0){
    $can_order = false;
    $disabled_reason = 'Ви вже замовили цю книгу';
  }

  if ($is_in_readingnow > 0) {
    $can_order = false;
    $disabled_reason = 'Ви вже читаєте цю книгу';
  }

  if(($stock < 1 || $is_in_order > 0 || $is_in_readingnow > 0) ) {
    $form['confirmordersmarkup'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="btn-container with-tip"><div class="book-tip disabled-tip">' . $disabled_reason . '</div>' . $button_disabled . '</div>',
    );
    return;
  }

  if($max_books < 1) {
    $can_order = false;
    $form['confirmordersmarkup'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="btn-container">' . $overslots_button . '</div>' . $overslots_modal,
    );
  }

  if ($can_order) {
    $form['confirmordersmarkup'] = array(
      '#type' => 'markup',
      '#markup' => '<div class="btn-container">' . $button . '</div>' . $modal,
    );
  }
}

//Додаткова функція перевірки замовлення і сабміт
function bookbox_confirm_book($arg0,$arg1) {
    $user = user_load($arg0);
    $user_name = $user->field_name['und'][0]['value'] . ' ' . $user->field_sirname['und'][0]['value'];
    $time = time();

    //additional check
    $can_order = true;
    $uid = $arg0;
    $max_books = variable_get('varMaxBooks') - bookbox_count_in_confirm($uid) - bookbox_count_in_reading_now($uid);
    $form_product = $arg1;

    $is_in_order = is_in_order($form_product, $uid);
    $is_in_readingnow = is_in_redingnow($form_product, $uid);
    $is_in_archive = is_in_archive($form_product, $uid);

    $product = commerce_product_load($form_product);
    $stock = 0;

    if($product) {
        $stock = $product->commerce_stock['und'][0]['value'];
    }

    if ($is_in_order > 0 || $is_in_readingnow > 0 || $max_books < 1 || $stock < 1) {
        $can_order = false;
    }

    //user can order
    if ($can_order) {
        $order_product = $arg1;
        //Фомування темлейту мейлу
        $mail_body = $user->field_name['und'][0]['value'] . ' ' . $user->field_sirname['und'][0]['value'] . ', вітання! ';
        $mail_body = $mail_body . 'Замовлення успішно підтверджено.</br>';

        $book = _bookbox_get_product_display_by_product_id($order_product, $bundle = 'product_display', $field_name = 'field_bookfields');

        $file = file_load($book->field_nni['und'][0]['fid']);
        $uri = $file->uri;
        $url = file_create_url($uri);

        $tid = $book->field_book_author['und'][0]['tid'];
        $author = taxonomy_term_load($tid);

        $order_book = array();
        $order_book['src'] =  $GLOBALS['base_root'].'/node/' . $book->nid;
        $order_book['img_src'] = $url;
        $order_book['author'] = $author->name;
        $order_book['title'] = $book->title;

        $mail_body = $mail_body . '<div style="display:inline-block; width:200px; margin-top:20px; margin-bottom:20px;">' . '<a href="'.$GLOBALS['base_root'].'/node/' . $book->nid .'">
        <img src = "' . $url . '" width="167" height="250" style="display:block; />'
            . $book->title . '<br/>' . $author->name .'</a> </div>';

        //Створимо комерс-замовлення
        $order = commerce_order_new($user->uid, 'checkout_checkout');
        commerce_order_save($order);

        $product = commerce_product_load($order_product);
        $line_item = commerce_product_line_item_new($product, 1, $order->order_id);
        commerce_line_item_save($line_item);

        $order_wrapper = entity_metadata_wrapper('commerce_order', $order);
        $order_wrapper->commerce_line_items[] = $line_item;

        commerce_order_save($order);
        commerce_order_status_update($order, 'completed', $skip_save = FALSE, $revision = NULL, $log = '');

        $node = _bookbox_get_product_display_by_product_id($order_product);
        bookbox_node_update($node);

        //todo: delete from test
        db_update('commerce_order')
            ->fields(array('created' => $time))
            ->fields(array('changed' => $time))
            ->condition('order_id', $order->order_id)
            ->execute();

        db_update('commerce_order_revision')
            ->fields(array('revision_timestamp' => $time))
            ->condition('order_id', $order->order_id)
            ->execute();

        $mail_body = '<div>' . $mail_body . '<div style="clear:both;"></div>Деталі щодо доставки буде надіслано окремо. <br /><br />Команда Book Box. <br /><br /><span style="font-size:12px;">Це автоматичне повідомлення, будь ласка, не відповідайте на нього.</span>' . '</div>';

        $params['subject'] = 'Ваше замовлення';
        $params['content'] = $mail_body;

        $params['img1'] = '<a href="'.$order_book['src'].'"><img alt = "" src = "' . $order_book['img_src'] . '" style = "max-width:1626px;" class="mcnImage" width = "264" ></a>';
        $params['merge_vars']['FNAME'] = $user->field_name['und']['0']['value'];
        $params['merge_vars']['FULLNAME'] = $user_name;
        $params['merge_vars']['BTITLE1'] = $book->title;
        $params['merge_vars']['BAUTHOR1'] = $order_book['author'];
        $params['merge_vars']['BURL1'] =  $order_book['src'];
        $params['merge_vars']['DELIVERYDATE'] = next_friday($time);
        $params['name'] = $user->field_name['und']['0']['value'];

        bookbox_mail_send('bookbox', 'book_box_order', $user->mail, $params);
    }

    $date = time();
    $dest = drupal_get_destination();
    drupal_set_message('Ура, замовлення підтверджено! ' . verbose_period4popup($date));
    drupal_goto($dest);
}

//Форма http://prntscr.com/i8e541
function bookbox_admin_delivery_form ($form, &$form_state) {
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => 'Ми все доставили!',
    );

    return $form;
}

//Сабміт форми http://prntscr.com/i8e541
//При сабміті, всі замовлення з статусу - замовлено, потраплять в статус доставлено
function bookbox_admin_delivery_form_submit($form, &$form_state) {
    $result = db_select('commerce_order', 'o')
        ->fields('o', array('order_id', 'status', 'changed'))
        ->condition('o.status', 'completed')
        ->orderBy('o.order_id', 'DESC')
        ->execute()->fetchAll();

    foreach ($result as $item) {
        if ($item->status == 'completed') {

            //Букбокс доставляє книжки у наступну пятницю від замовлення.
            //Тобто, якщо замовлено в четверг ввечері або в пятницю,
            //то замоленя буде у наступну. Наступну пятницю калькулює ф-ця next_friday_object
            $nfo = next_friday_object($item->changed);
            $script_day = time();

            if($nfo->format('U') < $script_day) {
                $order = commerce_order_load($item->order_id);
                commerce_order_status_update($order, 'delivered', $skip_save = FALSE, $revision = NULL, $log = '');
            }
        }
    }

    //Пісял цього треба оновить стоки
    bookbox_equal_stocks();

    drupal_set_message(t('Статуси замовлень змінено!'));
}
