<!--(bake parts/login-register-header.php)-->

<div id="auth_box" class="login-block">
<div class="container">
<div class="row">
<div class="login-inner-block clearfix">
    <h1 class="title">Вхід</h1>
    <div class="reg-block"><span><a href="/user/register">Не зареєстровані?</a></span></div>

    <?php print $messages; ?>

    <?php print render($page['content']); ?>
    </div>
    </div>
   </div>
</div>

<!--(bake parts/login-register-footer.php)-->
