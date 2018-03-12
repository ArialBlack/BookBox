(function ($) {
    $(function() {

        var resizeTimer;

        var $label = $('.book-labels .field');
        $label.each(function( index ) {
            var $text = $(this).find('.field-item').text();
            if ($text.length < 3) {
                $(this).remove();
            }
        });

        function createCookie(name,value,days) {
            if (days) {
                var date = new Date();
                date.setTime(date.getTime()+(days*24*60*60*1000));
                var expires = "; expires="+date.toGMTString();
            }
            else var expires = "";
            document.cookie = name+"="+value+expires+"; path=/";
        }

      //Pagination for Main page
      function BookBoxPagination(page, box) {
        var BookBox =  page + ' ' + box,
          countOfBookBoxes = $(BookBox).length,
          booksInBlock;

        if ($(window).width() >= 1200) {
          booksInBlock = 4;
        } else if ($(window).width() >= 992){
          booksInBlock = 3;
        } else if($(window).width() >= 740) {
          booksInBlock = 2;
        } else {
          booksInBlock = 1;
        }

        for (var i = 1; i<=countOfBookBoxes; i++) {
          var currentBookBox = BookBox + ':nth-child('+ i.toString() + ')>ul';

          if (countOfBookBoxes === 1) {
            currentBookBox = BookBox + '>ul';
          }

          var book = currentBookBox+'>li',
            booksCount;

          if (box === '#block-system-main') {
            currentBookBox = page + ' ' + box;
            book = currentBookBox + '>.node-book';
          }

          booksCount= $(book).length;

          if ( booksCount > booksInBlock) {
            $(currentBookBox).addClass('box-pagination');
            var innerBoxesCount = Math.ceil(booksCount/booksInBlock);
            for(var k = 1; k<=innerBoxesCount; k++) {
              $(currentBookBox).append('<div class="inner-block-bookbox"></div>');
            }

            $(currentBookBox + ' .inner-block-bookbox').each(function(){
              for(var j = 1; j<=booksInBlock; j++) {
                $(this).append($(book + ':first-child'));
              }
            });
          }
        }
      }

      function BookBoxBlockBuilder(index, book) {
          var BookContainer = index + ' ' + book,
              BooksCount=$(BookContainer).length;

          $(index).append('<div class="book-inner-block"></div>');
          for (var i=1; i<=BooksCount; i++) {
            $(index + ' ' + '.book-inner-block').append($(BookContainer + ':first'));
          }
      }

      function changeFormSelect(hiddenForm, visibleForm) {
          var currentValue = $(hiddenForm).val();
          $(visibleForm).val(currentValue);
      }

        function readCookie(name) {
            var nameEQ = name + "=";
            var ca = document.cookie.split(';');
            for(var i=0;i < ca.length;i++) {
                var c = ca[i];
                while (c.charAt(0)==' ') c = c.substring(1,c.length);
                if (c.indexOf(nameEQ) == 0) return c.substring(nameEQ.length,c.length);
            }
            return null;
        }

        function eraseCookie(name) {
            createCookie(name,"",-1);
        }

      function checkBookName(bookBlock) {
        for(var tb = 0; tb<$(bookBlock).length; tb++) {
          if ($(bookBlock + ':nth-child('+ tb +' ) h4').text().length > 48) {
            var newBookName = $(bookBlock + ':nth-child('+ tb +' ) h4').text().substr(0, 47);
            $(bookBlock + ':nth-child('+ tb +' ) h4').text(newBookName + '...');
          }
        }
      }

      function validateTextField(id){
        var value = $(id).val();
        if( value.length !== 0){
          $(id).css('border', '2px solid #dfdfdf');
          $(id).css('background', '#e9e9e9');
          $(id).css('color', '#dfdfdf');
          return true;
        } else {
          $(id).css('border', '2px solid #db553f');
          $(id).css('background', 'rgba(255, 0, 0, .06)');
          $(id).addClass('webform-error');
          $(id).attr('placeholder', 'Це поле необхідно заповнити');
          return false
        }
      }

      function validateTel(telId) {
        var telValue = $(telId).val().trim();
        var re = /^((8|0|((\+|00)\d{1,2}))[\- ]?)?(\(?\d{3}\)?[\- ]?)?[\d\- ]{7,10}$/;
        if(telValue.length !== 0 && re.test(telValue) && telValue.length == 13){
          $(telId).css('border', '2px solid #dfdfdf');
          $(telId).css('background', '#e9e9e9');
          $(telId).css('color', '#dfdfdf');
          return true;
        } else {
          if(telValue.length < 1) {
            $(telId).css('border', '2px solid #db553f');
            $(telId).css('background', 'rgba(255, 0, 0, .06)');
            $(telId).attr('placeholder', 'Це поле необхідно заповнити');
            $(telId).addClass('webform-error');
            $(telId).val('');
            return false;
          }
          if(!re.test(telValue) && telValue.length > 1) {
            $(telId).css('border', '2px solid #db553f');
            $(telId).css('background', 'rgba(255, 0, 0, .06)');
            $(telId).addClass('webform-error');
            document.getElementById('edit-submitted-tel').value='';
            $(telId).attr('placeholder', 'Введіть телефон у форматі 380ХХХХХХХХХ');
            $(telId).val('');
          }
        }
      }

      function validateNewPass(pass, confirm) {
          if (pass.val() == '' && confirm.val() == '') {
            console.log('cond1 true');
            return true
          } else if (pass.val() == confirm.val()) {
            console.log('cond2 true');
            return true;
          } else if (pass.val() !== confirm.val()) {
            console.log('cond3 false');
            pass.attr('placeholder', 'Паролі не співпадають');
            pass.css('border', '2px solid #f86b54');
            pass.css('border-bottom', 'none');
            pass.val('');
            confirm.attr('placeholder', 'Паролі не співпадають');
            confirm.css('border', '2px solid #f86b54');
            confirm.val('');
            return false;
          }
      }

        $(document).ajaxStop(function() {
            var $label = $('.book-labels .field');
            $label.each(function( index ) {
                var $text = $(this).find('.field-item').text();
                if ($text.length < 3) {
                    $(this).remove();
                }
            });

            // Submit search button when ajax stop
          $('#autocomplete .show-all a').not('.books-btn').on('click', function(e) {
            e.preventDefault();

            setTimeout(function(){
              $('#finder-form-content-finder').submit();
            }, 260);
          });

          checkBookName('#autocomplete ul>li');
        });

        $('#userreglink').appendTo("#edit-actions"); //todo in backend
        $('.sort-submenu').insertAfter(".page-header");

        function searchResultsActions() {
            if($('.region-precontent #finder-block-content_finder-wrapper form').length > 0) {
                var sString = $('#finder-block-content_finder form input.finder-element').val();

                if($('.view-search-results-div').length > 0) {
                    $('.view-search-results-div').find('span').text(sString);
                }

                $('.view-search-results-div').insertAfter( ".region-precontent #finder-block-content_finder-wrapper" );
            }
        }

      $('.alert.alert-block.alert-success.messages.status').insertBefore($('.page-node-893 .main-container'));
      $('<h4>Повідомлення надіслано!</h4>').insertBefore($('.page-node-893 .alert.alert-block.alert-success.messages.status p'));
      $('<a class="btn" data-dismiss="alert">OK</a>').insertAfter($('.page-node-893 .alert.alert-block.alert-success.messages.status p'));
      $('.page-node-893 .alert.alert-block.alert-success.messages.status p').text('Якнайскоріше відповімо :)');

      if($('.page-node-893 .alert.alert-block.alert-success.messages.status, .node-type-book .alert.alert-block.alert-success.messages.status, .page-user-edit .alert.alert-block.alert-success.messages.status').length) {
        $('body').addClass('open-alert modal-open');
      }

      //Script for slides in collection slider. Fix height.
      var equalheight = function(container) {

        var currentTallest = 0,
          currentRowStart = 0,
          rowDivs = new Array(),
          $el,
          topPosition = 0;
        $(container).each(function() {

          $el = $(this);
          $($el).height('auto')
          topPostion = $el.position().top;

          if (currentRowStart != topPostion) {
            for (currentDiv = 0 ; currentDiv < rowDivs.length ; currentDiv++) {
              rowDivs[currentDiv].height(currentTallest);
            }
            rowDivs.length = 0; // empty the array
            currentRowStart = topPostion;
            currentTallest = $el.height();
            rowDivs.push($el);
          } else {
            rowDivs.push($el);
            currentTallest = (currentTallest < $el.height()) ? ($el.height()) : (currentTallest);
          }
          for (currentDiv = 0 ; currentDiv < rowDivs.length ; currentDiv++) {
            rowDivs[currentDiv].height(currentTallest);
          }
        });
      }

      $(window).load(function() {
        equalheight('.front .view-collections-slider .slick-track .views-row');
      });


      $(window).resize(function(){
        equalheight('.front .view-collections-slider .slick-track .views-row');
      });

      //end.
      $(window).on('load', function() {
        if ($('body').hasClass('page-user')) {
          if (location.hash) {
            setTimeout(function () {

              window.scrollTo(0, 0);
            }, 0);
          }
        }


        if ($('body').hasClass('node-type-book')) {
          var textHeight = $('.text-cover-block').height(),
              marginBottom,
              paddingTop;

          if($(window).width() >= 1200 ) {
            marginBottom = textHeight - 512;
            paddingTop = 485 - textHeight;

            $('.name-and-links').css('padding-top', paddingTop + 'px');
            $('.book-cover-block .field-type-image').css('margin-bottom', marginBottom + 'px');
          }
          else if ($(window).width() >= 992 && $(window).width() < 1199) {
              marginBottom = textHeight - 412;
              paddingTop = 385 - textHeight;

            $('.name-and-links').css('padding-top', paddingTop + 'px');
            $('.book-cover-block .field-type-image').css('margin-bottom', marginBottom + 'px');
          }
        }
      });

      $('.form-item-current-pass .form-text.error').attr('placeholder', 'Ви ввели невірний пароль.');

      $( document ).ready(function() {
            //console.log(Drupal.settings.firstLogin);

            searchResultsActions();

            //Submit forms on Enter and button click on search page and navber
        $('.page-book-search .yellow-block .finder-element.form-autocomplete').keypress(function(e) {
          if (e.keyCode == 13) {
            if ($(this).val() == '') {
              e.preventDefault();
            } else {
              setTimeout(function() {
                $('#finder-form-content-finder--2').submit();
              }, 260);
            }
          }
        });

        $('.page-book-search .yellow-block .btn-default.form-submit').click(function(e) {
          if ($('.page-book-search .yellow-block .finder-element.form-autocomplete').val() == '') {
            e.preventDefault();
          } else {
            setTimeout(function() {
              $('#finder-form-content-finder--2').submit();
            }, 250);
          }
        });

        $('.navbar .finder-element.form-autocomplete').keypress(function(e) {
          if (e.keyCode == 13) {
            if ($(this).val() == '') {
              e.preventDefault();
            } else {
              setTimeout(function() {
                $('#finder-form-content-finder').submit();
              }, 260);
            }
          }
        });

        $('.navbar .btn-default.form-submit').click(function(e) {
          if ($('.navbar .finder-element.form-autocomplete').val() == '') {
            e.preventDefault();
          } else {
            setTimeout(function() {
              $('#finder-form-content-finder').submit();
            }, 250);
          }
        });

            ///url must switch tab
            var hash = window.location.hash;
            hash && $('.user-tabs ul.nav a[href="' + hash + '"]').tab('show');
            console.log(hash);

            $('.user-tabs .nav-tabs a').click(function (e) {
                $(this).tab('show');
                var scrollmem = $('body').scrollTop() || $('html').scrollTop();
                window.location.hash = this.hash;
                $('html,body').scrollTop(scrollmem);
            });

            $('.menu.navbar-nav.secondary .dropdown-menu a').click(function() {
                var url = $(this).attr('href'),
                    hash = '#' + url.split('#')[1];

                hash && $('.user-tabs ul.nav a[href="' + hash + '"]').tab('show');
            });


            $( ".region-sidebar-second .block-bookbox" ).each(function( index ) {
                var $this = $(this),
                    bookCount = $this.find('.book-container').length;

                if (bookCount > 2) {
                    $this.addClass('three-books');
                }

            });

            if ($('.page-content-finder').length) {
                $('.page-content-finder .page-header').html('Пошук');
                $('.page-content-finder .form-autocomplete>label').html('Введіть пошукове слово');
                $('.page-content-finder #edit-find').html('Пошук');
            }

            if($('.btn-container.with-tip').length > 0) {
                $('#block-system-main').addClass('with-tip');
            }

            var html = document.documentElement;
            var startSize =  parseInt(getComputedStyle(html, '').fontSize);

            up.onclick = function() {
                html.style.fontSize = parseInt(getComputedStyle(html, '').fontSize) + 2 + 'px';
            };
            down.onclick = function() {
                var currentSize = parseInt(getComputedStyle(html, '').fontSize);
                if (currentSize >= startSize + 2) {
                    html.style.fontSize = currentSize - 2 + 'px';
                }
            };
            /////////////////////////////////////

            $(".modal").appendTo("body");
            $('.user-profile-hot-links').insertAfter(".page-header");

            $('.navbar-toggle[data-target=".main-nav-collapse"]').click(function(){
                $(this).toggleClass('active-left');
            })

            $('.menu.secondary .dropdown-toggle, #navbar .search-block .svg-icon.icon-search').click(function(){
                if( $('.active-left').length ) {
                    $('.active-left').click();
                }
            });


            $('.page-faq #block-system-main .view-id-faq .nav-tabs li').click(function(){
                if ($(window).width() <768) {
                    if (!$(this).hasClass('active')) {
                        $('.page-faq #block-system-main .view-id-faq .tab-content').css('display','none');
                        $(this).append($('.page-faq #block-system-main .view-id-faq .tab-content'));
                        $('.page-faq #block-system-main .view-id-faq .tab-content').slideToggle(300, function(){
                            var offsetActiveFaq = $('.page-faq #block-system-main .view-id-faq .nav-tabs .active').offset().top;
                            $('html, body').animate( { scrollTop: offsetActiveFaq }, 300 );
                        });
                    } else {
                        $('.page-faq #block-system-main .view-id-faq .tab-content').slideToggle();
                    }
                }
            });

            $('.page-user-login .form-type-password').append('<div class="show-pass"><img  src="/sites/all/themes/bookbox_ui/images/singup_eye.svg"></div>');

          if ($(window).width() > 992) {
            $('.show-pass').mousedown(function(){
              var type = $('.page-user-login .form-type-password input').attr('type') == "text" ? "password" : 'text';
              $(this).css('opacity', '0.5');
              $('.page-user-login .form-type-password input').prop('type', type);
            });

            $('.show-pass').mouseup(function(){
              var type = $('.page-user-login .form-type-password input').attr('type') == "text" ? "password" : 'text';
              $(this).css('opacity', '1');
              $('.page-user-login .form-type-password input').prop('type', type);
            });
          } else {
            $('.show-pass').click(function(){
              var type = $('.page-user-login .form-type-password input').attr('type') == "text" ? "password" : 'text';
              $(this).css('opacity', '1');
              $('.page-user-login .form-type-password input').prop('type', type);
            });
          }

          $('.page-user-login .alert-block.alert-success .close').text(' ');
          $('.page-user-login .alert-block.alert-success .close').text('Ок');

          //Delete whitespaces from phone form
          var txt = $(".page-user-register .field-name-field-tel input");
          var func = function() {
            txt.val(txt.val().replace(/\s/g, ''));
          };
          txt.keyup(func).blur(func);
          //

          $('.page-user-register .field-name-field-tel input').click(function() {
            if (!$(this).val().length) {
              $(this).val('+380');
            }
          });

          checkBookName('.front #block-bookbox-manualhits ul>li');
          checkBookName('.front #block-bookbox-companyhits ul>li');
          checkBookName('.front #block-bookbox-newbyadmin ul>li');
          checkBookName('body:not(.front) .block-bookbox ul>li');
          checkBookName('.page-books .view-content>.views-row');
          checkBookName('body.books .view-content>.views-row');
          checkBookName('body.collection .view-content>.views-row');
          checkBookName('.node-type-book .inner-block-bookbox>li');
          checkBookName('.publishers .view-content>.views-row');
          checkBookName('.book-search .view-content>article');
          checkBookName('body.authors .view-content .views-row');

          $('.navbar .menu.secondary').click(function() {
            if($(window).width() < 768) {
              $('body').toggleClass('openNav');
            }
          });

          //Initialization of pagination for Main page
          BookBoxPagination('.front', '.block-bookbox');
          BookBoxPagination('.node-type-book', '.block-bookbox');
          BookBoxBlockBuilder('.page-user- .visible-desktop #order>form>div', '.book-container');
          BookBoxBlockBuilder('.page-user- .visible-desktop #read>form>div', '.book-container');
          BookBoxBlockBuilder('.page-user- .visible-desktop #history', '.node-book');
          BookBoxBlockBuilder('.page-user- .visible-desktop #favs>.view-user-wishlist>.view-content', '.views-row');
          BookBoxBlockBuilder('body.authors #block-system-main .view-content', '.views-row');

          changeFormSelect('.books.category .col-sm-3 #edit-items-per-page','.books.category .col-sm-9 #edit-items-per-page');
          changeFormSelect('.page-books .col-sm-3 #edit-items-per-page','.page-books .col-sm-9 #edit-items-per-page');
          changeFormSelect('.collection .col-sm-3 #edit-items-per-page','.collection .col-sm-9 #edit-items-per-page');
          changeFormSelect('.page-books-company-hits .col-sm-3 #edit-items-per-page','.page-books-company-hits .col-sm-9 #edit-items-per-page');

          $('.books.category .col-sm-9 #edit-items-per-page, ' +
              '.collection .col-sm-9 #edit-items-per-page, ' +
              '.page-books-company-hits .col-sm-9 #edit-items-per-page, ' +
              '.page-books .col-sm-9 #edit-items-per-page').change(function() {
            var thisValue = $(this).val();
            $('.books.category .col-sm-3 #edit-items-per-page, ' +
                '.collection .col-sm-3 #edit-items-per-page, ' +
                '.page-books-company-hits .col-sm-3 #edit-items-per-page, ' +
                '.page-books .col-sm-3 #edit-items-per-page').val(thisValue).trigger('change');
          });

          //Add placeholder to finder
          $('.search-block .finder-element-title').attr('placeholder', 'Пошук за назвою та автором');
          $('.page-book-search .main-container .finder-element-title').attr('placeholder', 'Пошук за назвою та автором');

          if($(window).width() < 992) {
            var activeCategory = $('.category #block-system-main-menu .menu.nav>.active-trail>a').text();
            $('.category #block-bookbox-sidebarfitlerblockcompany').prepend('<button class="comp-block-btn">Всі книги</button>');
            $('<button class="category-block-btn">Обрати</button>').insertAfter('.category #block-system-main-menu .block-title');
            $('<button class="lang-block-btn">Обрати</button>').insertAfter('.category #edit-lang-wrapper>label');
            $('<button class="collection-block-btn">Обрати</button>').insertAfter('.category #block-views-collection-list-block-1 .block-title');
            $('.category .category-block-btn').text(activeCategory);

            $('.page-books #block-bookbox-sidebarfitlerblockcompany').prepend('<button class="comp-block-btn">Всі книги</button>');
            $('<button class="category-block-btn">Обрати</button>').insertAfter('.page-books #block-system-main-menu .block-title');
            $('<button class="lang-block-btn">Обрати</button>').insertAfter('.page-books #edit-lang-wrapper>label');
            $('<button class="collection-block-btn">Обрати</button>').insertAfter('.page-books #block-views-collection-list-block-1 .block-title');

            $('.collection #block-bookbox-sidebarfitlerblockcompany').prepend('<button class="comp-block-btn">Всі книги</button>');
            $('<button class="category-block-btn">Обрати</button>').insertAfter('.collection #block-system-main-menu .block-title');
            $('<button class="lang-block-btn">Обрати</button>').insertAfter('.collection #edit-lang-wrapper>label');
            $('<button class="collection-block-btn">Обрати</button>').insertAfter('.collection #block-views-collection-list-block-1 .block-title');

            if($('body').hasClass('hits') || $('body').hasClass('new') || $('body').hasClass('company-hits')) {
              $('.comp-block-btn').text($('.page-header').text());
            }
          }

          //For FAQ page

        if($(window).width() < 768 && $('body').hasClass('page-faq')) {
            var countOfBlocks = $('#views-bootstrap-tab-1 .tab-pane').length;

            for (var i = 0; i< countOfBlocks; i++) {
              var titleText = $('a[href="#tab-1-' + i + '"]').text();

              $('#tab-1-' + i).prepend('<a href="#link-'+ i +'" class="open-faq-link">' + titleText + '</a>');
              $('#tab-1-' + i + '>.views-field-body').addClass('open-faq-block');
              $('#tab-1-' + i + '>.views-field-body').attr('id', 'link-' + i);
            }
        }

        //Change structure for Front-page

        if ($('body.front').length && $(window).width() < 768) {
            $('#block-bookbox-manualhits').append($('#block-bookbox-manualhits > a'));
            $('#block-bookbox-companyhits').append($('#block-bookbox-companyhits > a'));
            $('#block-bookbox-newbyadmin').append($('#block-bookbox-newbyadmin > a'));
        }

            // Add slideDown animation to Bootstrap dropdown when expanding.
            $('.category .col-sm-3 #block-system-main-menu .dropdown, .page-books .col-sm-3 #block-system-main-menu .dropdown, .collection .col-sm-3 #block-system-main-menu .dropdown').on('show.bs.dropdown', function() {
              $(this).find('.dropdown-menu').first().stop(true, true).slideDown();
            });
            // Add slideUp animation to Bootstrap dropdown when collapsing.
            $('.category .col-sm-3 #block-system-main-menu .dropdown, .page-books .col-sm-3 #block-system-main-menu .dropdown, .collection .col-sm-3 #block-system-main-menu .dropdown').on('hide.bs.dropdown', function() {
              $(this).find('.dropdown-menu').first().stop(true, true).slideUp();
            });

          //Open Dropdown on open category
          if($(window).width() > 991) {
            $('.category .col-sm-3 .menu.nav>.active-trail>a').click();
          }

          $('.category #block-bookbox-sidebarfitlerblockcompany a').click(function() {
            var newCategory = $(this).text();
            $('.lang button').text(newCategory);
          });

          $('#block-bookbox-sidebarfitlerblockcompany .comp-block-btn').click(function(e) {
            e.preventDefault();
            $('#block-bookbox-sidebarfitlerblockcompany>ul').toggleClass('visible');
            $(this).toggleClass('open');
            $('#block-bookbox-sidebarfitlerblockcompany').toggleClass('open-block');
          });

          $('#block-system-main-menu .category-block-btn').click(function(e) {
            e.preventDefault();
            $('#block-system-main-menu .menu.nav').toggleClass('visible');
            $(this).toggleClass('open');
            $('#block-system-main-menu').toggleClass('open-block');
          });

          $('#edit-lang-wrapper .lang-block-btn').click(function(e) {
            e.preventDefault();
            $('#edit-lang-wrapper .views-widget').toggleClass('visible');
            $(this).toggleClass('open');
            $('#block-views-exp-taxonomy-term-page').toggleClass('open-block');
            $('#block-views-exp-books-page-2').toggleClass('open-block');
            $('#block-views-exp-books-page-1').toggleClass('open-block');
            $('#block-views-exp-books-page').toggleClass('open-block');
          });

          $('#block-views-collection-list-block-1 .collection-block-btn').click(function(e) {
            e.preventDefault();
            $('#block-views-collection-list-block-1 .view-collection-list').toggleClass('visible');
            $(this).toggleClass('open');
            $('#block-views-collection-list-block-1').toggleClass('open-block');
          });

          $('.alert.alert-block.alert-success.messages.status .close, .alert.alert-block.alert-success.messages.status .btn').click(function() {
            $('body').removeClass('open-alert');
            $('body').removeClass('modal-open');
          });

          $('.scroll-to').click(function(e) {
            e.preventDefault();
            var target = $(this).attr('href');
            var offsetScroll = $(target).offset().top;
            $('html, body').animate( { scrollTop:  offsetScroll}, 800);
          });

          var firstChild = $('.text-center>ul.pagination>li:first-child span').text();
          if(firstChild === '1') {
            $('.text-center>ul.pagination>li').first().addClass('first');
          }

          $(document).on('click', '.category .col-sm-3 .menu.nav .dropdown-menu', function (e) {
            e.stopPropagation();
          });
          $(document).on('click', '.category .main-container *', function (e) {
            e.stopPropagation();
          });

          $(document).on('click', '.page-books .col-sm-3 .menu.nav .dropdown-menu', function (e) {
            e.stopPropagation();
          });
          $(document).on('click', '.page-books .main-container *', function (e) {
            e.stopPropagation();
          });

          $('.page-faq .panel-collapse').on('shown.bs.collapse', function () {
            $('.panel-collapse.in').not(this).siblings('.panel-heading').find('a').click();
          });

          $('.page-faq .panel-heading a').click(function() {
            var currentLink = $(this).attr('aria-controls'),
                currentTab = $('.page-faq .panel-default.' + currentLink);

            currentTab.toggleClass('open');
          });


          $('.page-user- .panel-collapse').on('shown.bs.collapse', function () {
            $('.profile .panel-collapse.in').not(this).siblings('.panel-heading').find('a').click();
          });

          $('.node-type-book .change-lang a').click(function(e) {
            e.preventDefault();
            $('.node-type-book .books-translations').toggleClass('open');
          });

          $('.navbar .show-finder').click(function() {
            $('.navbar').addClass('finder-open');
            $('.show-finder.bg').addClass('visible');
          });

          $('.show-finder.bg').click(function() {
            $('.navbar').removeClass('finder-open');
            $('.show-finder.bg').removeClass('visible');
          });

          //VALIDATE OF FORMS

        $('.page-node-893 button.webform-submit').click(function(e) {
          e.preventDefault();
          e.stopPropagation();
          var text = validateTextField('#edit-submitted-message');

          if (text) {
            $('#webform-client-form-892').submit();
          }
        });

        $('.page-user-edit #edit-submit').click(function(e) {
          e.preventDefault();
          e.stopPropagation();


          var tel = validateTel('#edit-field-tel-und-0-value'),
              newPass = validateNewPass($('#edit-pass-pass1'), $('#edit-pass-pass2'));

          if (tel && newPass) {
            $('#user-profile-form').submit();
          }
        });

        $('.page-user-edit .form-text.error').click (function() {
          $(this).removeClass('error');
          $(this).attr('placeholder', '');
        });

        $('.form-type-password-confirm .form-text').click(function() {
          $(this).css('border', 'initial');
          $(this).css('border-bottom', 'initial');
        });

        $('#webform-client-form-892 textarea').click(function() {
          $(this).css('border','');
          $(this).css('border-bottom', '');
          $(this).css('background','');
          $(this).css('color','');
          $(this).removeClass('webform-error');
          $(this).attr('placeholder', '');
        });

        //page-faq

        $('.open-faq-link').click(function(e) {
          e.preventDefault();
          e.stopPropagation();

          var textAddress = $(this).attr('href'),
              inHeight = $(textAddress + ' .field-content').height() + 15;

          $('.open-faq-link.opened-link').not(this).click();
          $(this).toggleClass('opened-link');
          $(textAddress).css('max-height', inHeight + 'px');
          if($(textAddress).hasClass('opened')) {
            $(textAddress).css('max-height', '0');
          }
          $(this).siblings('.open-faq-block').toggleClass('opened');

          $('.open-faq-block:not('+textAddress+')').css('max-height', '0');
        });
        $('a[href="#link-0"]').click();

        if($(window).width() < 768) {
          $('.open-faq-block.opened .panel-title>a').click(function() {
            setTimeout(function(){
              var inHeight = $('.open-faq-block.opened .field-content').height() + 22;
              $('.open-faq-block.opened').css('max-height', inHeight + 'px');
            }, 200);

          });
        }

        //Sliders
          $('.view-front-slider>.view-content').slick({
            autoplay: true,
            autoplaySpeed: 8000,
            dots: true,
            infinite: true,
            speed: 350,
            fade: true,
            cssEase: 'linear'
          });

          $('.box-pagination').slick({
            autoplay: false,
            dots: true,
            infinite: true,
            fade: false,
            cssEase: 'none'
          });

          if($(window).width() >= 768 ) {
            $('.front #block-views-collections-slider-block .view-content').slick({
              lazyLoad: 'ondemand',
              dots: true,
              slidesToScroll: 2,
              slidesToShow:2
            });
          } else {
            $('.front #block-views-collections-slider-block .view-content').slick({
              lazyLoad: 'ondemand',
              dots: true,
              slidesToScroll: 1,
              slidesToShow: 1
            });
          }
        });

        $( document ).on( "click", ".sort-submenu a", function() {
            var $this = $(this),
                value = $this.data('value'),
                $select = $('.view-taxonomy-term .views-exposed-form select');

            if (value == '1') {
                value = "commerce_stock_value";
            }

            if (value == '2') {
                value = "field_hit_value";
            }

            $select.val(value);
            $('#edit-submit-taxonomy-term').click();

            $('.sort-submenu a').removeClass('active');
            $this.addClass('active');

        });

        $('.page-user-register .field-name-field-agree label').bind("DOMSubtreeModified",function(){
            $(this).find('div.error').appendTo(".page-user-register .field-name-field-agree .form-item");
        });

        $(".page-user-register #edit-field-company-und").change(function () {
            $( "select option:selected" ).each(function() {
                var cid = $(this).val(),
                tiptext = $( "#clist li:contains(" + cid + ")" ).data('d');
            });
        }).change();

        $(window).on('resize', function() {
            clearTimeout(resizeTimer);
            resizeTimer = setTimeout(function() {

            }, 250);
        });

        $('#show-filters').click(function() {
            $('body').toggleClass('open-filters');
        });

        $('.primary-nav .dropdown-toggle').click(function() {
            var $url = $(this).attr('href');
            window.location.href = $url;
        });

        var $primaryDropdowns = $('.primary-nav .dropdown-toggle');
        $primaryDropdowns.each(function( index ) {
            var $this = $(this);
            $('<a data-target="#" class="new-dropdown-toggle" data-toggle="dropdown"></a>').insertAfter($this);
        });

    });
}(jQuery));
