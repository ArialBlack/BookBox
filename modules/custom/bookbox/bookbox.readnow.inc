<?php


// Блок ЧИТАЮ СЕЙЧАС
//
function bookbox_reading_now_block ($form, &$form_state) {
    global $user;
    $uid = $user->uid;
    $destination = request_path();

    //$title = variable_get('readingNow_title');
    $title = 'Зараз читаю';

    $result = bookbox_get_in_reading_now($uid);
    //dsm($result);
    //dsm($result);

    if ($result) {
        $form['title'] = array(
            '#type' => 'markup',
            //'#markup' => '<h3>' . $title . ' </h3><h6>Доставка книг відбудеться <span>27 ' .  ua_month(intval(m()-1)) . '</span></h6>', //todo
            '#markup' => '<h3>' . $title . ' </h3><h6>Поверніть книжки в стелаж до <span>25 ' . ua_month(intval(m()-1)) . '</span> або подовжіть ще на місяць</h6>',
        );

        $box_count = 0;

        foreach ($result as $res) {
            //
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
                                            <a class="btn btn-outline red" href="/confirm/' . $uid . '/' . $res->order_id .'/prolong' . $box_count . '?destination=' . $destination . '">Так</a>
                                            <button type="button" class="btn btn-outline red" data-dismiss="modal">Ні</button>
                                          </div>
                                        </div>
                                      </div>
                                    </div>';

                            $wrapper = _bookbox_get_cart_items();
                            $cart_count = 0;

                            if ($wrapper) {
                                foreach ($wrapper->commerce_line_items as $delta => $line_item_wrapper) {
                                    $cart_product = $line_item_wrapper->commerce_product->value()->product_id;

                                    $product_display1 = _bookbox_get_product_display_by_product_id($cart_product);

                                    if ($product_display1->nid) {
                                        $cart_count = $cart_count + 1;
                                    }
                                }
                            }

                            $reading_now_count = count(bookbox_get_in_reading_now($uid));

                            if ($cart_count + $reading_now_count > 2) {
                                $modal = '<button type="button" class="btn btn-primary" data-toggle="modal" data-target="#confirm-prolong' . $box_count . '">Подовжити на місяць</button>
                            <div class="modal fade" tabindex="-1" role="dialog" id="confirm-prolong' . $box_count . '">
                                      <div class="modal-dialog" role="document">
                                        <div class="modal-content">
                                          <div class="modal-header">
                                            <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
                                          </div>
                                          <div class="modal-body">
                                            <p>Для успішного подовження видаліть обрану книгу із “Замовлення місяця”.</p>
                                          </div>
                                          <div class="modal-footer">
                                            <button type="button" class="btn btn-outline red" data-dismiss="modal">Зрозуміло</button>
                                          </div>
                                        </div>
                                      </div>
                                    </div>';
                            }

                            if (bookbox_count_in_confirm_this_month($uid) > 0) {
                                $modal = '';
                            }

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
    //dsm($form);

    return $form;
}

function bookbox_prolongbook1($arg0, $arg1) {
    $order_id = $arg1;
    $order = commerce_order_load($order_id);
    //dsm(time());

    /*db_update('commerce_order')
        ->fields(array('changed' => time() ))
        ->fields(array('status' => 'prolong'))
        ->condition('order_id', $order_id)
        ->execute();*/

    commerce_order_status_update($order, 'prolong', $skip_save = FALSE, $revision = NULL, $log = '');
    commerce_order_save($order);

    $dest = drupal_get_destination();
    drupal_goto($dest);
}

function bookbox_prolongbook2($arg0, $arg1) {
    $order_id = $arg1;
    $order = commerce_order_load($order_id);
    //dsm(time()); // 1498889721

    /*db_update('commerce_order')
        ->fields(array('changed' => time() ))
        ->fields(array('status' => 'prolong'))
        ->condition('order_id', $order_id)
        ->execute();*/

    commerce_order_status_update($order, 'prolong', $skip_save = FALSE, $revision = NULL, $log = '');
    commerce_order_save($order);

    $dest = drupal_get_destination();
    drupal_goto($dest);
}
