function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "control_system2"};
	this.sidHashMap["control_system2"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/time "] = {sid: "control_system2:1"};
	this.sidHashMap["control_system2:1"] = {rtwname: "<Root>/time "};
	this.rtwnameHashMap["<Root>/endpoint "] = {sid: "control_system2:2"};
	this.sidHashMap["control_system2:2"] = {rtwname: "<Root>/endpoint "};
	this.rtwnameHashMap["<Root>/x"] = {sid: "control_system2:6"};
	this.sidHashMap["control_system2:6"] = {rtwname: "<Root>/x"};
	this.rtwnameHashMap["<Root>/Model"] = {sid: "control_system2:3"};
	this.sidHashMap["control_system2:3"] = {rtwname: "<Root>/Model"};
	this.rtwnameHashMap["<Root>/Model1"] = {sid: "control_system2:4"};
	this.sidHashMap["control_system2:4"] = {rtwname: "<Root>/Model1"};
	this.rtwnameHashMap["<Root>/Model2"] = {sid: "control_system2:5"};
	this.sidHashMap["control_system2:5"] = {rtwname: "<Root>/Model2"};
	this.rtwnameHashMap["<Root>/signals"] = {sid: "control_system2:7"};
	this.sidHashMap["control_system2:7"] = {rtwname: "<Root>/signals"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
