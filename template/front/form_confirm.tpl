入力内容:<br>
文字：{$form.text_data}<br>
数値：{$form.int_data}<br>
<form action="/index.php?c=form_fin" method="post">
<input type="hidden" name="csrf_token" value="{$csrf_token}">
<button type="submit">完了</button>
</form>

