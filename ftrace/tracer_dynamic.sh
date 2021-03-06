#!/bin/bash
 
DPATH="/sys/kernel/debug/tracing"
PID=$1
FUNC=$2

echo "ftrace test"

if [ $# -ne 2 ]
then
	echo Usage: tracer_graph.sh pid function_name
	exit 1
fi

# flush existing trace data
echo nop > $DPATH/current_tracer

# disable trace
echo 0 > $DPATH/tracing_on

# set function tracer
echo function > $DPATH/current_tracer

# write current process id to set_ftrace_pid file
echo $PID > $DPATH/set_ftrace_pid

echo $FUNC > $DPATH/set_ftrace_filter

# enable the current tracer
echo 1 > $DPATH/tracing_on
