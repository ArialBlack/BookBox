<?php

/**
 * @file
 * Default theme implementation to present all user profile data.
 *
 * This template is used when viewing a registered member's profile page,
 * e.g., example.com/user/123. 123 being the users ID.
 *
 * Use render($user_profile) to print all profile items, or print a subset
 * such as render($user_profile['user_picture']). Always call
 * render($user_profile) at the end in order to print all remaining items. If
 * the item is a category, it will contain all its profile items. By default,
 * $user_profile['summary'] is provided, which contains data on the user's
 * history. Other data can be included by modules. $user_profile['user_picture']
 * is available for showing the account picture.
 *
 * Available variables:
 *   - $user_profile: An array of profile items. Use render() to print them.
 *   - Field variables: for each field instance attached to the user a
 *     corresponding variable is defined; e.g., $account->field_example has a
 *     variable $field_example defined. When needing to access a field's raw
 *     values, developers/themers are strongly encouraged to use these
 *     variables. Otherwise they will have to explicitly specify the desired
 *     field language, e.g. $account->field_example['en'], thus overriding any
 *     language negotiation rule that was previously applied.
 *
 * @see user-profile-category.tpl.php
 *   Where the html is handled for the group.
 * @see user-profile-item.tpl.php
 *   Where the html is handled for each item in the group.
 * @see template_preprocess_user_profile()
 *
 * @ingroup themeable
 */
global $user;
$email = $user->mail;
//dsm($user_profile);
$edit_link = '/user/' . $user->uid .'/edit';

?>
<div class="profile"<?php print $attributes; ?>>

  <?php

    if(isset($user_profile['field_position'])) {
      $pos = $user_profile['field_position'][0]['#markup'];
      if(isset($pos)) {
        print '<div class="field field-name-field-position field-type-text field-label-above"><div class="field-label">Посада <a href="' . $edit_link . '"> (Змінити) </a></div><div class="field-items"><div class="field-item even">' . $pos . '</div></div></div>';
      }
    }

    if(isset($user_profile['field_tel'])) {
      $tel = $user_profile['field_tel'][0]['#markup'];
      if(isset($tel)) {
        print '<div class="field field-name-field-tel field-type-text field-label-above"><div class="field-label">Телефон <a href="' . $edit_link . '"> (Змінити) </a></div><div class="field-items"><div class="field-item even">' . $tel . '</div></div></div>';
      }
    }

    print '<div class="field field-name-field-email field-type-text field-label-above"><div class="field-label">Email</div><div class="field-items"><div class="field-item even">' . $email . '</div></div></div>';
    print '<a class="user-change-pass" href="' . $edit_link . '">Змінити пароль</a>'
  ?>

</div>
