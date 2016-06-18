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

//private:

} // end of class

