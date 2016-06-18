<?php
/*
 * 1レコードが1ユーザを意味するテーブル 用 clump_base
 * XXX 自動生成用クラスなので、ここに追記などはしないこと！！
 *
 */


require_once("data_clump.inc");

class admin_users_clump_base extends data_clump {

public function __construct()
{
  parent::__construct();
}

public function init()
{
  parent::init();
  $this->set_element();	// ユーザ登録画面の要素を登録
}

/**
 * 基本的な情報の設定
 *
 * テーブル名およびカラム名を設定する
 *
 * @access protected
 * @return boolean falseは現状想定外。
 */
protected function set_element()
{
  //
  $this->set_table_name('admin_users');

  // $inname, $cginame, $tmpname, $dbname, $keyflg, $data_type(db)
  $this->push_element('id', '', '', '', 'pk', data_clump::DATATYPE_STRING); // 管理者を識別するためのID(varbinary(128))
  $this->push_element('pass', '', '', '', '', data_clump::DATATYPE_STRING); // ログインパスワード。password_hashが現在のお勧め(varbinary(128))
  $this->push_element('lock_time', '', '', '', '', data_clump::DATATYPE_INT); // ロックタイム(エポック秒)。0以外なら「入っている時間まではログイン出来ない」(bigint(20) unsigned)
  $this->push_element('err_count', '', '', '', '', data_clump::DATATYPE_INT); // ロックタイム(エポック秒)。0以外なら「入っている時間まではログイン出来ない」(int(10) unsigned)
  $this->push_element('account_stop', '', '', '', '', data_clump::DATATYPE_INT); // これが０以外(基本は１)なら「アカウント停止状態」と見なす(int(10) unsigned)
  $this->push_element('name', '', '', '', '', data_clump::DATATYPE_STRING); // 表示名(varchar(128))
  $this->push_element('role', '', '', '', '', data_clump::DATATYPE_INT); // 権限系。使わなければ削除で。(int(10) unsigned)
  $this->push_element('created', '', '', '', '', data_clump::DATATYPE_DATE); // 作成日時(datetime)
  $this->push_element('updated', '', '', '', '', data_clump::DATATYPE_DATE); // 修正日時(datetime)
  $this->push_element('memo', '', '', '', '', data_clump::DATATYPE_STRING); // ユーザに対するmemo(text)


}

//private:


} // end of class



