<!--(bake parts/login-register-header.php)-->

<div id="auth_box" class="reset-block">

  <!-- <div id="middle_part"> -->
  <div class="container">
    <div class="row">
    <div class="reset-inner-block clearfix">
    <h2 class="title"><?php print $title; ?></h2>

    <?php print $messages; ?>

    <?php print render($page['content']); ?>
    </div>
      </div>
    </div>
  <!-- </div> -->

</div>

<!--(bake parts/login-register-footer.php)-->
