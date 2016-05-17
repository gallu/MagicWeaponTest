<?php

// MWを使えるようにする
$dir = '/opt/www/MagicWeapon/';
set_include_path(get_include_path() . PATH_SEPARATOR . $dir);
// Smartyを使えるようにする
$dir = $bp . 'lib/plugin/smarty-3.1.29/libs/';
set_include_path(get_include_path() . PATH_SEPARATOR . $dir);

// 基本的なphp iniの設定を一式
require_once('mw_set_ini.inc');
// タイムゾーンの設定
date_default_timezone_set('Asia/Tokyo');

// セッション用基本設定群
ini_set('session.entropy_file', '/dev/urandom');
ini_set('session.entropy_length', '16');
ini_set('session.hash_function', '1');
ini_set('session.use_only_cookies', '1');
ini_set('session.cookie_lifetime', '0');
ini_set('session.cache_expire', 20);
ini_set('session.use_trans_sid', '0');
ini_set('session.name', 'session_id');

// PHPセッションの開始
session_start();

// config
$config       = $bp . 'conf/config.conf';
$admin_config = $bp . 'conf/admin_config.conf';

// controller周り
require_once('controller.inc');
//
$co = new controller;
$co->set_base_path($bp);

// Smarty周り設定
require_once('controller.inc');
