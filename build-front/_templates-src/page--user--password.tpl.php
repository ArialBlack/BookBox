<!--(bake parts/login-register-header.php)-->

<div id="auth_box" class="password-block">

 <!-- <div id="middle_part"> -->
  <div class="container">
  <div class="row">
  <div class="password-inner-block clearfix">
    <h2 class="title">Відновлення паролю</h2>

    <?php print $messages; ?>

    <?php
      $page['content']['system_main']['name']['#title'] = 'Корпоративний email';
      //$page['content']['system_main']['actions']['submit']['value'] = 'Надіслати';
    ?>

    <?php print render($page['content']); ?>
</div>
  </div>
</div>
</div>

<!-- </div> -->

<!--(bake parts/login-register-footer.php)-->
