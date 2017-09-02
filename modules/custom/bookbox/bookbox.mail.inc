<?php
function create_message_vars(&$mandrill_params, $message){
  $global_merge_vars = array();
  $global_merge_vars[] = array(
      'name' => 'subject',
      'content' => $message['subject'],
  );
  $global_merge_vars[] = array(
      'name' => 'from',
      'content' => $message['from'],
  );
  $global_merge_vars[] = array(
      'name' => 'domain',
      'content' => $GLOBALS['base_url'] . $GLOBALS['base_path'],
  );

  if(!empty($message['params']['merge_vars'])) {
    foreach($message['params']['merge_vars'] as $name => $content) {
      if(is_string($content)) {
        $global_merge_vars[] = array(
            'name' => $name,
            'content' => $content,
        );
      }
    }
  }

  $merge_vars = array();
  if(!empty($mandrill_params['message']['to'])) {
    foreach($mandrill_params['message']['to'] as $i => $rcpt) {
      $vars = array();
      $vars[] = array(
          'name' => 'to',
          'content' => $rcpt['email'],
      );
      $merge_vars[] = array(
          'rcpt' => $rcpt['email'],
          'vars' => $vars,
      );
    }
  }

  $mandrill_params['message']['global_merge_vars'] = $global_merge_vars;

  if(!empty($merge_vars)) {
    $mandrill_params['message']['merge_vars'] = $merge_vars;
  }

  $settings = array();
  $settings['message'] = $message;
  $settings['mandrill_params'] = $mandrill_params;
  return $settings;
}

function bookbox_mail($key, &$message, $params) {
  $message['headers']['Content-Type'] = 'text/html; charset=UTF-8';

  switch ($key) {
    case "password_change":
      if(!empty($params['merge_vars'])) {
        foreach($params['merge_vars'] as $name => $content) {
          if(is_string($content)) {
            $message['global_merge_vars'][] = array(
                'name' => $name,
                'content' => $content,
            );
          }
        }
      }
      $message['subject'] = isset($params['subject']) ? $params['subject'] : t('Ваш пароль змінено');
      if (isset($params['headers']) && is_array($params['headers'])) {
        $message['headers'] += $params['headers'];
      }
      break;
    case "book_box_order":
      if(!empty($params['merge_vars'])) {
        foreach($params['merge_vars'] as $name => $content) {
          if(is_string($content)) {
            $message['global_merge_vars'][] = array(
                'name' => $name,
                'content' => $content,
            );
          }
        }
      }
      $message['mandrill_template_id'] = 'order-confirmation-mandrill';
      $message['mandrill_template_content'] = array(
          array(
              'name' => 'books_info',
              'content' => $params['content']
          ),
          array(
              'name' => 'img1',
              'content' => $params['img1']
          ),
      );
      $message['subject'] = isset($params['subject']) ? $params['subject'] : t('Замовлення підтверджено');
      $mandrill_params['message']['from_name'] = 'Book Box';
      $mandrill_params['message']['headers']['From'] = 'info@bookbox.ua';
      $mandrill_params['message']['headers']['Reply-To'] = 'info@bookbox.ua';
      if (isset($params['headers']) && is_array($params['headers'])) {
        $message['headers'] += $params['headers'];
      }
      break;
  }
}

function bookbox_mandrill_mail_alter(&$mandrill_params, $message){
  if($message['key'] == "book_box_order") {
    $global_merge_vars = array();
    if(!empty($message['global_merge_vars'])) {

      foreach($message['global_merge_vars'] as $name => $content) {
        $global_merge_vars[] = array(
            'name' => $content['name'],
            'content' => $content['content'],
        );

      }
    }
    $mandrill_params['message']['subject'] = 'Замовлення підтверджено';
    $mandrill_params['args']['template_id'] = 'order-confirmation-mandrill';
    $mandrill_params['message']['from_name'] = 'Book Box';
    $mandrill_params['message']['from_email'] = 'info@bookbox.ua';
    $mandrill_params['message']['headers']['From'] = 'info@bookbox.ua';
    $mandrill_params['message']['headers']['Reply-To'] = 'info@bookbox.ua';
    $mandrill_params['message']['global_merge_vars'] = $global_merge_vars;
  }
  if($message['key'] == "password_change"){
    $global_merge_vars = array();
    if(!empty($message['global_merge_vars'])) {

      foreach($message['global_merge_vars'] as $name => $content) {
        $global_merge_vars[] = array(
            'name' => $content['name'],
            'content' => $content['content'],
        );

      }
    }
    $mandrill_params['message']['subject'] = 'Ваш пароль змінено';
    $mandrill_params['args']['template_id'] = 'password-change-mandrill';
    $mandrill_params['message']['from_name'] = 'Book Box';
    $mandrill_params['message']['from_email'] = 'info@bookbox.ua';
    $mandrill_params['message']['headers']['From'] = 'info@bookbox.ua';
    $mandrill_params['message']['headers']['Reply-To'] = 'info@bookbox.ua';
  }
}

