<?php
/**
 * @file
 * Shield module's admin funcions.
 */

/**
 * Administration settings form
 */
function shield_full_admin_settings($form, &$form_state) {
  $form['description'] = array(
    '#type' => 'item',
    '#title' => t('Shield full settings'),
    '#description' => t('Set up credentials for an authenticated user. You can also decide whether you want to print out the credentials or not.'),
  );

  $form['general'] = array(
    '#type' => 'fieldset',
    '#title' => t('General settings'),
   );

  $form['general']['shield_full_allow_cli'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow command line access'),
    '#description' => t('When the site is accessed from command line (e.g. from Drush, cron), the shield full should not work.'),
    '#default_value' => variable_get('shield_full_allow_cli', 1),
  );

  $form['credentials'] = array(
    '#type' => 'fieldset',
    '#title' => t('Credentials'),
   );

  $form['credentials']['shield_full_user'] = array(
    '#type' => 'textfield',
    '#title' => t('User'),
    '#default_value' => variable_get('shield_full_user', ''),
    '#description' => t('Live it blank to disable authentication.')
  );

  $form['credentials']['shield_full_pass'] = array(
    '#type' => 'textfield',
    '#title' => t('Password'),
    '#default_value' => variable_get('shield_full_pass', ''),
  );

  $form['shield_full_print'] = array(
    '#type' => 'textfield',
    '#title' => t('Authentication message'),
    '#description' => t("The message to print in the authentication request popup. You can use [user] and [pass] to print the user and the password respectively. You can leave it empty, if you don't want to print out any special message to the users."),
    '#default_value' => variable_get('shield_full_print', 'Hello, user: [user], pass: [pass]!'),
  );


  $form['shield_full_access'] = array(
    '#type' => 'radios',
    '#title' => t('Pages which will be be shield full'),
    '#default_value' => variable_get('shield_full_access', 1),
    '#options' => array(t('Make "Shield full" every page except the listed pages.'), t('Make "Shield full" only the listed pages.')),
  );

  $form['shield_full_pages'] = array(
    '#type' => 'textarea',
    '#title' => t('Shield full pages'),
    '#default_value' => variable_get('shield_full_pages', ''),
    '#cols' => 40,
    '#rows' => 5,
    '#description' => t("Enter one page per line as Drupal paths. The '*' character is a wildcard. Example paths are '<em>blog</em>' for the main blog page and '<em>blog/*</em>' for every personal blog. '<em>&lt;front&gt;</em>' is the front page."),
  );

  $trail = '';
  $form['shield_full_ignore'] = array(
    '#type' => 'textfield',
    '#title' => t('Shield full ignore pages'),
    '#default_value' => variable_get('shield_full_ignore', $trail),
    '#size' => 255,
    '#maxlength' => 255,
  );
  return system_settings_form($form);
}
