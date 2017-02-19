<?php

// Блок корзины
function bookbox_mini_cart_block($form, &$form_state) {
    $form['title'] = array(
        '#type' => 'markup',
        '#markup' => '<h3>Замовлення '. ua_month() . '</h3>',
    );

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

                if ($product_display->field_nni) {
                    $fid = $product_display->field_nni['und']['0']['fid'];
                    $file = file_load($fid);

                    if ($file) {
                        $uri = $file->uri;
                        $img = '<img src=\'' . image_style_url("bookcover", $uri) . '\' />';

                        $form['book_cover' . $cart_count] = array(
                            '#type' => 'markup',
                            '#markup' => $img,
                        );
                    }
                }

                $form['book_' . $cart_count] = array(
                    '#type' => 'markup',
                    '#markup' => $product_display->title,
                );

                $form['del_from_cart_submit' . $cart_count] = array(
                    '#type' => 'submit',
                    '#submit' => array('bookbox_delete_bookfromcart' . $cart_count),
                    '#value' => t('delete from box'),
                );
            }
        }
    }
    
    $in_prolong = bookbox_count_in_prolong();
    $in_confirm = bookbox_get_in_confirm();

    dsm(bookbox_count_in_confirm_this_month());

    // кнопка подтверждения доступна если
    // 1. число 1- 20
    // и 2.колво выбраных + кол-во в пролонге = 2
    /////// если колво выбраных + пролонг > 2 и (1.) писать "удалите одну"
    // 3. если он уже подтверждал выбор в этом мес (полтв в этом мес > 0)
    // писать вы уже какбе того


/*
    if ($cart_count > 0) {
        $form['submit_box'] = array(
            '#type' => 'submit',
            '#submit' => array('bookbox_confirm_box'),
            '#weight' => 10,
            '#value' => t('Підтвердити замовлення'), //todo
        );
    }*/

    if ($cart_count < 2) {
        $in_prolong = bookbox_count_in_prolong();
        $empty_cells = 2 - $cart_count - $in_prolong;

        for($i=0; $i <$empty_cells;$i++) {
            $form['add_book_link_'.$i] = array(
                '#type' => 'markup',
                '#markup' => '<a class="add_some_book" href="/books">Оберіть книгу</a>',
            );

        }
        //todo можно один сабмитить если 1 книга в продлении :TRUE
        //$form['submit_box']['#attributes']['disabled'] = FALSE;
        //dsm($form, 'form');
    }

    return $form;
}


function bookbox_delete_bookfromcart1 ($form, &$form_state) {
    global $user;
    $order = commerce_cart_order_load($user->uid);
    $line_item = $order->commerce_line_items['und'][0]['line_item_id'];
    //dsm($line_item);
    commerce_cart_order_product_line_item_delete($order, $line_item);
    commerce_cart_order_refresh($order);
}


function bookbox_delete_bookfromcart2 ($form, &$form_state) {
    global $user;
    $order = commerce_cart_order_load($user->uid);
    $line_item = $order->commerce_line_items['und'][1]['line_item_id'];
    commerce_cart_order_product_line_item_delete($order, $line_item);
    commerce_cart_order_refresh($order);
}



function bookbox_confirm_box($form, &$form_state) {
    drupal_set_message('confirm');
    global $user;

    $prolong = bookbox_get_in_prolong();
    $in_prolong = 0;
    //что-то продлено
    if($prolong) {
        foreach($prolong as $item) {
            if ($item->status == 'prolong') {
                $in_prolong = $in_prolong + 1;
            }
        }
    }

    $order = commerce_cart_order_load($user->uid);
    //dsm($order, 'order');

    if(count($order->commerce_line_items['und']) + $in_prolong == 2) {
        // 1. запомним второй товар
        $line_item_id2 = $order->commerce_line_items['und'][1]['line_item_id'];
        $line_item2 = commerce_line_item_load($line_item_id2); // второй товар
        $product_id2 = $line_item2->commerce_product['und']['0']['product_id'];
        //dsm($line_item2);

        //2. удалим второй товар
        commerce_cart_order_product_line_item_delete($order, $line_item_id2);

        //3. проапдейтим статус первого товара
        commerce_order_status_update($order, 'completed', $skip_save = FALSE, $revision = NULL, $log = '');

        //4. добавим второй товар в корзину
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
    } else {
        drupal_set_message('Error');
    }
}