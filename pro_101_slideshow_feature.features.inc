<?php
/**
 * @file
 * pro_101_slideshow_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function pro_101_slideshow_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "flexslider" && $api == "flexslider_default_preset") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function pro_101_slideshow_feature_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function pro_101_slideshow_feature_image_default_styles() {
  $styles = array();

  // Exported image style: slide_wide.
  $styles['slide_wide'] = array(
    'name' => 'slide_wide',
    'effects' => array(
      1 => array(
        'label' => 'Crop and scale manually',
        'help' => 'Crop and scale a user-selected area, respecting the ratio of the destination width and height.',
        'effect callback' => 'manualcrop_crop_and_scale_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'manualcrop_crop_and_scale_form',
        'summary theme' => 'manualcrop_crop_and_scale_summary',
        'module' => 'manualcrop',
        'name' => 'manualcrop_crop_and_scale',
        'data' => array(
          'width' => '1220',
          'height' => '400',
          'upscale' => 1,
          'respectminimum' => 1,
          'onlyscaleifcrop' => 0,
          'style_name' => 'slide_wide',
        ),
        'weight' => '0',
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function pro_101_slideshow_feature_node_info() {
  $items = array(
    'slide' => array(
      'name' => t('Slide'),
      'base' => 'node_content',
      'description' => t('Use <em>Slide</em> to prominently showcase featured content usually on the front page.'),
      'has_title' => '1',
      'title_label' => t('Slide Title'),
      'help' => '',
    ),
  );
  return $items;
}
