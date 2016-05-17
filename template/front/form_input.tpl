<form action="/index.php?c=form_confirm" method="post">
{if true == $if_error_text_data}
文字でエラーです。<br>
{/if}
{if true == $if_error_must_text_data}
文字は必須です<br>
{/if}
{if true == $if_error_max_text_data}
文字は５～10文字でお願いします。長すぎます<br>
{/if}
{if true == $if_error_min_text_data}
文字は５～10文字でお願いします。短すぎます<br>
{/if}
文字:<input type="text" name="text_data" value="{$text_data}"><br>
数値:<input type="text" name="int_data" value="{$int_data}"><br>
<br>
<button type="submit">確認</button>
</form>
