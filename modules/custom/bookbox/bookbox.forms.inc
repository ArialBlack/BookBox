<?php
function bookbox_form_alter(&$form, &$form_state, $form_id){
    if ($form['#id'] == 'user-register-form') {
        $form['#validate'][] = 'bookbox_registeruser_validate';
    }
}

function bookbox_registeruser_validate($form, &$form_state) {
    $company_id = $form_state['values']['field_company']['und'][0]['target_id'];
    $usermail = $form_state['values']['mail'];

    if ($usermail && $company_id) {
        $usermail_domain = substr(strrchr($usermail, "@"), 1);
        $node = node_load($company_id);
        $domains = $node->field_maildomain['und'];
        $in_list = false;

        for($i = 0; $i < count($domains); $i++) {
            if ($domains[$i]['value'] == $usermail_domain) {
                $in_list = true;
            }
        }

        if (!$in_list) {
            form_set_error('mail', 'Ваш email не співпадає з обранною компанією');
        }
    }
}