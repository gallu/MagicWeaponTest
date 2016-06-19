<html>
 <head>
  <meta http-equiv="Content-Type" content="text/html; charset=Shift_JIS" />
  <title>ログイン(管理画面)</title>
 </head>
 <body>
提供しているダミーユーザは以下の通りです。<br>
<br>
<form>
anyユーザ(権限を持たないユーザ)<br>
<input value="test"> / <input value="testpass"> <br>
<br>
一般権限ユーザ(一般権限まであるユーザ)<br>
<input value="test2"> / <input value="testpass"> <br>
<br>
管理権限ユーザ(管理権限まであるユーザ)<br>
非公開です <br>
<br>
</form>
  <form action="./admin.php" method="post">
    管理画面のログイン
{if true == $is_login_error}<p class="alert">ログインでエラーが発生しました。IDとパスワードを入れなおしてみてください</p>{/if}
    <input type="hidden" id="c" name="c" value="login" />
    <dl>
     <dt> <label for="id">ID</label> </dt>
     <dd> <input type="text" id="id" name="id" value="{$id}" /> </dd>
     <dt> <label for="pass">pass</label> </dt>
     <dd> <input type="password" id="pass" name="pass" value="" /> </dd>
     <dt>&emsp;</dt>
     <dd> <input type="submit" value="login" /></dd>
    </dl>
  </form>
<hr>
<a href="./admin.php?c=static_1">静的画面サンプル</a><br>


 </body>
</html>

