<?php

/***************************************************
 * form 確認画面
 *
 *
 * @package
 * @access  public
 * @author  
 * @create  
 * @version 
 ***************************************************/

require_once('common/base_model_front_base.inc');
require_once('clump/form_test_clump.inc');

class form_confirm extends base_model_front_base {

//処理
public function execute() {
  // データを取得する
  $form_test_c = $this->get_clump('form_test_clump');
  $form_test_c->set_from_cgi($this->get_cgi_request());
//var_dump($form_test_c->get_all_data_to_hash());

  // validate(定型のみ)
  if (false === $form_test_c->is_valid($this->get_conv())) {
    $this->forward('form_input');
    return ;
  }

  // セッションに保存
  $_SESSION['form_test'] = $form_test_c->get_all_data_to_hash();

  // 表示
  $this->get_conv()->set('form', $form_test_c->get_all_view_values());
  $this->set_csrf_token();
//var_dump($_SESSION);

  //
  return ;
}

} // end of class

