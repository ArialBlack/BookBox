<?php

function m() {
  $month = date("m");

  //hack month for testing
  $month = '03';

  return $month;
}


function d() {
  $day = date("d");

  //hack day for testing
  $day = '1';

  return $day;
}



function ua_month() {
  $current_date = intval(m()) - 1;
  $ua_monthes = ['січня', 'лютого', 'березня', 'квітня', 'травня','червня', 'липня', 'серпня', 'вересня', 'жовтня', 'листопада', 'грудня'];

  return $ua_monthes[$current_date];
}

function current_period() {
  $current_date = d();
  $period = 0;

  if ($current_date >=1 && $current_date <=20) {
    $period = 1;
  } else {
    $period = 2;
  }

  return $period;
}

function _bookbox_get_cart_items() {
  global $user;
  $can_add2cart = true;

  $order = commerce_cart_order_load($user->uid);
  if ($order) {
    $wrapper = entity_metadata_wrapper('commerce_order', $order);
    return $wrapper;
  } else {
    return false;
  }
}

function _bookbox_get_product_display_by_product_id($product_id, $bundle = 'product_display', $field_name = 'field_bookfields') {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node');
  //$query->propertyCondition('type', $bundle);
  $query->fieldCondition($field_name, 'product_id', $product_id);
  $query->range(0, 1);
  $result = $query->execute();
  if ($result) {
    $product_display_nid = key($result['node']);
    return node_load($product_display_nid);
  }
}

function bookbox_count_in_prolong() {
  return count(bookbox_get_in_prolong());
}

function bookbox_count_in_prolong_this_month() {
  $in_prolong_this_month = 0;

  foreach(bookbox_get_in_prolong() as $item) {
    if (date("m", $item->changed) == date("m")) {
      $in_prolong_this_month = $in_prolong_this_month + 1;
    }
  }

  return $in_prolong_this_month;
}

function bookbox_get_in_prolong() {
  global $user;

  $result = db_select('commerce_order', 'o')
      ->fields('o', array('order_id', 'status'))
      ->condition('o.uid', $user->uid)
      //->condition(
      //    db_or()
      //        ->condition('o.status', 'completed')
      //        ->condition('o.status', 'prolong')
      //)
      ->condition('o.status', 'prolong')
      ->orderBy('o.order_id', 'DESC')
      ->range(0,2)
      ->execute()->fetchAll();

  return $result;
}

function bookbox_count_in_confirm() {
  return count(bookbox_get_in_confirm());
}

function bookbox_count_in_confirm_this_month() {
  $in_confirm_this_month = 0;

  foreach(bookbox_get_in_confirm() as $item) {
    if (date("m", $item->changed) == m()) {
      $in_confirm_this_month = $in_confirm_this_month + 1;
    }
  }

  return $in_confirm_this_month;
}

function bookbox_get_in_confirm() {
  global $user;

  $result = db_select('commerce_order', 'o')
      ->fields('o', array('order_id', 'status', 'changed'))
      ->condition('o.uid', $user->uid)
      //->condition(
      //    db_or()
      //        ->condition('o.status', 'completed')
      //        ->condition('o.status', 'prolong')
      //)
      ->condition('o.status', 'completed')
      ->orderBy('o.order_id', 'DESC')
      ->range(0,2)
      ->execute()->fetchAll();

  return $result;
}

function bookbox_get_in_reading_now() {
  global $user;

  $result = db_select('commerce_order', 'o')
      ->fields('o', array('order_id', 'status'))
      ->condition('o.uid', $user->uid)
      ->condition(
          db_or()
              ->condition('o.status', 'completed')
              ->condition('o.status', 'prolong')
      )
      ->orderBy('o.order_id', 'DESC')
      ->range(0,2)
      ->execute()->fetchAll();

  return $result;
}