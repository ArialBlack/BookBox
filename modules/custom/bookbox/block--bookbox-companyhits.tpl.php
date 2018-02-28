<?php
  //Темлейт блоку http://prntscr.com/i8dts9
?>

<?php if($bookslist !=null): ?>

  <h2>Популярне в <?php print $name;?></h2>
  <a href="/books/company-hits">Дивитись більше</a>

  <?php print $bookslist; ?>

<?php endif; ?>



