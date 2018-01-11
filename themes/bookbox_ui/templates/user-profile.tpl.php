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
  $edit_link = '/user/' . $user->uid .'/edit';
  $uri = $user_profile['field_author_photo'][0]['#item']['uri'];
?>

<div class="yellow-block">
  <div class="container">
    <div class="a-img">
      <img src="<?php print image_style_url("medium", $uri); ?>"/>
    </div>
    <h6>
      <?php print $user_profile['field_company'][0]['#markup'];?>
    </h6>
    <h1>
      <?php print $user_profile['field_name']['#items'][0]['value'] . ' ' . $user_profile['field_sirname']['#items'][0]['value'];?>
    </h1>

    <div class="field field-name-field-email field-type-text field-label-above">
      <div class="field-label">Email</div>
      <div class="field-items">
        <div class="field-item even">
          <?php print $email;?>
        </div>
      </div>
    </div>

    <?php
      if(isset($user_profile['field_tel'])) {
        $tel = $user_profile['field_tel'][0]['#markup'];
        if(isset($tel)) {
          print '<div class="field field-name-field-tel field-type-text field-label-above"><div class="field-label">Телефон <a href="' . $edit_link . '"> (Змінити) </a></div><div class="field-items"><div class="field-item even">' . $tel . '</div></div></div>';
        }
      }

      print '<a class="user-change-pass" href="' . $edit_link . '">Встановити новий пароль</a>'
    ?>
  </div>
</div>

<div class="container">
  <div class="profile"<?php print $attributes; ?>>

    <div class="user-tabs">
      <?php
      $u_orders_c = bookbox_count_in_confirm($user->uid);
      $u_reading_c = bookbox_count_in_reading_now($user->uid);

      list($x,$y) = _bookbox_user_orders_history();
      $u_history = $x;
      $u_history_c = $y;

      $favs_view = views_get_view('user_wishlist');
      $favs_view->set_display('block_1');
      $favs_view->set_arguments(array($user->uid));
      $favs_view->pre_execute();
      $favs_view->execute();
      $u_favs_c = $favs_view->total_rows;

      ?>
      <ul class="nav nav-tabs" role="tablist">
        <li role="presentation" class="active">
          <a href="#order" aria-controls="order" role="tab" data-toggle="tab">Замовлено
            <?php if($u_orders_c > 0):?>
              <span class="badge"><?php print $u_orders_c;?></span>
            <?php endif; ?>
          </a>
        </li>
        <li role="presentation">
          <a href="#read" aria-controls="read" role="tab" data-toggle="tab">Зараз читаю
            <?php if($u_reading_c > 0):?>
              <span class="badge"><?php print $u_reading_c;?></span>
            <?php endif; ?>
          </a>
        </li>
        <li role="presentation">
          <a href="#history" aria-controls="history" role="tab" data-toggle="tab">Прочитано
            <?php if($u_history_c > 0):?>
              <span class="badge"><?php print $u_history_c;?></span>
            <?php endif; ?>
          </a>
        </li>
        <li role="presentation">
          <a href="#favs" aria-controls="favs" role="tab" data-toggle="tab">Вішліст
            <?php if($u_favs_c > 0):?>
              <span class="badge"><?php print $u_favs_c;?></span>
            <?php endif; ?>
          </a>
        </li>
      </ul>
      <div class="tab-content">
        <div role="tabpanel" class="tab-pane active" id="order">
          <?php
          $block = module_invoke('bookbox', 'block_view', 'MonthOrder');
          print render($block['content']);
          ?>
        </div>
        <div role="tabpanel" class="tab-pane" id="read">
          <?php
          $block = module_invoke('bookbox', 'block_view', 'ReadingNow');
          print render($block['content']);
          ?>
        </div>
        <div role="tabpanel" class="tab-pane" id="history">
          <h3>Історія замовлень</h3>
          <?php
          print $u_history;
          ?>
        </div>
        <div role="tabpanel" class="tab-pane" id="favs">
          <?php
          print $favs_view->render();
          ?>
        </div>
      </div>
    </div>
  </div>
</div>

