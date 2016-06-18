<?php
/*
 * 1レコードが1ユーザを意味するテーブル 用 clump
 *
 */
require_once("clump/base/admin_users_clump_base.inc");

class admin_users_clump extends admin_users_clump_base {


/**
 * 基本的な情報の設定
 *
 * validate項目などを設定する。「テーブル名およびカラム名」はbase側で設定。
 *
 * @access protected
 * @return boolean falseは現状想定外。
 */
protected function set_element()
{
  //
  parent::set_element();

  /*
  typeの説明
data_clump::V_MUST      // 必須
data_clump::V_STRING    // 文字列(パラメタは文字数(バイト数)を表す
data_clump::V_NUMERIC   // 数値(パラメタは値を示す
data_clump::V_DIGIT     // 数字(パラメタは桁数を示す
data_clump::V_ALPHA     // 英字(パラメタは文字数(バイト数)を表す
data_clump::V_ALPNUM    // 英数字(パラメタは文字数(バイト数)を表す
data_clump::V_POST      // 郵便番号(nnn-nnnn、nnnnnnn、nnn nnnnの３パターンフォロー
data_clump::V_DATE      // 日付
data_clump::V_EMAIL1    // メアド
data_clump::V_M_STRING  // 全角交じりの文字列(サイズのチェックを 全角:2文字 半角:1文字として扱う(mb_strwidth使用)
data_clump::V_M_STRING2 // 全角交じりの文字列(サイズのチェックを 全角半角ともすべて１文字として扱う(mb_strlen使用)
data_clump::V_KATAKANA_UTF8 // UTF-8文字コードのカタカナ(文字長の規定はしてないんで、基本、V_M_STRINGと一緒がいいと思う)
  */

  // validateの設定
  // name, type(0ならチェックしない), param(書式は'min-max')
  $this->push_validate('id', 0, ''); // 管理者を識別するためのID
  $this->push_validate('pass', 0, ''); // ログインパスワード。password_hashが現在のお勧め
  $this->push_validate('lock_time', 0, ''); // ロックタイム(エポック秒)。0以外なら「入っている時間まではログイン出来ない」
  $this->push_validate('err_count', 0, ''); // ロックタイム(エポック秒)。0以外なら「入っている時間まではログイン出来ない」
  $this->push_validate('account_stop', 0, ''); // これが０以外(基本は１)なら「アカウント停止状態」と見なす
  $this->push_validate('name', 0, ''); // 表示名
  $this->push_validate('role', 0, ''); // 権限系。使わなければ削除で。

  // insert/updateフックの設定
  //$this->set_insert_date_name('create_date');
  //$this->set_update_date_name('update_date');

  // set_all_to_conv用(secure_conv使用時)
  //$this->push_selected_item('');
  //$this->push_checked_item('');
}

// パスワードを間違っても返さないように、少し小細工
public function get_all_data_to_hash($extra_param = array()) {
  // まず親をcall
  $ret = parent::get_all_data_to_hash($extra_param);

  // パスワード情報は抜いておく
  unset($ret['pass']);

  //
  return $ret;
}


//private:


} // end of class


/*
割とオーバーライドしたりするのをフックしてメモ書き
メソッドの意味とかはdata_clumpを適宜調べてください。

public function is_valid_insert($conv = NULL)
{
}
public function is_valid_update($conv = NULL)
{
}

public function set_from_cgi_insert($req, $empty_overwrite_flg = false)
{
}
public function set_from_cgi_update($req, $empty_overwrite_flg = false)
{
}

public function get_all_data_to_hash($extra_param = array())
{
}

public function get_value($name)
{
}
public function set_value($name, $value, $flg = false)
{
}

*/
