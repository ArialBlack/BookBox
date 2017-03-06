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

            if (!container.is(e.target) // if the target of the click isn't the container...
                && container.has(e.target).length === 0) // ... nor a descendant of the container
            {
                container.hide();
            }
        });
         
    });
}(jQuery));