(function ($) {
    $(function() {

        var resizeTimer;
        
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

        $('#views-exposed-form-booksearch-page .fa-search').click(function() {
            console.log('--------------c');
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
         
    });
}(jQuery));