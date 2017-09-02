<?php
//Получить номер текущего месяца
//depricated
function m() {
  $month = date("m");
  return $month;
}

//Получить текущий день
//depricated
function d() {
  $day = date("d");
  return $day;
}

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

//Получить Текущий период
//1-20 включительно = 1
//21 - 31 = 2

//depricated
function current_period() {
  //depricated
  $current_date = d();
  if ($current_date >=1 && $current_date <=20) {
    $period = 1;
  } else {
    $period = 2;
  }
  return $period;
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
    return "Очікуйте доставку у найближчу п'ятницю: <span>" . next_friday($date) . "</span>";
  } else {
    return "Очікуйте доставку у наступну п'ятницю: <span>" . next_friday($date) . "</span>";
  }
}

//Функція формує строку дати доставки
function verbose_period4order_short($date) {
  return "Доставка: <span>" . next_friday($date) . "</span>";
}

//Получить товары в корзине
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

//Получить Дисплей книги по айдишнику ее продукта
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
  } else {
    return null;
  }
}

//Выборка из базы - подтверждено юзером
function bookbox_get_in_confirm($uid) {
  //global $user;
  $result = db_select('commerce_order', 'o')
      ->fields('o', array('order_id', 'status', 'changed'))
      ->condition('o.uid', $uid)
      ->condition('o.status', 'completed')
      ->orderBy('o.order_id', 'DESC')
      //->range(0,2)
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

//Сколько Подтверждено в прошлом месяце
//depricated
function bookbox_count_in_confirm_prev_month($uid) {
  return count( bookbox_in_confirm_prev_month($uid) );
}

//Получить список подтвержденных в этом мес
//depricated
function bookbox_in_confirm_this_month($uid) {
  $in_confirm_this_month = [];
  foreach(bookbox_get_in_confirm($uid) as $item) {
    if (date("m", $item->changed) == m()) {
      //$in_confirm_this_month = $in_confirm_this_month + 1;
      array_push($in_confirm_this_month, $item);
    }
  }
  return $in_confirm_this_month;
}

//Получить список подтвержденных в прошлом мес
//depricated
function bookbox_in_confirm_prev_month($uid) {
  $in_confirm_prev_month = [];
  foreach(bookbox_get_in_confirm($uid) as $item) {
    $year = date("Y");
    $prev_month = intval(date("m")) - 1;
    if($prev_month < 1) {
      $prev_month = 12;
      $year = intval(date("Y")) - 1;
      $prev_date = $prev_month . "-" . $year;
    } else {
      if ($prev_month < 10) {
        $prev_date =  "0" . $prev_month  . "-" . $year;
      } else {
        $prev_date =  $prev_month  . "-" . $year;
      }
    }
    if (date("m-Y", $item->changed) == $prev_date) {
      array_push($in_confirm_prev_month, $item);
    }
  }
  return $in_confirm_prev_month;
}

/////////////////////////////////////////////////////////////
//Сколько Продлено в этом месяце
//depricated
function bookbox_count_in_prolong_this_month($uid) {
  return count( bookbox_in_prolong_this_month($uid) );
}

//Сколько Продлено в прошлом месяце
//depricated
function bookbox_count_in_prolong_prev_month($uid) {
  return count( bookbox_in_prolong_prev_month($uid) );
}

//Список продленного в этом мес
//depricated
function bookbox_in_prolong_this_month($uid) {
  $in_prolong_this_month = [];
  foreach(bookbox_get_in_prolong($uid) as $item) {
    if (date("m-Y", $item->changed) == date("m-Y")) {
      array_push($in_prolong_this_month, $item);
    }
  }
  return $in_prolong_this_month;
}

//Список Продлено в прошлом месяце
//depricated
function bookbox_in_prolong_prev_month($uid) {
  $in_prolong_prev_month = [];
  foreach(bookbox_get_in_prolong($uid) as $item) {
    $year = date("Y");
    $prev_month = intval(date("m")) - 1;
    if($prev_month < 1) {
      $prev_month = 12;
      $year = intval(date("Y")) - 1;
      $prev_date = $prev_month . "-" . $year;
    } else {
      if ($prev_month < 10) {
        $prev_date =  "0" . $prev_month  . "-" . $year;
      } else {
        $prev_date =  $prev_month  . "-" . $year;
      }
    }
    if (date("m-Y", $item->changed) == $prev_date) {
      array_push($in_prolong_prev_month, $item);
    }
  }

  return $in_prolong_prev_month;
}

//Выборка из базы - продлено юзером
//depricated
function bookbox_get_in_prolong($uid) {
  $result = db_select('commerce_order', 'o')
      ->fields('o', array('order_id', 'status', 'changed'))
      ->condition('o.uid', $uid)
      ->condition('o.status', 'prolong')
      ->orderBy('o.order_id', 'DESC')
      //->range(0,2)
      ->execute()->fetchAll();
  return $result;
}

//Сколько заказов этой книги Вообще
//depricated
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
                ->condition('o.status', 'prolong')
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

//Сколько заказов этой книги в этом месяце
//depricated
function bookbox_get_in_orders_this_month($node) {
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
        ->fields('o', array('order_id', 'status', 'created'))
        ->condition('o.order_id', $order_id)
        ->condition('o.status', 'completed')
        ->execute()->fetchAll();

    foreach ($result as $item) {
      if (date("m-Y", $item->created) == date("m-Y")) {
        $in_orders = $in_orders + 1;
        //dsm($result);
      }
    }
  }
  return $in_orders;
}

