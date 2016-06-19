<h2>管理者ユーザ編集</h2>

{if true == $update_error}<span class="error">DBへのinsertに失敗しました。確認してください。</span>{/if}
<form action="./admin.php?c=admin_user_edit_fin" method="post">
<table border="1">
<tr>
  <td>編集対象のID
  <td>{$id}<br>
<tr>
  <td>アカウント停止状態(0以外(基本1)なら停止状態で作成)
  <td><input type="text" name="account_stop" value="{$account_stop}"><br>
<tr>
  <td>エラーカウント
      {if true == $if_error_numeric_err_count}<span class="error">(エラーカウントは数値でお願いします)</span>{/if}
      {if true == $if_error_max_id}<span class="error">(IDは100バイト以内です)</span>{/if}
  <td><input type="text" name="err_count" value="{$err_count}"><br>
<tr>
  <td>ロックタイム
      {if true == $if_error_date_lock_time}<span class="error">(ロックタイムは日付表記(yyy-mm-dd hh:mm:ss)または空でお願いします)</span>{/if}
  <td><input type="text" name="lock_time_string" value="{$lock_time_string}"><br>
<tr>
  <td>表示名
  <td><input type="text" name="name" value="{$name}"><br>
<tr>
  <td>権限系。 0:無権限, 1:一般権限, 3:管理権限
  <td><input type="text" name="role" value="{$role}"><br>
<tr>
  <td>ユーザに対するmemo
  <td><input type="text" name="memo" value="{$memo}"><br>
</table>
<input type="hidden" name="id" value="{$id}">
<input type="hidden" name="pass" value="dummy"><!-- 攻撃に対する軽いテスト用 -->
<input type="hidden" name="csrf_token" value="{$csrf_token}">
<button type="submit">編集する</button>
</form>

