<?php
/**
 * @file
 * all_views.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function all_views_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'Store_mass_edit';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Адмін-склад-редагування';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Склад';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ще';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Застосувати';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Скинути';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Впорядкувати за';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Зрост';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Спад';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'editableviews_table';
  $handler->display->display_options['style_options']['columns'] = array(
    'sku' => 'sku',
    'field_nni' => 'field_nni',
    'title' => 'title',
    'field_origin_name' => 'field_origin_name',
    'commerce_stock' => 'commerce_stock',
    'field_book_author' => 'field_book_author',
    'field_book_publisher' => 'field_book_publisher',
    'field_book_category' => 'field_book_category',
    'field_lang' => 'field_lang',
    'field_isnew' => 'field_isnew',
    'field_hit' => 'field_hit',
    'field_bookbox_rec' => 'field_bookbox_rec',
    'edit_node' => 'edit_node',
    'count' => 'count',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'sku' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_nni' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_origin_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_stock' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_book_author' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_book_publisher' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_book_category' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lang' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_isnew' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_hit' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_bookbox_rec' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'count' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['batch_size'] = '10';
  /* Зв'язок: Вміст: Товари за посиланнями */
  $handler->display->display_options['relationships']['field_bookfields_product_id']['id'] = 'field_bookfields_product_id';
  $handler->display->display_options['relationships']['field_bookfields_product_id']['table'] = 'field_data_field_bookfields';
  $handler->display->display_options['relationships']['field_bookfields_product_id']['field'] = 'field_bookfields_product_id';
  $handler->display->display_options['relationships']['field_bookfields_product_id']['required'] = TRUE;
  /* Поле: Торгівля: Товар: Артикул */
  $handler->display->display_options['fields']['sku']['id'] = 'sku';
  $handler->display->display_options['fields']['sku']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['sku']['field'] = 'sku';
  $handler->display->display_options['fields']['sku']['relationship'] = 'field_bookfields_product_id';
  $handler->display->display_options['fields']['sku']['link_to_product'] = 0;
  /* Поле: Вміст: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Вміст: Новинка (editable) */
  $handler->display->display_options['fields']['field_isnew_editable']['id'] = 'field_isnew_editable';
  $handler->display->display_options['fields']['field_isnew_editable']['table'] = 'field_data_field_isnew';
  $handler->display->display_options['fields']['field_isnew_editable']['field'] = 'field_isnew_editable';
  $handler->display->display_options['fields']['field_isnew_editable']['label'] = 'Новинка -ред.';
  $handler->display->display_options['fields']['field_isnew_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['field_isnew_editable']['suppress_label'] = 0;
  $handler->display->display_options['fields']['field_isnew_editable']['suppress_description'] = 0;
  /* Поле: Вміст: Хіт (editable) */
  $handler->display->display_options['fields']['field_hit_editable']['id'] = 'field_hit_editable';
  $handler->display->display_options['fields']['field_hit_editable']['table'] = 'field_data_field_hit';
  $handler->display->display_options['fields']['field_hit_editable']['field'] = 'field_hit_editable';
  $handler->display->display_options['fields']['field_hit_editable']['label'] = 'Хіт -ред.';
  $handler->display->display_options['fields']['field_hit_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['field_hit_editable']['suppress_label'] = 0;
  $handler->display->display_options['fields']['field_hit_editable']['suppress_description'] = 0;
  /* Поле: Вміст: Рекомендуємо (editable) */
  $handler->display->display_options['fields']['field_bookbox_rec_editable']['id'] = 'field_bookbox_rec_editable';
  $handler->display->display_options['fields']['field_bookbox_rec_editable']['table'] = 'field_data_field_bookbox_rec';
  $handler->display->display_options['fields']['field_bookbox_rec_editable']['field'] = 'field_bookbox_rec_editable';
  $handler->display->display_options['fields']['field_bookbox_rec_editable']['label'] = 'Рекомендуємо -ред.';
  $handler->display->display_options['fields']['field_bookbox_rec_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['field_bookbox_rec_editable']['suppress_label'] = 0;
  $handler->display->display_options['fields']['field_bookbox_rec_editable']['suppress_description'] = 0;
  /* Поле: Торгівля: Товар: Товарні запаси */
  $handler->display->display_options['fields']['commerce_stock']['id'] = 'commerce_stock';
  $handler->display->display_options['fields']['commerce_stock']['table'] = 'field_data_commerce_stock';
  $handler->display->display_options['fields']['commerce_stock']['field'] = 'commerce_stock';
  $handler->display->display_options['fields']['commerce_stock']['relationship'] = 'field_bookfields_product_id';
  $handler->display->display_options['fields']['commerce_stock']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Поле: Торгівля: Товар: Абсолютний сток (editable) */
  $handler->display->display_options['fields']['field_absolute_stock_editable']['id'] = 'field_absolute_stock_editable';
  $handler->display->display_options['fields']['field_absolute_stock_editable']['table'] = 'field_data_field_absolute_stock';
  $handler->display->display_options['fields']['field_absolute_stock_editable']['field'] = 'field_absolute_stock_editable';
  $handler->display->display_options['fields']['field_absolute_stock_editable']['relationship'] = 'field_bookfields_product_id';
  $handler->display->display_options['fields']['field_absolute_stock_editable']['label'] = 'Абсолютний сток- ред.';
  $handler->display->display_options['fields']['field_absolute_stock_editable']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 0,
  );
  $handler->display->display_options['fields']['field_absolute_stock_editable']['widget_type'] = '0';
  $handler->display->display_options['fields']['field_absolute_stock_editable']['suppress_label'] = 0;
  $handler->display->display_options['fields']['field_absolute_stock_editable']['suppress_description'] = 0;
  /* Критерій впорядкування: Вміст: Дата публікації */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Критерій фільтрування: Вміст: Опубліковано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерій фільтрування: Вміст: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'book' => 'book',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/bookbox/store-massedit';
  $translatables['Store_mass_edit'] = array(
    t('Master'),
    t('Склад'),
    t('ще'),
    t('Застосувати'),
    t('Скинути'),
    t('Впорядкувати за'),
    t('Зрост'),
    t('Спад'),
    t('Товари, на які посилається поле field_bookfields'),
    t('Артикул'),
    t('Новинка -ред.'),
    t('Хіт -ред.'),
    t('Рекомендуємо -ред.'),
    t('Товарні запаси'),
    t('Абсолютний сток- ред.'),
    t('Page'),
  );
  $export['Store_mass_edit'] = $view;

  $view = new view();
  $view->name = 'admin_store';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Адмін-склад';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Склад';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ще';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Застосувати';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Скинути';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Впорядкувати за';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Зрост';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Спад';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Елементів на сторінку';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Усе -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Зміщення';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« перша';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ попередня';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'наступна ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'остання »';
  $handler->display->display_options['style_plugin'] = 'table_megarows';
  $handler->display->display_options['style_options']['columns'] = array(
    'sku' => 'sku',
    'field_nni' => 'field_nni',
    'title' => 'title',
    'field_origin_name' => 'field_origin_name',
    'commerce_stock' => 'commerce_stock',
    'field_book_author' => 'field_book_author',
    'field_book_publisher' => 'field_book_publisher',
    'field_book_category' => 'field_book_category',
    'field_lang' => 'field_lang',
    'field_isnew' => 'field_isnew',
    'field_hit' => 'field_hit',
    'field_bookbox_rec' => 'field_bookbox_rec',
    'edit_node' => 'edit_node',
    'count' => 'count',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'sku' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_nni' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_origin_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_stock' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_book_author' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_book_publisher' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_book_category' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_lang' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_isnew' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_hit' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_bookbox_rec' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'count' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['style_options']['scroll_padding'] = '120';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Зв'язок: Вміст: Товари за посиланнями */
  $handler->display->display_options['relationships']['field_bookfields_product_id']['id'] = 'field_bookfields_product_id';
  $handler->display->display_options['relationships']['field_bookfields_product_id']['table'] = 'field_data_field_bookfields';
  $handler->display->display_options['relationships']['field_bookfields_product_id']['field'] = 'field_bookfields_product_id';
  $handler->display->display_options['relationships']['field_bookfields_product_id']['required'] = TRUE;
  /* Зв'язок: Прапори: bookmarks лічильник */
  $handler->display->display_options['relationships']['flag_count_rel']['id'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_count_rel']['field'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_count_rel']['flag'] = 'bookmarks';
  /* Поле: Торгівля: Товар: Артикул */
  $handler->display->display_options['fields']['sku']['id'] = 'sku';
  $handler->display->display_options['fields']['sku']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['sku']['field'] = 'sku';
  $handler->display->display_options['fields']['sku']['relationship'] = 'field_bookfields_product_id';
  /* Поле: Поле: Зображення обкладинки */
  $handler->display->display_options['fields']['field_nni']['id'] = 'field_nni';
  $handler->display->display_options['fields']['field_nni']['table'] = 'field_data_field_nni';
  $handler->display->display_options['fields']['field_nni']['field'] = 'field_nni';
  $handler->display->display_options['fields']['field_nni']['label'] = 'Обкладинка';
  $handler->display->display_options['fields']['field_nni']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_nni']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Поле: Вміст: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Вміст: Оригінальна назва */
  $handler->display->display_options['fields']['field_origin_name']['id'] = 'field_origin_name';
  $handler->display->display_options['fields']['field_origin_name']['table'] = 'field_data_field_origin_name';
  $handler->display->display_options['fields']['field_origin_name']['field'] = 'field_origin_name';
  /* Поле: Торгівля: Товар: Товарні запаси */
  $handler->display->display_options['fields']['commerce_stock']['id'] = 'commerce_stock';
  $handler->display->display_options['fields']['commerce_stock']['table'] = 'field_data_commerce_stock';
  $handler->display->display_options['fields']['commerce_stock']['field'] = 'commerce_stock';
  $handler->display->display_options['fields']['commerce_stock']['relationship'] = 'field_bookfields_product_id';
  $handler->display->display_options['fields']['commerce_stock']['label'] = 'Запаси';
  $handler->display->display_options['fields']['commerce_stock']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Поле: Вміст: Автор */
  $handler->display->display_options['fields']['field_book_author']['id'] = 'field_book_author';
  $handler->display->display_options['fields']['field_book_author']['table'] = 'field_data_field_book_author';
  $handler->display->display_options['fields']['field_book_author']['field'] = 'field_book_author';
  /* Поле: Вміст: Видавництво */
  $handler->display->display_options['fields']['field_book_publisher']['id'] = 'field_book_publisher';
  $handler->display->display_options['fields']['field_book_publisher']['table'] = 'field_data_field_book_publisher';
  $handler->display->display_options['fields']['field_book_publisher']['field'] = 'field_book_publisher';
  $handler->display->display_options['fields']['field_book_publisher']['label'] = 'Видавнитво';
  /* Поле: Вміст: Категорія */
  $handler->display->display_options['fields']['field_book_category']['id'] = 'field_book_category';
  $handler->display->display_options['fields']['field_book_category']['table'] = 'field_data_field_book_category';
  $handler->display->display_options['fields']['field_book_category']['field'] = 'field_book_category';
  $handler->display->display_options['fields']['field_book_category']['delta_offset'] = '0';
  /* Поле: Вміст: Мова */
  $handler->display->display_options['fields']['field_lang']['id'] = 'field_lang';
  $handler->display->display_options['fields']['field_lang']['table'] = 'field_data_field_lang';
  $handler->display->display_options['fields']['field_lang']['field'] = 'field_lang';
  /* Поле: Вміст: Новинка */
  $handler->display->display_options['fields']['field_isnew']['id'] = 'field_isnew';
  $handler->display->display_options['fields']['field_isnew']['table'] = 'field_data_field_isnew';
  $handler->display->display_options['fields']['field_isnew']['field'] = 'field_isnew';
  $handler->display->display_options['fields']['field_isnew']['type'] = 'list_key';
  /* Поле: Вміст: Хіт */
  $handler->display->display_options['fields']['field_hit']['id'] = 'field_hit';
  $handler->display->display_options['fields']['field_hit']['table'] = 'field_data_field_hit';
  $handler->display->display_options['fields']['field_hit']['field'] = 'field_hit';
  $handler->display->display_options['fields']['field_hit']['type'] = 'list_key';
  /* Поле: Вміст: Рекомендуємо */
  $handler->display->display_options['fields']['field_bookbox_rec']['id'] = 'field_bookbox_rec';
  $handler->display->display_options['fields']['field_bookbox_rec']['table'] = 'field_data_field_bookbox_rec';
  $handler->display->display_options['fields']['field_bookbox_rec']['field'] = 'field_bookbox_rec';
  $handler->display->display_options['fields']['field_bookbox_rec']['label'] = 'Bookbox рекомендує';
  $handler->display->display_options['fields']['field_bookbox_rec']['type'] = 'list_key';
  /* Поле: Вміст: Посилання на редагування */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  /* Поле: Прапори: Лічильник прапорів */
  $handler->display->display_options['fields']['count']['id'] = 'count';
  $handler->display->display_options['fields']['count']['table'] = 'flag_counts';
  $handler->display->display_options['fields']['count']['field'] = 'count';
  $handler->display->display_options['fields']['count']['relationship'] = 'flag_count_rel';
  $handler->display->display_options['fields']['count']['label'] = 'Лічильник обранного';
  $handler->display->display_options['fields']['count']['separator'] = ' ';
  /* Критерій впорядкування: Вміст: Дата публікації */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Критерій фільтрування: Вміст: Опубліковано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерій фільтрування: Вміст: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'book' => 'book',
  );
  /* Критерій фільтрування: Вміст: Заголовок */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'word';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Заголовок';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/bookbox/store';
  $translatables['admin_store'] = array(
    t('Master'),
    t('Склад'),
    t('ще'),
    t('Застосувати'),
    t('Скинути'),
    t('Впорядкувати за'),
    t('Зрост'),
    t('Спад'),
    t('Елементів на сторінку'),
    t('- Усе -'),
    t('Зміщення'),
    t('« перша'),
    t('‹ попередня'),
    t('наступна ›'),
    t('остання »'),
    t('Товари, на які посилається поле field_bookfields'),
    t('лічильник'),
    t('Артикул'),
    t('Обкладинка'),
    t('Оригінальна назва'),
    t('Запаси'),
    t('Автор'),
    t('Видавнитво'),
    t('Категорія'),
    t('Мова'),
    t('Новинка'),
    t('Хіт'),
    t('Bookbox рекомендує'),
    t('Посилання на редагування'),
    t('Лічильник обранного'),
    t('.'),
    t(' '),
    t('Заголовок'),
    t('Page'),
  );
  $export['admin_store'] = $view;

  $view = new view();
  $view->name = 'books';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'books';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Всі книги';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ще';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Застосувати';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Скинути';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Впорядкувати за';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Зрост';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Спад';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Щоб побачити результат, виберіть довільний фільтр і натисніть "Застосувати"',
          'format' => 'filtered_html',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Розширені параметри',
      'secondary_collapse_override' => '0',
    ),
    'sort' => array(
      'bef_format' => 'default',
      'advanced' => array(
        'collapsible' => 0,
        'collapsible_label' => 'Sort options',
        'combine' => 0,
        'combine_param' => 'sort_bef_combine',
        'combine_rewrite' => '',
        'reset' => 0,
        'reset_label' => '',
        'is_secondary' => 0,
        'autosubmit' => 0,
      ),
    ),
    'language' => array(
      'bef_format' => 'bef',
      'more_options' => array(
        'bef_select_all_none' => 0,
        'bef_collapsible' => 0,
        'autosubmit' => 0,
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Елементів на сторінку';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '12, 24, 48, 60';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Усе -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Зміщення';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« перша';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ попередня';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'наступна ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'остання »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Зв'язок: Вміст: Товари за посиланнями */
  $handler->display->display_options['relationships']['field_bookfields_product_id']['id'] = 'field_bookfields_product_id';
  $handler->display->display_options['relationships']['field_bookfields_product_id']['table'] = 'field_data_field_bookfields';
  $handler->display->display_options['relationships']['field_bookfields_product_id']['field'] = 'field_bookfields_product_id';
  /* Поле: Вміст: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Критерій впорядкування: Вміст: Хіт (field_hit) */
  $handler->display->display_options['sorts']['field_hit_value']['id'] = 'field_hit_value';
  $handler->display->display_options['sorts']['field_hit_value']['table'] = 'field_data_field_hit';
  $handler->display->display_options['sorts']['field_hit_value']['field'] = 'field_hit_value';
  $handler->display->display_options['sorts']['field_hit_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['field_hit_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_hit_value']['expose']['label'] = 'Популярністю';
  /* Критерій впорядкування: Торгівля: Товар: Товарні запаси (commerce_stock) */
  $handler->display->display_options['sorts']['commerce_stock_value']['id'] = 'commerce_stock_value';
  $handler->display->display_options['sorts']['commerce_stock_value']['table'] = 'field_data_commerce_stock';
  $handler->display->display_options['sorts']['commerce_stock_value']['field'] = 'commerce_stock_value';
  $handler->display->display_options['sorts']['commerce_stock_value']['relationship'] = 'field_bookfields_product_id';
  $handler->display->display_options['sorts']['commerce_stock_value']['order'] = 'DESC';
  $handler->display->display_options['sorts']['commerce_stock_value']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['commerce_stock_value']['expose']['label'] = 'Наявністю';
  /* Критерій впорядкування: Вміст: Дата публікації */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Критерій фільтрування: Вміст: Мова */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'uk' => 'uk',
    'en' => 'en',
    'ru' => 'ru',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  $handler->display->display_options['filters']['language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Мова';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'lang';
  $handler->display->display_options['filters']['language']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['language']['expose']['reduce'] = TRUE;
  /* Критерій фільтрування: Вміст: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'book' => 'book',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Критерій фільтрування: Вміст: Опубліковано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'books';

  /* Display: Хіти */
  $handler = $view->new_display('page', 'Хіти', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Хіти';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерій фільтрування: Вміст: Мова */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'uk' => 'uk',
    'en' => 'en',
    'ru' => 'ru',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  $handler->display->display_options['filters']['language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Мова';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'lang';
  $handler->display->display_options['filters']['language']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['language']['expose']['reduce'] = TRUE;
  /* Критерій фільтрування: Вміст: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'book' => 'book',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Критерій фільтрування: Вміст: Опубліковано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерій фільтрування: Вміст: Хіт (field_hit) */
  $handler->display->display_options['filters']['field_hit_value']['id'] = 'field_hit_value';
  $handler->display->display_options['filters']['field_hit_value']['table'] = 'field_data_field_hit';
  $handler->display->display_options['filters']['field_hit_value']['field'] = 'field_hit_value';
  $handler->display->display_options['filters']['field_hit_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'books/hits';

  /* Display: Новинки */
  $handler = $view->new_display('page', 'Новинки', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Нові надходження';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерій фільтрування: Вміст: Мова */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'uk' => 'uk',
    'en' => 'en',
    'ru' => 'ru',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  $handler->display->display_options['filters']['language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Мова';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'lang';
  $handler->display->display_options['filters']['language']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['language']['expose']['reduce'] = TRUE;
  /* Критерій фільтрування: Вміст: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'book' => 'book',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Критерій фільтрування: Вміст: Опубліковано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерій фільтрування: Вміст: Новинка (field_isnew) */
  $handler->display->display_options['filters']['field_isnew_value']['id'] = 'field_isnew_value';
  $handler->display->display_options['filters']['field_isnew_value']['table'] = 'field_data_field_isnew';
  $handler->display->display_options['filters']['field_isnew_value']['field'] = 'field_isnew_value';
  $handler->display->display_options['filters']['field_isnew_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['path'] = 'books/new';
  $translatables['books'] = array(
    t('Master'),
    t('Всі книги'),
    t('ще'),
    t('Застосувати'),
    t('Скинути'),
    t('Впорядкувати за'),
    t('Зрост'),
    t('Спад'),
    t('Щоб побачити результат, виберіть довільний фільтр і натисніть "Застосувати"'),
    t('Розширені параметри'),
    t('Sort options'),
    t('Елементів на сторінку'),
    t('- Усе -'),
    t('Зміщення'),
    t('« перша'),
    t('‹ попередня'),
    t('наступна ›'),
    t('остання »'),
    t('Товари, на які посилається поле field_bookfields'),
    t('Популярністю'),
    t('Наявністю'),
    t('Мова'),
    t('Page'),
    t('Хіти'),
    t('Новинки'),
    t('Нові надходження'),
  );
  $export['books'] = $view;

  $view = new view();
  $view->name = 'category_hits';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'category_hits';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ще';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Застосувати';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Скинути';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Впорядкувати за';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Зрост';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Спад';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '11';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Поле: Вміст: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Критерій впорядкування: Вміст: Дата публікації */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Контекстний фільтр: Вміст: Категорія (field_book_category) */
  $handler->display->display_options['arguments']['field_book_category_tid']['id'] = 'field_book_category_tid';
  $handler->display->display_options['arguments']['field_book_category_tid']['table'] = 'field_data_field_book_category';
  $handler->display->display_options['arguments']['field_book_category_tid']['field'] = 'field_book_category_tid';
  $handler->display->display_options['arguments']['field_book_category_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_book_category_tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_book_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_book_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_book_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_book_category_tid']['summary_options']['items_per_page'] = '25';
  /* Критерій фільтрування: Вміст: Опубліковано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерій фільтрування: Вміст: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'book' => 'book',
  );
  /* Критерій фільтрування: Вміст: Мова */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
    '***DEFAULT_LANGUAGE***' => '***DEFAULT_LANGUAGE***',
    'und' => 'und',
    'uk' => 'uk',
  );
  $translatables['category_hits'] = array(
    t('Master'),
    t('ще'),
    t('Застосувати'),
    t('Скинути'),
    t('Впорядкувати за'),
    t('Зрост'),
    t('Спад'),
    t('Все'),
  );
  $export['category_hits'] = $view;

  $view = new view();
  $view->name = 'collection_list';
  $view->description = '';
  $view->tag = 'collection-block-list';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Список колекцій';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Слайдер колекцій';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ще';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Застосувати';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Скинути';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Впорядкувати за';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Зрост';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Спад';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Поле: Термін таксономії: Назва (ім'я) */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Поле: Поле: Зображення обкладинки */
  $handler->display->display_options['fields']['field_nni']['id'] = 'field_nni';
  $handler->display->display_options['fields']['field_nni']['table'] = 'field_data_field_nni';
  $handler->display->display_options['fields']['field_nni']['field'] = 'field_nni';
  $handler->display->display_options['fields']['field_nni']['label'] = '';
  $handler->display->display_options['fields']['field_nni']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_nni']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_nni']['settings'] = array(
    'image_style' => 'large',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_nni']['group_column'] = 'fid';
  $handler->display->display_options['fields']['field_nni']['group_columns'] = array(
    'bundle' => 'bundle',
  );
  /* Поле: Термін таксономії: Опис терміна */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = '';
  $handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
  /* Поле: Термін таксономії: ID терміна */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['tid']['alter']['text'] = '[tid]';
  $handler->display->display_options['fields']['tid']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['element_default_classes'] = FALSE;
  /* Критерій фільтрування: Словник таксономії: Машинна назва */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'collections' => 'collections',
  );

  /* Display: list-block */
  $handler = $view->new_display('block', 'list-block', 'block_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Термін таксономії: Назва (ім'я) */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  $translatables['collection_list'] = array(
    t('Master'),
    t('Слайдер колекцій'),
    t('ще'),
    t('Застосувати'),
    t('Скинути'),
    t('Впорядкувати за'),
    t('Зрост'),
    t('Спад'),
    t('[tid]'),
    t('.'),
    t(','),
    t('list-block'),
  );
  $export['collection_list'] = $view;

  $view = new view();
  $view->name = 'collections_slider';
  $view->description = '';
  $view->tag = 'front-block';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Слайдер колекцій на головну';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Слайдер колекцій';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ще';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Застосувати';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Скинути';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Впорядкувати за';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Зрост';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Спад';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Поле: Термін таксономії: Назва (ім'я) */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Поле: Поле: Зображення обкладинки */
  $handler->display->display_options['fields']['field_nni']['id'] = 'field_nni';
  $handler->display->display_options['fields']['field_nni']['table'] = 'field_data_field_nni';
  $handler->display->display_options['fields']['field_nni']['field'] = 'field_nni';
  $handler->display->display_options['fields']['field_nni']['label'] = '';
  $handler->display->display_options['fields']['field_nni']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_nni']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_nni']['settings'] = array(
    'image_style' => 'large',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_nni']['group_column'] = 'fid';
  $handler->display->display_options['fields']['field_nni']['group_columns'] = array(
    'bundle' => 'bundle',
  );
  /* Поле: Термін таксономії: Опис терміна */
  $handler->display->display_options['fields']['description']['id'] = 'description';
  $handler->display->display_options['fields']['description']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['description']['field'] = 'description';
  $handler->display->display_options['fields']['description']['label'] = '';
  $handler->display->display_options['fields']['description']['element_label_colon'] = FALSE;
  /* Поле: Термін таксономії: ID терміна */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = '';
  $handler->display->display_options['fields']['tid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['tid']['alter']['text'] = '[tid]';
  $handler->display->display_options['fields']['tid']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['element_default_classes'] = FALSE;
  /* Критерій фільтрування: Словник таксономії: Машинна назва */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'collections' => 'collections',
  );

  /* Display: front-block */
  $handler = $view->new_display('block', 'front-block', 'block');
  $translatables['collections_slider'] = array(
    t('Master'),
    t('Слайдер колекцій'),
    t('ще'),
    t('Застосувати'),
    t('Скинути'),
    t('Впорядкувати за'),
    t('Зрост'),
    t('Спад'),
    t('[tid]'),
    t('.'),
    t(','),
    t('front-block'),
  );
  $export['collections_slider'] = $view;

  $view = new view();
  $view->name = 'companies';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Компанії';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Компанії';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ще';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Застосувати';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Скинути';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Впорядкувати за';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Зрост';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Спад';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Елементів на сторінку';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Усе -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Зміщення';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« перша';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ попередня';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'наступна ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'остання »';
  $handler->display->display_options['style_plugin'] = 'table_megarows';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Поле: Вміст: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Вміст: Мейл - домен */
  $handler->display->display_options['fields']['field_maildomain']['id'] = 'field_maildomain';
  $handler->display->display_options['fields']['field_maildomain']['table'] = 'field_data_field_maildomain';
  $handler->display->display_options['fields']['field_maildomain']['field'] = 'field_maildomain';
  $handler->display->display_options['fields']['field_maildomain']['delta_offset'] = '0';
  /* Поле: Вміст: Посилання на редагування */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  /* Критерій впорядкування: Вміст: Дата публікації */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Критерій фільтрування: Вміст: Опубліковано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерій фільтрування: Вміст: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'company' => 'company',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/bookbox/companies';
  $translatables['companies'] = array(
    t('Master'),
    t('Компанії'),
    t('ще'),
    t('Застосувати'),
    t('Скинути'),
    t('Впорядкувати за'),
    t('Зрост'),
    t('Спад'),
    t('Елементів на сторінку'),
    t('- Усе -'),
    t('Зміщення'),
    t('« перша'),
    t('‹ попередня'),
    t('наступна ›'),
    t('остання »'),
    t('Мейл - домен'),
    t('Посилання на редагування'),
    t('Page'),
  );
  $export['companies'] = $view;

  $view = new view();
  $view->name = 'company_orders';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_order';
  $view->human_name = 'company_orders';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ще';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Застосувати';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Скинути';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Впорядкувати за';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Зрост';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Спад';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Зв'язок: Торгівля: Замовлення: Власник */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'commerce_order';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Зв'язок: Торгівля: Замовлення: Позиції обліку за посиланнями */
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['id'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['field'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['required'] = TRUE;
  /* Поле: Торгівля: Позиція обліку: Товар */
  $handler->display->display_options['fields']['commerce_product']['id'] = 'commerce_product';
  $handler->display->display_options['fields']['commerce_product']['table'] = 'field_data_commerce_product';
  $handler->display->display_options['fields']['commerce_product']['field'] = 'commerce_product';
  $handler->display->display_options['fields']['commerce_product']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['commerce_product']['label'] = '';
  $handler->display->display_options['fields']['commerce_product']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_product']['type'] = 'commerce_product_reference_rendered_product';
  $handler->display->display_options['fields']['commerce_product']['settings'] = array(
    'view_mode' => 'node_teaser',
    'page' => 1,
  );
  /* Поле: COUNT(Торгівля: Замовлення: ID замовлення) */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['group_type'] = 'count';
  $handler->display->display_options['fields']['order_id']['label'] = 'Було замовлень';
  /* Критерій впорядкування: COUNT(Торгівля: Замовлення: ID замовлення) */
  $handler->display->display_options['sorts']['order_id']['id'] = 'order_id';
  $handler->display->display_options['sorts']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['sorts']['order_id']['field'] = 'order_id';
  $handler->display->display_options['sorts']['order_id']['group_type'] = 'count';
  $handler->display->display_options['sorts']['order_id']['order'] = 'DESC';
  /* Контекстний фільтр: Користувач: Компанія (field_company) */
  $handler->display->display_options['arguments']['field_company_target_id']['id'] = 'field_company_target_id';
  $handler->display->display_options['arguments']['field_company_target_id']['table'] = 'field_data_field_company';
  $handler->display->display_options['arguments']['field_company_target_id']['field'] = 'field_company_target_id';
  $handler->display->display_options['arguments']['field_company_target_id']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['field_company_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_company_target_id']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_company_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_company_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_company_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_company_target_id']['summary_options']['items_per_page'] = '25';
  /* Критерій фільтрування: Торгівля: Замовлення: Тип замовлення */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'commerce_order' => 'commerce_order',
  );
  $translatables['company_orders'] = array(
    t('Master'),
    t('ще'),
    t('Застосувати'),
    t('Скинути'),
    t('Впорядкувати за'),
    t('Зрост'),
    t('Спад'),
    t('Власник замовлення'),
    t('Позиції обліку, на які посилаються commerce_line_items'),
    t('Було замовлень'),
    t('Все'),
  );
  $export['company_orders'] = $view;

  $view = new view();
  $view->name = 'export_orders';
  $view->description = '';
  $view->tag = 'commerce';
  $view->base_table = 'commerce_order';
  $view->human_name = 'export Orders';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Замовлення';
  $handler->display->display_options['css_class'] = 'commerce-backoffice-view';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ще';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer commerce_order entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Застосувати';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Скинути';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Впорядкувати за';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Зрост';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Спад';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Елементів на сторінку';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Усе -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Зміщення';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« перша';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ попередня';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'наступна ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'остання »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'order_number' => 'order_number',
    'commerce_product' => 'commerce_product',
    'changed' => 'changed',
    'status' => 'status',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'order_number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'commerce_product' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Дії за відсутності результату: Торгівля: Замовлення: Порожній текст */
  $handler->display->display_options['empty']['empty_text']['id'] = 'empty_text';
  $handler->display->display_options['empty']['empty_text']['table'] = 'commerce_order';
  $handler->display->display_options['empty']['empty_text']['field'] = 'empty_text';
  /* Зв'язок: Торгівля: Замовлення: Власник */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'commerce_order';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Зв'язок: Торгівля: Замовлення: Позиції обліку за посиланнями */
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['id'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['field'] = 'commerce_line_items_line_item_id';
  /* Зв'язок: Торгівля: Позиція обліку: Товари за посиланнями */
  $handler->display->display_options['relationships']['commerce_product_product_id']['id'] = 'commerce_product_product_id';
  $handler->display->display_options['relationships']['commerce_product_product_id']['table'] = 'field_data_commerce_product';
  $handler->display->display_options['relationships']['commerce_product_product_id']['field'] = 'commerce_product_product_id';
  $handler->display->display_options['relationships']['commerce_product_product_id']['relationship'] = 'commerce_line_items_line_item_id';
  /* Поле: Торгівля: Замовлення: Номер замовлення */
  $handler->display->display_options['fields']['order_number']['id'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_number']['field'] = 'order_number';
  $handler->display->display_options['fields']['order_number']['label'] = 'ID Замовлення';
  /* Поле: Торгівля: Товар: Артикул */
  $handler->display->display_options['fields']['sku']['id'] = 'sku';
  $handler->display->display_options['fields']['sku']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['sku']['field'] = 'sku';
  $handler->display->display_options['fields']['sku']['relationship'] = 'commerce_product_product_id';
  $handler->display->display_options['fields']['sku']['link_to_product'] = 0;
  /* Поле: Торгівля: Позиція обліку: Товар */
  $handler->display->display_options['fields']['commerce_product']['id'] = 'commerce_product';
  $handler->display->display_options['fields']['commerce_product']['table'] = 'field_data_commerce_product';
  $handler->display->display_options['fields']['commerce_product']['field'] = 'commerce_product';
  $handler->display->display_options['fields']['commerce_product']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['commerce_product']['label'] = 'Книга';
  $handler->display->display_options['fields']['commerce_product']['exclude'] = TRUE;
  $handler->display->display_options['fields']['commerce_product']['type'] = 'commerce_product_reference_title_link';
  $handler->display->display_options['fields']['commerce_product']['settings'] = array(
    'show_quantity' => 0,
    'default_quantity' => '1',
    'combine' => 1,
    'show_single_product_attributes' => 0,
    'line_item_type' => 'product',
  );
  /* Поле: Торгівля: Замовлення: Дата оновлення */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Дата замовлення';
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'd.m.Y H:i:s';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Поле: Глобальне: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Дата доставки';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return next_friday_full($row->changed);';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php print $value; ?> ';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Поле: Торгівля: Замовлення: Статус замовлення */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Статус';
  /* Поле: Користувач: Компанія */
  $handler->display->display_options['fields']['field_company']['id'] = 'field_company';
  $handler->display->display_options['fields']['field_company']['table'] = 'field_data_field_company';
  $handler->display->display_options['fields']['field_company']['field'] = 'field_company';
  $handler->display->display_options['fields']['field_company']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_company']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_company']['settings'] = array(
    'link' => 0,
  );
  /* Поле: Користувач: Ім'я */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_name']['exclude'] = TRUE;
  /* Поле: Користувач: Прізвище */
  $handler->display->display_options['fields']['field_sirname']['id'] = 'field_sirname';
  $handler->display->display_options['fields']['field_sirname']['table'] = 'field_data_field_sirname';
  $handler->display->display_options['fields']['field_sirname']['field'] = 'field_sirname';
  $handler->display->display_options['fields']['field_sirname']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_sirname']['exclude'] = TRUE;
  /* Поле: Користувач: Електронна пошта */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'uid';
  /* Критерій впорядкування: Торгівля: Замовлення: Дата оновлення */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'commerce_order';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Контекстний фільтр: Торгівля: Замовлення: ID замовлення */
  $handler->display->display_options['arguments']['order_id']['id'] = 'order_id';
  $handler->display->display_options['arguments']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['arguments']['order_id']['field'] = 'order_id';
  $handler->display->display_options['arguments']['order_id']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['order_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['order_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['order_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['order_id']['summary_options']['items_per_page'] = '25';
  /* Критерій фільтрування: Торгівля: Замовлення: Статус замовлення */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = array(
    'delivered' => 'delivered',
    'completed' => 'completed',
    'archive' => 'archive',
  );
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Статус';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['status']['expose']['reduce'] = TRUE;
  /* Критерій фільтрування: Дата: Дата (commerce_order) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator_id'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['identifier'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['date_filter_1']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'commerce_order.changed' => 'commerce_order.changed',
  );

  /* Display: Admin page */
  $handler = $view->new_display('page', 'Admin page', 'admin_page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/orders/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Orders';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Orders';
  $handler->display->display_options['tab_options']['description'] = 'Manage orders in the store.';
  $handler->display->display_options['tab_options']['weight'] = '';
  $handler->display->display_options['tab_options']['name'] = 'management';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'admin/orders/list/export';
  $handler->display->display_options['displays'] = array(
    'admin_page' => 'admin_page',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['segment_size'] = '100';
  $translatables['export_orders'] = array(
    t('Master'),
    t('Замовлення'),
    t('ще'),
    t('Застосувати'),
    t('Скинути'),
    t('Впорядкувати за'),
    t('Зрост'),
    t('Спад'),
    t('Елементів на сторінку'),
    t('- Усе -'),
    t('Зміщення'),
    t('« перша'),
    t('‹ попередня'),
    t('наступна ›'),
    t('остання »'),
    t('Власник замовлення'),
    t('Позиції обліку, на які посилаються commerce_line_items'),
    t('Товари, на які посилається поле commerce_product'),
    t('ID Замовлення'),
    t('Артикул'),
    t('Книга'),
    t('Дата замовлення'),
    t('Дата доставки'),
    t('Статус'),
    t('Компанія'),
    t('Ім\'я'),
    t('Прізвище'),
    t('Електронна пошта'),
    t('Все'),
    t('Admin page'),
    t('Data export'),
  );
  $export['export_orders'] = $view;

  $view = new view();
  $view->name = 'export_users';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'export_users';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Export users';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ще';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Застосувати';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Скинути';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Впорядкувати за';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Зрост';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Спад';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Елементів на сторінку';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Усе -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Зміщення';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« перша';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ попередня';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'наступна ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'остання »';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Нижній колонтитул: Глобальне: Текстова область */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<div class="feed-icon">
      <a href="/admin/all-users/export"><img typeof="foaf:Image" src="/sites/all/modules/views_data_export/images/xls.png" alt="XLS" title="XLS"></a>
</div>';
  $handler->display->display_options['footer']['area']['format'] = 'php_code';
  /* Поле: Користувач: Дата створення */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Дата реєстрації';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd.m.Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Поле: Користувач: Електронна пошта */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  /* Поле: Користувач: Ім'я */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  /* Поле: Користувач: Прізвище */
  $handler->display->display_options['fields']['field_sirname']['id'] = 'field_sirname';
  $handler->display->display_options['fields']['field_sirname']['table'] = 'field_data_field_sirname';
  $handler->display->display_options['fields']['field_sirname']['field'] = 'field_sirname';
  /* Поле: Користувач: Компанія */
  $handler->display->display_options['fields']['field_company']['id'] = 'field_company';
  $handler->display->display_options['fields']['field_company']['table'] = 'field_data_field_company';
  $handler->display->display_options['fields']['field_company']['field'] = 'field_company';
  $handler->display->display_options['fields']['field_company']['settings'] = array(
    'link' => 0,
  );
  /* Поле: Користувач: Телефон */
  $handler->display->display_options['fields']['field_tel']['id'] = 'field_tel';
  $handler->display->display_options['fields']['field_tel']['table'] = 'field_data_field_tel';
  $handler->display->display_options['fields']['field_tel']['field'] = 'field_tel';
  /* Критерій впорядкування: Користувач: Дата створення */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Критерій фільтрування: Користувач: Активно */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/all-users';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'admin/all-users/export';
  $handler->display->display_options['sitename_title'] = 0;
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['segment_size'] = '100';
  $translatables['export_users'] = array(
    t('Master'),
    t('Export users'),
    t('ще'),
    t('Застосувати'),
    t('Скинути'),
    t('Впорядкувати за'),
    t('Зрост'),
    t('Спад'),
    t('Елементів на сторінку'),
    t('- Усе -'),
    t('Зміщення'),
    t('« перша'),
    t('‹ попередня'),
    t('наступна ›'),
    t('остання »'),
    t('<div class="feed-icon">
      <a href="/admin/all-users/export"><img typeof="foaf:Image" src="/sites/all/modules/views_data_export/images/xls.png" alt="XLS" title="XLS"></a>
</div>'),
    t('Дата реєстрації'),
    t('Електронна пошта'),
    t('Ім\'я'),
    t('Прізвище'),
    t('Компанія'),
    t('Телефон'),
    t('Page'),
    t('Data export'),
  );
  $export['export_users'] = $view;

  $view = new view();
  $view->name = 'faq';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'FAQ';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'FAQ';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ще';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Застосувати';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Скинути';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Впорядкувати за';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Зрост';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Спад';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_tab_plugin_style';
  $handler->display->display_options['style_options']['tab_field'] = 'title';
  $handler->display->display_options['style_options']['justified'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Поле: Вміст: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Поле: Вміст: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Поле: Draggableviews: Вміст */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 1;
  /* Критерій впорядкування: Draggableviews: Вага */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'faq:page_1';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
  /* Критерій фільтрування: Вміст: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'faq' => 'faq',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Вміст: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Поле: Вміст: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'faq';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'FAQ';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-footer-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Сторінка */
  $handler = $view->new_display('page', 'Сторінка', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'body' => 'body',
    'draggableviews' => 'draggableviews',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'draggableviews' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Вміст: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Поле: Draggableviews: Вміст */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 1;
  $handler->display->display_options['path'] = 'admin/faq/sort';
  $translatables['faq'] = array(
    t('Master'),
    t('FAQ'),
    t('ще'),
    t('Застосувати'),
    t('Скинути'),
    t('Впорядкувати за'),
    t('Зрост'),
    t('Спад'),
    t('Вміст'),
    t('Page'),
    t('Сторінка'),
  );
  $export['faq'] = $view;

  $view = new view();
  $view->name = 'front_slider';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Слайдер на головну';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ще';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Застосувати';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Скинути';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Впорядкувати за';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Зрост';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Спад';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Поле: Вміст: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Вміст: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Поле: Вміст: Колір фону (hex) */
  $handler->display->display_options['fields']['field_bgcolor_hex']['id'] = 'field_bgcolor_hex';
  $handler->display->display_options['fields']['field_bgcolor_hex']['table'] = 'field_data_field_bgcolor_hex';
  $handler->display->display_options['fields']['field_bgcolor_hex']['field'] = 'field_bgcolor_hex';
  $handler->display->display_options['fields']['field_bgcolor_hex']['label'] = '';
  $handler->display->display_options['fields']['field_bgcolor_hex']['element_label_colon'] = FALSE;
  /* Поле: Вміст: Зображення */
  $handler->display->display_options['fields']['field_header_cover']['id'] = 'field_header_cover';
  $handler->display->display_options['fields']['field_header_cover']['table'] = 'field_data_field_header_cover';
  $handler->display->display_options['fields']['field_header_cover']['field'] = 'field_header_cover';
  $handler->display->display_options['fields']['field_header_cover']['label'] = '';
  $handler->display->display_options['fields']['field_header_cover']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_header_cover']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_header_cover']['settings'] = array(
    'image_style' => 'slider',
    'image_link' => '',
  );
  /* Поле: Вміст: Call to action */
  $handler->display->display_options['fields']['field_cta_link_1']['id'] = 'field_cta_link_1';
  $handler->display->display_options['fields']['field_cta_link_1']['table'] = 'field_data_field_cta_link';
  $handler->display->display_options['fields']['field_cta_link_1']['field'] = 'field_cta_link';
  $handler->display->display_options['fields']['field_cta_link_1']['label'] = '';
  $handler->display->display_options['fields']['field_cta_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cta_link_1']['click_sort_column'] = 'url';
  /* Поле: Draggableviews: Вміст */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
  /* Критерій впорядкування: Вміст: Дата публікації */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Критерій впорядкування: Draggableviews: Вага */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'draggableviews_structure';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_view'] = 'front_slider:page_1';
  $handler->display->display_options['sorts']['weight']['draggableviews_setting_new_items_bottom_list'] = 1;
  /* Критерій фільтрування: Вміст: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'slider_item' => 'slider_item',
  );

  /* Display: Сторінка */
  $handler = $view->new_display('page', 'Сторінка', 'page_1');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'body' => 'body',
    'field_bgcolor_hex' => 'field_bgcolor_hex',
    'field_header_cover' => 'field_header_cover',
    'field_cta_link_1' => 'field_cta_link_1',
    'draggableviews' => 'draggableviews',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_bgcolor_hex' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_header_cover' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_cta_link_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'draggableviews' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Вміст: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Вміст: Зображення */
  $handler->display->display_options['fields']['field_header_cover']['id'] = 'field_header_cover';
  $handler->display->display_options['fields']['field_header_cover']['table'] = 'field_data_field_header_cover';
  $handler->display->display_options['fields']['field_header_cover']['field'] = 'field_header_cover';
  $handler->display->display_options['fields']['field_header_cover']['label'] = '';
  $handler->display->display_options['fields']['field_header_cover']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_header_cover']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_header_cover']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Поле: Draggableviews: Вміст */
  $handler->display->display_options['fields']['draggableviews']['id'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['table'] = 'node';
  $handler->display->display_options['fields']['draggableviews']['field'] = 'draggableviews';
  $handler->display->display_options['fields']['draggableviews']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['draggableviews']['draggableviews']['ajax'] = 0;
  $handler->display->display_options['path'] = 'admin/slider/sort';

  /* Display: Блок */
  $handler = $view->new_display('block', 'Блок', 'block_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Поле: Вміст: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Вміст: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Поле: Вміст: Колір фону (hex) */
  $handler->display->display_options['fields']['field_bgcolor_hex']['id'] = 'field_bgcolor_hex';
  $handler->display->display_options['fields']['field_bgcolor_hex']['table'] = 'field_data_field_bgcolor_hex';
  $handler->display->display_options['fields']['field_bgcolor_hex']['field'] = 'field_bgcolor_hex';
  $handler->display->display_options['fields']['field_bgcolor_hex']['label'] = '';
  $handler->display->display_options['fields']['field_bgcolor_hex']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_bgcolor_hex']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_bgcolor_hex']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bgcolor_hex']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_bgcolor_hex']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_bgcolor_hex']['field_api_classes'] = TRUE;
  /* Поле: Вміст: Зображення */
  $handler->display->display_options['fields']['field_header_cover']['id'] = 'field_header_cover';
  $handler->display->display_options['fields']['field_header_cover']['table'] = 'field_data_field_header_cover';
  $handler->display->display_options['fields']['field_header_cover']['field'] = 'field_header_cover';
  $handler->display->display_options['fields']['field_header_cover']['label'] = '';
  $handler->display->display_options['fields']['field_header_cover']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_header_cover']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_header_cover']['settings'] = array(
    'image_style' => 'slider',
    'image_link' => '',
  );
  /* Поле: Вміст: Call to action */
  $handler->display->display_options['fields']['field_cta_link_1']['id'] = 'field_cta_link_1';
  $handler->display->display_options['fields']['field_cta_link_1']['table'] = 'field_data_field_cta_link';
  $handler->display->display_options['fields']['field_cta_link_1']['field'] = 'field_cta_link';
  $handler->display->display_options['fields']['field_cta_link_1']['label'] = '';
  $handler->display->display_options['fields']['field_cta_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cta_link_1']['click_sort_column'] = 'url';
  $translatables['front_slider'] = array(
    t('Master'),
    t('ще'),
    t('Застосувати'),
    t('Скинути'),
    t('Впорядкувати за'),
    t('Зрост'),
    t('Спад'),
    t('Вміст'),
    t('Сторінка'),
    t('Блок'),
  );
  $export['front_slider'] = $view;

  $view = new view();
  $view->name = 'hits';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Хіти';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Хіти';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ще';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Застосувати';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Скинути';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Впорядкувати за';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Зрост';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Спад';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['root_object'] = 'hits';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  /* Поле: Вміст: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Вміст: Автор */
  $handler->display->display_options['fields']['field_book_author']['id'] = 'field_book_author';
  $handler->display->display_options['fields']['field_book_author']['table'] = 'field_data_field_book_author';
  $handler->display->display_options['fields']['field_book_author']['field'] = 'field_book_author';
  $handler->display->display_options['fields']['field_book_author']['label'] = 'автор';
  $handler->display->display_options['fields']['field_book_author']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_book_author']['delta_offset'] = '0';
  /* Поле: Поле: Зображення обкладинки */
  $handler->display->display_options['fields']['field_nni']['id'] = 'field_nni';
  $handler->display->display_options['fields']['field_nni']['table'] = 'field_data_field_nni';
  $handler->display->display_options['fields']['field_nni']['field'] = 'field_nni';
  $handler->display->display_options['fields']['field_nni']['label'] = 'cover';
  $handler->display->display_options['fields']['field_nni']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_nni']['settings'] = array(
    'image_style' => 'bookcover',
    'image_link' => '',
  );
  /* Критерій впорядкування: Вміст: Дата публікації */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Критерій фільтрування: Вміст: Опубліковано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерій фільтрування: Вміст: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'book' => 'book',
  );
  /* Критерій фільтрування: Вміст: Хіт (field_hit) */
  $handler->display->display_options['filters']['field_hit_value']['id'] = 'field_hit_value';
  $handler->display->display_options['filters']['field_hit_value']['table'] = 'field_data_field_hit';
  $handler->display->display_options['filters']['field_hit_value']['field'] = 'field_hit_value';
  $handler->display->display_options['filters']['field_hit_value']['value'] = array(
    1 => '1',
  );

  /* Display: Хіти */
  $handler = $view->new_display('page', 'Хіти', 'page_1');
  $handler->display->display_options['path'] = 'json/hits';

  /* Display: Категорії */
  $handler = $view->new_display('page', 'Категорії', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Категорії';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_json';
  $handler->display->display_options['style_options']['root_object'] = 'books';
  $handler->display->display_options['style_options']['plaintext_output'] = 1;
  $handler->display->display_options['style_options']['remove_newlines'] = 0;
  $handler->display->display_options['style_options']['jsonp_prefix'] = '';
  $handler->display->display_options['style_options']['using_views_api_mode'] = 0;
  $handler->display->display_options['style_options']['object_arrays'] = 0;
  $handler->display->display_options['style_options']['numeric_strings'] = 0;
  $handler->display->display_options['style_options']['bigint_string'] = 0;
  $handler->display->display_options['style_options']['pretty_print'] = 0;
  $handler->display->display_options['style_options']['unescaped_slashes'] = 0;
  $handler->display->display_options['style_options']['unescaped_unicode'] = 0;
  $handler->display->display_options['style_options']['char_encoding'] = array();
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Критерій впорядкування: Вміст: Хіт (field_hit) */
  $handler->display->display_options['sorts']['field_hit_value']['id'] = 'field_hit_value';
  $handler->display->display_options['sorts']['field_hit_value']['table'] = 'field_data_field_hit';
  $handler->display->display_options['sorts']['field_hit_value']['field'] = 'field_hit_value';
  $handler->display->display_options['sorts']['field_hit_value']['order'] = 'DESC';
  /* Критерій впорядкування: Вміст: Дата публікації */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Контекстний фільтр: Вміст: Категорія (field_book_category) */
  $handler->display->display_options['arguments']['field_book_category_tid']['id'] = 'field_book_category_tid';
  $handler->display->display_options['arguments']['field_book_category_tid']['table'] = 'field_data_field_book_category';
  $handler->display->display_options['arguments']['field_book_category_tid']['field'] = 'field_book_category_tid';
  $handler->display->display_options['arguments']['field_book_category_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_book_category_tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_book_category_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_book_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_book_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_book_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Критерій фільтрування: Вміст: Опубліковано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерій фільтрування: Вміст: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'book' => 'book',
  );
  $handler->display->display_options['path'] = 'json/category/%';
  $translatables['hits'] = array(
    t('Master'),
    t('Хіти'),
    t('ще'),
    t('Застосувати'),
    t('Скинути'),
    t('Впорядкувати за'),
    t('Зрост'),
    t('Спад'),
    t('автор'),
    t('cover'),
    t('Категорії'),
    t('Все'),
  );
  $export['hits'] = $view;

  $view = new view();
  $view->name = 'hits_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Список книг для ручного списку';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Хіти';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ще';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Застосувати';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Скинути';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Впорядкувати за';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Зрост';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Спад';
  $handler->display->display_options['exposed_form']['options']['autosubmit_hide'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Елементів на сторінку';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Усе -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Зміщення';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« перша';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ попередня';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'наступна ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'остання »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Поле: Entity Reference View Widget Checkbox: Вміст */
  $handler->display->display_options['fields']['entityreference_view_widget']['id'] = 'entityreference_view_widget';
  $handler->display->display_options['fields']['entityreference_view_widget']['table'] = 'node';
  $handler->display->display_options['fields']['entityreference_view_widget']['field'] = 'entityreference_view_widget';
  $handler->display->display_options['fields']['entityreference_view_widget']['label'] = '';
  $handler->display->display_options['fields']['entityreference_view_widget']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['entityreference_view_widget']['ervw']['force_single'] = 0;
  /* Поле: Вміст: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Поле: Вміст: Дата публікації */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Дата';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd.m.Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Поле: Вміст: Новинка */
  $handler->display->display_options['fields']['field_isnew']['id'] = 'field_isnew';
  $handler->display->display_options['fields']['field_isnew']['table'] = 'field_data_field_isnew';
  $handler->display->display_options['fields']['field_isnew']['field'] = 'field_isnew';
  /* Поле: Вміст: Рекомендуємо */
  $handler->display->display_options['fields']['field_bookbox_rec']['id'] = 'field_bookbox_rec';
  $handler->display->display_options['fields']['field_bookbox_rec']['table'] = 'field_data_field_bookbox_rec';
  $handler->display->display_options['fields']['field_bookbox_rec']['field'] = 'field_bookbox_rec';
  /* Поле: Вміст: Хіт */
  $handler->display->display_options['fields']['field_hit']['id'] = 'field_hit';
  $handler->display->display_options['fields']['field_hit']['table'] = 'field_data_field_hit';
  $handler->display->display_options['fields']['field_hit']['field'] = 'field_hit';
  /* Критерій впорядкування: Вміст: Дата публікації */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Критерій фільтрування: Вміст: Опубліковано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерій фільтрування: Вміст: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'book' => 'book',
  );

  /* Display: Посилання на сутність */
  $handler = $view->new_display('entityreference', 'Посилання на сутність', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;

  /* Display: Entity Reference View Widget */
  $handler = $view->new_display('entityreference_view_widget', 'Entity Reference View Widget', 'entityreference_view_widget_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'entityreference_view_widget' => 'entityreference_view_widget',
    'title' => 'title',
    'created' => 'created',
    'field_isnew' => 'field_isnew',
    'field_bookbox_rec' => 'field_bookbox_rec',
    'field_hit' => 'field_hit',
  );
  $handler->display->display_options['style_options']['default'] = 'created';
  $handler->display->display_options['style_options']['info'] = array(
    'entityreference_view_widget' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_isnew' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_bookbox_rec' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_hit' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $translatables['hits_list'] = array(
    t('Master'),
    t('Хіти'),
    t('ще'),
    t('Застосувати'),
    t('Скинути'),
    t('Впорядкувати за'),
    t('Зрост'),
    t('Спад'),
    t('Елементів на сторінку'),
    t('- Усе -'),
    t('Зміщення'),
    t('« перша'),
    t('‹ попередня'),
    t('наступна ›'),
    t('остання »'),
    t('Дата'),
    t('Новинка'),
    t('Рекомендуємо'),
    t('Хіт'),
    t('Посилання на сутність'),
    t('Entity Reference View Widget'),
  );
  $export['hits_list'] = $view;

  $view = new view();
  $view->name = 'main_recomend';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Букбокс рекомендує';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'BookBox рекомендує';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ще';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Застосувати';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Скинути';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Впорядкувати за';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Зрост';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Спад';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Елементів на сторінку';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Усе -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Зміщення';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« перша';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ попередня';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'наступна ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'остання »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Поле: Вміст: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Критерій впорядкування: Вміст: Дата публікації */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Критерій фільтрування: Вміст: Опубліковано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерій фільтрування: Вміст: Рекомендуємо (field_bookbox_rec) */
  $handler->display->display_options['filters']['field_bookbox_rec_value']['id'] = 'field_bookbox_rec_value';
  $handler->display->display_options['filters']['field_bookbox_rec_value']['table'] = 'field_data_field_bookbox_rec';
  $handler->display->display_options['filters']['field_bookbox_rec_value']['field'] = 'field_bookbox_rec_value';
  $handler->display->display_options['filters']['field_bookbox_rec_value']['value'] = array(
    1 => '1',
  );
  /* Критерій фільтрування: Вміст: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'book' => 'book',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['path'] = 'recommendations';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'recommendations.xml';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );

  /* Display: Блок */
  $handler = $view->new_display('block', 'Блок', 'block_1');
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ще';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Елементів на сторінку';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Усе -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Зміщення';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« перша';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ попередня';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'наступна ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'остання »';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'Дивитись більше';
  $handler->display->display_options['pager']['options']['effects']['type'] = 'fade';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $translatables['main_recomend'] = array(
    t('Master'),
    t('BookBox рекомендує'),
    t('ще'),
    t('Застосувати'),
    t('Скинути'),
    t('Впорядкувати за'),
    t('Зрост'),
    t('Спад'),
    t('Елементів на сторінку'),
    t('- Усе -'),
    t('Зміщення'),
    t('« перша'),
    t('‹ попередня'),
    t('наступна ›'),
    t('остання »'),
    t('Page'),
    t('Feed'),
    t('Блок'),
    t('Дивитись більше'),
  );
  $export['main_recomend'] = $view;

  $view = new view();
  $view->name = 'page_404';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Дві рандомні книги на 404';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Дві рандомні книги на 404';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ще';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Застосувати';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Скинути';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Впорядкувати за';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Зрост';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Спад';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Поле: Вміст: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Критерій впорядкування: Глобальне: Випадково */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Критерій фільтрування: Вміст: Опубліковано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерій фільтрування: Вміст: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'book' => 'book',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['page_404'] = array(
    t('Master'),
    t('Дві рандомні книги на 404'),
    t('ще'),
    t('Застосувати'),
    t('Скинути'),
    t('Впорядкувати за'),
    t('Зрост'),
    t('Спад'),
    t('Block'),
  );
  $export['page_404'] = $view;

  $view = new view();
  $view->name = 'popuar_orders';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_order';
  $view->human_name = 'popuar_orders';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ще';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Застосувати';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Скинути';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Впорядкувати за';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Зрост';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Спад';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Зв'язок: Торгівля: Замовлення: Позиції обліку за посиланнями */
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['id'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['field'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['required'] = TRUE;
  /* Зв'язок: Торгівля: Позиція обліку: Товари за посиланнями */
  $handler->display->display_options['relationships']['commerce_product_product_id']['id'] = 'commerce_product_product_id';
  $handler->display->display_options['relationships']['commerce_product_product_id']['table'] = 'field_data_commerce_product';
  $handler->display->display_options['relationships']['commerce_product_product_id']['field'] = 'commerce_product_product_id';
  $handler->display->display_options['relationships']['commerce_product_product_id']['relationship'] = 'commerce_line_items_line_item_id';
  /* Зв'язок: Торгівля: Товар: Матеріал, що посилається */
  $handler->display->display_options['relationships']['field_bookfields']['id'] = 'field_bookfields';
  $handler->display->display_options['relationships']['field_bookfields']['table'] = 'commerce_product';
  $handler->display->display_options['relationships']['field_bookfields']['field'] = 'field_bookfields';
  $handler->display->display_options['relationships']['field_bookfields']['relationship'] = 'commerce_product_product_id';
  /* Поле: Торгівля: Позиція обліку: Товар */
  $handler->display->display_options['fields']['commerce_product']['id'] = 'commerce_product';
  $handler->display->display_options['fields']['commerce_product']['table'] = 'field_data_commerce_product';
  $handler->display->display_options['fields']['commerce_product']['field'] = 'commerce_product';
  $handler->display->display_options['fields']['commerce_product']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['commerce_product']['label'] = '';
  $handler->display->display_options['fields']['commerce_product']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_product']['type'] = 'commerce_product_reference_rendered_product';
  $handler->display->display_options['fields']['commerce_product']['settings'] = array(
    'view_mode' => 'node_teaser',
    'page' => 1,
  );
  /* Поле: COUNT(Торгівля: Замовлення: ID замовлення) */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['group_type'] = 'count';
  $handler->display->display_options['fields']['order_id']['label'] = 'Було замовлень';
  /* Критерій впорядкування: COUNT(Торгівля: Замовлення: ID замовлення) */
  $handler->display->display_options['sorts']['order_id']['id'] = 'order_id';
  $handler->display->display_options['sorts']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['sorts']['order_id']['field'] = 'order_id';
  $handler->display->display_options['sorts']['order_id']['group_type'] = 'count';
  $handler->display->display_options['sorts']['order_id']['order'] = 'DESC';
  /* Контекстний фільтр: Вміст: Автор (field_book_author) */
  $handler->display->display_options['arguments']['field_book_author_tid']['id'] = 'field_book_author_tid';
  $handler->display->display_options['arguments']['field_book_author_tid']['table'] = 'field_data_field_book_author';
  $handler->display->display_options['arguments']['field_book_author_tid']['field'] = 'field_book_author_tid';
  $handler->display->display_options['arguments']['field_book_author_tid']['relationship'] = 'field_bookfields';
  $handler->display->display_options['arguments']['field_book_author_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_book_author_tid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_book_author_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_book_author_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_book_author_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_book_author_tid']['summary_options']['items_per_page'] = '25';
  /* Критерій фільтрування: Торгівля: Замовлення: Тип замовлення */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'commerce_order' => 'commerce_order',
  );
  $translatables['popuar_orders'] = array(
    t('Master'),
    t('ще'),
    t('Застосувати'),
    t('Скинути'),
    t('Впорядкувати за'),
    t('Зрост'),
    t('Спад'),
    t('Позиції обліку, на які посилаються commerce_line_items'),
    t('Товари, на які посилається поле commerce_product'),
    t('Матеріал посилається на товари з field_bookfields'),
    t('Було замовлень'),
    t('Все'),
  );
  $export['popuar_orders'] = $view;

  $view = new view();
  $view->name = 'store_export';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Експорт складу';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Експорт складу';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ще';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Застосувати';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Скинути';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Впорядкувати за';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Зрост';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Спад';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Елементів на сторінку';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Усе -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Зміщення';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« перша';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ попередня';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'наступна ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'остання »';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Зв'язок: Вміст: Товари за посиланнями */
  $handler->display->display_options['relationships']['field_bookfields_product_id']['id'] = 'field_bookfields_product_id';
  $handler->display->display_options['relationships']['field_bookfields_product_id']['table'] = 'field_data_field_bookfields';
  $handler->display->display_options['relationships']['field_bookfields_product_id']['field'] = 'field_bookfields_product_id';
  /* Поле: Торгівля: Товар: Артикул */
  $handler->display->display_options['fields']['sku']['id'] = 'sku';
  $handler->display->display_options['fields']['sku']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['sku']['field'] = 'sku';
  $handler->display->display_options['fields']['sku']['relationship'] = 'field_bookfields_product_id';
  $handler->display->display_options['fields']['sku']['link_to_product'] = 0;
  /* Поле: Вміст: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Вміст: Новинка */
  $handler->display->display_options['fields']['field_isnew']['id'] = 'field_isnew';
  $handler->display->display_options['fields']['field_isnew']['table'] = 'field_data_field_isnew';
  $handler->display->display_options['fields']['field_isnew']['field'] = 'field_isnew';
  /* Поле: Вміст: Хіт */
  $handler->display->display_options['fields']['field_hit']['id'] = 'field_hit';
  $handler->display->display_options['fields']['field_hit']['table'] = 'field_data_field_hit';
  $handler->display->display_options['fields']['field_hit']['field'] = 'field_hit';
  /* Поле: Вміст: Рекомендуємо */
  $handler->display->display_options['fields']['field_bookbox_rec']['id'] = 'field_bookbox_rec';
  $handler->display->display_options['fields']['field_bookbox_rec']['table'] = 'field_data_field_bookbox_rec';
  $handler->display->display_options['fields']['field_bookbox_rec']['field'] = 'field_bookbox_rec';
  /* Поле: Торгівля: Товар: Товарні запаси */
  $handler->display->display_options['fields']['commerce_stock']['id'] = 'commerce_stock';
  $handler->display->display_options['fields']['commerce_stock']['table'] = 'field_data_commerce_stock';
  $handler->display->display_options['fields']['commerce_stock']['field'] = 'commerce_stock';
  $handler->display->display_options['fields']['commerce_stock']['relationship'] = 'field_bookfields_product_id';
  $handler->display->display_options['fields']['commerce_stock']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Поле: Торгівля: Товар: Абсолютний сток */
  $handler->display->display_options['fields']['field_absolute_stock']['id'] = 'field_absolute_stock';
  $handler->display->display_options['fields']['field_absolute_stock']['table'] = 'field_data_field_absolute_stock';
  $handler->display->display_options['fields']['field_absolute_stock']['field'] = 'field_absolute_stock';
  $handler->display->display_options['fields']['field_absolute_stock']['relationship'] = 'field_bookfields_product_id';
  $handler->display->display_options['fields']['field_absolute_stock']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '0',
    'prefix_suffix' => 1,
  );
  /* Критерій впорядкування: Вміст: Дата публікації */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Критерій фільтрування: Вміст: Опубліковано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерій фільтрування: Вміст: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'book' => 'book',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/bookbox/store/export';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['path'] = 'admin/bookbox/store/export/xls';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['segment_size'] = '100';
  $translatables['store_export'] = array(
    t('Master'),
    t('Експорт складу'),
    t('ще'),
    t('Застосувати'),
    t('Скинути'),
    t('Впорядкувати за'),
    t('Зрост'),
    t('Спад'),
    t('Елементів на сторінку'),
    t('- Усе -'),
    t('Зміщення'),
    t('« перша'),
    t('‹ попередня'),
    t('наступна ›'),
    t('остання »'),
    t('Товари, на які посилається поле field_bookfields'),
    t('Артикул'),
    t('Новинка'),
    t('Хіт'),
    t('Рекомендуємо'),
    t('Товарні запаси'),
    t('Абсолютний сток'),
    t('Page'),
    t('Data export'),
  );
  $export['store_export'] = $view;

  $view = new view();
  $view->name = 'user_company_hits';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'commerce_order';
  $view->human_name = 'User company hits';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ще';
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Застосувати';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Скинути';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Впорядкувати за';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Зрост';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Спад';
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'input_required' => 0,
      'text_input_required' => array(
        'text_input_required' => array(
          'value' => 'Щоб побачити результат, виберіть довільний фільтр і натисніть "Застосувати"',
          'format' => 'filtered_html',
        ),
      ),
      'allow_secondary' => 0,
      'secondary_label' => 'Розширені параметри',
      'secondary_collapse_override' => '0',
    ),
    'pager' => array(
      'bef_format' => 'default',
      'is_secondary' => 0,
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'КІЛЬКІСТЬ ДЛЯ ВІДОБРАЖЕННЯ:';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '12, 24, 48, 60';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Усе -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Зміщення';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« перша';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ попередня';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'наступна ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'остання »';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Зв'язок: Торгівля: Замовлення: Власник */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'commerce_order';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['required'] = TRUE;
  /* Зв'язок: Торгівля: Замовлення: Позиції обліку за посиланнями */
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['id'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['table'] = 'field_data_commerce_line_items';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['field'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['relationships']['commerce_line_items_line_item_id']['required'] = TRUE;
  /* Поле: Торгівля: Позиція обліку: Товар */
  $handler->display->display_options['fields']['commerce_product']['id'] = 'commerce_product';
  $handler->display->display_options['fields']['commerce_product']['table'] = 'field_data_commerce_product';
  $handler->display->display_options['fields']['commerce_product']['field'] = 'commerce_product';
  $handler->display->display_options['fields']['commerce_product']['relationship'] = 'commerce_line_items_line_item_id';
  $handler->display->display_options['fields']['commerce_product']['label'] = '';
  $handler->display->display_options['fields']['commerce_product']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['commerce_product']['alter']['text'] = '[commerce_product-product_id] ';
  $handler->display->display_options['fields']['commerce_product']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['commerce_product']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['commerce_product']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['commerce_product']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['commerce_product']['type'] = 'commerce_product_reference_rendered_product';
  $handler->display->display_options['fields']['commerce_product']['settings'] = array(
    'view_mode' => 'commerce_line_item_token',
    'page' => 0,
  );
  /* Поле: COUNT(Торгівля: Замовлення: ID замовлення) */
  $handler->display->display_options['fields']['order_id']['id'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['fields']['order_id']['field'] = 'order_id';
  $handler->display->display_options['fields']['order_id']['group_type'] = 'count';
  $handler->display->display_options['fields']['order_id']['label'] = 'Було замовлень';
  /* Критерій впорядкування: COUNT(Торгівля: Замовлення: ID замовлення) */
  $handler->display->display_options['sorts']['order_id']['id'] = 'order_id';
  $handler->display->display_options['sorts']['order_id']['table'] = 'commerce_order';
  $handler->display->display_options['sorts']['order_id']['field'] = 'order_id';
  $handler->display->display_options['sorts']['order_id']['group_type'] = 'count';
  $handler->display->display_options['sorts']['order_id']['order'] = 'DESC';
  /* Контекстний фільтр: Користувач: Компанія (field_company) */
  $handler->display->display_options['arguments']['field_company_target_id']['id'] = 'field_company_target_id';
  $handler->display->display_options['arguments']['field_company_target_id']['table'] = 'field_data_field_company';
  $handler->display->display_options['arguments']['field_company_target_id']['field'] = 'field_company_target_id';
  $handler->display->display_options['arguments']['field_company_target_id']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['field_company_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_company_target_id']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['field_company_target_id']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_company_target_id']['default_argument_options']['code'] = 'global $user;
$uid = $user->uid;
$account = user_load($uid);
$company_nid = $account->field_company[\'und\'][0][\'target_id\'];
return $company_nid;';
  $handler->display->display_options['arguments']['field_company_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_company_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_company_target_id']['summary_options']['items_per_page'] = '25';
  /* Критерій фільтрування: Торгівля: Замовлення: Тип замовлення */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'commerce_order';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'commerce_order' => 'commerce_order',
  );

  /* Display: Сторінка */
  $handler = $view->new_display('page', 'Сторінка', 'page_1');
  $handler->display->display_options['field_language_add_to_query'] = 0;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'books/company-hits';
  $translatables['user_company_hits'] = array(
    t('Master'),
    t('ще'),
    t('Застосувати'),
    t('Скинути'),
    t('Впорядкувати за'),
    t('Зрост'),
    t('Спад'),
    t('Щоб побачити результат, виберіть довільний фільтр і натисніть "Застосувати"'),
    t('Розширені параметри'),
    t('КІЛЬКІСТЬ ДЛЯ ВІДОБРАЖЕННЯ:'),
    t('- Усе -'),
    t('Зміщення'),
    t('« перша'),
    t('‹ попередня'),
    t('наступна ›'),
    t('остання »'),
    t('Власник замовлення'),
    t('Позиції обліку, на які посилаються commerce_line_items'),
    t('[commerce_product-product_id] '),
    t('Було замовлень'),
    t('Все'),
    t('Сторінка'),
  );
  $export['user_company_hits'] = $view;

  $view = new view();
  $view->name = 'user_wishlist';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Вішліст юзера';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Список бажань';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ще';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Застосувати';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Скинути';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Впорядкувати за';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Зрост';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Спад';
  $handler->display->display_options['pager']['type'] = 'load_more';
  $handler->display->display_options['pager']['options']['items_per_page'] = '12';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Елементів на сторінку';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Усе -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Зміщення';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« перша';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ попередня';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'наступна ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'остання »';
  $handler->display->display_options['pager']['options']['more_button_text'] = 'Дивитись більше';
  $handler->display->display_options['pager']['options']['effects']['speed'] = 'slow';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Зв'язок: Вміст: Товари за посиланнями */
  $handler->display->display_options['relationships']['field_bookfields_product_id']['id'] = 'field_bookfields_product_id';
  $handler->display->display_options['relationships']['field_bookfields_product_id']['table'] = 'field_data_field_bookfields';
  $handler->display->display_options['relationships']['field_bookfields_product_id']['field'] = 'field_bookfields_product_id';
  $handler->display->display_options['relationships']['field_bookfields_product_id']['required'] = TRUE;
  /* Зв'язок: Прапори: bookmarks */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'bookmarks';
  /* Поле: Торгівля: Товар: Стан */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'commerce_product';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['relationship'] = 'field_bookfields_product_id';
  $handler->display->display_options['fields']['status']['label'] = 'Доступно для замовлення';
  $handler->display->display_options['fields']['status']['type'] = 'unicode-yes-no';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Поле: Поле: Зображення обкладинки */
  $handler->display->display_options['fields']['field_nni']['id'] = 'field_nni';
  $handler->display->display_options['fields']['field_nni']['table'] = 'field_data_field_nni';
  $handler->display->display_options['fields']['field_nni']['field'] = 'field_nni';
  $handler->display->display_options['fields']['field_nni']['label'] = 'Обкладинка';
  $handler->display->display_options['fields']['field_nni']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_nni']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Поле: Вміст: Заголовок */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Поле: Вміст: Оригінальна назва */
  $handler->display->display_options['fields']['field_origin_name']['id'] = 'field_origin_name';
  $handler->display->display_options['fields']['field_origin_name']['table'] = 'field_data_field_origin_name';
  $handler->display->display_options['fields']['field_origin_name']['field'] = 'field_origin_name';
  /* Поле: Вміст: Автор */
  $handler->display->display_options['fields']['field_book_author']['id'] = 'field_book_author';
  $handler->display->display_options['fields']['field_book_author']['table'] = 'field_data_field_book_author';
  $handler->display->display_options['fields']['field_book_author']['field'] = 'field_book_author';
  /* Поле: Вміст: Видавництво */
  $handler->display->display_options['fields']['field_book_publisher']['id'] = 'field_book_publisher';
  $handler->display->display_options['fields']['field_book_publisher']['table'] = 'field_data_field_book_publisher';
  $handler->display->display_options['fields']['field_book_publisher']['field'] = 'field_book_publisher';
  $handler->display->display_options['fields']['field_book_publisher']['label'] = 'Видавнитво';
  /* Поле: Вміст: Мова */
  $handler->display->display_options['fields']['field_lang']['id'] = 'field_lang';
  $handler->display->display_options['fields']['field_lang']['table'] = 'field_data_field_lang';
  $handler->display->display_options['fields']['field_lang']['field'] = 'field_lang';
  /* Поле: Вміст: Новинка */
  $handler->display->display_options['fields']['field_isnew']['id'] = 'field_isnew';
  $handler->display->display_options['fields']['field_isnew']['table'] = 'field_data_field_isnew';
  $handler->display->display_options['fields']['field_isnew']['field'] = 'field_isnew';
  $handler->display->display_options['fields']['field_isnew']['type'] = 'list_key';
  /* Поле: Вміст: Хіт */
  $handler->display->display_options['fields']['field_hit']['id'] = 'field_hit';
  $handler->display->display_options['fields']['field_hit']['table'] = 'field_data_field_hit';
  $handler->display->display_options['fields']['field_hit']['field'] = 'field_hit';
  $handler->display->display_options['fields']['field_hit']['type'] = 'list_key';
  /* Поле: Вміст: Рекомендуємо */
  $handler->display->display_options['fields']['field_bookbox_rec']['id'] = 'field_bookbox_rec';
  $handler->display->display_options['fields']['field_bookbox_rec']['table'] = 'field_data_field_bookbox_rec';
  $handler->display->display_options['fields']['field_bookbox_rec']['field'] = 'field_bookbox_rec';
  $handler->display->display_options['fields']['field_bookbox_rec']['label'] = 'Bookbox рекомендує';
  $handler->display->display_options['fields']['field_bookbox_rec']['type'] = 'list_key';
  /* Поле: Прапори: Час встановлення прапора */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'flagging';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Дата';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'custom';
  $handler->display->display_options['fields']['timestamp']['custom_date_format'] = 'd.m.Y';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Критерій впорядкування: Прапори: Час встановлення прапора */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'flagging';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Контекстний фільтр: Прапори: User uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'flagging';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['exception']['title'] = 'Все';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Критерій фільтрування: Вміст: Опубліковано */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Критерій фільтрування: Вміст: Тип */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'book' => 'book',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'user/favorites';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Список бажань';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Блок */
  $handler = $view->new_display('block', 'Блок', 'block_1');
  $translatables['user_wishlist'] = array(
    t('Master'),
    t('Список бажань'),
    t('ще'),
    t('Застосувати'),
    t('Скинути'),
    t('Впорядкувати за'),
    t('Зрост'),
    t('Спад'),
    t('Елементів на сторінку'),
    t('- Усе -'),
    t('Зміщення'),
    t('« перша'),
    t('‹ попередня'),
    t('наступна ›'),
    t('остання »'),
    t('Дивитись більше'),
    t('Товари, на які посилається поле field_bookfields'),
    t('прапор'),
    t('Доступно для замовлення'),
    t('Обкладинка'),
    t('Оригінальна назва'),
    t('Автор'),
    t('Видавнитво'),
    t('Мова'),
    t('Новинка'),
    t('Хіт'),
    t('Bookbox рекомендує'),
    t('Дата'),
    t('Все'),
    t('Page'),
    t('Блок'),
  );
  $export['user_wishlist'] = $view;

  $view = new view();
  $view->name = 'users';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Юзери';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Юзери';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'ще';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Застосувати';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Скинути';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Впорядкувати за';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Зрост';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Спад';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Елементів на сторінку';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Усе -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Зміщення';
  $handler->display->display_options['pager']['options']['tags']['first'] = '« перша';
  $handler->display->display_options['pager']['options']['tags']['previous'] = '‹ попередня';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'наступна ›';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'остання »';
  $handler->display->display_options['style_plugin'] = 'table_megarows';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['scroll_padding'] = '120';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Поле: Користувач: Назва (ім'я) */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Поле: Користувач: Ім'я */
  $handler->display->display_options['fields']['field_name']['id'] = 'field_name';
  $handler->display->display_options['fields']['field_name']['table'] = 'field_data_field_name';
  $handler->display->display_options['fields']['field_name']['field'] = 'field_name';
  /* Поле: Користувач: Прізвище */
  $handler->display->display_options['fields']['field_sirname']['id'] = 'field_sirname';
  $handler->display->display_options['fields']['field_sirname']['table'] = 'field_data_field_sirname';
  $handler->display->display_options['fields']['field_sirname']['field'] = 'field_sirname';
  /* Поле: Користувач: Компанія */
  $handler->display->display_options['fields']['field_company']['id'] = 'field_company';
  $handler->display->display_options['fields']['field_company']['table'] = 'field_data_field_company';
  $handler->display->display_options['fields']['field_company']['field'] = 'field_company';
  $handler->display->display_options['fields']['field_company']['settings'] = array(
    'link' => 0,
  );
  /* Поле: Користувач: Дата створення */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd.m.Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Поле: Користувач: Активно */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Критерій впорядкування: Користувач: Дата створення */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Критерій фільтрування: Користувач: Активно */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/bookbox/users';
  $translatables['users'] = array(
    t('Master'),
    t('Юзери'),
    t('ще'),
    t('Застосувати'),
    t('Скинути'),
    t('Впорядкувати за'),
    t('Зрост'),
    t('Спад'),
    t('Елементів на сторінку'),
    t('- Усе -'),
    t('Зміщення'),
    t('« перша'),
    t('‹ попередня'),
    t('наступна ›'),
    t('остання »'),
    t('Ім\'я'),
    t('Прізвище'),
    t('Компанія'),
    t('Дата створення'),
    t('Активно'),
    t('Page'),
  );
  $export['users'] = $view;

  return $export;
}
