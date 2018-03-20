<?php
// Функціонал http://prntscr.com/i8dva9
function bookbox_admin_labels_form($form, &$form_state){
    $form['varMaxBooks'] = array(
        '#type' => 'textfield',
        '#title' => 'Максимальна кількість книжок (2 - 10)',
        '#required' => TRUE,
        '#default_value' => variable_get('varMaxBooks', 3),
    );

    $form['bookbox_allbooks_desc'] = array(
      '#type' => 'textarea',
      '#title' => 'Текст для "Всі книги"',
      '#required' => FALSE,
      '#default_value' => variable_get('bookbox_allbooks_desc', ''),
    );

    $form['bookbox_hits_desc'] = array(
      '#type' => 'textarea',
      '#title' => 'Текст для "Хіти"',
      '#required' => FALSE,
      '#default_value' => variable_get('bookbox_hits_desc', ''),
    );

    $form['bookbox_usercompanyhits_desc'] = array(
      '#type' => 'textarea',
      '#title' => 'Текст для "Хіти компанії"',
      '#required' => FALSE,
      '#default_value' => variable_get('bookbox_usercompanyhits_desc', ''),
    );

    $form['bookbox_new_desc'] = array(
      '#type' => 'textarea',
      '#title' => 'Текст для "Новинки"',
      '#required' => FALSE,
      '#default_value' => variable_get('bookbox_new_desc', ''),
    );

    $form['bookbox_order_tab'] = array(
      '#type' => 'textarea',
      '#title' => 'Текст для вкладки "Замовлено"',
      '#required' => FALSE,
      '#default_value' => variable_get('bookbox_order_tab', ''),
    );

    $form['bookbox_reading_tab'] = array(
      '#type' => 'textarea',
      '#title' => 'Текст для вкладки "Зараз читаю"',
      '#required' => FALSE,
      '#default_value' => variable_get('bookbox_reading_tab', ''),
    );

    $form['bookbox_archive_tab'] = array(
      '#type' => 'textarea',
      '#title' => 'Текст для вкладки "Прочитано"',
      '#required' => FALSE,
      '#default_value' => variable_get('bookbox_archive_tab', ''),
    );

    $form['bookbox_fav_tab'] = array(
      '#type' => 'textarea',
      '#title' => 'Текст для вкладки "Список бажань"',
      '#required' => FALSE,
      '#default_value' => variable_get('bookbox_fav_tab', ''),
    );

    return system_settings_form($form);
}

function bookbox_set_default_header_image_form(){
  $form['bookbox_allbooks_icon'] = array(
    '#type' => 'managed_file',
    '#title' => t('Іконка для "Всі книги"'),
    '#description' => t('Set the site-wide default header image'),
    '#upload_location' => 'public://files',
    '#default_value' => variable_get('bookbox_allbooks_icon', ''),
  );

  $form['bookbox_hits_icon'] = array(
    '#type' => 'managed_file',
    '#title' => t('Іконка для "Хіти"'),
    '#description' => t('Set the site-wide default header image'),
    '#upload_location' => 'public://files',
    '#default_value' => variable_get('bookbox_hits_icon', ''),
  );

  $form['bookbox_usercompanyhits_icon'] = array(
    '#type' => 'managed_file',
    '#title' => t('Іконка для "Хіти компанії"'),
    '#description' => t('Set the site-wide default header image'),
    '#upload_location' => 'public://files',
    '#default_value' => variable_get('bookbox_usercompanyhits_icon', ''),
  );

  $form['bookbox_new_icon'] = array(
    '#type' => 'managed_file',
    '#title' => t('Іконка для "Новинки"'),
    '#description' => t('Set the site-wide default header image'),
    '#upload_location' => 'public://files',
    '#default_value' => variable_get('bookbox_new_icon', ''),
  );

  $form['#submit'][] = 'bookbox_set_default_header_image_form_submit';

  return system_settings_form($form);
}

function bookbox_set_default_header_image_form_submit($form, &$form_state){
  $form['bookbox_allbooks_icon']['#file']->status = FILE_STATUS_PERMANENT;
  file_save($form['bookbox_allbooks_icon']['#file']);

  $form['bookbox_hits_icon']['#file']->status = FILE_STATUS_PERMANENT;
  file_save($form['bookbox_hits_icon']['#file']);

  $form['bookbox_usercompanyhits_icon']['#file']->status = FILE_STATUS_PERMANENT;
  file_save($form['bookbox_usercompanyhits_icon']['#file']);

  $form['bookbox_new_icon']['#file']->status = FILE_STATUS_PERMANENT;
  file_save($form['bookbox_new_icon']['#file']);
}