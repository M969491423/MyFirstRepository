<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<script type="text/javascript" src="./jsfiles/check.js">
</script>
<head>
<meta charset="UTF-8">
<title></title>
</head>
<body>
	<form action="Add" name="form1" onsubmit="return doCheck(form1);" method="post">
		<table align="center" border="1">
			<tr>
				<td>户别:</td>
				<td>
					<input type="radio" name="households" value="家庭户">家庭户
					<input type="radio" name="households" value="集体户">集体户
				</td>
			</tr>
			<tr>
				<td>住房类型</td>
				<td>
					<input type="radio" name="homeType" value="家庭住房">家庭住房
					<input type="radio" name="homeType" value="集体住所">集体住所
					<input type="radio" name="homeType" value="工作地住所">工作地住所
					<input type="radio" name="homeType" value="其他住宅">其他住宅
					<input type="radio" name="homeType" value="无住宅">无住宅
				</td>
			</tr>
			<tr>
				<td>本户现住房面积</td>
				<td><input type="text" name="homeArea">平方米</td>
			</tr>
			<tr>
				<td>本户现住房间数</td>
				<td><input type="text" name="roomNum">间</td>
			</tr>
			<tr>
				<td>户主姓名</td>
				<td><input type="text" name="name"></td>
			</tr>
			<tr>
				<td>身份证号码</td>
				<td><input type="text" name="ID"></td>
			</tr>
			<tr>
				<td>性别</td>
				<td>
					<input type="radio" name="sex" value="男">男
					<input type="radio" name="sex" value="女">女
				</td>
			</tr>
			<tr>
				<td>民族</td>
				<td><input type="text" name="nation"></td>
			</tr>
			<tr>
				<td>受教育程度</td>
				<td>
					<select name="education">
						<option value="研究生">研究生
						<option value="大学本科">大学本科
						<option value="大学专科">大学专科
						<option value="高中">高中
						<option value="初中">初中
						<option value="小学">小学
						<option value="未上过学">未上过学
					</select>
				</td>
			</tr>
			
			<tr> 
				<td align="center" colspan="5">
					<input type="reset" value="重置">
					<input type="submit" value="确认" >
				</td>
			</tr>
		</table>
		
	</form>
</body>
</html>