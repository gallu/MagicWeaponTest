<?php
/*
 * 1レコードが「1ユーザの1セッション」を意味するテーブル 用 clump_base
 * XXX 自動生成用クラスなので、ここに追記などはしないこと！！
 *
 */


require_once("data_clump.inc");

class admin_users_session_clump_base extends data_clump {

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
  $this->set_table_name('admin_users_session');

  // $inname, $cginame, $tmpname, $dbname, $keyflg, $data_type(db)
  $this->push_element('sid', '', '', '', 'pk', data_clump::DATATYPE_STRING); // セッションID(varbinary(128))
  $this->push_element('id', '', '', '', '', data_clump::DATATYPE_STRING); // ユーザ(管理者)を識別するためのID(varbinary(128))
  $this->push_element('expire', '', '', '', '', data_clump::DATATYPE_INT); // セッションの寿命(エポック秒)(bigint(20) unsigned)


}

//private:


} // end of class



