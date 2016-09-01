<?php
/**
 * @file
 */
/**
 * function for send all data to gateway.
 */


function page_send_response_data() {

  $api_key = variable_get('commerce_instamojo_api_key');
  $auth_token = variable_get('commerce_instamojo_auth_token');
  $account_type = variable_get('commerce_instamojo_account_type');

  $api = new InstamojoAPI($api_key, $auth_token, $account_type);

  $payment_response = $api->generatePaymentUrl($_POST);

  drupal_goto($payment_response['payment_request']['longurl']);
}
