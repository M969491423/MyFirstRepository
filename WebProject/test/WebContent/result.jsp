<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    <%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>处理结果</title>
</head>
<body style="text-align: center;">
	<c:choose>
		<c:when test="${result==0}">
			<h1>添加成功</h1>
			<h1>信息如下</h1>
	<table align="center">
		<tr>
			<td>户别：${info.households}</td>
		</tr>
		<tr>
			<td>住房类型：${info.homeType}</td>
		</tr>
		<tr>
			<td>本户现住房面积：${info.homeArea}</td>
		</tr>
		<tr>
			<td>本户现住房间数：${info.roomNum}</td>
		</tr>
		<tr>
			<td>户主姓名：${info.name}</td>
		</tr>
		<tr>
			<td>身份证号码：${info.ID}</td>
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
		</c:when>
		<c:when test="${result==-1}">
			<h1>添加失败</h1>
		</c:when>
		<c:when test="${result==-2}">
			<h1>无此人信息</h1>
		</c:when>
		<c:when test="${result==1}">
			<h1>删除成功</h1>
		</c:when>
	</c:choose>
	<a href="index.jsp">返回首页</a>
</body>
</html>