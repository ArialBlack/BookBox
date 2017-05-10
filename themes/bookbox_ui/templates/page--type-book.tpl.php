<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see bootstrap_preprocess_page()
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see bootstrap_process_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup templates
 */




?>

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




<div class="main-container <?php print $container_class; ?>">

  <header role="banner" id="page-header">
    <?php if (!empty($site_slogan)): ?>
      <p class="lead"><?php print $site_slogan; ?></p>
    <?php endif; ?>

    <?php print render($page['header']); ?>
  </header> <!-- /#page-header -->

  <div class="row">
    <div class="col-sm-12">
      <?php print render($page['precontent']); ?>
    </div>
 
    <section class="col-sm-8">
      <?php print $messages; ?>
      <?php if (!empty($page['highlighted'])): ?>
        <div class="highlighted jumbotron"><?php print render($page['highlighted']); ?></div>
      <?php endif; ?>
      
      <?php if (!empty($breadcrumb)): print $breadcrumb; endif;?>

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

    <?php if (!empty($page['sidebar_second'])): ?>
      <aside class="col-sm-4" role="complementary">
        <?php print render($page['sidebar_second']); ?>
      </aside>  <!-- /#sidebar-second -->
    <?php endif; ?>

  </div>
</div>

<?php if (!empty($page['footer'])): ?>
    <footer class="footer">
        <div class="container">
            <?php print render($page['footer']); ?>
        </div>
    </footer>
<?php endif; ?>


