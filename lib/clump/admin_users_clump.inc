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
  $this->push_validate('id', data_clump::V_MUST | data_clump::V_STRING, '-100'); // 管理者を識別するためのID
  $this->push_validate('pass', 0, ''); // ログインパスワード。password_hashが現在のお勧め
  $this->push_validate('lock_time', 0, ''); // ロックタイム(エポック秒)。0以外なら「入っている時間まではログイン出来ない」
  $this->push_validate('err_count', data_clump::V_NUMERIC, ''); // ロックタイム(エポック秒)。0以外なら「入っている時間まではログイン出来ない」
  $this->push_validate('account_stop', 0, ''); // これが０以外(基本は１)なら「アカウント停止状態」と見なす
  $this->push_validate('name', 0, ''); // 表示名
  $this->push_validate('role', 0, ''); // 権限系。使わなければ削除で。

  // insert/updateフックの設定
  $this->set_insert_date_name('created');
  $this->set_update_date_name('updated');

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
public function get_all_view_values($extra_param = array()) {
  // まず親をcall
  $ret = parent::get_all_view_values($extra_param);
  // パスワード情報は抜いておく
  unset($ret['pass']);
  // 時間情報を文字列にしておく
  if (0 == $ret['lock_time']) {
    $ret['lock_time_string'] = '';
  } else {
    $ret['lock_time_string'] = date('Y-m-d H:i:s', $ret['lock_time']);
  }
  // 役割名を名前で振っておく
  $role_awk = array(0 => '無権限ユーザ', 1 => '一般ユーザ', 3 => '管理者');
  if (isset($role_awk[$ret['role']])) {
    $ret['role_string'] = $role_awk[$ret['role']];
  } else {
    $ret['role_string'] = '不明';
  }
//var_dump($ret);
  //
  return $ret;
}

// formからパスワード情報を取得(inputの時と「パスワード上書き」の時で両方使うので)
public function get_password_from_cgi_request($req) {
  // 入力用パスワード系情報を取得
  $this->pass_1_ = $req->find('pass_1');
  $this->pass_2_ = $req->find('pass_2');
  // とりあえず「合ってるだろう」(上位でvalidateで適切にチェックされる)前提でパスワードハッシュ入れとく
  $this->set_value('pass', password_hash($this->pass_1_, PASSWORD_DEFAULT) );
}

// パスワード情報のvalidate(inputの時と「パスワード上書き」の時で両方使うので)
public function is_valid_password($conv) {
  //
  $r = true;

  // パスワード系チェックの追加
  foreach(['pass_1', 'pass_2'] as $s) {
    // 元ネタ文字列
    $ss = $s . '_';
    $check_string = $this->$ss;

    // 必須チェック
    if (0 == strlen($check_string)) {
      $r = false;
      $conv->multiDic('if_error', new simple_put());
      $conv->multiDic('if_error_' . $s, new simple_put());
      $conv->multiDic('if_error_must_' . $s, new simple_put());
    }

    // 長さチェック
    if (72 < strlen($check_string)) {
      $r = false;
      $conv->multiDic('if_error', new simple_put());
      $conv->multiDic('if_error_' . $s, new simple_put());
      $conv->multiDic('if_error_max_' . $s, new simple_put());
    }

    // XXX 文字種チェック(今回やらないけど、やりたいならここで)
  }

  // パスワードとパスワード(再)の比較
  if ($this->pass_1_ !== $this->pass_2_) {
    $r = false;
    $conv->multiDic('if_error', new simple_put());
    $conv->multiDic('if_error_pass_1', new simple_put());
    $conv->multiDic('if_error_unmach_pass', new simple_put());
  }

  //
  return $r;
}


// insert系処理
public function set_from_cgi_insert($req, $empty_overwrite_flg = false)
{
  // とりあえず親をcall
  $r = parent::set_from_cgi_insert($req, $empty_overwrite_flg);

  // 入力用パスワード系情報を取得
  $this->get_password_from_cgi_request($req);

  // その他デフォルト各種
  $this->set_value('lock_time', 0);
  $this->set_value('err_count', 0);
  if ('' === $this->get_value('role')) {
    $this->set_value('role', 0);
  }
  //
  return $r;
}

//
public function is_valid_insert($conv = NULL)
{
  // とりあえず親をcall
  $r = parent::is_valid_insert($conv);

  // パスワード系のvalidate
  $r2 = $this->is_valid_password($conv);

  //
  return $r && $r2;
}

// update系処理
public function set_from_cgi_update($req, $empty_overwrite_flg = false)
{
  // パスワード情報は上書きされないようにする
  $params = array_diff($this->get_all_no_key_names(), array('pass'));
  $this->set_from_cgi_detail($req, $params, $empty_overwrite_flg);

  // ロックタイムを一旦変換して保持(validateのほうはそっちでやってもらう)
  $this->lock_time_string_ = $req->find('lock_time_string');
  if ('' === $this->lock_time_string_) {
    $this->set_value('lock_time', '');
  } else {
    $this->set_value('lock_time', strtotime($this->lock_time_string_));
  }
}

public function is_valid_update($conv = NULL)
{
  // とりあえず親をcall
  $r = parent::is_valid_update($conv);

  // ロックタイムのチェック処理追加
  if (false === $this->get_value('lock_time')) {
    // テンプレートに設定はしておく
    $conv->monoDic('lock_time_string', $this->lock_time_string_);
    // エラー出力処理
    $r = false;
    $conv->multiDic('if_error', new simple_put());
    $conv->multiDic('if_error_lock_time', new simple_put());
    $conv->multiDic('if_error_date_lock_time', new simple_put());
  }

  //
  return $r;
}



//private:
private $pass_1_;
private $pass_2_;
private $lock_time_string_;
} // end of class


/*
割とオーバーライドしたりするのをフックしてメモ書き
メソッドの意味とかはdata_clumpを適宜調べてください。


public function get_value($name)
{
}
public function set_value($name, $value, $flg = false)
{
}

*/
