<!--(bake parts/login-register-header.php)-->

<div id="auth_box" class="login">

    <h1 class="title">Вхід</h1>
    <span>Ще не зареєструвались?</span> <a href="/user/register">реєстрація</a>

    <?php print $messages; ?>

    <?php print render($page['content']); ?>

</div>

<!--(bake parts/login-register-footer.php)-->