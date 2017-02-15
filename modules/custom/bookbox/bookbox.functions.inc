<?php

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

function bookbox_get_in_prolong() {
  global $user;

  $result = db_select('commerce_order', 'o')
      ->fields('o', array('order_id'))
      ->condition('o.status', 'completed')
      ->condition('o.uid', $user->uid)
      ->orderBy('o.order_id', 'DESC')
      ->range(0,2)
      ->execute()->fetchAll();

  return $result;
}