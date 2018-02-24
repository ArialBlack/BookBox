<?php
global $user;
?>

<header id="navbar" role="banner" class="<?php print $navbar_classes; ?>">
    <div class="<?php print $container_class; ?>">
        <div class="navbar-header">
            <?php if ($logo): ?>
                <a class="logo navbar-btn pull-left" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
                    <!-- <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" /> -->
                    <img src="/sites/all/themes/bookbox_ui/images/svg/bookboxlogo.svg" alt="<?php print t('Home'); ?>" />
                </a>
            <?php endif; ?>
        </div>

        <div class="button-block">
          <a href="/books" class="all-books">Всі книги</a>
        </div>

        <div class="search-block">
            <?php
                $block = module_invoke('finder', 'block_view', 'content_finder');
                print render($block['content']);
            ?>
        </div>
        <div class="show-finder"></div>

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
                <a href="/user#order" title="Замовлено">
                  <?php if ($u_orders_c >= 0): ?>
                    <span class="badge"><?php print $u_orders_c; ?></span>
                  <?php else: ?>
                    <span class="badge badge-empty">0</span>
                  <?php endif; ?>
                </a>
              </li>
              <li role="presentation">
                <a href="/user#read" title="Зараз читаю">
                  <?php if ($u_reading_c >= 0): ?>
                    <span class="badge"><?php print $u_reading_c; ?></span>
                  <?php else: ?>
                    <span class="badge badge-empty">0</span>
                  <?php endif; ?>
                </a>
              </li>
              <li role="presentation">
                <a href="/user#favs" title="Список бажань">
                  <?php if ($u_favs_c >= 0): ?>
                    <span class="badge"><?php print $u_favs_c; ?></span>
                  <?php else: ?>
                    <span class="badge badge-empty">0</span>
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




<div class="main-container <?php print $container_class; ?>">
  <header role="banner" id="page-header">
    <?php if (!empty($site_slogan)): ?>
      <p class="lead"><?php print $site_slogan; ?></p>
    <?php endif; ?>

    <?php print render($page['header']); ?>
  </header> <!-- /#page-header -->

  <div class="row">
    <div class="col-sm-12">
      <?php print render($page['slider_area']); ?>
    </div>

    <div class="col-sm-12">
      <?php print render($page['precontent']); ?>
    </div>
    <div class="yellow-block">
      <div class="container">
        <div class="row">
          <div class="col-md-9">
            <?php if (!empty($breadcrumb)): print $breadcrumb; endif;?>
               <?php print render($title_prefix); ?>
                  <?php if (!empty($title)): ?>
                    <h1 class="page-header"><?php print $title; ?></h1>
                  <?php endif; ?>
               <?php print render($title_suffix); ?>
          </div>
          <div class="col-md-2">
            <div class="page-icon"></div>
          </div>
        </div>
      </div>
    </div>

    <div class="container categories-block">
    	<div class="row">
    		<?php if (!empty($page['sidebar_first'])): ?>
      <aside class="col-sm-3" role="complementary">
        <?php print render($page['sidebar_first']); ?>
      </aside>  <!-- /#sidebar-first -->
    <?php endif; ?>

    <section<?php print $content_column_class; ?>>
      <?php print $messages; ?>
      <?php if (!empty($page['highlighted'])): ?>
        <div class="highlighted jumbotron"><?php print render($page['highlighted']); ?></div>
      <?php endif; ?>

      <a id="main-content"></a>
      <?php if (!empty($tabs)): ?>
        <?php print render($tabs); ?>
      <?php endif; ?>
      <?php if (!empty($page['help'])): ?>
        <?php print render($page['help']); ?>
      <?php endif; ?>
      <?php if (!empty($action_links)): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php print render($page['content']); ?>
    </section>
    	</div>
    </div>



    <?php if (!empty($page['sidebar_second'])): ?>
      <aside class="col-sm-4" role="complementary">
        <?php print render($page['sidebar_second']); ?>
      </aside>  <!-- /#sidebar-second -->
    <?php endif; ?>

    <?php if (!empty($page['content_bottom'])): ?>
      <div class="col-sm-12" role="complementary">
        <?php print render($page['content_bottom']); ?>
      </div>  <!-- /#sidebar-second -->
    <?php endif; ?>

  </div>
</div>

<?php if (!empty($page['footer'])): ?>
    <div class="show-finder bg"></div>
    <footer class="footer">
<a href="#navbar" class="scroll-to"><img src="/sites/all/themes/bookbox_ui/images/scroll-to-2.jpg"></a>
        <div class="container">
            <?php print render($page['footer']); ?>
        </div>
    </footer>
<?php endif; ?>





