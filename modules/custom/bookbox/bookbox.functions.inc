<?php

//Получить номер текущего месяца
function m() {
  $month = date("m");
  return $month;
}

//Получить текущий день
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
function current_period() {
  $current_date = d();

  if ($current_date >=1 && $current_date <=20) {
    $period = 1;
  } else {
    $period = 2;
  }

  return $period;
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
  }
}

///////////////////////////////////////////////////////////////////////////
//Сколько Подтвержено в этом месяце
function bookbox_count_in_confirm_this_month($uid) {
  return count( bookbox_in_confirm_this_month($uid) );
}

//Сколько Подтверждено в прошлом месяце
function bookbox_count_in_confirm_prev_month($uid) {
  return count( bookbox_in_confirm_prev_month($uid) );
}

//Получить список подтвержденных в этом мес
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
/////////////////////////////////////////////////////////////

//Сколько Продлено в этом месяце
function bookbox_count_in_prolong_this_month($uid) {
  return count( bookbox_in_prolong_this_month($uid) );
}

//Сколько Продлено в прошлом месяце
function bookbox_count_in_prolong_prev_month($uid) {
  return count( bookbox_in_prolong_prev_month($uid) );
}

//Список продленного в этом мес
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


//Выборка продлено и заказы в прошлом месяце
function bookbox_get_in_reading_now($uid) {
  $in_confirm_prev_month = bookbox_in_confirm_prev_month($uid);
  $in_prolong_this_month = bookbox_in_prolong_this_month($uid);
  $in_reading_now = array_merge($in_confirm_prev_month,$in_prolong_this_month);

  return $in_reading_now;
}