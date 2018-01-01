<?php

//Получить укр.месяц в склонении
//Если пусто то возвращает текущий
//иначе нужно передать n-1, то есть ua_month(2) = 'березня'
function ua_month($m = null) {
  if(!$m) {
    $current_date = intval(m()) - 1;
  } else {
    $current_date = $m;
  }
  $ua_monthes = ['січня', 'лютого', 'березня', 'квітня', 'травня','червня', 'липня', 'серпня', 'вересня', 'жовтня', 'листопада', 'грудня'];
  return $ua_monthes[$current_date];
}

//Получить укр.месяц без склонения
//Если пусто то возвращает текущий
//иначе нужно передать n-1, то есть ua_month(2) = 'березень'
function ua_month_original($m = null) {
  if(!$m) {
    $current_date = intval(m()) - 1;
  } else {
    $current_date = $m;
  }
  $ua_monthes = ['січень', 'лютий', 'березень', 'квітень', 'травень','червень', 'липень', 'серпень', 'вересень', 'жовтень', 'листопад', 'грудень'];
  return $ua_monthes[$current_date];
}

//Функція визначає, в який період замовив юзер
//3. Замовити на найближчу п’ятницю можна до 18:00 четверга..  = 1
//3.1 при замовленні після 18:00 четверга, щоб писало дату доставки наступної п’ятниці. = 2
//3.2 але якщо у пт - то у наступну пт.
function period4order ($date) {
  $day = date('N', $date);
  $time = date('H:i', $date);

  if (($day > 5 || $day < 4) || ($day == 4 && $time < '18:00')) {
    return 1;
  } elseif ($day == 5 ) {
    return 3;
  } else {
    return 2;
  }
}

function next_friday($date) {
  $dt = new DateTime(date('d.m.Y H:i', $date));
  $dt->modify('next friday');

  if (period4order ($date) == 1 || period4order($date) == 3) {
    return $dt->format('d.m');
  } else {
    $dt->add(new DateInterval('P7D'));
    return $dt->format('d.m');
  }
}

function next_friday_full($date) {
  $dt = new DateTime(date('d.m.Y H:i', $date));
  $dt->modify('next friday');

  if (period4order ($date) == 1 || period4order($date) == 3) {
    return $dt->format('d.m.Y');
  } else {
    $dt->add(new DateInterval('P7D'));
    return $dt->format('d.m.Y');
  }
}

function next_friday_object($date) {
  $dt = new DateTime(date('d.m.Y H:i', $date));
  $dt->modify('next friday');

  if (period4order ($date) == 1 || period4order($date) == 3) {
    return $dt;
  } else {
    $dt->add(new DateInterval('P7D'));
    return $dt;
  }
}

//Функція формує строку дати доставки
function verbose_period4order($date) {
  if (period4order ($date) == 1 || period4order($date) == 3) {
    return "<div class='order-date'>Очікуйте доставку у п'ятницю: <span>" . next_friday($date) . "</span></div>";
  } else {
    return "<div class='order-date'>Очікуйте доставку у п'ятницю: <span>" . next_friday($date) . "</span></div>";
  }
}

//Функція формує строку дати доставки
function verbose_period4order_short($date) {
  return "<div class='order-date'>Доставка: <span>" . next_friday($date) . "</span></div>";
}

//Получить Дисплей книги по айдишнику ее продукта
function _bookbox_get_product_display_by_product_id($product_id, $bundle = 'product_display', $field_name = 'field_bookfields') {
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node');
  $query->fieldCondition($field_name, 'product_id', $product_id);
  $query->range(0, 1);
  $result = $query->execute();
  if ($result) {
    $product_display_nid = key($result['node']);
    return node_load($product_display_nid);
  } else {
    return null;
  }
}

//Выборка из базы - подтверждено юзером
function bookbox_get_in_confirm($uid) {
  $result = db_select('commerce_order', 'o')
      ->fields('o', array('order_id', 'status', 'changed'))
      ->condition('o.uid', $uid)
      ->condition('o.status', 'completed')
      ->orderBy('o.order_id', 'DESC')
      ->execute()->fetchAll();
  return $result;
}

function bookbox_count_in_confirm($uid) {
  return count(bookbox_get_in_confirm($uid) );
}

//Выборка читаю сейчас
function bookbox_get_in_reading_now($uid) {
  $result = db_select('commerce_order', 'o')
      ->fields('o', array('order_id', 'status', 'changed'))
      ->condition('o.uid', $uid)
      ->condition('o.status', 'delivered')
      ->orderBy('o.order_id', 'DESC')
      //->range(0,2)
      ->execute()->fetchAll();
  return $result;
}

