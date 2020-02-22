function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "thrust_allocation2"};
	this.sidHashMap["thrust_allocation2"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "thrust_allocation2:2"};
	this.sidHashMap["thrust_allocation2:2"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<Root>/tau "] = {sid: "thrust_allocation2:1"};
	this.sidHashMap["thrust_allocation2:1"] = {rtwname: "<Root>/tau "};
	this.rtwnameHashMap["<Root>/thrust-allocator"] = {sid: "thrust_allocation2:2"};
	this.sidHashMap["thrust_allocation2:2"] = {rtwname: "<Root>/thrust-allocator"};
	this.rtwnameHashMap["<Root>/signals "] = {sid: "thrust_allocation2:3"};
	this.sidHashMap["thrust_allocation2:3"] = {rtwname: "<Root>/signals "};
	this.rtwnameHashMap["<S1>:1"] = {sid: "thrust_allocation2:2:1"};
	this.sidHashMap["thrust_allocation2:2:1"] = {rtwname: "<S1>:1"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
