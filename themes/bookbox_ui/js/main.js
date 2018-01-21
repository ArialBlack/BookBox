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
          console.log(index);
          console.log(BooksCount);

          $(index).append('<div class="book-inner-block"></div>');
          for (var i=1; i<=BooksCount; i++) {
            $(index + ' ' + '.book-inner-block').append($(BookContainer + ':first'));
          }
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

        $(document).ajaxStop(function() {
            var $label = $('.book-labels .field');
            $label.each(function( index ) {
                var $text = $(this).find('.field-item').text();
                if ($text.length < 3) {
                    $(this).remove();
                }
            });
        });

        $('#userreglink').appendTo("#edit-actions"); //todo in backend
        $('.sort-submenu').insertAfter(".page-header");

        $( document ).ready(function() {
            //console.log(Drupal.settings.firstLogin);

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
            $('.publishers #block-system-main .term-listing-heading').detach();
            // BookBoxPagination('.publishers', '#block-system-main');
          BookBoxBlockBuilder('.page-user- .visible-desktop #order>form>div', '.book-container');
          BookBoxBlockBuilder('.page-user- .visible-desktop #read>form>div', '.book-container');
          BookBoxBlockBuilder('.page-user- .visible-desktop #history', '.node-book');
          BookBoxBlockBuilder('.page-user- .visible-desktop #favs>.view-user-wishlist>.view-content', '.views-row');
          BookBoxBlockBuilder('body.authors #block-system-main', '.node-book');

          $('.page-user- .panel-collapse').on('shown.bs.collapse', function () {
            $('.profile .panel-collapse.in').not(this).siblings('.panel-heading').find('a').click();
          });

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

          $('.node-type-book .change-lang a').click(function(e) {
            e.preventDefault();
            $('.node-type-book .books-translations').toggleClass('open');
          });
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

                // $(".page-user-register #edit-mail--2").attr('placeholder', tiptext);
            });
        }).change();

        $(window).on('resize', function() {
            clearTimeout(resizeTimer);
            resizeTimer = setTimeout(function() {

            }, 250);
        });


        // $(document).mouseup(function (e) {
        //     var container = $(".search-block");
        //
        //     if (!container.is(e.target) && container.has(e.target).length === 0) {
        //         $('body').removeClass('open-search');
        //     }
        //     ////
        //     var filters = $('.sidebar-filters');
        //
        //     if (!filters.is(e.target)
        //         && filters.has(e.target).length === 0) {
        //         $('body').removeClass('open-filters');
        //     }
        // });

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
