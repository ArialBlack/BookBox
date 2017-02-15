<?php

function bookbox_admin_labels_form($form, &$form_state){
    $form['readingNow_title'] = array(
        '#type' => 'textfield',
        '#title' => t('Box title'),
        '#required' => TRUE,
        '#default_value' => variable_get('readingNow_title', 'Зараз читаю'),
    );

    return system_settings_form($form);
}