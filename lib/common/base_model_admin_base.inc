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

abstract class base_model_back_base extends base_model_base {

// 認証処理を通すexecute
public function execute_auth(){
  // 認証処理(実際にはちゃんと実装する。一旦ダミー)
  if (true) {
    return $this->execute();
  }
}

} // end of class

