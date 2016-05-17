<html>
 <head>
  <meta http-equiv="Content-Type" content="text/html; charset=Shift_JIS" />
  <title>ログイン(管理画面)</title>
 </head>
 <body>
  <form action="./admin.php" method="post">
    <legend>管理画面のログイン</legend>
<!-- %%%login_error%%%<br> -->
$$$is_login_error$$$<p class="alert">ログインでエラーが発生しました。IDとパスワードを入れなおしてみてください</p>$$$/is_login_error$$$
    <input type="hidden" id="c" name="c" value="login" />
    <dl>
     <dt> <label for="id">ID</label> </dt>
     <dd> <input type="text" id="id" name="id" value="%%%id%%%" /> </dd>
     <dt> <label for="pass">pass</label> </dt>
     <dd> <input type="password" id="pass" name="pass" value="" /> </dd>
     <dt>&emsp;</dt>
     <dd> <input type="submit" value="login" /></dd>
    </dl>
  </form>

 </body>
</html>

