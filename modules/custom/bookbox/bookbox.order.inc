<?php

// Блок Заказ
function bookbox_current_order_block ($form, &$form_state) {
    global $user;
    $uid = $user->uid;
    $destination = request_path();

    $max_books = variable_get('varMaxBooks') - bookbox_count_in_confirm($uid) - bookbox_count_in_reading_now($uid);
    $can_order_text = '';

    switch ($max_books) {
        case 1:
            $can_order_text = $max_books . ' книгу';
            break;
        case 2:
        case 3:
        case 4:
            $can_order_text = $max_books . ' книги';
            break;
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
            $can_order_text = $max_books . ' книжок';
            break;
    }

    $result =  bookbox_get_in_confirm($uid);

    if (bookbox_count_in_confirm($uid) > 0) {
            $form['title'] = array(
                '#type' => 'markup',
                '#markup' => '<h3>Замовлено</h3>',
            );
        } else {
        $form['title'] = array(
                '#type' => 'markup',
                '#markup' => '<h3>Зробіть замовлення</h3><h6>Доставка книжок щоп’ятниці</h6>',
            );
    }

    $box_count = 0;

    foreach ($result as $res) {
            $order = commerce_order_load($res->order_id);

            $line_item_id = $order->commerce_line_items['und'][0]['line_item_id'];
            $line_item = commerce_line_item_load($line_item_id);
            $product_id =  $line_item->commerce_product['und'][0]['product_id'];
            $product_display = _bookbox_get_product_display_by_product_id($product_id);

            $order_date = date('d.m.Y H:i', $order->changed);

            if ($product_display->nid) {
                $box_count = $box_count + 1;

                $order_date = 'Замовлено: ' . $order_date;

                $node = node_load($product_display->nid);
                $node_view = node_view($node, 'teaser');
                $rendered_teaser = render($node_view);

                $form['bms' . $box_count] = array(
                    '#type' => 'markup',
                    '#markup' => '<div class="book-container">' . verbose_period4order_short($order->changed),
                );

                $form['book_' . $box_count] = array(
                    '#type' => 'markup',
                    '#markup' => $rendered_teaser
                );

                $form['bme' . $box_count] = array(
                    '#type' => 'markup',
                    '#markup' => '<div class="order-date debug-info">' . $order_date . '</div>' . '</div>',
                );
            }
        }
    
    return $form;
}


