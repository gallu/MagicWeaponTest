-- SQLを一式
-- 小さければ１ファイルでもよいし、沢山テーブルがあれば複数ファイルでもよし

DROP TABLE IF EXISTS users;
CREATE TABLE users (
  `user_id` bigint NOT NULL AUTO_INCREMENT COMMENT 'ユーザを識別するためのID',
  `fb_id` varbinary(64) NOT NULL COMMENT 'facebook ID',
  `name` varbinary(128) NOT NULL COMMENT '表示名。デフォルトはfacebookのname？',
  `insert_date` datetime,
  INDEX fb_id_idx(fb_id),
  PRIMARY KEY (`user_id`)
)CHARACTER SET 'utf8mb4', ENGINE=InnoDB, COMMENT='1レコードが1ユーザを意味するテーブル';

