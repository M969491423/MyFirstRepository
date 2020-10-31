<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    <%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>登陆失败</title>
</head>
<body style="text-align: center;">
	<c:choose>
		<c:when test="${result==-1}">
			<h1>无此学生</h1>
		</c:when>
		<c:otherwise>
			<h1>密码错误</h1>
		</c:otherwise>
	</c:choose>
</body>
</html>