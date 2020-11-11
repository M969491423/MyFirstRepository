/**
 * 
 */
function isID(_input){
	var str = _input.value;
	var patt = /^\d{12}(\d|X|x)$/g
	return patt.test(str);
}

function isNum(_input){
	var str = _input.value;
	var patt = /^\d*$/g;
	return patt.test(str);
}

function doCheck(form){
	if(!isNum(form.homeArea)){
		alert("住房面积只能是整数");
		return false;
	}
	if(!isNum(form.roomNum)){
		alert("房间数只能是整数");
		return false;
	}
	if(!isID(form.ID)){
		alert("身份证号码不正确");
		return false;
	}
	return true;
}