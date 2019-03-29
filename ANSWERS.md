**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**
1. Created
  This is where the process starts. It's not running yet or doing it's job. It waits for it's place in the next step.

2. Ready
  In the ready state, the process is in the main memory. It waits for it's turn in the processor. Processors can only execute on process at a time.

3. Running
  When it's time for execution the process goes into the running state. The process is executed by the CPU.

4. Waiting
  If a process cannot be completed temporarily, It will be set to waiting. It gets put to the side while other processes run. After the process is done waiting it can be moved back to running.

5. Terminated
  A process can complete it's work then it's done. It terminates itself. Otherwise it may be killed by the user. If it's parent is terminated it may become a zombie process. 



**2. What is a zombie process?**
A zombie process is a process that was left behind by it's parent. 

**3. How does a zombie process get created? How does one get destroyed?**

When a parent process completes it's work, and the child process is left, it becomes a zombie. One solution is to use `wait()` on the parent process. Then the child process will complete before the parent.
A zombie process who lost it's parent will be adopted by the Process 1. Processes always have a parent. Eventually it will take it's last steps at the direction of the first process.



**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

When a programmer compiles code once, it's never compiled again. So when the user runs the program, it's ready to go. By contrast, a non-compiled language is translated into a version more useful to the computer at run-time. Compiled languages tend to be faster and more efficient. This means a programmer takes extra time at the development stage. A compiled language is more useful across platforms. Whereas a non-compiled languages may need extra software to run on various systems.
