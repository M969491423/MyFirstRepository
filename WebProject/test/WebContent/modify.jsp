<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
    <%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>信息修改</title>
</head>
<body>
	<form action="Modify" name="form1" onsubmit="return doCheck(form1);" method="post">
		<table align="center" border="1">
			<tr>
				<td>户别:</td>
				<td>
					<input type="radio" name="households" value="家庭户"
					<c:if test="${info.households==\"家庭户\"}">checked</c:if>>家庭户
					<input type="radio" name="households" value="集体户"
					<c:if test="${info.households==\"集体户\"}">checked</c:if>>集体户
				</td>
			</tr>
			<tr>
				<td>住房类型</td>
				<td>
					<input type="radio" name="homeType" value="家庭住房"
					<c:if test="${info.homeType==\"家庭住房\"}">checked</c:if>>家庭住房
					<input type="radio" name="homeType" value="集体住所"
					<c:if test="${info.homeType==\"集体住所\"}">checked</c:if>>集体住所
					<input type="radio" name="homeType" value="工作地住所"
					<c:if test="${info.homeType==\"工作地住所\"}">checked</c:if>>工作地住所
					<input type="radio" name="homeType" value="其他住宅"
					<c:if test="${info.homeType==\"其他住宅\"}">checked</c:if>>其他住宅
					<input type="radio" name="homeType" value="无住宅"
					<c:if test="${info.homeType==\"无住宅\"}">checked</c:if>>无住宅
				</td>
			</tr>
			<tr>
				<td>本户现住房面积</td>
				<td><input type="text" name="homeArea" value="${info.homeArea}">平方米</td>
			</tr>
			<tr>
				<td>本户现住房间数</td>
				<td><input type="text" name="roomNum" value="${info.roomNum}">间</td>
			</tr>
			<tr>
				<td>身份证号码</td>
				<td><input type="text" name="ID" value="${info.ID}"></td>
			</tr>
			<tr>
				<td><input type="hidden" name="name" value="${info.name}"></td>
			</tr>
			<tr>
				<td>性别</td>
				<td>
					<input type="radio" name="sex" value="M" 
					<c:if test="${info.sex==\"M\"}">checked</c:if>>男
					<input type="radio" name="sex" value="F"
					<c:if test="${info.sex==\"F\"}">checked</c:if>>女
				</td>
			</tr>
			<tr>
				<td>民族</td>
				<td><input type="text" name="nation" value="${info.nation}"></td>
			</tr>
			<tr>
				<td>受教育程度</td>
				<td>
					<select name="education">
						<option value="研究生" 
						<c:if test="${info.education==\"研究生\"}">selected</c:if>
						>研究生
						<option value="大学本科"
						<c:if test="${info.education==\"大学本科\"}">selected</c:if>
						>大学本科
						<option value="大学专科"
						<c:if test="${info.education==\"大学专科\"}">selected</c:if>
						>大学专科
						<option value="高中"
						<c:if test="${info.education==\"高中\"}">selected</c:if>
						>高中
						<option value="初中"
						<c:if test="${info.education==\"初中\"}">selected</c:if>
						>初中
						<option value="小学"
						<c:if test="${info.education==\"小学\"}">selected</c:if>
						>小学
						<option value="未上过学"
						<c:if test="${info.education==\"未上过学\"}">selected</c:if>
						>未上过学
					</select>
				</td>
			</tr>
			
			<tr> 
				<td align="center" colspan="5">
					<input type="reset" value="清除">
					<input type="submit" value="确认修改" >
				</td>
			</tr>
		</table>
		
	</form>
</body>
</html>