DROP TABLE IF EXISTS `mb_テスト`;
CREATE TABLE `mb_テスト` (
  `エネルギー（kcal）` int,
  `食物繊維総量` int,
  `α-カロテン` int
)CHARACTER SET 'utf8mb4', ENGINE=InnoDB, COMMENT='マルチバイトカラム名テスト用テーブル';

insert into `mb_テスト`(`エネルギー（kcal）`, `食物繊維総量`, `α-カロテン`)
     values(500, 20, 10);
insert into `mb_テスト`(`エネルギー（kcal）`, `食物繊維総量`, `α-カロテン`)
     values(600, 60, 66);

