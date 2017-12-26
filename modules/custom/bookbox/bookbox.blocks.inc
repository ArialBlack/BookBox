<?php

function bookbox_block_info() {
    $blocks = array();

    $blocks['debug']= array(
        'info' => t('debuginfo'),
    );

    $blocks['MonthOrder'] = array(
        'info' => t('Current orders'),
    );

    $blocks['ReadingNow'] = array(
        'info' => t('Reading now'),
    );

    $blocks['CatBiz'] = array(
        'info' => t('cat biz'),
    );

    $blocks['CatKrug'] = array(
        'info' => t('cat krug'),
    );

    $blocks['CatSamo'] = array(
        'info' => t('cat samo'),
    );

    $blocks['CatZoj'] = array(
        'info' => t('cat zoj'),
    );

    $blocks['CatNauch'] = array(
        'info' => t('cat nauch'),
    );

    $blocks['CatHud'] = array(
        'info' => t('cat hud'),
    );

    $blocks['BBUserMenu'] = array(
        'info' => t('custom user menu'),
    );

    $blocks['ManualHits'] = array(
      'info' => t('Manual hits'),
    );

    $blocks['CompanyHits'] = array(
      'info' => t('Company hits'),
    );

    $blocks['NewByAdmin'] = array(
      'info' => t('New by Admin'),
    );

    return $blocks;
}

function bookbox_block_view($delta = '') {
    global $user;
    $uid = $user->uid;
    $max_books = variable_get('varMaxBooks');

    $block = array();

    $show_order = true;

    $show_reading_now = true;
    if (bookbox_count_in_reading_now($uid) < 1) {
        $show_reading_now = false;
    }

    switch ($delta) {
        case 'MonthOrder':
            if ($show_order) {
                $block['subject'] = '';
                $form = drupal_get_form('bookbox_current_order_block');
                $block['content'] = drupal_render($form);
            } else {
                $block['subject'] = null;
                $block['content'] = null;
            }
            break;

        case 'ReadingNow':
            if ($show_reading_now) {
                $block['subject'] = '';
                $form = drupal_get_form('bookbox_reading_now_block');
                $block['content'] = drupal_render($form);
            } else {
                $block['subject'] = null;
                $block['content'] = null;
            }
            break;

        case 'CatBiz':
            $block['subject'] = '';
            $block['content'] = bookbox_cat_biz_block();
            break;

        case 'CatKrug':
            $block['subject'] = '';
            $block['content'] = bookbox_cat_krug_block();
            break;

        case 'CatSamo':
            $block['subject'] = '';
            $block['content'] = bookbox_cat_samo_block();
            break;

        case 'CatZoj':
            $block['subject'] = '';
            $block['content'] = bookbox_cat_zoj_block();
            break;

        case 'CatNauch':
            $block['subject'] = '';
            $block['content'] = bookbox_cat_nauch_block();
            break;

        case 'CatHud':
            $block['subject'] = '';
            $block['content'] = bookbox_cat_hud_block();
            break;

        case 'BBUserMenu':
            $block['subject'] = '';
            $block['content'] = bookbox_custom_usermenu_block();
            break;

        case 'ManualHits':
          $variables = array();
          $block = array('content' => theme('manualhits', $variables));
          break;

        case 'NewByAdmin':
          $variables = array();
          $block = array('content' => theme('newbyadmin', $variables));
          break;

        case 'CompanyHits':
          $variables = array();
          $block = array('content' => theme('companyhits', $variables));
          break;

        case 'debug':
            $block['subject'] = '';
            $block['content'] = bookbox_debug_block();
            break;
    }
    return $block;
}

function bookbox_preprocess_companyhits(&$variables) {
  global $user;
  $uid = $user->uid;
  $account = user_load($uid);
  $company_nid = $account->field_company['und'][0]['target_id'];
  $company = node_load($company_nid);

  $date_diff = (time() - $company->created)/60/60/24;

  if($date_diff > 60) {
    $view_results = views_get_view_result('company_orders', 'default', $company_nid);
    $content = null;

    if(count($view_results) > 0) {
      $content = '<ul>';

      foreach ($view_results as $row) {
        $product_id = $row->commerce_line_item_field_data_commerce_line_items__field_dat;
        $book = _bookbox_get_product_display_by_product_id($product_id);

        $node_view = node_view($book, 'teaser');
        $rendered_teaser = render($node_view);

        $content = $content . '<li>' . $rendered_teaser . '</li>';
      }
      $content = $content . '</ul>';
    }
    $variables['bookslist'] = $content;
    $variables['name'] = $company->title;
  } else {
    $variables['bookslist'] = null;
  }
}

