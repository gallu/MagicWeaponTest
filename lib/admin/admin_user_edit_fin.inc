<?php

/***************************************************
 * 管理者管理画面(ユーザ編集完了)
 *
 *
 * @package
 * @access  public
 * @author  
 * @create  
 * @version 
 ***************************************************/

require_once('common/base_model_admin_base.inc');

class admin_user_edit_fin extends base_model_admin_base {

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

  // ユーザ情報を編集
  $admin_users_c = $this->get_clump('admin_users_clump');
  // まずユーザ情報をDBから取得
  $user_id = $this->get_cgi_request()->find('id');
  if ('' === $user_id) {
    // XXX 正常ルートだとあんまり想定できないから、top突き返しでいいかねぇ
    $this->redirect_command('admin_user_list');
    return ;
  }
  // DBからゲット
  $admin_users_c->set_value('id', $user_id);
  $r = $admin_users_c->get();
  if (false === $r) {
    // XXX 正常ルートだとあんまり想定できないから、top突き返しでいいかねぇ
    $this->redirect_command('admin_user_list');
    return ;
  }

  // 入力値を一通り埋め込み
  $admin_users_c->set_from_cgi_update($this->get_cgi_request());
  // validate(ユーザID重複はチェックしてない)
  $r = $admin_users_c->is_valid_update($this->get_conv());
  if (false === $r) {
    $this->set_bag('edit_fin_forward', true); // edit側で「IDをkeyにデータを引っ張ってくる」処理を食い止める為
    $this->forward('admin_user_edit');
    return ;
  }
//var_dump($admin_users_c->get_all_data_to_hash());
//var_dump($admin_users_c->get_value('pass'));

  // 修正
  $r = $admin_users_c->update();
  if (false === $r) {
    $this->get_conv()->set('update_error', true);
    $this->forward('admin_user_edit');
    return ;
  }

  // 表示
  $this->get_conv()->set('user', $admin_users_c->get_all_view_values());

  //
  return ;
}

} // end of class

