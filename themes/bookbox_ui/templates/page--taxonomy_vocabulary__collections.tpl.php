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

$term = taxonomy_term_load(arg(2));

?>

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

            <svg class="svg-icon icon-search" preserveAspectRatio="xMaxYMax"><use xmlns:xlink="http://www.w3.org/1999/xlink" xlink:href="/sites/all/themes/bookbox_ui/images/svg/search.svg#icon-search"></use></svg>
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
                <a href="/user#order">Замовлено
                  <?php if ($u_orders_c > 0): ?>
                    <span class="badge"><?php print $u_orders_c; ?></span>
                  <?php endif; ?>
                </a>
              </li>
              <li role="presentation">
                <a href="/user#read">Зараз читаю
                  <?php if ($u_reading_c > 0): ?>
                    <span class="badge"><?php print $u_reading_c; ?></span>
                  <?php endif; ?>
                </a>
              </li>
              <li role="presentation">
                <a href="/user#favs">Вішліст
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




<div class="main-container <?php print $container_class; ?>">
  <div class="row">
    <section<?php print $content_column_class; ?>>
      <?php print $messages; ?>
    <div class="yellow-block">
      <div class="container">
      	<div class="row">
      		<div class="col-md-9">
      			<?php if (!empty($breadcrumb)): print $breadcrumb; endif;?>


            <h1 class="page-header"><?php print $term->name; ?></h1>

            <?php
            if(isset($term->field_nni)) {
              print '<img src="'. image_style_url('slider', $term->field_nni['und'][0]['uri']). '" />';
            }

            if (module_exists('i18n_taxonomy') && i18n_taxonomy_vocabulary_mode($term->vid) == 1) {
              $description = i18n_string("taxonomy:term:$term->tid:description", $term->description);
            }
            else {
              $description = $term->description;
            }
            print '<div class="description">' . check_markup($description, $term->format, '', TRUE) . '</div>';
            ?>



          </div>
      		<div class="col-md-2">
          <div class="page-icon"></div>
      		</div>
      	</div>
        
        </div>
    </div>
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
    </div>
    </section>
</div>

<?php if (!empty($page['footer'])): ?>
    <footer class="footer">
<a href="#navbar" class="scroll-to"><img src="/sites/all/themes/bookbox_ui/images/scroll-to-2.jpg"></a>
        <div class="container">
            <?php print render($page['footer']); ?>
        </div>
    </footer>
<?php endif; ?>




