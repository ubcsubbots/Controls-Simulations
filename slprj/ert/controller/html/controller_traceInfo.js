function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "controller"};
	this.sidHashMap["controller"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/x_d"] = {sid: "controller:1"};
	this.sidHashMap["controller:1"] = {rtwname: "<Root>/x_d"};
	this.rtwnameHashMap["<Root>/x_dot_d"] = {sid: "controller:2"};
	this.sidHashMap["controller:2"] = {rtwname: "<Root>/x_dot_d"};
	this.rtwnameHashMap["<Root>/x_dot_dot_d "] = {sid: "controller:3"};
	this.sidHashMap["controller:3"] = {rtwname: "<Root>/x_dot_dot_d "};
	this.rtwnameHashMap["<Root>/x"] = {sid: "controller:4"};
	this.sidHashMap["controller:4"] = {rtwname: "<Root>/x"};
	this.rtwnameHashMap["<Root>/x_dot "] = {sid: "controller:5"};
	this.sidHashMap["controller:5"] = {rtwname: "<Root>/x_dot "};
	this.rtwnameHashMap["<Root>/x_dot_dot "] = {sid: "controller:6"};
	this.sidHashMap["controller:6"] = {rtwname: "<Root>/x_dot_dot "};
	this.rtwnameHashMap["<Root>/tau "] = {sid: "controller:7"};
	this.sidHashMap["controller:7"] = {rtwname: "<Root>/tau "};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
