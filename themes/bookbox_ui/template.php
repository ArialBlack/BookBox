<?php
/**
 * @file
 * The primary PHP file for this theme.
 */

function bookbox_ui_theme() {
  $items = array();

  $items['user_login'] = array(
      'render element' => 'form',
      'path' => drupal_get_path('theme', 'bookbox_ui') . '/templates',
      'template' => 'user-login-template',
      'preprocess functions' => array(
          'bookbox_ui_preprocess_user_login'
      ),
  );

  return $items;
}

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

function bookbox_ui_preprocess_views_view(&$vars) {

  if (in_array($vars['view']->name, array('taxonomy_term'))) {
    $breadcrumb = array();
    $breadcrumb[] = l('Головна', '<front>');
    $breadcrumb[] = l('Всі книги', '/books');

    $tid = $vars['view']->args[0];

    if(isset($tid)) {
      $parent = taxonomy_get_parents_all($tid);
      $breadcrumb[] = l($parent[0]->name, 'taxonomy/term/' . $parent[0]->tid);
    }

    drupal_set_breadcrumb($breadcrumb);
  }
}

function bookbox_ui_preprocess_page(&$vars) {

  $url  = request_path();
  $status = drupal_get_http_header("status");

  if(user_is_anonymous() && $status == '404 Not Found') {
    header('Location: /user/login');
  }

  if(user_is_anonymous() && $status == '403 Forbidden') {
    header('Location: /user/login');
  }

  if(user_is_anonymous() && arg(0) != 'user'){ //check user here
    header('Location: /user/login');
  }

  if ($views_page = views_get_page_view() ) {
    if ($views_page->name === "books") {
      $vars['theme_hook_suggestions'][] = 'page__views__books';
    }

    if ($views_page->name === "user_company_hits") {
      $vars['theme_hook_suggestions'][] = 'page__views__usercompanyhits';
    }
  }

  // Do we have a node?
  if (isset($vars['node'])) {
    ///////////////
    $breadcrumb = array();
    $breadcrumb[] = l('Головна', '<front>');
    $breadcrumb[] = l('Всі книги', '/books');
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

  if (arg(0) == 'taxonomy' && arg(1) == 'term' ) {
    $term = taxonomy_term_load(arg(2));
    $parents =  taxonomy_get_parents(arg(2));

    $breadcrumb = array();
    $breadcrumb[] = l('Головна', '<front>');
    $breadcrumb[] = l('Всі книги', '/books');

    if(count($parents) != 0) {
      $newArray = array_keys($parents);
      $key = $newArray[0];
      $parent_name = $parents[$key]->name;
      $breadcrumb[] = l($parent_name, '/taxonomy/term/' . $key);
    }

    $breadcrumb[] = l($term->name, '/taxonomy/term/' . $term->tid);
    drupal_set_breadcrumb($breadcrumb);

    $vocabulary = taxonomy_vocabulary_load($term->vid);
    $vars['theme_hook_suggestions'][] = 'page__taxonomy_vocabulary__' . $vocabulary->machine_name;
  }
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

  if (arg(0) == 'books') {
    $vars['head_title'] = 'Всі книги | Book Box';
  }

  if ($r == 'books/hits') {
    $vars['head_title'] = 'Хіти | Book Box';
  }

  if ($r == 'books/new') {
    $vars['head_title'] = 'Нові надходження | Book Box';
  }

  if ($r == 'books/company-hits') {
    $vars['head_title'] = drupal_get_title() . ' | Book Box';
  }

  if (user_is_logged_in()) {
    if($r == 'user/' . $vars['user']->uid . '/edit') {
      $vars['head_title'] = 'Налаштування | Book Box';
    }
  }
}

function bookbox_ui_preprocess_field(&$variables) {
  $field_name = $variables['element']['#field_name'];

  if($field_name == 'field_book_size') {
    $instance = field_info_instance('node', $field_name, 'book');
    $variables['element']['#help'] = $instance['description'];
  }
}


