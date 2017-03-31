<?php

// Блок корзины
function bookbox_mini_cart_block($form, &$form_state) {
    global $user;
    $uid = $user->uid;
    $destination = request_path();

    if(current_period() == 1) {
        $form['ftitle'] = array(
            '#type' => 'markup',
            '#markup' => '<h3>Замовлення ' . ua_month() . '</h3><h6>Оберіть дві книги до <span>20-го ' .  ua_month() . '</span> включно</h6>',
        );
    }

    if(current_period() == 2) {
        $form['ftitle'] = array(
            '#type' => 'markup',
            '#markup' => '<h3>Замовлення ' . ua_month() . ' не підтверджено</h3><h6>Робіть замовлення з <span>1-го ' .  ua_month(intval(m())) . '</span></h6>',
        );
    }


    //todo
    // если у нас есть книжки их прошлого месяца то тогда что?
    // если 1 из прошлого то показывать 1 свободное место
    $wrapper = _bookbox_get_cart_items();
    $cart_count = 0;

    if ($wrapper) {
        foreach ($wrapper->commerce_line_items as $delta => $line_item_wrapper) {
            $cart_product = $line_item_wrapper->commerce_product->value()->product_id;

            $product_display = _bookbox_get_product_display_by_product_id($cart_product);

            if ($product_display->nid) {
                $cart_count = $cart_count + 1;

                $node = node_load($product_display->nid);
                $node_view = node_view($node, 'teaser');
                $rendered_teaser = render($node_view);

                $form['bms' . $cart_count] = array(
                    '#type' => 'markup',
                    '#markup' => '<div class="book-container">',
                );

                $form['book_' . $cart_count] = array(
                    '#type' => 'markup',
                    '#markup' => $rendered_teaser,
                );

                $form['del_from_cart_submit' . $cart_count] = array(
                    '#type' => 'submit',
                    '#submit' => array('bookbox_delete_bookfromcart' . $cart_count),
                    '#value' => 'видалити' . $cart_count,
                );

                $form['bme' . $cart_count] = array(
                    '#type' => 'markup',
                    '#markup' => '</div>',
                );
            }
        }
    }

    //$in_prolong = bookbox_count_in_prolong();
    //$in_confirm = bookbox_get_in_confirm();
    
    //$reading_now = count(bookbox_get_in_reading_now($uid));
    //dsm($reading_now);

    if ($cart_count < 2) {
        $in_prolong = bookbox_count_in_prolong_this_month($uid);
        //dsm($in_prolong);
        $empty_cells = 2 - $cart_count - $in_prolong;

        for($i=0; $i <$empty_cells;$i++) {
            $form['add_book_link_'.$i] = array(
                '#type' => 'markup',
                '#markup' => '<div class="add_some_book">Оберіть книгу</div>',
            );

        }

        if ($empty_cells < 1) {
            //dsm($form);
            unset($form['ftitle']);
        }
        //todo можно один сабмитить если 1 книга в продлении :TRUE
        //$form['submit_box']['#attributes']['disabled'] = FALSE;
        //dsm($form, 'form');
    }



    //dsm(bookbox_count_in_confirm_this_month());

    // кнопка подтверждения доступна если
    // 1. число 1- 20
    // и 2.колво выбраных + кол-во в пролонге = 2
    /////// если колво выбраных + пролонг > 2 и (1.) писать "удалите одну"
    // 3. если он уже подтверждал выбор в этом мес (полтв в этом мес > 0)
    // писать вы уже какбе того
    //dsm('this', bookbox_count_in_confirm_this_month());
//dsm(current_period());

    if(current_period() == 1 && bookbox_count_in_confirm_this_month($uid) == 0 && $cart_count > 0) {
        //может быть кнопка. 1-20 число и еще не потверждал и что-то есть в корзине


        /*if ($cart_count + $reading_now == 2) {
            $form['submit_box'] = array(
                '#type' => 'submit',
                '#submit' => array('bookbox_confirm_box'),
                '#weight' => 10,
                '#value' => 'Підтвердити замовлення', //todo
            );
        }*/

        if ($cart_count + bookbox_count_in_prolong_this_month($uid) == 2) {

            $modal = '<button type="button" id="edit-submit-box" class="btn btn-primary" data-toggle="modal" data-target="#confirm-orders">Підтвердити замовлення</button>
                            <div class="modal fade" tabindex="-1" role="dialog" id="confirm-orders">
                                      <div class="modal-dialog" role="document">
                                        <div class="modal-content">
                                          <div class="modal-header">
                                            <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
                                          </div>
                                          <div class="modal-body">
                                            <p>Ви підтверджуєте замовлення місяця?</p>
                                          </div>
                                          <div class="modal-footer">
                                            <a class="btn btn-outline red" href="/confirm/' . $uid . '/orders?destination=' . $destination . '">Так</a>
                                            <button type="button" class="btn btn-outline red" data-dismiss="modal">Ні</button>
                                          </div>
                                        </div>
                                      </div>
                                    </div>';


            $form['confirmordersprolongmarkup'] = array(
                '#type' => 'markup',
                '#markup' => $modal,
            );
        }


        if ($cart_count + bookbox_count_in_prolong_this_month($uid) == 3 && bookbox_count_in_prolong_this_month($uid) == 1) {
            $form['submit_box_markup'] = array(
                '#type' => 'markup',
                '#markup' => '<p class="tip_message">Видаліть одну книгу для підтвердження замовлення</p>'
            );
        }

        if ($cart_count + bookbox_count_in_prolong_this_month($uid) > 3) {
            $form['submit_box_markup'] = array(
                '#type' => 'markup',
                '#markup' => '<p class="tip_message">Підтвердьте замовлення з 1-го числа наступного місяця</p>'
            );
        }
    } else {
       // $form['submit_box_markup'] = array(
       //     '#type' => 'markup',
       //     '#markup' => '<p class="tip_message">Підтвердьте замовлення з 1-го числа наступного місяця</p>'
       // );
    }


/*
    if ($cart_count > 0) {
        $form['submit_box'] = array(
            '#type' => 'submit',
            '#submit' => array('bookbox_confirm_box'),
            '#weight' => 10,
            '#value' => t('Підтвердити замовлення'), //todo
        );
    }*/

    //dsm('c', $cart_count);



    return $form;
}


