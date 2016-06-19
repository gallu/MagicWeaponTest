<H2>管理ユーザ一詳細</H2>
<a href="./admin.php?c=admin_user_edit&user_id={$user.id}">このユーザ情報を編集する</a><br>
<a href="./admin.php?c=admin_user_edit_pass&user_id={$user.id}">このユーザのパスワードを強制的に変更する</a><br>
<h3>ユーザ情報</h3>
ユーザ名：{$user.name}{if 0 != $i.account_stop}(アカウント停止状態){/if}<br>
ユーザID：{$user.id}<br>
ロック時間：{$user.lock_time_string}<br>
エラーカウント：{$user.err_count}<br>
ロール：{$user.role_string}<br>
ユーザ作成日：{$user.created}<br>
ユーザ情報修正日：{$user.updated}<br>
メモ書き：
<pre>
{$user.memo}
</pre>
{*$user|var_dump*}
<h3>ロックテーブル情報</h3>
{if false == $user_lock.flg}
ロック情報はありません
{else}
ロック日：{$user_lock.created}<br>
メモ書き：
<pre>
{$user_lock.memo}
</pre>
{/if}
{*$user_lock|var_dump*}

