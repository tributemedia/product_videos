<?php
/**
 * @file
 * product_videos.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function product_videos_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "feeds_tamper" && $api == "feeds_tamper_default") {
    return array("version" => "2");
  }
}

/**
 * Implements hook_views_api().
 */
function product_videos_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function product_videos_image_default_styles() {
  $styles = array();

  // Exported image style: support_videos.
  $styles['support_videos'] = array(
    'label' => 'Support Videos',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 300,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function product_videos_node_info() {
  $items = array(
    'product_video' => array(
      'name' => t('Product Video'),
      'base' => 'node_content',
      'description' => t('Service/Support, or Marketing video for catalog products. These videos will reference a specific product(s) in the catalog, and be displayed on the referenced product display page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'video_feed' => array(
      'name' => t('Video Feed'),
      'base' => 'node_content',
      'description' => t('Import product videos.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
