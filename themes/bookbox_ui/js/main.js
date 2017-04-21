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

        $(".col-sm-4").niceScroll({cursorcolor:"#999", mousescrollstep:60}); // end of nicescroll

    });
}(jQuery));
