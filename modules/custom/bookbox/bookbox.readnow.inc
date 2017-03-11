<?php


// Блок ЧИТАЮ СЕЙЧАС
//
function bookbox_reading_now_block ($form, &$form_state) {
    $title = variable_get('readingNow_title');

    $result = bookbox_get_in_reading_now();
    //dsm($result);

    if ($result) {
        $form['title'] = array(
            '#type' => 'markup',
            '#markup' => '<h3>' . $title . ' </h3><h6>Повернення книг до <span>20-го ' .  ua_month(intval(m())) . '</span></h6>', //todo
        );

        $box_count = 0;

        foreach ($result as $res) {
            //
            $order = commerce_order_load($res->order_id);

            //dsm($order);

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

                //todo
                switch ($res->status) {
                    case 'completed':
                        if(current_period() == 1) {
                            $form['prolong_book' . $box_count] = array(
                                '#type' => 'submit',
                                '#submit' => array('bookbox_prolongbook' . $box_count),
                                '#value' => 'Подовжити на місяць <span>' . $box_count . '</span>',
                            );

                        }
                        break;
                    case 'prolong':
                        $form['prolong_book' . $box_count] = array(
                            '#type' => 'submit',
                            //'#submit' => array('bookbox_prolongbook' . $box_count),
                            '#value' => 'Подовжено <span>' . $box_count . '</span>',
                        );
                        $form['prolong_book' . $box_count]['#attributes']['disabled'] = TRUE;
                        break;
                }

                $form['bme' . $box_count] = array(
                    '#type' => 'markup',
                    '#markup' => '</div>',
                );
            }
        }
    }

    return $form;
}

function bookbox_prolongbook1($form, &$form_state) {
    $result = bookbox_get_in_reading_now();
   // dsm($result);

    if ($result) {
        $order_id = $result[0]->order_id;
        $order = commerce_order_load($order_id);
        //dsm($order);
        commerce_order_status_update($order, 'prolong', $skip_save = FALSE, $revision = NULL, $log = '');
    }
}

function bookbox_prolongbook2($form, &$form_state) {
    $result = bookbox_get_in_reading_now();

    if ($result && count($result) > 1) {
        $order_id = $result[1]->order_id;
        $order = commerce_order_load($order_id);
        commerce_order_status_update($order, 'prolong', $skip_save = FALSE, $revision = NULL, $log = '');
    }
}