function bookbox_preprocess_newbyadmin(&$variables) {
  if ($cache = cache_get('bookbox_newbyadmin_data')) {
    $content = $cache->data;
  } else {
    $content = null;

    $nid = db_select('node', 'n')
      ->fields('n', array('nid'))
      ->condition('n.title', 'Нові надходження')
      ->execute()->fetchField();

    if(isset($nid)) {
      $node = node_load($nid);
      $content = $content . '<ul>';

      foreach ($node->field_book['und'] as $field) {
        $book_nid = $field['target_id'];

        $book = node_load($book_nid);

        $node_view = node_view($book, 'teaser');
        $rendered_teaser = render($node_view);

        $content = $content . '<li>' . $rendered_teaser . '</li>';
      }
      $content = $content . '</ul>';
    }

    cache_set('bookbox_newbyadmin_data', $content, 'cache');
  }

  $variables['bookslist'] = $content;
}

function bookbox_preprocess_manualhits(&$variables) {
  if ($cache = cache_get('bookbox_manualhits_data')) {
    $content = $cache->data;
  } else {
    $content = null;

    $nid = db_select('node', 'n')
      ->fields('n', array('nid'))
      ->condition('n.title', 'Хіти на головну')
      ->execute()->fetchField();

    if(isset($nid)) {
      $node = node_load($nid);
      $content = $content . '<ul>';

      foreach ($node->field_book['und'] as $field) {
        $book_nid = $field['target_id'];

        $book = node_load($book_nid);

        $node_view = node_view($book, 'teaser');
        $rendered_teaser = render($node_view);

        $content = $content . '<li>' . $rendered_teaser . '</li>';
      }
      $content = $content . '</ul>';
    }

    cache_set('bookbox_manualhits_data', $content, 'cache');
  }

  $variables['bookslist'] = $content;
}

function bookbox_debug_block() {
    global $user;
    $uid = $user->uid;

    $output = 'тестовое время: ' . date('d.m.Y H:i', time()) . '<br>';
    $output = $output  . 'Максимальна кіклькість книжок для замовлень взагалі: ' . variable_get('varMaxBooks')  . '<br>';
    $output = $output  . 'Я замовив вже: ' . bookbox_count_in_confirm($uid) . '<br>';
    $output = $output  . 'Я читаю вже: ' . bookbox_count_in_reading_now($uid) . '<br>';

    return $output;
}

function bookbox_custom_usermenu_block() {
    $content = "";
    global $user;
    $uid = $user->uid;
    $account = user_load($uid);

    $show_cart = true;
    if(bookbox_count_in_confirm($uid) > 0 ) {
        $show_cart = false;
    }

    $show_order = true;
    if( bookbox_count_in_confirm($uid) < 1 ) {
        $show_order = false;
    }

    $show_reading_now = true;
    if( count(bookbox_get_in_reading_now($uid)) < 1) {
        $show_reading_now = false;
    }

    $nanme = $account->field_name['und'][0]['safe_value'];
    $snanme = $account->field_sirname['und'][0]['safe_value'];

    $content = $content . '<ul class="menu nav navbar-nav secondary">';
    $content = $content . '<li class="first last expanded dropdown">';
    $content = $content . '<a href="/user" title="" data-target="#" class="dropdown-toggle" data-toggle="dropdown" aria-expanded="false"> <span class="user-name"><span>' . $nanme . '</span> <span>' . $snanme . '</span></span> <span class="caret"></span></a>';
    $content = $content . '<ul class="dropdown-menu"><li class="first leaf"><a href="/user" title="">Профіль</a></li>';
    $content = $content . '<li class="leaf"><a href="/user/' . $uid . '/favorites" title="">Список бажань</a></li>';
    $content = $content . '<li class="leaf"><a href="/user/' . $uid . '/orders" title="">Історія замовлень</a></li>';
    $content = $content . '<li class="last leaf"><a href="/user/logout">Вихід</a></li>';

    if($show_cart || $show_order || $show_reading_now ) {
        $content = $content . '<li role="separator" class="divider visible-sm visible-xs"></li>';
    }

    if($show_cart) {
        $content = $content . '<li class="leaf visible-sm visible-xs"><a href="/user/usercart" title="">Замовлення місяця</a></li>';
    }

    if($show_order) {
        $content = $content . '<li class="leaf visible-sm visible-xs"><a href="/user/userorder" title="">Замовлення підтверджено</a></li>';
    }

    if($show_reading_now) {
        $content = $content . '<li class="leaf visible-sm visible-xs"><a href="/user/userreadingnow" title="">Зараз читаю</a></li>';
    }

    $content = $content . '</ul></li></ul>';

    return $content;
}

