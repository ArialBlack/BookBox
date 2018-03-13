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

    $blocks['OrdersHistory'] = array(
      'info' => t('Orders history'),
    );

    // Старі блоки видалить після релізу
    /*$blocks['CatBiz'] = array(
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
    );*/

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

    $blocks['RelevantBooks'] = array(
      'info' => t('Relevant books'),
    );

    $blocks['SidebarFitlerBlockCompany'] = array(
      'info' => t('Sidebar Fitler Block Company'),
    );

    $blocks['SidebarFitlerBlockCollections'] = array(
      'info' => t('Sidebar Fitler Block Collections'),
    );

    return $blocks;
}

function bookbox_block_view($delta = '') {
    //Логіка блоків
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

        //Видалить після релізу
        /*case 'CatBiz':
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
        */

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

        case 'RelevantBooks':
          $variables = array();
          $block = array('content' => theme('relevantbooks', $variables));
          break;

        case 'debug':
            $block['subject'] = '';
            $block['content'] = bookbox_debug_block();
            break;

        case 'OrdersHistory':
            $block['subject'] = '';
            $block['content'] = bookbox_user_orders_history_block();
          break;

        case 'SidebarFitlerBlockCompany':
          $block['subject'] = '';
          $block['content'] = bookbox_sidebarfc_block();
          break;

        case 'SidebarFitlerBlockCollections':
          $block['subject'] = '';
          //$block['content'] = bookbox_sidebarfc_block();
          break;
    }
    return $block;
}

function bookbox_preprocess_relevantbooks(&$variables) {
  /*
   * Наступна пріоритетність:
2. Ще книги цього автора. Максимум дві. Якщо їх більше, то дві обираємо за популярністю.
3. Беремо за основу ту категорію, яка відображається в хлібних крихтах. І з неї показуємо хіти.
4. Якщо хітів не вистачає, аби добити 12 штук, тоді добиваємо популярними нехітами з категорії, яка в хлібних крихтах.
   */
  $node = menu_get_object();
  $books_list = [];
  $books_count = 0;

  if (isset($node->nid)) {
    //книги цього автора. Максимум дві. Якщо їх більше, то дві обираємо за популярністю.
    if(isset($node->field_book_author['und'])) {
      //автора може буть > 2
      foreach ($node->field_book_author['und'] as $atid) {
        $vtid = $atid['tid'];
        $view_results = views_get_view_result('popuar_orders', 'default', $vtid);

        if(count($view_results) > 0) {
          foreach ($view_results as $row) {
            $product_id = $row->commerce_line_item_field_data_commerce_line_items__field_dat;
            $book = _bookbox_get_product_display_by_product_id($product_id);

            //Нам не потрібна ця ж книга
            if($book->nid != $node->nid) {
              $node_view = node_view($book, 'teaser');
              $rendered_teaser = render($node_view);
              $books_count++;
              $books_list[] = $rendered_teaser;
            }
          }
        }
      }

      //категорія у крихтах
      $ttid = null;
      $urlparams = drupal_get_query_parameters();

      if(isset($urlparams['term'])) {
        $ttid = $urlparams['term'];
      }
      else {
        $ttid = $node->field_book_category['und'][1]['tid'];
      }

      if(isset($ttid)) {
        $view_results = views_get_view_result('category_hits', 'default', $ttid);

        if(count($view_results) > 0) {
          foreach ($view_results as $row) {
            //Нам не потрібна ця ж книга
            if ($row->nid != $node->nid) {
              $book = node_load($row->nid);
              $node_view = node_view($book, 'teaser');
              $rendered_teaser = render($node_view);
              $books_count++;
              $books_list[] = $rendered_teaser;
            }
          }
        }
      }
    }
  }

  if ($books_count > 0) {
    $content = '<ul>';
    $c = 0;
    foreach ($books_list as $item) {
      $content = $content . '<li>' . $item . '</li>';
      $c++;
      if ($c == 12) {
        break;
      }
    }
    $content = $content . '</ul>';
    $variables['bookslist'] = $content;

  } else {
    $variables['bookslist'] = null;
  }
}

