/**
 * 
 */

function isNull(str){
	if(str.length==0){
		return true;
	}
}

function check(form){
	var stunum = form.stunum.value;
	var passwd = form.passwd.value;
	if(isNull(stunum)){
		alert("学号不能为空");
		return false;
	}
	
	if(isNull(passwd)){
		alert("密码不能为空");
		return false;
	}
	return true;
}