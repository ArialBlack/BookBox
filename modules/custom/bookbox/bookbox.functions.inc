<?php

function _bookbox_get_cart_items() {
  global $user;
  $can_add2cart = true;

  $order = commerce_cart_order_load($user->uid);
  $wrapper = entity_metadata_wrapper('commerce_order', $order);

  return $wrapper;
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