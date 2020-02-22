function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "frame_conversion2"};
	this.sidHashMap["frame_conversion2"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "frame_conversion2:3"};
	this.sidHashMap["frame_conversion2:3"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<Root>/nu"] = {sid: "frame_conversion2:1"};
	this.sidHashMap["frame_conversion2:1"] = {rtwname: "<Root>/nu"};
	this.rtwnameHashMap["<Root>/eta"] = {sid: "frame_conversion2:2"};
	this.sidHashMap["frame_conversion2:2"] = {rtwname: "<Root>/eta"};
	this.rtwnameHashMap["<Root>/MATLAB Function"] = {sid: "frame_conversion2:3"};
	this.sidHashMap["frame_conversion2:3"] = {rtwname: "<Root>/MATLAB Function"};
	this.rtwnameHashMap["<Root>/eta_dot"] = {sid: "frame_conversion2:4"};
	this.sidHashMap["frame_conversion2:4"] = {rtwname: "<Root>/eta_dot"};
	this.rtwnameHashMap["<S1>:1"] = {sid: "frame_conversion2:3:1"};
	this.sidHashMap["frame_conversion2:3:1"] = {rtwname: "<S1>:1"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
