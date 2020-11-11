<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>个人信息</title>
</head>
<body style="text-align: center;">
	<table align="center">
		<tr>
			<td>户主姓名：${info.name}</td>
		</tr>
		<tr>
			<td>姓名：${info.name}</td>
		</tr>
		<tr>
			<td>性别：${info.sex}</td>
		</tr>
		<tr>
			<td>民族：${info.nation}</td>
		</tr>
		<tr>
			<td>受教育程度：${info.education}</td>
		</tr>
	</table>
		<a href="index.jsp">返回首页</a>
	
</body>
</html>