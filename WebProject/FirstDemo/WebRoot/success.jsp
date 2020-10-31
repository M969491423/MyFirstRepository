<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    <%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>登陆成功</title>
</head>
<body style="text-align: center;">
	<h1>登陆成功</h1>
	<table align="center">
		<tr align="center">
			<td colspan="4">选课</td>
		</tr>
		<c:forEach items="${classes}" var="i">
			<tr>
				<td>${i.name}</td>
				<td>${i.teacher}</td>
				<td>${i.room}</td>
				<td><input type="button" value="选课" onclick="javascript:window.location.href='DoChoose?name=${i.name}&teacher=${i.teacher}&room=${i.room}'"></td>
			</tr>
		</c:forEach>
	</table>
</body>
</html>