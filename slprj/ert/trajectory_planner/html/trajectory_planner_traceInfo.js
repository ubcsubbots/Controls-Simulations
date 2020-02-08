function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "trajectory_planner"};
	this.sidHashMap["trajectory_planner"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<Root>/cmd "] = {sid: "trajectory_planner:1"};
	this.sidHashMap["trajectory_planner:1"] = {rtwname: "<Root>/cmd "};
	this.rtwnameHashMap["<Root>/time "] = {sid: "trajectory_planner:5"};
	this.sidHashMap["trajectory_planner:5"] = {rtwname: "<Root>/time "};
	this.rtwnameHashMap["<Root>/x_d"] = {sid: "trajectory_planner:2"};
	this.sidHashMap["trajectory_planner:2"] = {rtwname: "<Root>/x_d"};
	this.rtwnameHashMap["<Root>/x_dot_d"] = {sid: "trajectory_planner:3"};
	this.sidHashMap["trajectory_planner:3"] = {rtwname: "<Root>/x_dot_d"};
	this.rtwnameHashMap["<Root>/x_dot_dot_d "] = {sid: "trajectory_planner:4"};
	this.sidHashMap["trajectory_planner:4"] = {rtwname: "<Root>/x_dot_dot_d "};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
