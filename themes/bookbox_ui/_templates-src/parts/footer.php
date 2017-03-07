<?php if (!empty($page['footer'])): ?>
    <footer class="footer">
        <div class="container">
            <?php print $messages; ?>
            <?php print render($page['footer']); ?>
        </div>
    </footer>
<?php endif; ?>