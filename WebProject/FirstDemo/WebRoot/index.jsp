<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<script type="text/javascript" src="./jsfiles/CheckData.js"></script>
<meta charset="UTF-8">
<title>登录</title>
</head>
<body>
	<form action="DoCheck" method="post" onsubmit="return check(this)">
		<table align="center" border="1">
			<tr>
				<td>学号</td>
				<td><input type="text" name="stunum" ></td>
			</tr>
			<tr>
				<td>密码</td>
				<td><input type="password" name="passwd"></td>
			</tr>
			<tr align="center">
				<td colspan="2">
				<input type="reset" value="重置" width="3">
				<input type="submit" value="登录" width="4">
				</td>
			</tr>
		</table>
	</form>
</body>
</html>