# mini_talk

### cd /minitalk
### run : `make`
### run : `./server`
### in another terminal run : `./client <pid printed by server> "message"`


### 1. What is a SIGNAL ?
- A signal is a software generated interrupt that is sent to a process by the OS because of when user press ctrl-c or another process tell something to this process.
- A signal is basically a form of inter-process communication (IPC), that is used to notify a process about an event or a condition that has occured.
- There are fix set of signals that can be sent to a process. signal are identified by integers.
Signal number have symbolic names. For example SIGCHLD is number of the signal sent to the parent process when child terminates.

- Examples:
```
#define SIGHUP  1   /* Hangup the process */ 
#define SIGINT  2   /* Interrupt the process */ 
#define SIGQUIT 3   /* Quit the process */ 
#define SIGILL  4   /* Illegal instruction. */ 
#define SIGTRAP 5   /* Trace trap. */ 
#define SIGABRT 6   /* Abort. */
```

### 2. Kill(): `to send a signal`
- Kill() is system call has two arguments, the pid(process ID) and the signal(signal number), we can use it to send the signal we want to the process we want which is identified by a pid.

### 3. Sigaction or Signal() ? `both for are to catch a signal. but sigaction is more advanced utility`
#### Sigaction :
- The sigaction structure specifies how to handle a signal.
- Signal handlers and actions are defined for the process and affect all threads in the process. For example, if one thread ignores a signal, then all threads ignore the signal.
The `sa_mask` field indicates any signals that should be blocked while the signal handler is being executed.
The `sa_flags` field determines a number of different things, but the important ones are whether we get the extended information (SA_SIGINFO ) and whether system calls that were interrupted by the signal are automatically restarted (SA_RESTART), The alternative is that the interrupted system calls will fail, so restarting them is obviously a better approach.
The `sa_handler` and sa_sigaction properties of the sigaction interchangeably to handle the sig_handler()function.
The sigaction function handler has a prototype that provides the signal number, information about the signal delivery, and information about the thread context.

- The function `sigaction()` : Examine or specify the action associated with a signal.
```int sigaction(int sig, const struct sigaction * act, struct sigaction * oact);```
- `sig` :
The signal number (defined in <signal.h>). For more information, see “POSIX and QNX Neutrino signals” in the documentation for SignalAction().
If the signal terminates a process, the cleanup of the terminated process occurs by default at the priority of the thread that sent the signal. As a QNX Neutrino extension, if you OR the SIG_TERMER_NOINHERIT flag (defined in <signal.h>) into sig, the cleanup occurs at the priority of the thread that received the signal.
- `act` :
NULL, or a pointer to a sigaction structure that specifies how you want to modify the action for the given signal.
- `oact` :
NULL, or a pointer to a sigaction structure that the function fills with information about the current action for the signal.

- Returns :
0 = Success.
-1 = An error occurred (errno is set).

### Signal() :
- this function is a very basic function to catch signals, it takes also two arguments, the signal(signal number) we want to catch, and the function/handler that will be called once the signal is caught .

### How Minitalk works ?
check this article : https://m4nnb3ll.medium.com/first-time-to-work-with-signals-minitalk-a-42-the-network-project-8bae32237975
