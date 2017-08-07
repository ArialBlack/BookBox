<?php

function bookbox_admin_labels_form($form, &$form_state){
    $form['varTestDayTime'] = array(
        '#type' => 'textfield',
        '#title' => 'Тестова дата час, наприклад, 1501700400 http://www.onlineconversion.com/unix_time.htm -3 години',
        '#required' => TRUE,
        '#default_value' => variable_get('varTestDayTime', '1501700400'),
    );

    $form['varMaxBooks'] = array(
        '#type' => 'textfield',
        '#title' => 'Максимальна кількість книжок (2 - 10)',
        '#required' => TRUE,
        '#default_value' => variable_get('varMaxBooks', 3),
    );

    return system_settings_form($form);
}