<?php

// Блок Заказ месяца
function bookbox_month_order_block ($form, &$form_state) {
    global $user;
    $uid = $user->uid;
    $destination = request_path();

    //$title = variable_get('readingNow_title');
    $title = 'Замовлення підтверджено';

    $result = bookbox_get_in_reading_now();
    //dsm($result);

    if ($result) {
        $form['title'] = array(
            '#type' => 'markup',
            '#markup' => '<h3>' . $title . ' </h3><h6>Доставка книг відбудеться <span>27 ' .  ua_month(intval(m()-1)) . '</span></h6>', //todo
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
                           /* $form['prolong_book' . $box_count] = array(
                                '#type' => 'submit',
                                '#submit' => array('bookbox_prolongbook' . $box_count),
                                '#value' => 'Подовжити на місяць <span>' . $box_count . '</span>',
                            );*/




                            $modal = '<button type="button" class="btn btn-primary" data-toggle="modal" data-target="#confirm-prolong' . $box_count . '">Подовжити на місяць</button>
                            <div class="modal fade" tabindex="-1" role="dialog" id="confirm-prolong' . $box_count . '">
                                      <div class="modal-dialog" role="document">
                                        <div class="modal-content">
                                          <div class="modal-header">
                                            <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
                                          </div>
                                          <div class="modal-body">
                                            <p>Ви підтверджуєте подовження книг на місяць?</p>
                                          </div>
                                          <div class="modal-footer">
                                            <a class="btn btn-outline red" href="/confirm/' . $uid . '/prolong' . $box_count . '?destination=' . $destination . '">Так</a>
                                            <button type="button" class="btn btn-outline red" data-dismiss="modal">Ні</button>
                                          </div>
                                        </div>
                                      </div>
                                    </div>';


                            ///////////
                            //скроем временно

                            $form['prolongmarkup' . $box_count] = array(
                                '#type' => 'markup',
                                '#markup' => $modal,
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


