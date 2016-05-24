<?php

/***************************************************
 * csv出力テスト
 *
 *
 * @package
 * @access  public
 * @author  
 * @create  
 * @version 
 ***************************************************/

require_once('common/base_model_front_base.inc');
require_once('csv_util.inc');

class csv_output extends base_model_front_base {

//

//処理
public function execute() {
  //
  $csv_test = array(
    array(1,2,3),
    array('a', 'b', 'c'),
  );
  //
  $csv_test_object = new arrayObject($csv_test);
  //
  $csv_test_string = '"1","2","3"
"1","2","3"
"a","b","c"
';

  //
  $this->csv_out('test.csv', $csv_test); // 配列で指定
  //$this->csv_out('test.csv', $csv_test_object); // arrayObjectインスタンスで指定
  //$this->csv_out('test.csv', $csv_test_string); // 文字列で指定
}

} // end of class

