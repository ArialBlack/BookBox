<?php global $user; ?>

<header id="navbar" role="banner" class="<?php print $navbar_classes; ?>">
    <div class="<?php print $container_class; ?>">
        <div class="navbar-header">
            <?php if ($logo): ?>
                <a class="logo navbar-btn pull-left" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
                    <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
                </a>
            <?php endif; ?>

            <?php if (!empty($site_name)): ?>
                <a class="name navbar-brand" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"><?php print $site_name; ?></a>
            <?php endif; ?>

            <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
                <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse"></button>
            <?php endif; ?>
        </div>

        <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
            <div class="navbar-collapse collapse">
                <nav role="navigation">
                    <?php if (!empty($primary_nav)): ?>
                            <span class="primary-nav"><?php print render($primary_nav); ?></span>
                    <?php endif; ?>

                    <div class="search-block">
                        <?php
                        $block = module_invoke('views', 'block_view', '-exp-booksearch-page');
                        print render($block['content']);
                        ?>
                    </div>

                    <?php if (!empty($secondary_nav) && $user->uid != 0): ?>
                        <?php print render($secondary_nav); ?>
                    <?php endif; ?>
                    <?php if (!empty($page['navigation']) && $user->uid != 0): ?>
                        <?php print render($page['navigation']); ?>
                    <?php endif; ?>

                    <?php if ($u_flag > 0): ?>
                        <div class="user-fav-nav">
                            <a href="/user/<?php print $user->uid;?>/favorites">
                                <svg class="svg-icon icon-heart" preserveAspectRatio="xMaxYMax"><use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="/sites/all/themes/bookbox_ui/images/svg-icons-sprite.svg#icon-fav"></use></svg>
                                <span class="counter_container"><span class="counter"><span><?php print $u_flag; ?></span></span></span>
                            </a>
                        </div>
                    <?php endif; ?>
                </nav>
            </div>
        <?php endif; ?>
    </div>
</header>


