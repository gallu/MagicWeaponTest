<?php

// 基本設定の読み込み
require_once('../base.inc');

// controllerへのconfigファイルの設定
$co->set_config($config);

// 実行
$co->run();
