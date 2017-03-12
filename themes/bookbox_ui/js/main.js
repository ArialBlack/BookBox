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

        $( document ).ready(function() {
            console.log('--------------run');
            /////////////////////////////////////
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



        });

        $(window).on('resize', function() {
            clearTimeout(resizeTimer);
            resizeTimer = setTimeout(function() {

            }, 250);
        });

        $('#views-exposed-form-booksearch-page .icon-search').click(function() {
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

        //NICESCROLL
        var nice = $("html").niceScroll({cursorcolor:"#999"});  // The document page (body)

        $(".col-sm-4").niceScroll({cursorcolor:"#999"}); // end of nicescroll
         
    });
}(jQuery));