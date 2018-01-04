<?php
/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct URL of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type; for example, "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type; for example, story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode; for example, "full", "teaser".
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined; for example, $node->body becomes $body. When needing to
 * access a field's raw values, developers/themers are strongly encouraged to
 * use these variables. Otherwise they will have to explicitly specify the
 * desired field language; for example, $node->body['en'], thus overriding any
 * language negotiation rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 *
 * @ingroup templates
 */
$product_id = $node->field_bookfields['und'][0]['product_id'];
$product = commerce_product_load($product_id);
$status = $product->status;

$aviable_class = '';

if ($status == 0) {
  $aviable_class = ' not-aviable';
}

$node_lang = $node->language;
$translations = translation_path_get_translations("node/" . $node->nid);

?>
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes;  print $aviable_class; ?> clearfix"<?php print $attributes; ?>>
  <?php
  // Hide comments, tags, and links now so that we can render them later.
  hide($content['comments']);
  hide($content['links']);
  hide($content['field_tags']);
  //print render($content);

  $author_count = count($node->field_book_author['und']);
  //dsm($author_count);

  if ($author_count > 1) {
    $tab_title = 'Про авторів';
  } else {
    $tab_title = 'Про автора';
  }
  ?>

  <div class="desktop hidden-xs">
    <header>
      <h1<?php print $title_attributes; ?>><?php print $title; ?></h1>
      <?php print render($content['field_book_author']); ?>
      <?php print $node->body['und'][0]['safe_value']; ?>

      <div class="book-dids">
        <?php print render($content['field_bookfields']); ?>
        <?php print render($content['links']); ?>

        <?php
          if (count($translations) > 1) {
            print '<ul class="books-translations">';
            foreach ($translations as $key => $value) {
              if($key != $node_lang) {
                switch ($key) {
                  case 'uk':
                    $l_name = 'українською';
                    break;

                  case 'en':
                    $l_name = 'англійською';
                    break;

                  case 'ru':
                    $l_name = 'російською';
                    break;
                }
                print '<li><a href="/' . drupal_get_path_alias($value) .'">Є  ' . $l_name . ' мовою</a></li>';
              }
            }
            print '</ul>';
          }
        ?>

      </div>
    </header>

    <div class="cover-description">
      <?php print render($content['field_nni']); ?>
      <?php print render($content['field_origin_name']); ?>
      <?php print render($content['field_book_publisher']); ?>
      <?php print render($content['field_lang']); ?>
      <?php print render($content['field_book_category']); ?>
    </div>

    <div class="description-tabs">
      <ul class="nav nav-tabs" role="tablist">
        <li role="presentation" class="active"><a href="#book" aria-controls="book" role="tab" data-toggle="tab">Про книгу</a></li>
        <li role="presentation"><a href="#author" aria-controls="author" role="tab" data-toggle="tab"><?php print $tab_title; ?></a></li>
      </ul>
      <div class="tab-content">
        <div role="tabpanel" class="tab-pane active" id="book">
          <?php print render($content['field_about']); ?>
        </div>
        <div role="tabpanel" class="tab-pane" id="author">
          <?php
          for($i = 0; $i < $author_count; $i++) {
            $desc = $node->field_book_author['und'][$i]['taxonomy_term']->description;
            $uri = $node->field_book_author['und'][$i]['taxonomy_term']->field_author_photo['und'][0]['uri'];
            print '<div class="author-block"><div class="a-img"><img src="' . image_style_url("medium", $uri) . '"/></div>';
            print $desc . '</div>';

          }
          ?>
        </div>
      </div>
    </div>
  </div>

  <div class="mobile visible-xs">
    <h1<?php print $title_attributes; ?>><?php print $title; ?></h1>
    <?php print render($content['field_book_author']); ?>
    <?php print render($content['field_nni']); ?>
    <?php print $node->body['und'][0]['safe_value']; ?>

    <div class="book-dids">
      <?php print render($content['field_bookfields']); ?>
      <?php print render($content['links']); ?>
    </div>

    <div class="description-tabs-mobile">
      <ul class="nav nav-tabs" role="tablist">
        <li role="presentation" class="active"><a href="#spec-m" aria-controls="spec-m" role="tab" data-toggle="tab">Характеристики</a></li>
        <li role="presentation"><a href="#book-m" aria-controls="book-m" role="tab" data-toggle="tab">Про книгу</a></li>
        <li role="presentation"><a href="#author-m" aria-controls="author-m" role="tab" data-toggle="tab">Про автора</a></li>
      </ul>

      <div class="tab-content">

        <div role="tabpanel" class="tab-pane active" id="spec-m">
          <?php print render($content['field_origin_name']); ?>
          <?php print render($content['field_book_publisher']); ?>
          <?php print render($content['field_lang']); ?>
          <?php print render($content['field_book_category']); ?>
        </div>

        <div role="tabpanel" class="tab-pane" id="book-m">
          <?php print render($content['field_about']); ?>
        </div>

        <div role="tabpanel" class="tab-pane" id="author-m">
          <?php
          for($i = 0; $i < $author_count; $i++) {
            $desc = $node->field_book_author['und'][$i]['taxonomy_term']->description;
            $uri = $node->field_book_author['und'][$i]['taxonomy_term']->field_author_photo['und'][0]['uri'];
            print '<div class="author-block"><div class="a-img"><img src="' . image_style_url("medium", $uri) . '"/></div>';
            print $desc . '</div>';

          }
          ?>
        </div>
      </div>
    </div>

  </div>


</article>
