<?php

/***************************************************
 * form 完了
 *
 *
 * @package
 * @access  public
 * @author  
 * @create  
 * @version 
 ***************************************************/

require_once('common/base_model_front_base.inc');

class form_fin extends base_model_front_base {

//
//public function initialize() {  }
//public function finalize() {  }

//処理
public function execute() {
//print "Trap 1\n";
  // CSRFチェック
  if (false === $this->is_csrf_token()) {
    $this->set_tmp_filename('form_csrf_error.tpl');
    return ;
  }

  // else
  // セッションからデータを取得
  // clumpに一度通してからviewへ
  $form_test_c = $this->get_clump('form_test_clump');
  $form_test_c->set_all_data_from_hash($_SESSION['form_test']);
  // 表示
  $this->get_conv()->set('form', $form_test_c->get_all_view_values());

}

} // end of class

