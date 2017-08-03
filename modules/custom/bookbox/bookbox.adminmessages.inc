<?php

function bookbox_admin_labels_form($form, &$form_state){
    $form['varTestDay'] = array(
        '#type' => 'textfield',
        '#title' => 'Порядковий номер тижня. наприклад, середа це 3',
        '#required' => TRUE,
        '#default_value' => variable_get('varTestDay', date('N')),
    );

    $form['varTestTime'] = array(
        '#type' => 'textfield',
        '#title' => 'Тестовий час. наприклад 18:00',
        '#required' => TRUE,
        '#default_value' => variable_get('varTestTime', date('H:i')),
    );

    $form['varMaxBooks'] = array(
        '#type' => 'textfield',
        '#title' => 'Максимальна кількість книжок (2 - 10)',
        '#required' => TRUE,
        '#default_value' => variable_get('varMaxBooks', 3),
    );

    return system_settings_form($form);
}