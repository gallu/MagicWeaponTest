<?php

/**
 * 業務 フロント用 基底クラス
 *
 *
 * @package magicweapon
 * @link http://www.grid-works-guild.net/MagicWeapon/ MagicWeapon
 * @access  public
 * @author  Michiaki Wuzawa <wuzawa@m-fr.net>
 **/

require_once('common/base_model_base.inc');

abstract class base_model_front_base extends base_model_base {

// 初期設定：レイアウトを有効にしておく
public function initialize() {
  // 親呼んで
  $r = parent::initialize();

  // 「１回だけ動かしたい」処理
  if (0 == $this->get_recursive_depth()) {
    // 一旦、デフォルトではレイアウトをonにしておく
    $this->set_layout_filename('layout.tpl');
  }
}


// 空メソッド。「認証が必要なmodel」は、このメソッドを上書き(orverwrite)して処理を実装
public function execute_auth(){}

// 認証処理を通すexecute
public function execute(){
  // 認証処理(実際にはちゃんと実装する。一旦ダミー)
  if (true) {
    return $this->execute_auth();
  }
  // else
  // XXX よしなに「認証失敗したよ」系処理
}

// CSRFトークンの登録
protected function set_csrf_token() {
  $this->_set_csrf_token('front');
}

// CSRFトークンの確認
protected function is_csrf_token() {
  return $this->_is_csrf_token('front');
}




//private:

} // end of class

