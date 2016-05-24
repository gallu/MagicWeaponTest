<?php

/***************************************************
 * json出力テスト
 *
 *
 * @package
 * @access  public
 * @author  
 * @create  
 * @version 
 ***************************************************/

require_once('common/base_model_front_base.inc');

class json_output extends base_model_front_base {

//

//処理
public function execute() {
  //
  $json_test = array(
    'status' => 'ok',
    'data' => array(1,2,3),
  );

  //
  $this->json_out($json_test);
  //$this->json_out($json_test, false); // XXX debug用
}

} // end of class





