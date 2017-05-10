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
            <?php if ($u_flag > 0): ?>
                <div class="user-fav-nav">
                    <a href="/user/<?php print $user->uid;?>/favorites">
                        <svg class="svg-icon icon-heart" preserveAspectRatio="xMaxYMax"><use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="/sites/all/themes/bookbox_ui/images/svg-icons-sprite.svg#icon-fav"></use></svg>
                        <span class="counter_container"><span class="counter"><span><?php print $u_flag; ?></span></span></span>
                    </a>
                </div>
            <?php endif; ?>

             <?php if ($user->uid != 0): ?>
                 <?php
                    $block = module_invoke('bookbox', 'block_view', 'BBUserMenu');
                    print render($block['content']);
                 ?>
             <?php endif; ?>

         </div>
    </div>
</header>


