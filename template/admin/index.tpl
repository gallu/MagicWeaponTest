<html>
 <head>
  <meta http-equiv="Content-Type" content="text/html; charset=Shift_JIS" />
  <title>������(��������)</title>
 </head>
 <body>
  <form action="./admin.php" method="post">
    <legend>�������̤Υ�����</legend>
<!-- %%%login_error%%%<br> -->
$$$is_login_error$$$<p class="alert">������ǥ��顼��ȯ�����ޤ�����ID�ȥѥ���ɤ�����ʤ����ƤߤƤ�������</p>$$$/is_login_error$$$
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

