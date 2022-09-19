# Technological communication

**Khaled Ismaeel, ST-6, k.ismaeel@innopolis.university**

## Task 1

### a.

- **Process**: a running instance of a program. It is characterized by an instruction pointer, address space, files descriptors, and other traits.
- **Daemon**: a background process not under direct user control.
- System call: a function call that transfers control to the kernel asking for a service.
- **Client & server**: an architecture where service logic is one directional from a client that sends a request to a server that responds to the request.
- **Peer to peer**: an architecture with no obvious client-server distinction.
- **Inter-process communication**: the state where different processes share data and signals to achieve a goal.

### b.

According to [1], the Win32 API provides the following primitives for inter-process communication:

- **Clipboard**: the usual copy-paste functionality is an IPC mechanism managed by the user.
- **Component Object Model (COM)**: a mechanism for difference process to collaborate on managing a single document, handled by the proprietary Object Linking and Embedding technology.
- **Data copy**: a system call for a properly setup sending and receiving applications to share data.
- **Dynamic Data Exchange (DDE)**: a technology now superseded by COM, it also allows for several processes to collaborate on a single document.
- **File mapping**: a mechanism for mapping file contents to a process's address space. When more than one process map the same file, they can exchange data through the shared mapped memory.
- **Mail slots**: a one way message-passing mechanism where a process sets up a mail slot and other processes send messages to it. It is also scalable to multiple machines and supports broadcasting.
- **Pipes**: a data stream between processes. They can be either unnamed, which are typically used to connecting output and input streams of closely-related processes, or named, which are typically used for connecting arbitrary processes even across a network.
- **Remote Procedure Call (RPC)**: enables a processes to call a function from another process's address space.
- **Windows sockets:** transport layer-style sockets but are actually implemented without passing through the network card.

Instead of dealing with Unix system calls, let us consider POSIX system calls since it is a more widely-implemented standard. According to [2], POSIX systems supports three types of IPC:

- **Message passing**: in particular, the creation of message queues with subscriptions.
- **Semaphores**: small-footprint data structures for coordinating process execution (for locking and unlocking resources, for example).
- **Shared memory**: similar to opening a file, a POSIX process can open a memory segment shared by other processes.


### c.

Let us consider two architectures: monolithic and micro.

In a monolithic kernel, there is significant scope for IPC functionality. This is because the IPC mechanisms run entirely in kernel space, allowing for privileged operations such as sharing memory, mapping a single file to multiple address spaces, and so forth. All of the mechanisms we discussed in the previous section are typical for monolithic kernels.

However, for microkernels, little IPC logic is running in kernel space. As a result, microkernel rely heavily on message passing and derivatives for IPC. Message passing logic imposes a significant overhead, which is why microkernels utilize aggressive optimizations to make it run quicker.

## Task 2

### a.

Actually, the solution to ***1.a.*** lists all common IPC mechanisms. Let us list them here (without repeating their brief explanation).

| Mechanism | Advantages | Disadvantages |
| --------- | ---------- | ------------- |
| Clipboard | Very convenient and intuitive | Limited to user-facing applications |
| Component Object Model | Leverages modern programming paradigms like OOP and DOM | Proprietary and not generalizable outside Windows GUI applications |
| Data copy | Fast and intuitive | Needs significant boiler plate code for encoding and decoding data |
| Dynamic Data Exchange | Similar to COM | Outdated |
| File mapping | Fast and intuitive, reuses existing OS functionality | Dumps significant responsibility on the programmer |
| Mail slots | Simple and clean | Somewhat difficult to manage in a networking environment |
| Pipes | Similar to data copy, fast and intuitive | Similar to data copy, need encoding and decoding |
| RPC | Very versatile | Imposes context switching overhead |
| Sockets (Windows or Unix) | Similar to pipes | Similar to pipes |
| Message passing | Intuitive and scalable | Slow |
| Shared memory | Similar to file mapping | Similar to file mapping |

### b.

Since I'm using a Linux system, the IPC facilities for me are message queues, shared memory segments, and semaphores. I can conveniently retrieve all of them with the `ipcs` command.

```
[khaledismaeel@archlinux ~]$ sudo ipcs
[sudo] password for khaledismaeel: 

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status      
0x00000000 98304      khaledisma 600        499712     2          dest         
0x00000000 131074     khaledisma 600        524288     2          dest         
0x00000000 98311      khaledisma 600        524288     2          dest         
0x00000000 98324      khaledisma 600        786432     2          dest         
0x00000000 98325      khaledisma 600        786432     2          dest         
0x00000000 65559      khaledisma 600        98304      2          dest         
0x00000000 65560      khaledisma 600        98304      2          dest         
0x00000000 65563      khaledisma 600        77824      2          dest         
0x00000000 65564      khaledisma 600        77824      2          dest         
0x00000000 32         khaledisma 600        86016      2          dest         
0x00000000 33         khaledisma 600        86016      2          dest         
0x00000000 32805      khaledisma 600        61440      2          dest         
0x00000000 98342      khaledisma 600        458752     2          dest         
0x00000000 32807      khaledisma 600        61440      2          dest         
0x00000000 32808      khaledisma 600        86016      2          dest         
0x00000000 32809      khaledisma 600        86016      2          dest         
0x00000000 98346      khaledisma 600        458752     2          dest         
0x00000000 65589      khaledisma 600        233472     2          dest         
0x00000000 65590      khaledisma 600        233472     2          dest         
0x00000000 65591      khaledisma 600        110592     2          dest         
0x00000000 65592      khaledisma 600        110592     2          dest         
0x00000000 98365      khaledisma 600        524288     2          dest         
0x00000000 65599      khaledisma 600        499712     2          dest         

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
```

We can see there are no message queues and semaphores but there are a bunch of shared memory segments.

### c.

This exercise is submitted as a video recording.

## References

1. https://learn.microsoft.com/en-us/windows/win32/ipc/interprocess-communications
2. https://man7.org/linux/man-pages/man2/ipc.2.html
3. http://cdworkshop.eit.lth.se/fileadmin/eit/project/142/IPC_Report.pdf
4. https://linux.die.net/man/2/pipe
5. https://man7.org/linux/man-pages/man1/ipcs.1.html
6. https://man7.org/linux/man-pages/man2/mmap.2.html
