<div class="header">
    <!-- <div class="container login-container">
      <div class="row text-right">
      </div>
    </div> -->
    <nav class="navbar navbar-inverse">
        <div class="container">
            <div class="row">
                <div class="col-md-3 col-sm-2 navbar-header">
                    <ul class="mobile-log-btns">
                        <li><a href="https://lib.bookbox.ua/user" class="login">Вхід</a></li>
                        <li><a href="https://lib.bookbox.ua/user/register" class="reg">Реєстрація</a></li>
                    </ul>
                    <button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#navbar" aria-expanded="false" aria-controls="navbar">
                        <span class="sr-only">Toggle navigation</span>
                        <span class="icon-bar"></span>
                        <span class="icon-bar"></span>
                        <span class="icon-bar"></span>
                    </button>
                    <a class="navbar-brand" href="https://bookbox.ua"><img src="/sites/all/themes/bookbox_ui/images/svg/bookboxlogo.svg"></a>
                </div>
                <div class="col-md-5 col-sm-6">
                    <div id="navbar" class="collapse navbar-collapse">
                        <ul class="nav navbar-nav">
                            <li class="active"><a href="https://bookbox.ua#how">Як це працює</a></li>
                            <li><a href="https://bookbox.ua#books">Асортимент</a></li>
                            <!-- <li><a href="/#price">Вартість</a></li> -->
                            <li><a href="https://bookbox.ua#partners">Наші клієнти</a></li>
                            <li><a href="https://bookbox.ua#faq">FAQ</a></li>
                            <div class="mob">
                                <li><a href="https://lib.bookbox.ua/user" class="login">Вхід</a></li>
                                <li><a href="https://lib.bookbox.ua/user/register" class="reg">Реєстрація</a></li>
                            </div>
                        </ul>
                    </div><!--/.nav-collapse -->
                </div>
                <div class="col-md-3 col-md-offset-1 col-sm-4 desktop-log-btns">
                    <ul>
                        <li><a href="https://lib.bookbox.ua/user" class="login">Вхід</a></li>
                        <li><a href="https://lib.bookbox.ua/user/register" class="reg">Реєстрація</a></li>
                    </ul>
                </div>
            </div>
        </div>
    </nav>
</div>


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

<footer class="footer">
    <div class="container">
        <div class="row links-row">
            <div class="col-md-2 col-sm-2 col-xs-2 footer-logo">
                <img src="/sites/all/themes/bookbox_ui/images/logo-2.png" alt="">
            </div>
            <div class="col-md-4 col-md-offset-2 col-sm-4 col-sm-offset-2 col-xs-4 col-xs-offset-2 text-center read-better">
                <h1>Read better</h1>
                <a href="https://www.facebook.com/bookboxua">Ми на Facebook</a>
            </div>
            <div class="col-md-4 col-sm-4 col-xs-4 text-right footer-links">
                <ul>
                    <li><a href="https://bookbox.ua/privacy">Політика конфіденційності</a></li>
                    <li><a href="https://bookbox.ua/terms">Правила користування</a></li>
                    <li><a href="https://bookbox.ua/contacts">Контакти</a></li>
                </ul>
            </div>
        </div>
        <div class="row all-rights">
            <div class="col-md-4 col-md-offset-4 text-center">2017 © Book Box. Всі права захищені</div>
        </div>
    </div>
</footer>

