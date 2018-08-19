// prepare
gcc a.c

// for tracer.sh
$ sudo -s
# ./a.out &
[1] 13111
# ./tracer.sh 13111
# cat /sys/kernel/debug/tracing/trace > ftrace.log

// for tracer_dynamic.sh
$ sudo -s
# ./a.out &
[1] 13111
# ./tracer_dynamic.sh 13111 *mm* 
# cat /sys/kernel/debug/tracing/trace > ftrace.log

// for tracer_graph.sh
$ sudo -s
# ./a.out &
[1] 13111
# ./tracer_graph.sh 13111 vfs*
# cat /sys/kernel/debug/tracing/trace > ftrace.log

reference
https://www.kernel.org/doc/Documentation/trace/ftrace.txt
https://lwn.net/Articles/365835/ -> Debugging the kernel using Ftrace - part 1
https://lwn.net/Articles/366796/ -> Debugging the kernel using Ftrace - part 2
https://lwn.net/Articles/370423/ -> Secrets of the Ftrace function tracer
https://github.com/brendangregg/perf-tools/ -> perf-tools
https://opensourceforu.com/2010/11/kernel-tracing-with-ftrace-part-1/
https://opensourceforu.com/2010/12/kernel-tracing-with-ftrace-part-2/
http://www.forshee.me/2011/12/15/using-ftrace-to-identify-process.html
http://oboguev.net/kernel-etc/linux-kernel-tracing-profiling.html -> linux kernel tracing profiling


