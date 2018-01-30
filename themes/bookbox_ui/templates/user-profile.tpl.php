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

//global $user;
$email = $elements['#account']->mail;
$edit_link = '/user/' . $elements['#account']->uid .'/edit';
$uri = $user_profile['field_author_photo'][0]['#item']['uri'];

?>

<div class="yellow-block">
	<div class="container">
		<div class="a-img profile-photo">
			<a href="<?php print $edit_link;?>">
			  <img src="<?php print image_style_url("medium", $uri); ?>"/>
			  <span> Обрати фото</span>
			</a>
		</div>
		<div class="profile-info">
			<h6>
				<?php print $user_profile['field_company'][0]['#markup'];?>
			</h6>
			<h1>
				<?php print $user_profile['field_name']['#items'][0]['value'] . ' ' . $user_profile['field_sirname']['#items'][0]['value'];?>
			</h1>

			<div class="field field-name-field-email field-type-text field-label-above">
				<div class="field-label">Email:</div>
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
					print '<div class="field field-name-field-tel field-type-text field-label-above"><div class="field-label">Телефон:</div><div class="field-items"><div class="field-item even">' . $tel . ' <a href="' . $edit_link . '"> <img src="/sites/all/themes/bookbox_ui/images/svg/change-phone.svg">...</a></div></div></div>';
				}
			}

			print '<a class="user-change-pass" href="' . $edit_link . '">Встановити новий пароль</a>'
			?>
		</div>

	</div>
</div>

<div class="container">
	<div class="profile"<?php print $attributes; ?>>

		<div class="visible-desktop">
			<div class="user-tabs">
				<?php
				$u_orders_c = bookbox_count_in_confirm($elements['#account']->uid);
				$u_reading_c = bookbox_count_in_reading_now($elements['#account']->uid);

				list($x,$y) = _bookbox_user_orders_history();
				$u_history = $x;
				$u_history_c = $y;

				$favs_view = views_get_view('user_wishlist');
				$favs_view->set_display('block_1');
				$favs_view->set_arguments(array($elements['#account']->uid));
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
					<h6>Атмосфера Юпітера — газова оболонка, яка оточує Юпітер. Атмосфера Юпітера є найбільшою планетною атмосферою в Сонячній системі.
            Вона не має чіткої нижньої межі і плавно переходить. в океан з рідкого водню. Виділяють такі шари атмосфери.</h6>
						<?php
						$block = module_invoke('bookbox', 'block_view', 'MonthOrder');
						print render($block['content']);
						?>
					</div>
					<div role="tabpanel" class="tab-pane" id="read">
					  <h6>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Doloribus beatae veritatis dignissimos, atque necessitatibus enim iusto.</h6>
						<?php
						$block = module_invoke('bookbox', 'block_view', 'ReadingNow');
						print render($block['content']);
						?>
					</div>
					<div role="tabpanel" class="tab-pane" id="history">
						<h6>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Obcaecati sunt blanditiis, debitis adipisci nisi sapiente eum iusto voluptatem odio quas aut facere cumque nulla.</h6>
						<?php
						print $u_history;
						?>
					</div>
					<div role="tabpanel" class="tab-pane" id="favs">
						<h6>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Temporibus dolores aspernatur sunt. Quis natus vitae laudantium dolor, quidem maiores cumque praesentium quod et voluptatem, ipsa magni necessitatibus saepe deserunt. Doloribus enim ipsa illo dignissimos adipisci quas quisquam nobis sunt suscipit.</h6>
						<?php
						print $favs_view->render();
						?>
					</div>
				</div>
			</div>
		</div>

		<div class="visible-mobile">
			<?php
			$u_orders_c = bookbox_count_in_confirm($elements['#account']->uid);
			$u_reading_c = bookbox_count_in_reading_now($elements['#account']->uid);

			list($x,$y) = _bookbox_user_orders_history();
			$u_history = $x;
			$u_history_c = $y;

			$favs_view = views_get_view('user_wishlist');
			$favs_view->set_display('block_1');
			$favs_view->set_arguments(array($elements['#account']->uid));
			$favs_view->pre_execute();
			$favs_view->execute();
			$u_favs_c = $favs_view->total_rows;
			?>

			<div class="panel-group" id="accordion" role="tablist" aria-multiselectable="true">
				<div class="panel panel-default">
					<div class="panel-heading">
						<h4 class="panel-title">
							<a data-toggle="collapse" data-parent="#collapse-group" href="#order-m" class="collapsed">Замовлено <span class="caret"></span></a>
						</h4>
					</div>
					<div id="order-m" class="panel-collapse collapse" aria-expanded="false">
						<div class="panel-body">
							<?php
							$block = module_invoke('bookbox', 'block_view', 'MonthOrder');
							print render($block['content']);
							?>
						</div>
					</div>
				</div>
				<div class="panel panel-default">
					<div class="panel-heading">
						<h4 class="panel-title">
							<a data-toggle="collapse" data-parent="#collapse-group" href="#read-m" class="collapsed">Зараз читаю <span class="caret"></span></a>
						</h4>
					</div>
					<div id="read-m" class="panel-collapse collapse" aria-expanded="false">
						<div class="panel-body">
							<?php
							$block = module_invoke('bookbox', 'block_view', 'ReadingNow');
							print render($block['content']);
							?>
						</div>
					</div>
				</div>
				<div class="panel panel-default">
					<div class="panel-heading">
						<h4 class="panel-title">
							<a data-toggle="collapse" data-parent="#collapse-group" href="#history-m" class="collapsed">Прочитано <span class="caret"></span></a>
						</h4>
					</div>
					<div id="history-m" class="panel-collapse collapse">
						<div class="panel-body">
							<?php
							print $u_history;
							?>
						</div>
					</div>
				</div>
				<div class="panel panel-default">
					<div class="panel-heading">
						<h4 class="panel-title">
							<a data-toggle="collapse" data-parent="#collapse-group" href="#favs-m" class="collapsed">Вішліст <span class="caret"></span></a>
						</h4>
					</div>
					<div id="favs-m" class="panel-collapse collapse">
						<div class="panel-body">
							<?php
							print $favs_view->render();
							?>
						</div>
					</div>
				</div>
			</div>
		</div>
	</div>
</div>

