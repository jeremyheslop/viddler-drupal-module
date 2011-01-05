<?php
// $Id: viddler.admin.inc,v 1.2 2011/01/05 03:42:20 jeremyheslop Exp $

/**
 * @file
 * The administrative settings page.
 */

/**
 * Callback for admin/content/viddler.
 */
function viddler_settings() {
  $form = array();
  $form['general'] = array(
    '#type' => 'fieldset',
    '#title' => t('General Settings'),
    '#description' => t('These features will effect all viddler content types.'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['general']['viddler_apikey'] = array(
    '#type' => 'textfield',
    '#title' => t('Viddler Api Key'),
    '#default_value' => variable_get('viddler_apikey', ''),
    '#required' => FALSE,
    '#description' => t('The viddler api key is the only way we can post recorded or uploaded videos to Viddler.'),
  );
  $form['general']['viddler_username'] = array(
    '#type' => 'textfield',
    '#title' => t('Viddler Username'),
    '#default_value' => variable_get('viddler_username', ''),
    '#required' => FALSE,
    '#description' => t('The viddler username that will be used to post videos for this all content types that use the viddler module.'),
  );
  $form['general']['viddler_password'] = array(
    '#type' => 'password',
    '#title' => t('Viddler Password'),
    '#default_value' => variable_get('viddler_password', ''),
    '#required' => FALSE,
    '#description' => t('The viddler password to use with this username.'),
  );
  $form['general']['viddler_delete_allowed'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow Viddler Videos to be Deleted?'),
    '#default_value' => variable_get('viddler_delete_allowed', ''),
    '#required' => FALSE,
    '#description' => t('Viddler videos will not be removed from the account above if unchecked. Videos cannot be if they are not owned by the user above.'),
  );
  $form['general']['viddler_show_debug'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Viddler API messages?'),
    '#default_value' => variable_get('viddler_show_debug', ''),
    '#required' => FALSE,
    '#description' => t('Display Viddler API messages for debugging purposes. Do not check on a production site.'),
  );
  
  return system_settings_form($form);
}