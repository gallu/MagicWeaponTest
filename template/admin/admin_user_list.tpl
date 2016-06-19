<H2>管理ユーザ一覧</H2>
注意：本来は「管理権限が必要」だと思いますが、サンプルなので、listのみ「一般権限でOK」にしました。<br>
<br>
{if '' != $del_user.name}<hr>{$del_user.name}(ID:{$del_user.id})を削除しました！！<br><hr>{/if}
<a href="./admin.php?c=admin_user_add">ユーザ追加</a><br>
<table border="1">
<tr>
  <th>ユーザID
  <th>登録日
  <th>ロール
  <th>ロック状態
{foreach from=$user_list item=i}
<tr>
  <td><a href="./admin.php?c=admin_user_detail&user_id={$i.id}">{$i.id}</a>
  <td>{$i.created}
  <td>{$i.role_string}
  <td>
{if true == $i.lock.flg}
  ロック中:{$i.lock.memo}<br>
<form action="./admin.php?c=admin_user_unlock" method="post">
<input type="hidden" name="user_id" value="{$i.id}">
<input type="hidden" name="csrf_token" value="{$csrf_token}">
<button type="submit" onClick="return confirm('ロックを解除してログイン可能にします。\nよろしいですか？')">ロック解除する</button>
</form>
{else}
  非ロック：
<form action="./admin.php?c=admin_user_lock" method="post">
ロック理由：<input type="text" name="memo"><br>
<input type="hidden" name="user_id" value="{$i.id}">
<input type="hidden" name="csrf_token" value="{$csrf_token}">
<button type="submit" onClick="return confirm('ロックしてログインを不可能にします。\nよろしいですか？')">ロックする</button>
</form>
{/if}
  <td>
<form action="./admin.php?c=admin_user_del_fin" method="post" onClick="return confirm('削除すると戻せません。\n本当に削除しますか？')">
<input type="hidden" name="user_id" value="{$i.id}">
<input type="hidden" name="csrf_token" value="{$csrf_token}">
<button type="submit">削除する</button>
</form>

  <!-- <td>{*$i|var_dump*} -->

{/foreach}

</table>

<hr>
現在 {$now_page} Pageです。
{if true == $is_back}
<a href="./admin.php?c=admin_user_list&p={$back_page}">前に戻る</a>
{/if}
　
{if true == $is_next}
<a href="./admin.php?c=admin_user_list&p={$next_page}">次を見る</a>
{/if}
<br>
