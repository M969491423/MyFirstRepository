<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>信息查看</title>
</head>
<body style="text-align: center;">
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
	<input type="button" value="确定删除" onclick="javascript:window.location.href='DoDelete?name=${info.name}'">
</body>
</html>