<?php
// $Id: viddler.admin.inc,v 1.1.2.6 2008/11/12 18:14:37 aaron Exp $

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
    '#description' => t('These features will be generally available for use by related modules as needed.'),
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
    '#description' => t('Viddler videos will not be removed from the account above if unchecked.'),
  );
  $form['general']['viddler_show_debug'] = array(
    '#type' => 'checkbox',
    '#title' => t('Show Viddler API messages?'),
    '#default_value' => variable_get('viddler_show_debug', ''),
    '#required' => FALSE,
    '#description' => t('Display Viddler API messages for debugging purposes. Should not check if the site is in production.'),
  );
  
  return system_settings_form($form);
}