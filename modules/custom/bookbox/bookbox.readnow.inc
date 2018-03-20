<?php

//Старый блок, можно удалить после релиза

// Блок ЧИТАЮ СЕЙЧАС
function bookbox_reading_now_block ($form, &$form_state) {
    global $user;
    $uid = $user->uid;
    $destination = request_path();

    //$title = variable_get('readingNow_title');
    $title = 'Зараз читаю';

    $result = bookbox_get_in_reading_now($uid);

    if ($result) {
        $form['title'] = array(
            '#type' => 'markup',
            '#markup' => '<h3>' . $title . ' </h3><h6>Прочитані книжки залишайте у стелажі Book Box</h6>',
        );

        $box_count = 0;

        foreach ($result as $res) {
            $order = commerce_order_load($res->order_id);
            
            $line_item_id = $order->commerce_line_items['und'][0]['line_item_id'];
            $line_item = commerce_line_item_load($line_item_id);
            $product_id =  $line_item->commerce_product['und'][0]['product_id'];
            $product_display = _bookbox_get_product_display_by_product_id($product_id);

            if ($product_display->nid) {
                $box_count = $box_count + 1;

                $node = node_load($product_display->nid);
                $node_view = node_view($node, 'teaser');
                $rendered_teaser = render($node_view);

                $form['bms' . $box_count] = array(
                    '#type' => 'markup',
                    '#markup' => '<div class="book-container">',
                );

                $form['book_' . $box_count] = array(
                    '#type' => 'markup',
                    '#markup' => $rendered_teaser,
                );

                $form['bme' . $box_count] = array(
                    '#type' => 'markup',
                    '#markup' => '</div>',
                );
            }
        }
    }

    return $form;
}

