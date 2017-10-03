<!--(bake parts/login-register-header.php)-->

<div id="auth_box" class="register">

    <h2 class="title">Реєстрація</h2>
    <span>Вже зареєстровані?</span> <a href="/user/login">Вхід</a>

    <?php print $messages; ?>
    
    <?php print render($page['content']); ?>


</div>

<!--(bake parts/login-register-footer.php)-->
