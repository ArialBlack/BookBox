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

          //Changes count of book-blocks relatively from the device size.
          // if ($(window).width() <= 991 && $(window).width() >= 741) {
          //   var allowBookCount = 8;
          //
          // } else if ($(window).width() <= 740) {
          //   allowBookCount = 4;
          // }
          //
          // if (booksCount > allowBookCount) {
          //   for (var b = 0; b < (booksCount - allowBookCount); b++ ) {
          //     console.log('detach works');
          //     $(book + ':last-child').detach();
          //   }
          // }
          //
          // booksCount= $(book).length;

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
          // console.log(index);
          // console.log(BooksCount);

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
          // console.log('checking book name');
          if ($(bookBlock + ':nth-child('+ tb +' ) h4').text().length > 32) {
            //console.log('book name is too long');
            var newBookName = $(bookBlock + ':nth-child('+ tb +' ) h4').text().substr(0, 31);
            $(bookBlock + ':nth-child('+ tb +' ) h4').text(newBookName + '...');
          }
        }
      }

      function checkBookName2(bookBlock, countOfChar) {
        for(var tb = 0; tb<$(bookBlock).length; tb++) {
          // console.log('checking book name');
          if ($(bookBlock + ':nth-child('+ tb +' ) h4').text().length > countOfChar) {
            //console.log('book name is too long');
            var newBookName = $(bookBlock + ':nth-child('+ tb +' ) h4').text().substr(0, countOfChar-1);
            $(bookBlock + ':nth-child('+ tb +' ) h4').text(newBookName + '...');
          }
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

          $('#autocomplete .show-all a').on('click', function(e) {
            e.preventDefault();

            $('.search-block button[type="submit"]').click();

            setTimeout(function(){
              $('.search-block button[type="submit"]').click();
            }, 250);
          });

          checkBookName2('#autocomplete ul>li', '37');

          // $('.search-block button[type="submit"]').click(function() {
          //   console.log('2xclick');
          // });
        });

        $('#userreglink').appendTo("#edit-actions"); //todo in backend
        $('.sort-submenu').insertAfter(".page-header");

        function searchResultsActions() {
            if($('.region-precontent #finder-block-content_finder-wrapper form').length > 0) {
                var sString = $('#finder-block-content_finder form input.finder-element').val();

                console.log(sString);
                if($('.view-search-results-div').length > 0) {
                    $('.view-search-results-div').find('span').text(sString);
                }

                $('.view-search-results-div').insertAfter( ".region-precontent #finder-block-content_finder-wrapper" );
            }
        }

        $( document ).ready(function() {
            //console.log(Drupal.settings.firstLogin);

            searchResultsActions();

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
            })

            if ($(window).width() <768) {
                $('.page-faq #block-system-main .view-id-faq .nav-tabs .active').append($('.page-faq #block-system-main .view-id-faq .tab-content'));

                $('.node-type-book .mobile.visible-xs .description-tabs-mobile .nav-tabs .active').append($('.node-type-book .mobile.visible-xs .description-tabs-mobile .tab-content'));
            }

            $(window).resize(function(){
                if ($(this).width() < 768 && $('.page-faq #block-system-main .view-id-faq .nav-tabs li.active').children().length == 1) {
                    $('.page-faq #block-system-main .view-id-faq .nav-tabs .active').append($('.page-faq #block-system-main .view-id-faq .tab-content'));
                } else if ( $(this).width() >= 768 ) {
                    $('.page-faq #block-system-main .view-id-faq .tab-content').css('display', 'block');
                    $('.page-faq #block-system-main .view-id-faq #views-bootstrap-tab-1').append($('.page-faq #block-system-main .view-id-faq .tab-content'));
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

            $('.node-type-book .mobile.visible-xs .description-tabs-mobile .nav-tabs li').click(function(){
                if ($(window).width() <768) {
                    if (!$(this).hasClass('active')) {
                        $('.node-type-book .mobile.visible-xs .description-tabs-mobile .tab-content').css('display','none');
                        $(this).append($('.node-type-book .mobile.visible-xs .description-tabs-mobile .tab-content'));
                        $('.node-type-book .mobile.visible-xs .description-tabs-mobile .tab-content').slideToggle(300, function(){
                            var offsetActiveBook = $('.node-type-book .mobile.visible-xs .description-tabs-mobile .tab-pane.active').parent().parent().offset().top + 5;
                            $('html, body').animate( { scrollTop: offsetActiveBook }, 300 );
                        });
                    } else {
                        $('.node-type-book .mobile.visible-xs .description-tabs-mobile .tab-content').slideToggle();
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
            // console.log($(this).val().length);
            if (!$(this).val().length) {
              $(this).val('+380');
            }
          });

          checkBookName('.block-bookbox ul>li');
          checkBookName('.page-books .view-content>.views-row');
          checkBookName('body.books .view-content>.views-row');
          checkBookName('body.collection .view-content>.views-row');
          checkBookName('.node-type-book .inner-block-bookbox>li');
          checkBookName('.publishers .view-content>.views-row');
          checkBookName('.book-search .view-content>article');

            $('.navbar .dropdown-toggle .user-name').click(function() {
              // $('body').toggleClass('openNav');
            });

          $('.navbar .menu.secondary').click(function() {
            if($(window).width() <= 768) {
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
          changeFormSelect('.books.category .col-sm-3 #edit-sort-by','.books.category .col-sm-9 #edit-sort-by');
          changeFormSelect('.page-books .col-sm-3 #edit-items-per-page','.page-books .col-sm-9 #edit-items-per-page');
          changeFormSelect('.page-books .col-sm-3 #edit-sort-by','.page-books .col-sm-9 #edit-sort-by');

          $('.books.category .col-sm-9 #edit-items-per-page').change(function() {
            var thisValue = $(this).val();
            $('.books.category .col-sm-3 #edit-items-per-page').val(thisValue).trigger('change');
          });
          $('.books.category .col-sm-9 #edit-sort-by').change(function() {
            var thisValue = $(this).val();
            $('.books.category .col-sm-3 #edit-sort-by').val(thisValue).trigger('change');
          });

          $('.page-books .col-sm-9 #edit-items-per-page').change(function() {
            var thisValue = $(this).val();
            $('.page-books .col-sm-3 #edit-items-per-page').val(thisValue).trigger('change');
          });
          $('.page-books .col-sm-9 #edit-sort-by').change(function() {
            var thisValue = $(this).val();
            $('.page-books .col-sm-3 #edit-sort-by').val(thisValue).trigger('change');
          });

          //Add placeholder to finder
          $('.search-block .finder-element-title').attr('placeholder', 'Пошук за назвою та (або) автором');
          $('.page-book-search .main-container .finder-element-title').attr('placeholder', 'Пошук за назвою та (або) автором');

          if($(window).width() < 992) {
            var activeCategory = $('.category #block-system-main-menu .menu.nav>.active-trail>a').text();
            $('.category #block-bookbox-sidebarfitlerblockcompany').prepend('<button class="comp-block-btn">Хіти</button>');
            $('<button class="category-block-btn">Обрати</button>').insertAfter('.category #block-system-main-menu .block-title');
            $('<button class="lang-block-btn">Обрати</button>').insertAfter('.category #edit-lang-wrapper>label');
            $('<button class="collection-block-btn">Обрати</button>').insertAfter('.category #block-views-collection-list-block-1 .block-title');
            $('.category .category-block-btn').text(activeCategory);

            $('.page-books #block-bookbox-sidebarfitlerblockcompany').prepend('<button class="comp-block-btn">Хіти</button>');
            $('<button class="category-block-btn">Обрати</button>').insertAfter('.page-books #block-system-main-menu .block-title');
            $('<button class="lang-block-btn">Обрати</button>').insertAfter('.page-books #edit-lang-wrapper>label');
            $('<button class="collection-block-btn">Обрати</button>').insertAfter('.page-books #block-views-collection-list-block-1 .block-title');

            if($('body').hasClass('hits') || $('body').hasClass('new') || $('body').hasClass('company-hits')) {
              $('.comp-block-btn').text($('.page-header').text());
            }
          }

            // Add slideDown animation to Bootstrap dropdown when expanding.
            $('.category .col-sm-3 #block-system-main-menu .dropdown').on('show.bs.dropdown', function() {
              $(this).find('.dropdown-menu').first().stop(true, true).slideDown();
            });
            // Add slideUp animation to Bootstrap dropdown when collapsing.
            $('.category .col-sm-3 #block-system-main-menu .dropdown').on('hide.bs.dropdown', function() {
              $(this).find('.dropdown-menu').first().stop(true, true).slideUp();
            });

          // Add slideDown animation to Bootstrap dropdown when expanding.
          $('.page-books .col-sm-3 #block-system-main-menu .dropdown').on('show.bs.dropdown', function() {
            $(this).find('.dropdown-menu').first().stop(true, true).slideDown();
          });
          // Add slideUp animation to Bootstrap dropdown when collapsing.
          $('.page-books .col-sm-3 #block-system-main-menu .dropdown').on('hide.bs.dropdown', function() {
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
          });

          $('#block-views-collection-list-block-1 .collection-block-btn').click(function(e) {
            e.preventDefault();
            $('#block-views-collection-list-block-1 .view-collection-list').toggleClass('visible');
            $(this).toggleClass('open');
            $('#block-views-collection-list-block-1').toggleClass('open-block');
          });

          $('.scroll-to').click(function(e) {
            e.preventDefault();
            var target = $(this).attr('href');
            var offsetScroll = $(target).offset().top;
            $('html, body').animate( { scrollTop:  offsetScroll}, 1400);
          });

          var firstChild = $('.text-center>ul.pagination>li:first-child span').text();
          if(firstChild === '1') {
            $('.text-center>ul.pagination>li').first().addClass('first');
          }

          //todo
          // $('.book-card').parent().mouseup(function() {
          //   console.log('click');
          //   $(this).find('.book-card').click();
          //   // $(this).click();
          // });

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

          $('.page-faq .panel-default').not('.open').click(function() {
            // $('.page-faq .panel-default.open .panel-heading a').click();
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
