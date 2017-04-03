<?php

function bookbox_mail($key, &$message, $params) {
  $message['headers']['Content-Type'] = 'text/html; charset=UTF-8';

  switch ($key) {
    case "bookbox":
      $message['mandrill_template_content'] = array(
          array(
              'name' => 'name',
              'content' => $params['name']
          ),
      );
      $message['subject'] = isset($params['subject']) ? $params['subject'] : t('Зробіть замовлення | @month', array('@month' => ua_month_original()));
      if (isset($params['headers']) && is_array($params['headers'])) {
        $message['headers'] += $params['headers'];
      }
      break;
    case "bookbox_19":
      $message['mandrill_template_content'] = array(
          array(
              'name' => 'name',
              'content' => $params['name']
          ),
      );

      $message['subject'] = isset($params['subject']) ? $params['subject'] : t('Зробіть замовлення | @month', array('@month' => ua_month_original()));
      if (isset($params['headers']) && is_array($params['headers'])) {
        $message['headers'] += $params['headers'];
      }
      break;
    case "book_box_order":
//      dpm($key);
//      dpm($message);
//      dpm($params);

      $message['mandrill_template_content'] = array(
//          array(
//              'name' => 'name',
//              'content' => $params['name']
//          ),
          array(
              'name' => 'book_title',
              'content' => $params['content']
          ),
      );
//      $params['message']['merge_vars'][] = array(
//        'rcpt' => $params['to'],
//        'vars' => array(
//            array(
//              'name' => 'NAME',
//              'content' => $params['name']
//          ),
////          array(
////            'name' => 'FNAME',
////            'content' => $params['name'],
////          ),
////          array(
////            'name' => 'LNAME',
////            'content' => $params['lastname'],
////          ),
//        )
//      );

      $message['subject'] = isset($params['subject']) ? $params['subject'] : t('Зробіть замовлення | @month', array('@month' => ua_month_original()));
     // $message['body']['content'] = isset($params) ? 'Ira' : NULL;
      if (isset($params['headers']) && is_array($params['headers'])) {
        $message['headers'] += $params['headers'];
      }
      break;
  }
}


function bookbox_mail_send($module, $key, $to, $params = array()) {

  $language = isset($params['lang']) ? $params['lang'] : language_default();

  $send = TRUE;
  
  $mail = drupal_mail($module, $key, $to, $language, $params);

  if ($mail['result']) {
    return TRUE;
  }
  else {
    $error_msg = 'Failed to send the email in bookbox Module';
    watchdog('bookbox-email', $error_msg, array(), WATCHDOG_ALERT);
    return FALSE;
  }
}





