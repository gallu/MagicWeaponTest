<?php

/***************************************************
 * トップ画面
 *
 *
 * @package
 * @access  public
 * @author  
 * @create  
 * @version 
 ***************************************************/

require_once('common/base_model_front_base.inc');
require_once('conv_util.inc');

class mw_index extends base_model_front_base {

//
//public function initialize() {  }
//public function finalize() {  }

//処理
public function execute() {
//print "Trap 1\n";

  // レイアウトをoffにする
  $this->set_layout_filename('');
}

} // end of class

