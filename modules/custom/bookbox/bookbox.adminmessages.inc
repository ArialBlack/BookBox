<?php
// Функціонал http://prntscr.com/i8dva9
function bookbox_admin_labels_form($form, &$form_state){
    $form['varMaxBooks'] = array(
        '#type' => 'textfield',
        '#title' => 'Максимальна кількість книжок (2 - 10)',
        '#required' => TRUE,
        '#default_value' => variable_get('varMaxBooks', 3),
    );

    return system_settings_form($form);
}