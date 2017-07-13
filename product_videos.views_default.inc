<?php
/**
 * @file
 * product_videos.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function product_videos_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'product_video_search';
  $view->description = 'Display products with referencing videos, and provide search capabilities.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Product Video Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Support Videos';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '40';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<p>Select your manufacturer or enter your model number above to find the right support videos for your needs.</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'It looks like your search returned no results. You can either go back to the advanced search options and try a different search or <a href="/product-video-search">click here to reset your search</a>.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_video_product_reference_node']['id'] = 'reverse_field_video_product_reference_node';
  $handler->display->display_options['relationships']['reverse_field_video_product_reference_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_video_product_reference_node']['field'] = 'reverse_field_video_product_reference_node';
  $handler->display->display_options['relationships']['reverse_field_video_product_reference_node']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Primary Image */
  $handler->display->display_options['fields']['field_primary_image']['id'] = 'field_primary_image';
  $handler->display->display_options['fields']['field_primary_image']['table'] = 'field_data_field_primary_image';
  $handler->display->display_options['fields']['field_primary_image']['field'] = 'field_primary_image';
  $handler->display->display_options['fields']['field_primary_image']['label'] = '';
  $handler->display->display_options['fields']['field_primary_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_primary_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_primary_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_primary_image']['settings'] = array(
    'image_style' => 'catalog-product-secondary',
    'image_link' => '',
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Manufacturer */
  $handler->display->display_options['fields']['field_catalog_manufacturer']['id'] = 'field_catalog_manufacturer';
  $handler->display->display_options['fields']['field_catalog_manufacturer']['table'] = 'field_data_field_catalog_manufacturer';
  $handler->display->display_options['fields']['field_catalog_manufacturer']['field'] = 'field_catalog_manufacturer';
  $handler->display->display_options['fields']['field_catalog_manufacturer']['label'] = '';
  $handler->display->display_options['fields']['field_catalog_manufacturer']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_catalog_manufacturer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_catalog_manufacturer']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_catalog_manufacturer']['delta_offset'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="catalog-product">
<div class="inner">
<div class="catalog-product-image"><div class="inner-inner">[field_primary_image]</div></div>
<div class="catalog-product-manufacturer">[field_catalog_manufacturer]</div>
<div class="catalog-product-title">[title]</div> 
<div class="service-videos"><a class="btn button" href="/product-videos/[nid]">Support Videos</a></div>
</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Manufacturer (field_catalog_manufacturer) */
  $handler->display->display_options['sorts']['field_catalog_manufacturer_tid']['id'] = 'field_catalog_manufacturer_tid';
  $handler->display->display_options['sorts']['field_catalog_manufacturer_tid']['table'] = 'field_data_field_catalog_manufacturer';
  $handler->display->display_options['sorts']['field_catalog_manufacturer_tid']['field'] = 'field_catalog_manufacturer_tid';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'catalog_product' => 'catalog_product',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Manufacturer (field_catalog_manufacturer) */
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['id'] = 'field_catalog_manufacturer_tid';
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['table'] = 'field_data_field_catalog_manufacturer';
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['field'] = 'field_catalog_manufacturer_tid';
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['expose']['operator_id'] = 'field_catalog_manufacturer_tid_op';
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['expose']['label'] = 'Manufacturer';
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['expose']['operator'] = 'field_catalog_manufacturer_tid_op';
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['expose']['identifier'] = 'field_catalog_manufacturer_tid';
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_catalog_manufacturer_tid']['vocabulary'] = 'copier_catalog_manufacturer';
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Model';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'video_search_page');
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'product-video-search';
  $export['product_video_search'] = $view;

  $view = new view();
  $view->name = 'product_videos';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Product Videos';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Product Videos';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['pure_distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_product_video_video_url]';
  $handler->display->display_options['fields']['title']['alter']['link_class'] = 'colorbox-load';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_product_reference_target_id']['id'] = 'field_product_reference_target_id';
  $handler->display->display_options['arguments']['field_product_reference_target_id']['table'] = 'field_data_field_product_reference';
  $handler->display->display_options['arguments']['field_product_reference_target_id']['field'] = 'field_product_reference_target_id';
  $handler->display->display_options['arguments']['field_product_reference_target_id']['relationship'] = 'reverse_field_product_reference_node';
  $handler->display->display_options['arguments']['field_product_reference_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_product_reference_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_product_reference_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_product_reference_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_product_reference_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product_video' => 'product_video',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Support Videos';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_video_category',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['class'] = 'video-group';
  $handler->display->display_options['style_options']['wrapper_class'] = 'video-category';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="product-title"><h2>[title_1]</h2></div>
<div class="product-image col-sm-12">[field_primary_image]</div>
';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<h3>There are no service videos available for this product, at this time. Please check back soon.</h3>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_video_product_reference_target_id']['id'] = 'field_video_product_reference_target_id';
  $handler->display->display_options['relationships']['field_video_product_reference_target_id']['table'] = 'field_data_field_video_product_reference';
  $handler->display->display_options['relationships']['field_video_product_reference_target_id']['field'] = 'field_video_product_reference_target_id';
  $handler->display->display_options['relationships']['field_video_product_reference_target_id']['required'] = TRUE;
  /* Relationship: Content: Video Category (field_video_category) */
  $handler->display->display_options['relationships']['field_video_category_tid']['id'] = 'field_video_category_tid';
  $handler->display->display_options['relationships']['field_video_category_tid']['table'] = 'field_data_field_video_category';
  $handler->display->display_options['relationships']['field_video_category_tid']['field'] = 'field_video_category_tid';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Primary Image */
  $handler->display->display_options['fields']['field_primary_image']['id'] = 'field_primary_image';
  $handler->display->display_options['fields']['field_primary_image']['table'] = 'field_data_field_primary_image';
  $handler->display->display_options['fields']['field_primary_image']['field'] = 'field_primary_image';
  $handler->display->display_options['fields']['field_primary_image']['relationship'] = 'field_video_product_reference_target_id';
  $handler->display->display_options['fields']['field_primary_image']['label'] = '';
  $handler->display->display_options['fields']['field_primary_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_primary_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_primary_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_primary_image']['settings'] = array(
    'image_style' => 'support_videos',
    'image_link' => '',
  );
  /* Field: Content: Manufacturer */
  $handler->display->display_options['fields']['field_catalog_manufacturer']['id'] = 'field_catalog_manufacturer';
  $handler->display->display_options['fields']['field_catalog_manufacturer']['table'] = 'field_data_field_catalog_manufacturer';
  $handler->display->display_options['fields']['field_catalog_manufacturer']['field'] = 'field_catalog_manufacturer';
  $handler->display->display_options['fields']['field_catalog_manufacturer']['label'] = '';
  $handler->display->display_options['fields']['field_catalog_manufacturer']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_catalog_manufacturer']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_catalog_manufacturer']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_catalog_manufacturer']['delta_offset'] = '0';
  /* Field: Content: Video - Video URL */
  $handler->display->display_options['fields']['field_product_video_video_url']['id'] = 'field_product_video_video_url';
  $handler->display->display_options['fields']['field_product_video_video_url']['table'] = 'field_data_field_product_video';
  $handler->display->display_options['fields']['field_product_video_video_url']['field'] = 'field_product_video_video_url';
  $handler->display->display_options['fields']['field_product_video_video_url']['label'] = '';
  $handler->display->display_options['fields']['field_product_video_video_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_product_video_video_url']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<p class="video-lightbox" vid-src="[field_product_video_video_url]">[title]</p>';
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_product_video_video_url]';
  $handler->display->display_options['fields']['title']['alter']['link_class'] = 'colorbox-load';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Video Category */
  $handler->display->display_options['fields']['field_video_category']['id'] = 'field_video_category';
  $handler->display->display_options['fields']['field_video_category']['table'] = 'field_data_field_video_category';
  $handler->display->display_options['fields']['field_video_category']['field'] = 'field_video_category';
  $handler->display->display_options['fields']['field_video_category']['label'] = '';
  $handler->display->display_options['fields']['field_video_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_video_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_video_category']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_video_product_reference_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Video Category (field_video_category) */
  $handler->display->display_options['sorts']['field_video_category_tid']['id'] = 'field_video_category_tid';
  $handler->display->display_options['sorts']['field_video_category_tid']['table'] = 'field_data_field_video_category';
  $handler->display->display_options['sorts']['field_video_category_tid']['field'] = 'field_video_category_tid';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Product Reference (field_video_product_reference) */
  $handler->display->display_options['arguments']['field_video_product_reference_target_id']['id'] = 'field_video_product_reference_target_id';
  $handler->display->display_options['arguments']['field_video_product_reference_target_id']['table'] = 'field_data_field_video_product_reference';
  $handler->display->display_options['arguments']['field_video_product_reference_target_id']['field'] = 'field_video_product_reference_target_id';
  $handler->display->display_options['arguments']['field_video_product_reference_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_video_product_reference_target_id']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_video_product_reference_target_id']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['field_video_product_reference_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_video_product_reference_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_video_product_reference_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product_video' => 'product_video',
  );
  $handler->display->display_options['path'] = 'product-videos';

  /* Display: Product Page: Block */
  $handler = $view->new_display('block', 'Product Page: Block', 'block_1');
  $handler->display->display_options['display_description'] = 'Display videos related to current product.';
  $handler->display->display_options['block_description'] = 'Product Videos';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $export['product_videos'] = $view;

  $view = new view();
  $view->name = 'products';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Products';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Products';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Relationship: Content: Manufacturer (field_catalog_manufacturer) */
  $handler->display->display_options['relationships']['field_catalog_manufacturer_tid']['id'] = 'field_catalog_manufacturer_tid';
  $handler->display->display_options['relationships']['field_catalog_manufacturer_tid']['table'] = 'field_data_field_catalog_manufacturer';
  $handler->display->display_options['relationships']['field_catalog_manufacturer_tid']['field'] = 'field_catalog_manufacturer_tid';
  $handler->display->display_options['relationships']['field_catalog_manufacturer_tid']['required'] = TRUE;
  /* Relationship: Broken/missing handler */
  $handler->display->display_options['relationships']['reverse_field_catalog_manufacturer_user']['id'] = 'reverse_field_catalog_manufacturer_user';
  $handler->display->display_options['relationships']['reverse_field_catalog_manufacturer_user']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['relationships']['reverse_field_catalog_manufacturer_user']['field'] = 'reverse_field_catalog_manufacturer_user';
  $handler->display->display_options['relationships']['reverse_field_catalog_manufacturer_user']['relationship'] = 'field_catalog_manufacturer_tid';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Content: Manufacturer */
  $handler->display->display_options['fields']['field_catalog_manufacturer']['id'] = 'field_catalog_manufacturer';
  $handler->display->display_options['fields']['field_catalog_manufacturer']['table'] = 'field_data_field_catalog_manufacturer';
  $handler->display->display_options['fields']['field_catalog_manufacturer']['field'] = 'field_catalog_manufacturer';
  $handler->display->display_options['fields']['field_catalog_manufacturer']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_catalog_manufacturer']['delta_offset'] = '0';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_language']['id'] = 'field_language';
  $handler->display->display_options['fields']['field_language']['table'] = 'field_data_field_language';
  $handler->display->display_options['fields']['field_language']['field'] = 'field_language';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Product';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Brochure */
  $handler->display->display_options['fields']['field_catalog_brochure']['id'] = 'field_catalog_brochure';
  $handler->display->display_options['fields']['field_catalog_brochure']['table'] = 'field_data_field_catalog_brochure';
  $handler->display->display_options['fields']['field_catalog_brochure']['field'] = 'field_catalog_brochure';
  $handler->display->display_options['fields']['field_catalog_brochure']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_catalog_brochure']['alter']['text'] = '[field_catalog_brochure-url]';
  $handler->display->display_options['fields']['field_catalog_brochure']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_catalog_brochure']['type'] = 'link_plain';
  /* Field: Content: Color or Black & White */
  $handler->display->display_options['fields']['field_color_or_black_white']['id'] = 'field_color_or_black_white';
  $handler->display->display_options['fields']['field_color_or_black_white']['table'] = 'field_data_field_color_or_black_white';
  $handler->display->display_options['fields']['field_color_or_black_white']['field'] = 'field_color_or_black_white';
  /* Field: Content: Family */
  $handler->display->display_options['fields']['field_catalog_family']['id'] = 'field_catalog_family';
  $handler->display->display_options['fields']['field_catalog_family']['table'] = 'field_data_field_catalog_family';
  $handler->display->display_options['fields']['field_catalog_family']['field'] = 'field_catalog_family';
  $handler->display->display_options['fields']['field_catalog_family']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Highlights */
  $handler->display->display_options['fields']['field_highlights']['id'] = 'field_highlights';
  $handler->display->display_options['fields']['field_highlights']['table'] = 'field_data_field_highlights';
  $handler->display->display_options['fields']['field_highlights']['field'] = 'field_highlights';
  $handler->display->display_options['fields']['field_highlights']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_highlights']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_highlights']['separator'] = '~';
  /* Field: Content: Price */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Primary Image */
  $handler->display->display_options['fields']['field_primary_image']['id'] = 'field_primary_image';
  $handler->display->display_options['fields']['field_primary_image']['table'] = 'field_data_field_primary_image';
  $handler->display->display_options['fields']['field_primary_image']['field'] = 'field_primary_image';
  $handler->display->display_options['fields']['field_primary_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_primary_image']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_primary_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Secondary Image 1 */
  $handler->display->display_options['fields']['field_secondary_image_1']['id'] = 'field_secondary_image_1';
  $handler->display->display_options['fields']['field_secondary_image_1']['table'] = 'field_data_field_secondary_image_1';
  $handler->display->display_options['fields']['field_secondary_image_1']['field'] = 'field_secondary_image_1';
  $handler->display->display_options['fields']['field_secondary_image_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_secondary_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_secondary_image_1']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_secondary_image_1']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Secondary Image 2 */
  $handler->display->display_options['fields']['field_secondary_image_2']['id'] = 'field_secondary_image_2';
  $handler->display->display_options['fields']['field_secondary_image_2']['table'] = 'field_data_field_secondary_image_2';
  $handler->display->display_options['fields']['field_secondary_image_2']['field'] = 'field_secondary_image_2';
  $handler->display->display_options['fields']['field_secondary_image_2']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_secondary_image_2']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_secondary_image_2']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Secondary Image 3 */
  $handler->display->display_options['fields']['field_secondary_image_3']['id'] = 'field_secondary_image_3';
  $handler->display->display_options['fields']['field_secondary_image_3']['table'] = 'field_data_field_secondary_image_3';
  $handler->display->display_options['fields']['field_secondary_image_3']['field'] = 'field_secondary_image_3';
  $handler->display->display_options['fields']['field_secondary_image_3']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_secondary_image_3']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_secondary_image_3']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_summary']['id'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['table'] = 'field_data_field_summary';
  $handler->display->display_options['fields']['field_summary']['field'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['alter']['trim_whitespace'] = TRUE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_type']['id'] = 'field_type';
  $handler->display->display_options['fields']['field_type']['table'] = 'field_data_field_type';
  $handler->display->display_options['fields']['field_type']['field'] = 'field_type';
  /* Field: Content: Virtual Demo */
  $handler->display->display_options['fields']['field_catalog_virtual_demo']['id'] = 'field_catalog_virtual_demo';
  $handler->display->display_options['fields']['field_catalog_virtual_demo']['table'] = 'field_data_field_catalog_virtual_demo';
  $handler->display->display_options['fields']['field_catalog_virtual_demo']['field'] = 'field_catalog_virtual_demo';
  $handler->display->display_options['fields']['field_catalog_virtual_demo']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_catalog_virtual_demo']['type'] = 'link_plain';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Content: Speed */
  $handler->display->display_options['fields']['field_speed2']['id'] = 'field_speed2';
  $handler->display->display_options['fields']['field_speed2']['table'] = 'field_data_field_speed2';
  $handler->display->display_options['fields']['field_speed2']['field'] = 'field_speed2';
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['relationship'] = 'field_catalog_manufacturer_tid';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['sorts']['title']['order'] = 'DESC';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'reverse_field_catalog_manufacturer_user';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['index'] = '2';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Broken/missing handler */
  $handler->display->display_options['arguments']['field_language_tid']['id'] = 'field_language_tid';
  $handler->display->display_options['arguments']['field_language_tid']['table'] = 'field_data_field_language';
  $handler->display->display_options['arguments']['field_language_tid']['field'] = 'field_language_tid';
  $handler->display->display_options['arguments']['field_language_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_language_tid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_language_tid']['default_argument_options']['code'] = '$user = user_load(arg(2));
if(!empty($user->field_language)) {
  return $user->field_language[LANGUAGE_NONE][0][\'tid\'];
}
else{
  return 0;
}';
  $handler->display->display_options['arguments']['field_language_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_language_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_language_tid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'catalog_product' => 'catalog_product',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Content: Manufacturer */
  $handler->display->display_options['fields']['field_catalog_manufacturer']['id'] = 'field_catalog_manufacturer';
  $handler->display->display_options['fields']['field_catalog_manufacturer']['table'] = 'field_data_field_catalog_manufacturer';
  $handler->display->display_options['fields']['field_catalog_manufacturer']['field'] = 'field_catalog_manufacturer';
  $handler->display->display_options['fields']['field_catalog_manufacturer']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_catalog_manufacturer']['delta_offset'] = '0';
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_language']['id'] = 'field_language';
  $handler->display->display_options['fields']['field_language']['table'] = 'field_data_field_language';
  $handler->display->display_options['fields']['field_language']['field'] = 'field_language';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Product';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Brochure */
  $handler->display->display_options['fields']['field_catalog_brochure']['id'] = 'field_catalog_brochure';
  $handler->display->display_options['fields']['field_catalog_brochure']['table'] = 'field_data_field_catalog_brochure';
  $handler->display->display_options['fields']['field_catalog_brochure']['field'] = 'field_catalog_brochure';
  $handler->display->display_options['fields']['field_catalog_brochure']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_catalog_brochure']['alter']['text'] = '[field_catalog_brochure-url]';
  $handler->display->display_options['fields']['field_catalog_brochure']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_catalog_brochure']['type'] = 'link_plain';
  /* Field: Content: Color or Black & White */
  $handler->display->display_options['fields']['field_color_or_black_white']['id'] = 'field_color_or_black_white';
  $handler->display->display_options['fields']['field_color_or_black_white']['table'] = 'field_data_field_color_or_black_white';
  $handler->display->display_options['fields']['field_color_or_black_white']['field'] = 'field_color_or_black_white';
  /* Field: Content: Family */
  $handler->display->display_options['fields']['field_catalog_family']['id'] = 'field_catalog_family';
  $handler->display->display_options['fields']['field_catalog_family']['table'] = 'field_data_field_catalog_family';
  $handler->display->display_options['fields']['field_catalog_family']['field'] = 'field_catalog_family';
  $handler->display->display_options['fields']['field_catalog_family']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Highlights */
  $handler->display->display_options['fields']['field_highlights']['id'] = 'field_highlights';
  $handler->display->display_options['fields']['field_highlights']['table'] = 'field_data_field_highlights';
  $handler->display->display_options['fields']['field_highlights']['field'] = 'field_highlights';
  $handler->display->display_options['fields']['field_highlights']['alter']['trim_whitespace'] = TRUE;
  $handler->display->display_options['fields']['field_highlights']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_highlights']['separator'] = '~';
  /* Field: Content: Price */
  $handler->display->display_options['fields']['field_price']['id'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['table'] = 'field_data_field_price';
  $handler->display->display_options['fields']['field_price']['field'] = 'field_price';
  $handler->display->display_options['fields']['field_price']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Primary Image */
  $handler->display->display_options['fields']['field_primary_image']['id'] = 'field_primary_image';
  $handler->display->display_options['fields']['field_primary_image']['table'] = 'field_data_field_primary_image';
  $handler->display->display_options['fields']['field_primary_image']['field'] = 'field_primary_image';
  $handler->display->display_options['fields']['field_primary_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_primary_image']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_primary_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Secondary Image 1 */
  $handler->display->display_options['fields']['field_secondary_image_1']['id'] = 'field_secondary_image_1';
  $handler->display->display_options['fields']['field_secondary_image_1']['table'] = 'field_data_field_secondary_image_1';
  $handler->display->display_options['fields']['field_secondary_image_1']['field'] = 'field_secondary_image_1';
  $handler->display->display_options['fields']['field_secondary_image_1']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_secondary_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_secondary_image_1']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_secondary_image_1']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Secondary Image 2 */
  $handler->display->display_options['fields']['field_secondary_image_2']['id'] = 'field_secondary_image_2';
  $handler->display->display_options['fields']['field_secondary_image_2']['table'] = 'field_data_field_secondary_image_2';
  $handler->display->display_options['fields']['field_secondary_image_2']['field'] = 'field_secondary_image_2';
  $handler->display->display_options['fields']['field_secondary_image_2']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_secondary_image_2']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_secondary_image_2']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Secondary Image 3 */
  $handler->display->display_options['fields']['field_secondary_image_3']['id'] = 'field_secondary_image_3';
  $handler->display->display_options['fields']['field_secondary_image_3']['table'] = 'field_data_field_secondary_image_3';
  $handler->display->display_options['fields']['field_secondary_image_3']['field'] = 'field_secondary_image_3';
  $handler->display->display_options['fields']['field_secondary_image_3']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_secondary_image_3']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_secondary_image_3']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Summary */
  $handler->display->display_options['fields']['field_summary']['id'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['table'] = 'field_data_field_summary';
  $handler->display->display_options['fields']['field_summary']['field'] = 'field_summary';
  $handler->display->display_options['fields']['field_summary']['alter']['trim_whitespace'] = TRUE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_type']['id'] = 'field_type';
  $handler->display->display_options['fields']['field_type']['table'] = 'field_data_field_type';
  $handler->display->display_options['fields']['field_type']['field'] = 'field_type';
  /* Field: Content: Virtual Demo */
  $handler->display->display_options['fields']['field_catalog_virtual_demo']['id'] = 'field_catalog_virtual_demo';
  $handler->display->display_options['fields']['field_catalog_virtual_demo']['table'] = 'field_data_field_catalog_virtual_demo';
  $handler->display->display_options['fields']['field_catalog_virtual_demo']['field'] = 'field_catalog_virtual_demo';
  $handler->display->display_options['fields']['field_catalog_virtual_demo']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_catalog_virtual_demo']['type'] = 'link_plain';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Content: Speed */
  $handler->display->display_options['fields']['field_speed2']['id'] = 'field_speed2';
  $handler->display->display_options['fields']['field_speed2']['table'] = 'field_data_field_speed2';
  $handler->display->display_options['fields']['field_speed2']['field'] = 'field_speed2';
  /* Field: Alt Text */
  $handler->display->display_options['fields']['field_primary_image_1']['id'] = 'field_primary_image_1';
  $handler->display->display_options['fields']['field_primary_image_1']['table'] = 'field_data_field_primary_image';
  $handler->display->display_options['fields']['field_primary_image_1']['field'] = 'field_primary_image';
  $handler->display->display_options['fields']['field_primary_image_1']['ui_name'] = 'Alt Text';
  $handler->display->display_options['fields']['field_primary_image_1']['label'] = 'Primary Image Alt';
  $handler->display->display_options['fields']['field_primary_image_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_primary_image_1']['alter']['text'] = '[field_primary_image_1]';
  $handler->display->display_options['fields']['field_primary_image_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_primary_image_1']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['path'] = 'products';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $export['products'] = $view;

  return $export;
}
