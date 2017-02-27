<?php

function bookbox_admin_labels_form($form, &$form_state){
    $form['readingNow_title'] = array(
        '#type' => 'textfield',
        '#title' => t('Текст для зараз читаю'),
        '#required' => TRUE,
        '#default_value' => variable_get('readingNow_title', 'Зараз читаю'),
    );

    $form['testDay_title'] = array(
        '#type' => 'textfield',
        '#title' => 'тестовий день. наприклад 01 або 21',
        '#required' => TRUE,
        '#default_value' => variable_get('testDay_title', date("d")),
    );

    $form['testMonth_title'] = array(
        '#type' => 'textfield',
        '#title' => 'тестовий місяць. наприклад 02 або 12',
        '#required' => TRUE,
        '#default_value' => variable_get('testMonth_title', date("m")),
    );

    return system_settings_form($form);
}