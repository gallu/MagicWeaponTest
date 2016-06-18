<?php

/***************************************************
 * ログアウト画面
 *
 * @package
 * @access  public
 * @author  
 * @create  
 * @version 
 ***************************************************/

require_once('common/base_model_admin_base.inc');

class logout extends base_model_admin_base {

public function initialize() {
  //
  parent::initialize();

  // 「必要なロール」はanyにしておく
  $this->set_need_role_any();
}

//処理
public function execute_auth() {

  // 認可用インスタンス取得
  $authorization_o = $this->get_authorization();

  // ログアウト処理
  $authorization_o->auth_off();

  // XXX 「ログアウトしました」Pageに行ってもいいんだけど、一旦、無味乾燥に「非ログインtop」へ移動
  $this->redirect('./admin.php');
}

} // end of class

