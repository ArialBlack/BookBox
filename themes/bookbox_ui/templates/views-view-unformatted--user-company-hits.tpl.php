<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */

global $user;
$uid = $user->uid;
$account = user_load($uid);
$company_nid = $account->field_company['und'][0]['target_id'];
$company = node_load($company_nid);

$result = db_select('field_data_field_company', 'c')
  ->fields('c', array('entity_id'))
  ->condition('c.field_company_target_id', $company_nid)
  ->execute()->fetchAll();

$company_orders = [];

foreach ($result as $uid) {
  $merge = array_merge($company_orders, _bookbox_user_orders($uid->entity_id));
  $company_orders = $merge;
}

$company_orders = sortAndUnique($company_orders);
$c = count($company_orders);

if($c >= 24) {
  $c = 24;
}
?>

<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>

<?php
  foreach ($company_orders as $key => $row) {
    $product_id = $key;
    $book = node_load($product_id);
    
    if($book->status == 1) {
      $node_view = node_view($book, 'teaser');
      $rendered_teaser = render($node_view);

      print '<div class="views-row">';
      print $rendered_teaser;
      print '</div>';

      $c--;
    }

    if($c == 0) {
      break;
    }
  }
?>


