<?php

/***************************************************
 * 管理者管理画面(ユーザ追加完了)
 *
 *
 * @package
 * @access  public
 * @author  
 * @create  
 * @version 
 ***************************************************/

require_once('common/base_model_admin_base.inc');

class admin_user_add_fin extends base_model_admin_base {

//
public function initialize() {
  //
  parent::initialize();

  // 「必要なロール」はadminにしておく
  $this->set_need_role_admin();
}

//処理
public function execute_auth() {
//print "Trap 1\n";

  // CSRFチェック
  if (false ==- $this->is_csrf_token()) {
    // XXX 正常ルートだとあんまり想定できないから、top突き返しでいいかねぇ
    $this->redirect_command('top');
    return ;
  }

  // ユーザ情報を取得
  $admin_users_c = $this->get_clump('admin_users_clump');
  $admin_users_c->set_from_cgi_insert($this->get_cgi_request());
  // validate(ユーザID重複はチェックしてない)
  $r = $admin_users_c->is_valid_insert($this->get_conv());
  if (false === $r) {
    $this->forward('admin_user_add');
    return ;
  }

  // 登録
  $r = $admin_users_c->insert();
  if (false === $r) {
    $this->get_conv()->set('insert_error', true);
    $this->forward('admin_user_add');
    return ;
  }

  // 表示
  $this->get_conv()->set('user', $admin_users_c->get_all_view_values());

  //
  return ;
}

} // end of class

