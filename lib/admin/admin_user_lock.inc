<?php

/***************************************************
 * 管理者管理画面(ロック設定)
 *
 *
 * @package
 * @access  public
 * @author  
 * @create  
 * @version 
 ***************************************************/

require_once('common/base_model_admin_base.inc');

class admin_user_lock extends base_model_admin_base {

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
  // ユーザ情報側を「アカウント停止状態」にする(これで以降loginが出来ない)
  $admin_users_c->set_value('account_stop', 1, true); // 即時update

  // ロックファイル情報を取得
  $admin_auth_lock_c = $this->get_clump('admin_auth_lock_clump');
  $admin_auth_lock_c->set_value('id', $user_id);
  $admin_auth_lock_c->set_value('memo', $this->get_cgi_request()->find('memo'));
  // ロックテーブルにIDをinsert(これで以降認可が常にNGになる)
  $r = $admin_auth_lock_c->insert();

  // list表示に戻す
  $this->redirect_command('admin_user_list');
}

} // end of class

