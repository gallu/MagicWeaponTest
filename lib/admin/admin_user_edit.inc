<?php

/***************************************************
 * 管理者管理画面(ユーザ編集)
 *
 *
 * @package
 * @access  public
 * @author  
 * @create  
 * @version 
 ***************************************************/

require_once('common/base_model_admin_base.inc');

class admin_user_edit extends base_model_admin_base {

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

  // admin_user_edit_finからのforwardなら(すでにconvん中にデータがあるはずなので)取得処理を行わない
  if (false === $this->is_bag('edit_fin_forward')) {
    // ユーザIDを取得
    $user_id = $this->get_cgi_request()->find('user_id');
    if ('' === $user_id) {
      // ユーザID指定なしなら突き返し
      $this->redirect_command('admin_user_list');
      return ;
    }

    // ユーザ情報を取得
    $admin_users_c = $this->get_clump('admin_users_clump');
    $admin_users_c->set_value('id', $user_id);
    $r = $admin_users_c->get();
    if (false === $r) {
      // ユーザIDが存在しなければ突き返し
      $this->redirect_command('admin_user_list');
      return ;
    }
    // テンプレートに設定
    $this->get_conv()->set($admin_users_c->get_all_view_values());
  }

  // CSRF対策
  $this->set_csrf_token();

  //
  return ;
}

} // end of class

