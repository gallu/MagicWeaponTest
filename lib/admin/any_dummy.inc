<?php

/***************************************************
 * any用ダミー画面
 *
 *
 * @package
 * @access  public
 * @author  
 * @create  
 * @version 
 ***************************************************/

require_once('common/base_model_admin_base.inc');

class any_dummy extends base_model_admin_base {

//
public function initialize() {
  //
  parent::initialize();

  // 「必要なロール」はanyにしておく
  $this->set_need_role_any();
}

//処理
public function execute_auth() {
//print 'uid is ' . $this->get_uid() . "<br>\n";

  //
  return ;
}

} // end of class

