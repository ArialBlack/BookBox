<?php global $user; ?>

<header id="navbar" role="banner" class="<?php print $navbar_classes; ?>">
    <div class="<?php print $container_class; ?>">
        <div class="navbar-header">
            <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".main-nav-collapse"></button>
            <a href="/" class="home-header"><i class="icon ion-ios-home-outline"></i></a>

            <?php if ($logo): ?>
                <a class="logo navbar-btn pull-left" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
                    <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
                </a>
            <?php endif; ?>

            <button type="button" class="navbar-toggle usermenu-toggle" data-toggle="collapse" data-target=".user-navbar-collapse"></button>
        </div>

        <div class="navbar-collapse collapse main-nav-collapse">
            <nav role="navigation">
                <?php if (!empty($primary_nav)): ?>
                    <span class="primary-nav"><?php print render($primary_nav); ?></span>
                <?php endif; ?>
            </nav>
        </div>

        <div class="search-block">
            <?php
                $block = module_invoke('finder', 'block_view', 'content_finder');
                print render($block['content']);
            ?>

            <svg class="svg-icon icon-search" preserveAspectRatio="xMaxYMax"><use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="/sites/all/themes/bookbox_ui/images/svg-icons-sprite.svg#icon-search"></use></svg>
        </div>

      <div class="navbar-collapse collapse user-navbar-collapse">
        <?php if ($user->uid != 0): ?>
          <?php
          $uid = $user->uid;

          $u_orders_c = bookbox_count_in_confirm($user->uid);
          $u_reading_c = bookbox_count_in_reading_now($user->uid);

          $favs_view = views_get_view('user_wishlist');
          $favs_view->set_display('block_1');
          $favs_view->set_arguments(array($user->uid));
          $favs_view->pre_execute();
          $favs_view->execute();
          $u_favs_c = $favs_view->total_rows;
          ?>


            <ul class="user-icons-menu nav nav-tabs dup-tabs" role="tablist">
              <li role="presentation">
                <a href="/user#order" aria-controls="order" role="tab"
                   data-toggle="tab">Замовлено
                  <?php if ($u_orders_c > 0): ?>
                    <span class="badge"><?php print $u_orders_c; ?></span>
                  <?php endif; ?>
                </a>
              </li>
              <li role="presentation">
                <a href="/user#read" aria-controls="read" role="tab"
                   data-toggle="tab">Зараз читаю
                  <?php if ($u_reading_c > 0): ?>
                    <span class="badge"><?php print $u_reading_c; ?></span>
                  <?php endif; ?>
                </a>
              </li>
              <li role="presentation">
                <a href="/user#favs" aria-controls="favs" role="tab"
                   data-toggle="tab">Вішліст
                  <?php if ($u_favs_c > 0): ?>
                    <span class="badge"><?php print $u_favs_c; ?></span>
                  <?php endif; ?>
                </a>
              </li>
            </ul>


          <?php
          $block = module_invoke('bookbox', 'block_view', 'BBUserMenu');
          print render($block['content']);
          ?>
        <?php endif; ?>

         </div>
    </div>
</header>