// function for use MERGE_VARS in Mandrill Template
function user_mandrill_mail_alter(&$mandrill_params, $message) {
  if($message['key'] == "register") {
    $urls = array();
    if (preg_match_all("~(http|https|ftp|ftps)://(.*?)(\s|\n|[,.?!](\s|\n)|$)~",$mandrill_params['message']['text'],$out)) {
      $urls[] = $out;
    }
    $account = $message['params']['account'];
    $global_merge_vars = array();
    $global_merge_vars[] = array(
        'name' => 'from',
        'content' => $message['from'],
    );
    $global_merge_vars[] = array(
        'name' => 'FNAME',
        'content' => $account->field_name['und'][0]['value'],
    );
    $global_merge_vars[] = array(
        'name' => 'URL',
        'content' => $urls[0][0][0],
    );
    $mandrill_params['message']['subject'] = 'Підтвердження email';
    $mandrill_params['message']['from_email'] = 'info@bookbox.ua';
    $mandrill_params['message']['from_name'] = 'Book Box';
    $mandrill_params['message']['headers']['From'] = 'info@bookbox.ua';
    $mandrill_params['message']['headers']['Reply-To'] = 'info@bookbox.ua';
    $mandrill_params['args']['template_id'] = 'email-confirmation-mandrill';
    $mandrill_params['args']['template_content'][0]['name'] = 'content';
    $mandrill_params['args']['template_content'][0]['content'] = '';
    $mandrill_params['message']['html'] = '';
    $mandrill_params['message']['text'] = '';

    $mandrill_params['message']['global_merge_vars'] = $global_merge_vars;

    if (!empty($merge_vars)) {
      $mandrill_params['message']['merge_vars'] = $merge_vars;
    }
  }

  if ($message['key'] == 'status_activated') {
    $account = $message['params']['account'];
    $global_merge_vars = array();
    $global_merge_vars[] = array(
        'name' => 'from',
        'content' => $message['from'],
    );
    $global_merge_vars[] = array(
        'name' => 'FNAME',
        'content' => $account->field_name['und'][0]['value'],
    );

    $mandrill_params['message']['subject'] = 'Welcome to Book Box';
    $mandrill_params['args']['template_id'] = 'welcome-letter-mandrill';
    $mandrill_params['message']['from_name'] = 'Book Box';
    $mandrill_params['message']['from_email'] = 'welcome@bookbox.ua';
    $mandrill_params['message']['headers']['From'] = 'welcome@bookbox.ua';
    $mandrill_params['message']['headers']['Reply-To'] = 'info@bookbox.ua';
    $mandrill_params['args']['template_content'][0]['name'] = 'content';
    $mandrill_params['args']['template_content'][0]['content'] = '';
    $mandrill_params['message']['html'] = '';
    $mandrill_params['message']['text'] = '';

    $mandrill_params['message']['global_merge_vars'] = $global_merge_vars;

    if (!empty($merge_vars)) {
      $mandrill_params['message']['merge_vars'] = $merge_vars;
    }

  }

  if($message['key'] == 'password_reset'){
    $urls = array();
    if (preg_match_all("~(http|https|ftp|ftps)://(.*?)(\s|\n|[,.?!](\s|\n)|$)~",$mandrill_params['message']['text'],$out)) {
      $urls[] = $out;
    }
    $account = $message['params']['account'];
    $global_merge_vars = array();
    $global_merge_vars[] = array(
        'name' => 'from',
        'content' => $message['from'],
    );
    $global_merge_vars[] = array(
        'name' => 'FNAME',
        'content' => $account->field_name['und'][0]['value'],
    );
    $global_merge_vars[] = array(
        'name' => 'URL',
        'content' => $urls[0][0][0],
    );
    $mandrill_params['message']['subject'] = 'Відновлення паролю';
    $mandrill_params['args']['template_id'] = 'password-reset-mandrill';
    $mandrill_params['message']['from_name'] = 'Book Box';
    $mandrill_params['message']['from_email'] = 'info@bookbox.ua';
    $mandrill_params['message']['headers']['From'] = 'info@bookbox.ua';
    $mandrill_params['message']['headers']['Reply-To'] = 'info@bookbox.ua';
    $mandrill_params['args']['template_content'][0]['name'] = 'content';
    $mandrill_params['args']['template_content'][0]['content'] = '';
    $mandrill_params['message']['html'] = '';
    $mandrill_params['message']['text'] = '';

    $mandrill_params['message']['global_merge_vars'] = $global_merge_vars;

    if (!empty($merge_vars)) {
      $mandrill_params['message']['merge_vars'] = $merge_vars;
    }
  }

  if($message['key'] == "password_change"){
    $global_merge_vars = array();
    if(!empty($message['global_merge_vars'])) {

      foreach($message['global_merge_vars'] as $name => $content) {
        $global_merge_vars[] = array(
            'name' => $content['name'],
            'content' => $content['content'],
        );

      }
    }
    $mandrill_params['message']['subject'] = 'Ваш пароль змінено';
    $mandrill_params['message']['from_name'] = 'Book Box';
    $mandrill_params['message']['from_email'] = 'info@bookbox.ua';
    $mandrill_params['message']['headers']['From'] = 'info@bookbox.ua';
    $mandrill_params['message']['headers']['Reply-To'] = 'info@bookbox.ua';
    $mandrill_params['args']['template_id'] = 'password-change-mandrill';
    $mandrill_params['message']['global_merge_vars'] = $global_merge_vars;
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

