<?php

/***************************************************
 * マルチバイトテスト
 *
 *
 * @package
 * @access  public
 * @author  
 * @create  
 * @version 
 ***************************************************/

require_once('common/base_model_front_base.inc');
require_once('mw_sql.inc');

class mb_test extends base_model_front_base {

//
//public function initialize() {  }
//public function finalize() {  }

//処理
public function execute() {
  // データ取得
  $mw_sql = new mw_sql();
  $mw_sql->set_sql('SELECT * FROM `mb_テスト`;');
  $res = $this->get_db()->query($mw_sql);
  $res->set_fetch_type_hash();
  //
  $data = array();
  while($res->fetch()) {
    //
    $wk = $res->get_row();
    $data[] = $wk;
  }
//var_dump($data);

  // 出力依頼
  $this->get_conv()->set('data', $data);
}

} // end of class

