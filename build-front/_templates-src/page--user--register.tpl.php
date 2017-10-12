<!--(bake parts/login-register-header.php)-->

<div id="auth_box" class="register-block">
<div class="container">
<div class="row">
<div class="register-block-inner">
    <h2 class="title">Реєстрація</h2>
    <div class="login-block">
    <span><a href="/user/login">Вже зареєстровані?</a></span>
    </div>

    <?php print $messages; ?>

    <?php print render($page['content']); ?>

</div>
</div>
</div>
</div>

<!--(bake parts/login-register-footer.php)-->
