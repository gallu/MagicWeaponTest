<?php
/*
 * form test 用 clump_base
 * XXX ここに追記などはしないこと！！
 *
 */


require_once("data_clump.inc");

class form_test_clump_base extends data_clump {

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
 * 項目名を設定する
 *
 * @access protected
 * @return boolean falseは現状想定外。
 */
protected function set_element()
{
  // $inname, $cginame, $tmpname, $dbname, $keyflg, $data_type(db)
  $this->push_element('text_data', '', '', '', '', data_clump::DATATYPE_STRING); //
  $this->push_element('int_data', '', '', '', '', data_clump::DATATYPE_INT); //
}

//private:


} // end of class