//Формує блок http://prntscr.com/i8dymf
function bookbox_sidebarfc_block() {
  $content = '<ul><li><a href="/books">Всі книги</a></li>';
  $content = $content . '<li><a href="/books/hits">Хіти</a></li>';

  global $user;
  $uid = $user->uid;
  $account = user_load($uid);
  $company_nid = $account->field_company['und'][0]['target_id'];
  $company = node_load($company_nid);
  $date_diff = (time() - $company->created)/60/60/24;

  //Якщо компнія молода, то не виводимо лінку.
  if($date_diff > 60) {
    $content = $content . '<li><a href="/books/company-hits">Популярне в ' . $company->title . '</a></li>';
  }

  $content = $content . '<li><a href="/books/new">Нові надходження</a></li></ul>';

  return $content;
}

//Логіка формування блоку http://prntscr.com/i8dts9
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

//Змінить заголовок на сторінці блоку http://prntscr.com/i8dts9
function bookbox_views_pre_render(&$view) {
  if ($view->name == 'user_company_hits' && $view->current_display == 'page_1') {
    global $user;
    $uid = $user->uid;
    $account = user_load($uid);
    $company_nid = $account->field_company['und'][0]['target_id'];
    $company = node_load($company_nid);
    $view->build_info['title'] = "Популярне в " . $company->title;
  }
}

//Логіка формування блоку http://prntscr.com/i8dtxv
function bookbox_preprocess_newbyadmin(&$variables) {

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

  $variables['bookslist'] = $content;
}

//Логіка формування блоку http://prntscr.com/i8duku
function bookbox_preprocess_manualhits(&$variables) {

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

//Формує блок http://prntscr.com/i8e0x0
function bookbox_custom_usermenu_block() {
    $content = "";
    global $user;
    $uid = $user->uid;
    $account = user_load($uid);

    $u_orders_c = bookbox_count_in_confirm($user->uid);
    $u_reading_c = bookbox_count_in_reading_now($user->uid);

    list($x,$y) = _bookbox_user_orders_history();
    $u_history_c = $y;

    $favs_view = views_get_view('user_wishlist');
    $favs_view->set_display('block_1');
    $favs_view->set_arguments(array($user->uid));
    $favs_view->pre_execute();
    $favs_view->execute();
    $u_favs_c = $favs_view->total_rows;

    $nanme = $account->field_name['und'][0]['safe_value'];
    $snanme = $account->field_sirname['und'][0]['safe_value'];

    $content = $content . '<ul class="menu nav navbar-nav secondary dup-tabs">';
    $content = $content . '<li class="first last expanded dropdown">';
    $content = $content . '<a href="/user" title="" data-target="#" class="dropdown-toggle" data-toggle="dropdown" aria-expanded="false"> <span class="user-name"><span>' . $nanme . '</span> <span>' . $snanme . '</span></span>';
    $content = $content . '<span class="caret"></span></a>';

    $content = $content . '<ul class="dropdown-menu"><li class="first leaf"><a href="/user" title="">Профіль</a></li>';

    $content = $content . '<li class="leaf"><a href="/user#order" title="">Замовлено ';

    if ($u_orders_c > 0) {
      $content = $content . '<span class="badge">' . $u_orders_c . '</span>';
    } else {
      $content = $content . '<span class="badge badge-empty">0</span>';
    }

    $content = $content . '</a></li>';
    //
    $content = $content . '<li class="leaf"><a href="/user#read" title="">Зараз читаю ';

    if ($u_history_c > 0) {
      $content = $content . '<span class="badge">' . $u_history_c . '</span>';
    } else {
      $content = $content . '<span class="badge badge-empty">0</span>';
    }
    $content = $content . '</a></li>';
    //
    $content = $content . '<li class="leaf"><a href="/user#favs" title="">Список бажань ';

    if ($u_favs_c > 0) {
      $content = $content . '<span class="badge">' . $u_favs_c . '</span>';
    } else {
      $content = $content . '<span class="badge badge-empty">0</span>';
    }
    $content = $content . '</a></li>';

    $content = $content . '<li class="last leaf"><a href="/user/logout">Вихід</a></li>';


    $content = $content . '</ul></li></ul>';

    return $content;
}

function bookbox_block_view_alter(&$data, $block) {
    if ($block->delta == 'client-block-892' && current_path() == 'faq') {
        $block->title = 'Маєте додаткове питання?';
    }
}

/*function bookbox_cat_biz_block() {
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
*/

/*function _bookbox_catblock($parent_tid) {
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
}*/

function bookbox_user_orders_history_block() {
  $content = '<h2>Історія замовлень</h2><div class="row">';

  list($x,$y) = _bookbox_user_orders_history();

  $content = $content . $x . '</div>';
  return $content;
}