function bookbox_block_view_alter(&$data, $block) {
    if ($block->delta == 'client-block-892' && current_path() == 'faq') {
        $block->title = 'Маєте додаткове питання?';
    }
}

function bookbox_cat_biz_block() {
    $content = _bookbox_catblock(7);
    return $content;
}

function bookbox_cat_krug_block() {
    $content = _bookbox_catblock(18);
    return $content;
}

function bookbox_cat_samo_block() {
    $content = _bookbox_catblock(13);
    return $content;
}

function bookbox_cat_zoj_block() {
    $content = _bookbox_catblock(276);
    return $content;
}

function bookbox_cat_nauch_block() {
    $content = _bookbox_catblock(286);
    return $content;
}

function bookbox_cat_hud_block() {
    $content = _bookbox_catblock(317);
    return $content;
}

function _bookbox_catblock($parent_tid) {
    $content = '';
    $childrens = taxonomy_get_children($parent_tid);

    foreach ($childrens as $subcategory) {
        $content = $content . '<div class="books-row"><h2><a href="/taxonomy/term/' . $subcategory->tid . '">' . $subcategory->name . '</a></h2>';
        $content = $content . '<a class="know-more" href="/taxonomy/term/' . $subcategory->tid . '">дивитись більше</a>';
        $nodes = taxonomy_select_nodes($subcategory->tid, $pager = FALSE, $limit = 100, $order = array('t.sticky' => 'DESC', 't.created' => 'DESC'));
        $content = $content . '<div class="books-row">';
        $good_nodes = 0;

        foreach ($nodes as $nid) {
            $node = node_load($nid);

            if($node) {
                $good_nodes = $good_nodes + 1;
                $node_view = node_view($node, 'teaser');
                $rendered_teaser = render($node_view);
                $content = $content . $rendered_teaser;
            }

            if ($good_nodes == 3) {
                break;
            }
        }

        $content = $content . '</div></div>';
    }
    return $content;
}

function bookbox_user_orders_history() {
    global $user;
    $content = '<h1>Історія замовлень</h1><div class="row">';
    drupal_set_title('Архів прочитаного | Book Box');

    $result = db_select('commerce_order', 'o')
        ->fields('o', array('order_id', 'created'))
        ->condition('o.uid', $user->uid)
        ->condition('o.status', 'archive')
        ->execute()->fetchAll();

    $user_product_displays = array();
    $c = 0;

    foreach ($result as $res) {
        $order = commerce_order_load($res->order_id);
        $line_item_id = $order->commerce_line_items['und'][0]['line_item_id'];
        $line_item = commerce_line_item_load($line_item_id);
        $product_id =  $line_item->commerce_product['und'][0]['product_id'];
        $product_display = _bookbox_get_product_display_by_product_id($product_id);

        $user_product_displays[$c] = array();
        $user_product_displays[$c]['title'] = $product_display->title;
        $user_product_displays[$c]['nid'] = $product_display->nid;
        $c++;
    }

    foreach ($user_product_displays as $key => $row) {
        $title[$key]  = $row['title'];
        $nid[$key] = $row['nid'];
    }

    array_multisort($user_product_displays, SORT_ASC, $title);

    foreach ($user_product_displays as $product_display) {
        if ($product_display['nid']) {
            $node = node_load($product_display['nid']);
            $node_view = node_view($node, 'teaser');
            $rendered_teaser = render($node_view);
            $content = $content . $rendered_teaser;
        }
    }

    $content = $content . '</div>';
    return $content;
}