function bookbox_count_in_reading_now($uid) {
  return count(bookbox_get_in_reading_now($uid));
}

function bookbox_get_in_orders($node) {
  $product_id = $node->field_bookfields['und'][0]['product_id'];

  $query = db_select('field_data_commerce_product', 'p');
  $query->innerJoin('field_data_commerce_line_items', 'l', 'p.entity_id = l.commerce_line_items_line_item_id');
  $query->fields('l', array('entity_id'));
  $query->condition('p.commerce_product_product_id', $product_id);
  $orders = $query->execute()->fetchAll();
  $in_orders = 0;

  foreach ($orders as $row) {
    $order_id = $row->entity_id;

    $result = db_select('commerce_order', 'o')
        ->fields('o', array('order_id', 'status', 'changed'))
        ->condition('o.order_id', $order_id)
        ->condition(
            db_or()
                ->condition('o.status', 'completed')
                ->condition('o.status', 'delivered')
        )
        ->execute()->fetchField();

    if($result) {
      $in_orders = $in_orders + 1;
    }
  }
  return $in_orders;
}

function _is_in_orders($product_id) {
  $query = db_select('field_data_commerce_product', 'p');
  $query->innerJoin('field_data_commerce_line_items', 'l', 'p.entity_id = l.commerce_line_items_line_item_id');
  $query->fields('l', array('entity_id'));
  $query->condition('p.commerce_product_product_id', $product_id);
  $orders = $query->execute()->fetchAll();

  return $orders;
}

function is_in_order($product_id, $uid) {
  $orders = _is_in_orders($product_id);

  $in_orders = 0;

  foreach ($orders as $row) {
    $order_id = $row->entity_id;

    $result = db_select('commerce_order', 'o')
        ->fields('o', array('order_id', 'status', 'changed'))
        ->condition('o.order_id', $order_id)
        ->condition('o.uid', $uid)
        ->condition('o.status', 'completed')
        ->execute()->fetchField();

    if($result) {
      $in_orders = $in_orders + 1;
    }
  }
  return $in_orders;
}

function is_in_redingnow($product_id, $uid) {
  $orders = _is_in_orders($product_id);

  $in_orders = 0;

  foreach ($orders as $row) {
    $order_id = $row->entity_id;

    $result = db_select('commerce_order', 'o')
        ->fields('o', array('order_id', 'status', 'changed'))
        ->condition('o.order_id', $order_id)
        ->condition('o.uid', $uid)
        ->condition('o.status', 'delivered')
        ->execute()->fetchField();

    if($result) {
      $in_orders = $in_orders + 1;
    }
  }
  return $in_orders;
}

function is_in_archive($product_id, $uid) {
  $orders = _is_in_orders($product_id);

  $in_orders = 0;

  foreach ($orders as $row) {
    $order_id = $row->entity_id;

    $result = db_select('commerce_order', 'o')
        ->fields('o', array('order_id', 'status', 'changed'))
        ->condition('o.order_id', $order_id)
        ->condition('o.uid', $uid)
        ->condition('o.status', 'archive')
        ->execute()->fetchField();

    if($result) {
      $in_orders = $in_orders + 1;
    }
  }
  return $in_orders;
}

function taxonomy_get_nested_tree($vid_or_terms = array(), $max_depth = NULL, $parent = 0, $parents_index = array(), $depth = 0) {
  if (!is_array($vid_or_terms)) {
    $vid_or_terms = taxonomy_get_tree($vid_or_terms, 0, NULL, TRUE);
  }

  foreach ($vid_or_terms as $term) {
    foreach ($term->parents as $term_parent) {
      if ($term_parent == $parent) {
        $return[$term->tid] = $term;
      } else {
        $parents_index[$term_parent][$term->tid] = $term;
      }
    }
  }

  foreach ($return as &$term) {
    if (isset($parents_index[$term->tid]) && (is_null($max_depth) || $depth < $max_depth)) {
      $term->children = taxonomy_get_nested_tree($parents_index[$term->tid], $max_depth, $term->tid, $parents_index, $depth + 1);
    }
  }

  return

      $return;
}

function taxonomy_nested_tree_render($tree, $recurring = FALSE) {
  $items = array();
  if (count($tree)) {
    foreach ($tree as $term) {
      $item = array('name' => $term->name, 'tid' => $term->tid);
      if (isset($term->children)) {
        $item["children"] = taxonomy_nested_tree_render($term->children, TRUE);
      }
      $items[] = $item;
    }
  }

  if ($recurring) {
    return $items;
  }

  return $items;
}

function _bookbox_user_orders_history() {
  global $user;
  $content = '';

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

  return array($content, $c);
}
