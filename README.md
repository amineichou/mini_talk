# mini_talk

### 1. What is a SIGNAL ?
- A signal is a software generated interrupt that is sent to a process by the OS because of when user press ctrl-c or another process tell something to this process.
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

