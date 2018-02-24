<!--(bake parts/header.php)-->

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

<!--(bake parts/footer.php)-->




