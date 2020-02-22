function CodeDefine() { 
this.def = new Array();
this.def["step"] = {file: "controller2_cpp.html",line:51,type:"fcn"};
this.def["initialize"] = {file: "controller2_cpp.html",line:345,type:"fcn"};
this.def["getRTM"] = {file: "controller2_cpp.html",line:366,type:"fcn"};
this.def["setErrorStatusPointer"] = {file: "controller2_cpp.html",line:372,type:"fcn"};
this.def["RT_MODEL_controller2_T"] = {file: "controller2_h.html",line:39,type:"type"};
this.def["struct_LRrGrd8qubFR55llqE8teD"] = {file: "controller2_h.html",line:79,type:"type"};
this.def["initialize"] = {file: "controller2_h.html",line:93,type:"fcn"};
this.def["rtCP_pooled_TFd8bf0TDh3x"] = {file: "../../_sharedutils/html/const_params_cpp.html",line:17,type:"var"};
this.def["rtCP_pooled_xIp5xqWwZtfz"] = {file: "../../_sharedutils/html/const_params_cpp.html",line:22,type:"var"};
this.def["int8_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:45,type:"type"};
this.def["uint8_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:46,type:"type"};
this.def["int16_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:47,type:"type"};
this.def["uint16_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:48,type:"type"};
this.def["int32_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:49,type:"type"};
this.def["uint32_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:50,type:"type"};
this.def["int64_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:51,type:"type"};
this.def["uint64_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:52,type:"type"};
this.def["real32_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:53,type:"type"};
this.def["real64_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:54,type:"type"};
this.def["real_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:60,type:"type"};
this.def["time_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:61,type:"type"};
this.def["boolean_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:62,type:"type"};
this.def["int_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:63,type:"type"};
this.def["uint_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:64,type:"type"};
this.def["ulong_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:65,type:"type"};
this.def["ulonglong_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:66,type:"type"};
this.def["char_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:67,type:"type"};
this.def["uchar_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:68,type:"type"};
this.def["byte_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:69,type:"type"};
this.def["pointer_T"] = {file: "../../_sharedutils/html/rtwtypes_h.html",line:90,type:"type"};
}
CodeDefine.instance = new CodeDefine();
var testHarnessInfo = {OwnerFileName: "", HarnessOwner: "", HarnessName: "", IsTestHarness: "0"};
var relPathToBuildDir = "../ert_main.c";
var fileSep = "\\";
var isPC = true;
function Html2SrcLink() {
	this.html2SrcPath = new Array;
	this.html2Root = new Array;
	this.html2SrcPath["controller2_cpp.html"] = "../controller2.cpp";
	this.html2Root["controller2_cpp.html"] = "controller2_cpp.html";
	this.html2SrcPath["controller2_h.html"] = "../controller2.h";
	this.html2Root["controller2_h.html"] = "controller2_h.html";
	this.html2SrcPath["const_params_cpp.html"] = "../const_params.cpp";
	this.html2Root["const_params_cpp.html"] = "../../_sharedutils/html/const_params_cpp.html";
	this.html2SrcPath["rtwtypes_h.html"] = "../rtwtypes.h";
	this.html2Root["rtwtypes_h.html"] = "../../_sharedutils/html/rtwtypes_h.html";
	this.getLink2Src = function (htmlFileName) {
		 if (this.html2SrcPath[htmlFileName])
			 return this.html2SrcPath[htmlFileName];
		 else
			 return null;
	}
	this.getLinkFromRoot = function (htmlFileName) {
		 if (this.html2Root[htmlFileName])
			 return this.html2Root[htmlFileName];
		 else
			 return null;
	}
}
Html2SrcLink.instance = new Html2SrcLink();
var fileList = [
"controller2_cpp.html","controller2_h.html","const_params_cpp.html","rtwtypes_h.html"];
