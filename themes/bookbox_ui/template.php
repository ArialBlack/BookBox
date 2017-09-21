<?php
/**
 * @file
 * The primary PHP file for this theme.
 */

function bookbox_ui_preprocess_node(&$vars) {
  if (variable_get('node_submitted_' . $vars['node']->type, TRUE)) {
    $date = format_date($vars['node']->created, 'date_type');
    $vars['submitted'] = t('Submitted by !username on !datetime', array('!username' => $vars['name'], '!datetime' => $date));
  }

  if($vars['view_mode'] == 'teaser') {
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->type . '__teaser';  // node--[type|nodeid]--teaser.tpl.php
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->nid . '__teaser';
  }

  if($vars['view_mode'] == 'full') {
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->type . '__full';  // node--[type|nodeid]--full.tpl.php
    $vars['theme_hook_suggestions'][] = 'node__' . $vars['node']->nid . '__full';
  }
}

function bookbox_ui_preprocess_page(&$vars) {

  $url  = request_path();

  if(!$vars['user']->uid && arg(0) != 'user' && arg(1) != 'login' && $url != 'terms' && $url !='privacy') {
    drupal_goto('user/login');
  }

  // Do we have a node?
  if (isset($vars['node'])) {

    ///////////////
    $breadcrumb = array();
    $breadcrumb[] = l('Головна', '<front>');
    $tid = null;

    $urlparams = drupal_get_query_parameters();
    if(isset($urlparams['term'])) {
      $tid = $urlparams['term'];
    } else {
      if ($vars['node']->type == 'book') {
        $nid = $vars['node']->nid;
        $node = node_load($nid);
        $tid = $node->field_book_category['und'][1]['tid'];
      }
    }

    if(isset($tid)) {
      $term = taxonomy_term_load($tid);
      $parent = taxonomy_get_parents_all($tid);
      $parent = array_reverse($parent);

      foreach ($parent as $item) {
        $breadcrumb[] = l($item->name, 'taxonomy/term/' . $item->tid);
      }
    }

    drupal_set_breadcrumb($breadcrumb);
    ////////////////

    // Ref suggestions cuz it's stupid long.
    $suggests = &$vars['theme_hook_suggestions'];

    // Get path arguments.
    $args = arg();
    // Remove first argument of "node".
    unset($args[0]);

    // Set type.
    $type = "page__type_{$vars['node']->type}";

    // Bring it all together.
    $suggests = array_merge(
      $suggests,
      array($type),
      theme_get_suggestions($args, $type)
    );

    // if the url is: 'http://domain.com/node/123/edit'
    // and node type is 'blog'..
    //
    // This will be the suggestions:
    //
    // - page__node
    // - page__node__%
    // - page__node__123
    // - page__node__edit
    // - page__type_blog
    // - page__type_blog__%
    // - page__type_blog__123
    // - page__type_blog__edit
    //
    // Which connects to these templates:
    //
    // - page--node.tpl.php
    // - page--node--%.tpl.php
    // - page--node--123.tpl.php
    // - page--node--edit.tpl.php
    // - page--type-blog.tpl.php          << this is what you want.
    // - page--type-blog--%.tpl.php
    // - page--type-blog--123.tpl.php
    // - page--type-blog--edit.tpl.php
    //
    // Latter items take precedence.
  }
}

function bookbox_ui_preprocess(&$variables) {
  global $user;

  $query = db_select('flagging', 'f');
  $query->addExpression('COUNT(*)');
  $query->condition('f.uid', $user->uid);
  $count = $query->execute()->fetchField();

  $variables['u_flag'] = $count;
}

function bookbox_ui_preprocess_html(&$vars, $hook) {
  $path = drupal_get_path_alias();
  $aliases = explode('/', $path);

  foreach($aliases as $alias) {
    $vars['classes_array'][] = drupal_clean_css_identifier($alias);
  }
  
  if ($vars['user']) {
    foreach($vars['user']->roles as $key => $role){
      $role_class = 'role-' . drupal_clean_css_identifier($role);
      $vars['classes_array'][] = $role_class;
    }
  }

  $r = request_path();

  //https://lib.bookbox.ua/user/login - Вхід | Book Box
  //https://lib.bookbox.ua/user/register - Реєстрація | Book Box
  //https://lib.bookbox.ua/user/password - Відновлення паролю | Book Box
  //https://lib.bookbox.ua/ - Book Box (не капсом і без рисочки)
  //https://lib.bookbox.ua/user (сторінка профілю) - Профіль | Book Box
  //https://lib.bookbox.ua/user/240/orders (історія замовлень) - Історія замовлень | Book Box

  if ($r == 'user/login') {
    $vars['head_title'] = 'Вхід | Book Box';
  }

  if ($r == 'user/register') {
    $vars['head_title'] = 'Реєстрація | Book Box';
  }

  if ($r == 'user/password') {
    $vars['head_title'] = 'Відновлення паролю | Book Box';
  }

  if ($r == 'user/password') {
    $vars['head_title'] = 'Відновлення паролю | Book Box';
  }

  if ($r == 'user') {
    $vars['head_title'] = 'Профіль | Book Box';
  }
}

