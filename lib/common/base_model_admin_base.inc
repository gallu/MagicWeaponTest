<?php

/**
 * 業務 管理画面用 基底クラス
 *
 *
 * @package magicweapon
 * @link http://www.grid-works-guild.net/MagicWeapon/ MagicWeapon
 * @access  public
 * @author  Michiaki Wuzawa <wuzawa@m-fr.net>
 **/

require_once('common/base_model_base.inc');
require_once('authorization_session.inc');

abstract class base_model_admin_base extends base_model_base {

//
public function initialize() {
  //
  parent::initialize();

  // デフォルトで「必要なロール」は一般権限にしておく
  $this->set_need_role_nomal();
}

// 空メソッド。「認証が必要なmodel」は、このメソッドを上書き(orverwrite)して処理を実装
public function execute_auth(){}

// 認可処理用のインスタンス＆初期設定
protected function get_authorization() {
  // 認可用インスタンス取得
# XXX 認可処理は「インタフェース完全に共通」が難しそうな気がしているので、一旦コメントアウト。cookie系とsession系でその辺の整合性がとれたら改修
  //$authorization_o = di::create('authorization');
  $authorization_o = new authorization_session();
  // 設定取り込み
  $authorization_o->set_config($this->get_config());

  // ロックテーブルのclumpを設定(ロックテーブルがある場合)
  //$authorization_o->set_user_lock_clump($this->get_clump($this->get_config()->find('rock_table') . '_clump'));

  //
  return $authorization_o;
}

// 認可処理を通すexecute
public function execute(){

  // 認可用インスタンス取得
  $authorization_o = $this->get_authorization();

  // 認可処理
  if (false === $authorization_o->is_auth()) {
    // XXX よしなに「認証失敗したよ」系処理
    // 一旦、top画面に突き返す(必要なら「認可でけんかったよ」エラー画面を別途作成してそちらにforwardさせる)
    $this->redirect('./admin.php');
    return ;
  }

  // else

  // 権限チェック
  // XXX 必要権限0ならanyなのでノーチェックにする
  $awk = $authorization_o->get_all_user_data();
  $user_role = $awk['role'];
//var_dump($this->get_need_role());
//var_dump($user_role & $this->get_need_role());
  if ( (0 !== $this->get_need_role()) && (0 === ($user_role & $this->get_need_role()))) {
    // 一旦、top画面に突き返す(必要なら「権限ないよ！！」エラー画面を別途作成してそちらにredirectさせる)
    $this->redirect('./admin.php?c=top');
    return ;
  }

  // 認可出来たので処理続行
  $this->set_uid($authorization_o->get_uid());
//var_dump($authorization_o->get_all_user_data());
  return $this->execute_auth();
}

// uid
public function get_uid() { return $this->uid_; }
public function set_uid($v) { $this->uid_ = $v; }
// need_role
public function get_need_role() { return $this->need_role_; }
public function set_need_role($v) { $this->need_role_ = $v; }
//
public function set_need_role_any() { $this->set_need_role(0); }
public function set_need_role_nomal() { $this->set_need_role(1); }
public function set_need_role_admin() { $this->set_need_role(2); }


//private:
private $uid_ = '';
private $need_role_;

} // end of class

