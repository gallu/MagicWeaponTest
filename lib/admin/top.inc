<?php

/***************************************************
 * ログイン後トップ画面
 *
 *
 * @package
 * @access  public
 * @author  
 * @create  
 * @version 
 ***************************************************/

require_once('common/base_model_admin_base.inc');

class top extends base_model_admin_base {

//
public function initialize() {
  //
  parent::initialize();

  // 「必要なロール」はanyにしておく
  $this->set_need_role_any();
}

//処理
public function execute_auth() {
//print "Trap 1\n";
//print 'uid is ' . $this->get_uid() . "<br>\n";

  //
  return ;
}

} // end of class

