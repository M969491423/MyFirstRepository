<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    <%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>信息查看</title>
</head>
<body style="text-align: center;">
	<table align="center" border="1">
		<tr>
			<th>户主姓名</th>
			<th>性别</th>
			<th>民族</th>
			<th>受教育程度</th>
		</tr>
	<c:forEach items="${infos}" var="i">
		<tr>
			<td><a href="GetInfo?name=${i.name}&type=3">${i.name}</a></td>
			<td>${i.sex}</td>
			<td>${i.nation}</td>
			<td>${i.education}</td>
		</tr>
	</c:forEach>
	</table>
	<a href="index.jsp" style="text-align: center;">返回首页</a>
</body>
</html>