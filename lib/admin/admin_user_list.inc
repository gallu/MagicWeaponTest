<?php

/***************************************************
 * 管理者管理画面(list)
 *
 *
 * @package
 * @access  public
 * @author  
 * @create  
 * @version 
 ***************************************************/

require_once('common/base_model_admin_base.inc');
require_once('mw_sql.inc');
require_once('page_controll_limit.inc');

class admin_user_list extends base_model_admin_base {

//
public function initialize() {
  //
  parent::initialize();

  // 「必要なロール」はadminにしておく
  $this->set_need_role_admin();
  // XXX 「サンプル」なので一般権限。微妙だけど、サンプルなので……
  $this->set_need_role_nomal();
}

//処理
public function execute_auth() {
//print "Trap 1\n";

  // ページ数把握
  $p = $this->get_cgi_request()->find('p') + 0;

  // admin_user一式取ってくる用のSQLを作成
  $mw_sql = new mw_sql();
  $mw_sql->set_sql('SELECT * FROM admin_users ORDER BY id ');

  // ページング付き
  $page_o = new page_controll_limit();
  $page_o->set_db($this->get_db());
  $page_o->set_sql($mw_sql);
  // ページ数、１ページ辺りの表示数の設定
  $page_o->set_page_num($p); // 指定ページ数
  $page_o->set_par_item_num(3); // １Page辺りの表示アイテム数(テスト用に３件ほど。実際なら50件くらい？)
  // listの作成
  $page_o->make_list();
  // listの取得
  $user_list = $page_o->get_list();
//var_dump($user_list);
  // page周りのテンプレートへの設定
  $page_o->set_to_conv($this->get_conv());


// --- ロックテーブルがない場合は以下の処理をコメントアウトしてください -----------
  // ロックテーブルの取得(これは件数が少ないと思われるから一旦全件)
  $mw_sql = new mw_sql();
  $mw_sql->set_sql('SELECT * FROM admin_auth_lock;');
  $res = $this->get_db()->query($mw_sql);
  $res->set_fetch_type_hash();

  // 配列のkeyをIDにする(ロックテーブルのチェックがしやすいように)
  $lock_user = array();
  while($res->fetch()) {
    //
    $awk = $res->get_row();
    // 
    $lock_user[$awk['id']] = $awk;
  }
//var_dump($lock_user);


  // user_listへのlockテーブル情報のmerge
  // ＋ 一度data_clumpに通してview_dataとして整理する
  $admin_user_c = null;
  foreach($user_list as $key => $val) {
    // clumpに通して「view用のデータ」として整形する
    $admin_user_c = $this->get_clump('admin_users_clump', $admin_user_c);
    // DBから情報を取得してclumpの中に取り込み
    $admin_user_c->set_all_data_from_hash($val);
    // 表示用のデータとして整形したものを設定
    $user_list[$key] = $admin_user_c->get_all_view_values();

    // ロックテーブルに該当ユーザがいるかいないかで処理を変える
    if (true === isset($lock_user[$val['id']])) {
      $user_list[$key]['lock'] = $lock_user[$val['id']];
      $user_list[$key]['lock']['flg'] = true;
    } else {
      $user_list[$key]['lock']['flg'] = false;
    }
  }
//var_dump($lock_user);

  //
  $this->get_conv()->set('user_list', $user_list);

  // 削除及びロック用にCSRFトークン埋め込み
  $this->set_csrf_token();

  //
  return ;
}

} // end of class

