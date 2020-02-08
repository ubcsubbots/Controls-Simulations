function TraceInfoFlag() {
    this.traceFlag = new Array();
}
top.TraceInfoFlag.instance = new TraceInfoFlag();
function TraceInfoLineFlag() {
    this.lineTraceFlag = new Array();
    this.lineTraceFlag["trajectory_planner.cpp:28"]=1;
    this.lineTraceFlag["trajectory_planner.cpp:34"]=1;
}
top.TraceInfoLineFlag.instance = new TraceInfoLineFlag();
