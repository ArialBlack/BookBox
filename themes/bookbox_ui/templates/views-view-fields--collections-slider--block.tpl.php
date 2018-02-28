<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 */

$tid = $fields['tid']->raw;
$data = taxonomy_select_nodes($tid);
$count = count($data);
$nc = '<div>' . verbose_book_num($count, 'книга', 'книги', 'книг') . '</div>'; //todo verbose
?>

<?php
  $output = '<a href="/taxonomy/term/' . $tid . '">';

  if(isset($fields['field_nni'])) {
    $output = $output . '<div class="term-image">' . $fields['field_nni']->content . '</div>';
  }

  $output = $output . $nc;

  if(isset($fields['name'])) {
    $output = $output .  '<div class="term-name">' . $fields['name']->raw . '</div>';
  }

  if (isset($fields['description'])) {
    $output = $output . '<div class="term-description">' . $fields['description']->content. '</div>';
  }

  $output = $output . '</a>';
  print $output;
?>
