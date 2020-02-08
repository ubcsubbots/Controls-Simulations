function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "thrust_allocator"};
	this.sidHashMap["thrust_allocator"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/tau "] = {sid: "thrust_allocator:1"};
	this.sidHashMap["thrust_allocator:1"] = {rtwname: "<Root>/tau "};
	this.rtwnameHashMap["<Root>/signals "] = {sid: "thrust_allocator:3"};
	this.sidHashMap["thrust_allocator:3"] = {rtwname: "<Root>/signals "};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
