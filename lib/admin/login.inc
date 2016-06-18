<?php

/***************************************************
 * ログイン画面
 *
 * @package
 * @access  public
 * @author  
 * @create  
 * @version 
 ***************************************************/

require_once('common/base_model_admin_base.inc');

class login extends base_model_admin_base {

//処理
public function execute() {
//print "Trap 1\n";

  // 認証系クラスのインスタンスを確保
  $auth_o = di::create('authentication');

  // 認証系クラスへの初期化諸々
  $auth_o->set_id($this->get_cgi_request()->find('id'));
  $auth_o->set_raw_password($this->get_cgi_request()->find('pass'));
  $auth_o->set_authentication_clump( $this->get_clump('admin_users_clump') ); // 管理ユーザテーブルのclumpインスタンスを取得

  // 認証
  $r = $auth_o->login();

  // 認証に失敗した時
  if (false === $r) {
    // エラーメッセージ出力
    $this->get_conv()->set('is_login_error', true);

    // もしロックがスタートしたら
    if (true === $auth_o->is_lock_start()) {
      // XXX 一旦未処理。基本的には「アラートmailをconfigあたりに書いたメール宛に投げる」などの処理が望まれる
    }
//exit;

    // top画面に突き返す
    $this->forward('index');
    return ;
  }

  // XXX 認証がOKなら

  // 認可用インスタンス取得
  $authorization_o = $this->get_authorization();

  // ログイン処理
  $r = $authorization_o->auth_on($auth_o->get_authentication_clump());
  if (false === $r) {
    // XXX なんかエラーメッセージ出した方がいいかねぇ…基本ここには入りようがないのだが

    // top画面に突き返す
    $this->forward('index');
    return ;
  }

  //
  $this->redirect('./admin.php?c=top');
}

} // end of class

