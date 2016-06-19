<h2>管理者ユーザ作成</h2>

{if true == $insert_error}<span class="error">DBへのinsertに失敗しました。ID重複の可能性があるので確認してください。</span>{/if}
<form action="./admin.php?c=admin_user_add_fin" method="post">
<table border="1">
<tr>
  <td>管理者を識別するためのID
      {if true == $if_error_must_id}<span class="error">(IDは必須です)</span>{/if}
      {if true == $if_error_max_id}<span class="error">(IDは100バイト以内です)</span>{/if}
  <td><input type="text" name="id" value="{$id}"><br>
<tr>
  <td>ログインパスワード
      {if true == $if_error_must_pass_1}<span class="error">(パスワードは必須です)</span>{/if}
      {if true == $if_error_max_pass_1}<span class="error">(パスワードは72バイト以内です)</span>{/if}
      {if true == $if_error_unmach_pass}<span class="error">(パスワードとパスワード(再)が不一致です)</span>{/if}
  <td><input type="password" name="pass_1" value=""><br>
<tr>
  <td>ログインパスワード(再度入力)
      {if true == $if_error_must_pass_2}<span class="error">パスワード(再)は必須です</span>{/if}
      {if true == $if_error_max_pass_2}<span class="error">(パスワード(再)は72バイト以内です)</span>{/if}
  <td><input type="password" name="pass_2" value=""><br>
<tr>
  <td>アカウント停止状態(0以外(基本1)なら停止状態で作成)
  <td><input type="text" name="account_stop" value="0"><br>
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
<input type="hidden" name="csrf_token" value="{$csrf_token}">
<button type="submit">登録する</button>
</form>

