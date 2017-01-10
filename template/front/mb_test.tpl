てすと<br>
{* $data|var_dump *}

{foreach from=$data item=i}
  {* $i|var_dump *}
  {* $i.食物繊維総量  この書き方はダメ *}<br>
  {$i['エネルギー（kcal）']}<br>
  {$i['食物繊維総量']}<br>
  {$i['α-カロテン']}<br>
  <br>
{/foreach}

