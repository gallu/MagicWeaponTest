<H2>管理ユーザ：パスワード強制変更</H2>


{if true == $update_error}<span class="error">DBへのinsertに失敗しました。確認してください。</span>{/if}
<form action="./admin.php?c=admin_user_edit_pass_fin" method="post">
編集対象のID：{$id}<br>
編集対象の名前：{$name}<br>
<table border="1">
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
</table>
<input type="hidden" name="user_id" value="{$id}">
<input type="hidden" name="csrf_token" value="{$csrf_token}">
<button type="submit">パスワードを上書きする</button>
</form>
