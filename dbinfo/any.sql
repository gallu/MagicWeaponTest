-- SQLを一式
-- 小さければ１ファイルでもよいし、沢山テーブルがあれば複数ファイルでもよし

-- 管理画面用管理者テーブル。ログイン情報系込み。割と固定なカラムも多し。
DROP TABLE IF EXISTS admin_users;
CREATE TABLE admin_users (
  `id` varbinary(128) NOT NULL COMMENT '管理者を識別するためのID',
  `pass` varbinary(128) NOT NULL COMMENT 'ログインパスワード。password_hashが現在のお勧め',
  `lock_time` bigint unsigned NOT NULL COMMENT 'ロックタイム(エポック秒)。0以外なら「入っている時間まではログイン出来ない」',
  `err_count` int unsigned NOT NULL COMMENT 'ロックタイム(エポック秒)。0以外なら「入っている時間まではログイン出来ない」',
  `account_stop` int unsigned NOT NULL default 0 COMMENT 'これが０以外(基本は１)なら「アカウント停止状態」と見なす',
  -- 以下、authentication_id_passクラス系の処理では使わない(けどまぁよくつかう)カラム群
  `name` varchar(128) NOT NULL COMMENT '表示名',
  `role` int unsigned NOT NULL COMMENT '権限系。 0:無権限, 1:一般権限, 3:管理権限(bit演算なので1+2で管理者は3)',
  `created` datetime NOT NULL COMMENT '作成日時',
  `updated` datetime NOT NULL COMMENT '修正日時',
  `memo` text NOT NULL COMMENT 'ユーザに対するmemo',
  PRIMARY KEY (`id`)
)CHARACTER SET 'utf8mb4', ENGINE=InnoDB, COMMENT='1レコードが1ユーザを意味するテーブル';

-- ダミーユーザ
INSERT INTO admin_users SET
  id='test',
  pass='$2y$10$0.sKATz0SM605hxkzZaMVefy5jEDKBOtFyEhBevH/h3uiUZdCVUyC', -- testpass
  lock_time=0,
  err_count=0,
  account_stop=0,
  name='テストユーザ',
  role=0,
  created='2016-6-18 12:00:00',
  updated='2016-6-18 12:00:00',
  memo='ログインだけ出来るテスト用ユーザ'  ;

-- ロックテーブル(ここに入っているユーザはいかなる状況でも認可されない)
DROP TABLE IF EXISTS admin_auth_lock;
CREATE TABLE admin_auth_lock (
  `id` varbinary(128) NOT NULL COMMENT 'ユーザ(管理者)を識別するためのID',
  -- 以下、authorization_系クラスの処理では使わない(けどまぁよくつかう)カラム群
  `created` datetime NOT NULL COMMENT '作成日時',
  `memo` text NOT NULL COMMENT 'lockした理由とか',
  PRIMARY KEY (`id`)
)CHARACTER SET 'utf8mb4', ENGINE=InnoDB, COMMENT='1レコードが「ロックされた1ユーザ」を意味するテーブル';






/*
-- $_SESSION使わず自前で認可処理をする時用のテーブル(未検証)
DROP TABLE IF EXISTS admin_users_session;
CREATE TABLE admin_users_session (
  `sid` varbinary(128) NOT NULL COMMENT 'セッションID',
  `id` varbinary(128) NOT NULL COMMENT 'ユーザ(管理者)を識別するためのID',
  `expire` bigint unsigned NOT NULL COMMENT 'セッションの寿命(エポック秒)',
  PRIMARY KEY (`sid`)
)CHARACTER SET 'utf8mb4', ENGINE=InnoDB, COMMENT='1レコードが「1ユーザの1セッション」を意味するテーブル';
*/


