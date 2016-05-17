<?php

/**
 * 業務全体基底クラス
 *
 *
 * @package magicweapon
 * @link http://www.grid-works-guild.net/MagicWeapon/ MagicWeapon
 * @access  public
 * @author  Michiaki Wuzawa <wuzawa@m-fr.net>
 **/

require_once('base_model.inc');

abstract class base_model_base extends base_model {

// CSRFトークンの登録本体
protected function _set_csrf_token($name) {
  //
  $num = $this->get_config()->find('csrf_token_num') + 0;
  if (0 >= $num) {
    $num = 10;
  }
//var_dump($num);

  // トークンの作成
  $diid = di::create('diid');
  $token = $diid->get_base64();
//var_dump($token);

  // テンプレートへの登録
  $this->get_conv()->set('csrf_token', $token);

  // token数の調整
  while ($num <= count(@$_SESSION[$name]['csrf_token'])) {
    array_shift($_SESSION[$name]['csrf_token']);
  }

  // セッションへの登録
  $_SESSION[$name]['csrf_token'][$token] = time();

}

// CSRFトークンの確認本体
protected function _is_csrf_token($name) {
  // CSRFチェック
  $post_csrf_token = $this->get_cgi_request()->find('csrf_token');
  if (false === isset($_SESSION[$name]['csrf_token'][$post_csrf_token])) {
    return false;
  }

  // 寿命の設定を把握
  $expire = $this->get_config()->find('csrf_token_expire') + 0;
  if (0 >= $expire) {
    $expire = 60;
  }
//var_dump($expire);


  // 寿命を把握して
  $ttl = $_SESSION[$name]['csrf_token'][$post_csrf_token];
  // 先にトークンは削除(使い捨てなので)
  unset($_SESSION[$name]['csrf_token'][$post_csrf_token]);
  // 寿命チェック(1分以内)
  if (time() >=  $ttl + $expire) {
    return false;
  }

  //
  return true;
}

} // end of class

