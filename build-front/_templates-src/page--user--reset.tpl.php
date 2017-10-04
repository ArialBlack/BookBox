<!--(bake parts/login-register-header.php)-->

<div id="auth_box" class="reset">
  
  <div id="middle_part">
    <h2 class="title"><?php print $title; ?></h2>

    <?php print $messages; ?>

    <?php print render($page['content']); ?>
  </div>
  
</div>

<!--(bake parts/login-register-footer.php)-->
