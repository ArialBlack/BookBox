<?php
//Темплейт блоку http://prntscr.com/i8dtxv
?>

<?php if($bookslist !=null): ?>

  <h2>Нові надходження</h2>
  <a href="/books/new">Дивитись більше</a>

  <?php print $bookslist; ?>

<?php endif; ?>
