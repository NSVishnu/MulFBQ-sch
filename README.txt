# p2

multi-level feedback queue scheduling algorithm is implemented by considering
the 3 scheduing queues.

1st Queue : Round Robin Scheduling of time quantum =8
at first all the processes entered by the user will be processed in this scheduling queue.

2nd Queue : Round Robin Scheduling of time quantum =16
those processes which are not completed in the 1st queue will be added into the 2nd queue.

3rd Queue : First Come First Serve 
all the remaining processes which are even not completed in the 2nd queue are placed into the 
FCFS queue and the process will be processed till it gets completed.

multilevl feedback queue scheduling is used to avoid starvation of any high level processes in 
lower priority queues. The solution for this is done through Aging. as a process passes from higher level
queue to lower level queue the priorty of the process is increased by 1.

inputs that should be given by the user are
1.process name
2.process arrival time
3.process burst time
4.process priority

it gives output in the form of gant chart 
like the time where the process is started and ending..
