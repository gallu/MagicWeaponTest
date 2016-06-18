<?php

/***************************************************
 * 単純な出力
 *
 *
 * @package
 * @access  public
 * @author  
 * @create  
 * @version 
 ***************************************************/

require_once('common/base_model_admin_base.inc');

class simple_put_model extends base_model_admin_base {

//処理
public function execute() {
  // レイアウトをoffにする
  $this->set_layout_filename('');

  //
  return ;
}

} // end of class