function bookbox_delete_bookfromcart1 ($form, &$form_state) {
    //dsm('-1');
    global $user;
    $order = commerce_cart_order_load($user->uid);
    $line_item = $order->commerce_line_items['und'][0]['line_item_id'];
    //dsm($line_item);
    commerce_cart_order_product_line_item_delete($order, $line_item);
    commerce_cart_order_refresh($order);
}


function bookbox_delete_bookfromcart2 ($form, &$form_state) {
    //dsm('-2');
    global $user;
    $order = commerce_cart_order_load($user->uid);
    $line_item = $order->commerce_line_items['und'][1]['line_item_id'];
    commerce_cart_order_product_line_item_delete($order, $line_item);
    commerce_cart_order_refresh($order);
}


function bookbox_confirm_box($arg0) {
    //drupal_set_message('Дякуємо! Ви щойно підтвердили замовлення місяця.');
    $user = user_load($arg0);
    $mail_body = $user->field_name['und'][0]['value'] . ' ' . $user->field_sirname['und'][0]['value'] . ', вітання!</br>';
    $mail_body = $mail_body . 'Замовлення місяця успішно підтверджено.</br>';

    $order = commerce_cart_order_load($user->uid);
    $order_count = count($order->commerce_line_items['und']);

    $product_id2 = '';

    // 1. запомним второй товар
    if($order_count == 2) {
        $line_item_id2 = $order->commerce_line_items['und'][1]['line_item_id'];
        $line_item2 = commerce_line_item_load($line_item_id2); // второй товар
        $product_id2 = $line_item2->commerce_product['und']['0']['product_id'];
        $book2 = _bookbox_get_product_display_by_product_id($product_id2, $bundle = 'product_display', $field_name = 'field_bookfields');
        $mail_body = $mail_body . ' Книга : ' . '<a href="http://lib.bookbox.ua/node/' . $book2->nid .'">' . $book2->title . '</a> </br>'; //todo domain

        //2. удалим второй товар
        commerce_cart_order_product_line_item_delete($order, $line_item_id2);
    }

    //3. проапдейтим статус первого товара
    $line_item_id1 = $order->commerce_line_items['und'][0]['line_item_id'];
    $line_item1 = commerce_line_item_load($line_item_id1); // второй товар
    $product_id1 = $line_item1->commerce_product['und']['0']['product_id'];
    $book1 = _bookbox_get_product_display_by_product_id($product_id1, $bundle = 'product_display', $field_name = 'field_bookfields');
    $mail_body = $mail_body . ' Книга : ' . '<a href="http://lib.bookbox.ua/node/' . $book1->nid .'">' . $book1->title . '</a> </br>'; //todo domain

    commerce_order_status_update($order, 'completed', $skip_save = FALSE, $revision = NULL, $log = '');

    //4. добавим второй товар в корзину
    if($order_count == 2) {
        $order = commerce_order_new($user->uid, 'checkout_checkout');
        commerce_order_save($order);

        $product = commerce_product_load($product_id2);
        $line_item = commerce_product_line_item_new($product, 1, $order->order_id);
        commerce_line_item_save($line_item);

        $order_wrapper = entity_metadata_wrapper('commerce_order', $order);
        $order_wrapper->commerce_line_items[] = $line_item;
        commerce_order_save($order);

        //5. проапдейтим статус второго товара
        commerce_order_status_update($order, 'completed', $skip_save = FALSE, $revision = NULL, $log = '');
    }

    $mail_body = $mail_body . 'Деталі щодо доставки буде надіслано окремо. </br>Команда Book Box </br>Це автоматичне повідомлення, будь ласка, не відповідайте на нього.';

    //6. Пошлем емейл
    drupal_mail('system', 'mail', $user->mail, language_default(), array(
        'context' => array(
        'subject' => 'Ваше замовлення ' . ua_month($m = null),
        'message' => $mail_body,
        )));

    $dest = drupal_get_destination();
    drupal_goto($dest);
}