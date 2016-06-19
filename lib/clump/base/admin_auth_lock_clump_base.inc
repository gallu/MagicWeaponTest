<?php
/*
 * 1レコードが「ロックされた1ユーザ」を意味するテーブル 用 clump_base
 * XXX 自動生成用クラスなので、ここに追記などはしないこと！！
 *
 */


require_once("data_clump.inc");

class admin_auth_lock_clump_base extends data_clump {

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
  $this->set_table_name('admin_auth_lock');

  // $inname, $cginame, $tmpname, $dbname, $keyflg, $data_type(db)
  $this->push_element('id', '', '', '', 'pk', data_clump::DATATYPE_STRING); // ユーザ(管理者)を識別するためのID(varbinary(128))
  $this->push_element('created', '', '', '', '', data_clump::DATATYPE_DATE); // 作成日時(datetime)
  $this->push_element('memo', '', '', '', '', data_clump::DATATYPE_STRING); // lockした理由とか(text)


}

//private:


} // end of class



