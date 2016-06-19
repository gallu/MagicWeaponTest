<?php

/***************************************************
 * 一般権限用ダミー画面
 *
 *
 * @package
 * @access  public
 * @author  
 * @create  
 * @version 
 ***************************************************/

require_once('common/base_model_admin_base.inc');

class nomal_dummy extends base_model_admin_base {

//
/*
// 今回は「base_model_admin_base#initialize()」でデフォルトをnomalにしてあるので、以下はコメントアウト
public function initialize() {
  //
  parent::initialize();

  // 「必要なロール」は一般権限にしておく
  $this->set_need_role_nomal();
}
*/

//処理
public function execute_auth() {
//print "Trap 1\n";
//print 'uid is ' . $this->get_uid() . "<br>\n";

  //
  return ;
}

} // end of class

