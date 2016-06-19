<h2>管理者ユーザ作成</h2>
ユーザが以下の情報で作成されました。<br>
<hr>
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

