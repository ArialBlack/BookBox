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

            $('body').append('<div class="scroll-up"></div>');

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

            $('.scroll-up').click(function() {
                $('html, body').animate({ scrollTop: 0}, 1000 );
            });

            $(window).scroll(function(){
                if ($(this).scrollTop() > 300 && $(this).width() < 768 ) {
                    $('.scroll-up').fadeIn();
                } else {
                    $('.scroll-up').fadeOut();
                }
            });

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

                // if ( $('.collapse-nav-items').length && $(window).width() < 992) {
                //    $('.primary-nav>ul').append($('.collapse-nav-items>ul>li'));
                //    $('.collapse-nav-items').remove();
                // }
            })

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

        });

        $(window).on('load', function() {
            if($('.role-authenticated-user #new-changes').length > 0) {
                var visited = readCookie('visitedBookbox');

                //user not visited in this month and last login was before changes
                if ((!visited || visited !== "true") && (lastLoginWasBeforeChanges)){
                    createCookie('visitedBookbox', "true", 30);
                    $('#new-changes').modal('show');
                }
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

                $(".page-user-register #edit-mail--2").attr('placeholder', tiptext);
            });
        }).change();

        $(window).on('resize', function() {
            clearTimeout(resizeTimer);
            resizeTimer = setTimeout(function() {

            }, 250);
        });

        //$('#views-exposed-form-booksearch-page .icon-search').click(function() {
        $('.search-block .svg-icon').click(function() {
            //console.log('--------------c');
            $('body').addClass('open-search');
        });

        $(document).mouseup(function (e) {
            var container = $(".search-block");

            if (!container.is(e.target)
                && container.has(e.target).length === 0) {
                $('body').removeClass('open-search');
            }
            ////
            var filters = $('.sidebar-filters');

            if (!filters.is(e.target)
                && filters.has(e.target).length === 0) {
                $('body').removeClass('open-filters');
            }
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

        //NICESCROLL
        var nice = $("html").niceScroll({cursorcolor:"#999", mousescrollstep:60});  // The document page (body)

        if ($(window).width() > 1024) {
            $(".col-sm-4").niceScroll({cursorcolor:"#999", mousescrollstep:60}); // end of nicescroll
        };

        if ($('.col-sm-8').height() < $('aside.col-sm-4').height() && $(window).width() <= 1024 && $(window).width() > 767) {
            $('.col-sm-8').css('height', $('aside.col-sm-4').height());
        };

    });
}(jQuery));
