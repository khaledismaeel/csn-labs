# Identification of a system

**Khaled Ismaeel, ST-6, k.ismaeel@innopolis.university**

## Task 1

A system is a collective of components. These components interact among each other and with outside entities according to a set of rules and, possibly, produce output in the process.

Cars are such a nice example of a system. They have components (the drivetrain, suspension, wheels, etc), they interact (among each other and with the driver), and they produce an output (torque to the wheels).

## Task 2

The components, the input, the output, and the constraints (or rules) which govern their interactions. A very crude approximation of this is presented in the UML entity-relationship diagram diagram below.

![](https://raw.githubusercontent.com/khaledismaeel/csn-labs/main/identification-of-a-system/diagrams/system.jpg)

The above diagram is inaccurate since constraints govern interactions between components, not only components. Regardless of the many other inaccuracies, let's accept it for now.

## Task 3

Feedback is the state where the output of a system is connected to its input. It helps when a system is meant to be self-governing; it is essential for the system to read its own output in order to autonomously guide itself.

Not all feedback is helpful though, sometimes we have to avoid it as designers or work around it as users. Think of the feedback from the headphone to the microphone.

## Task 4

An information system is a system in the context of Shannon's information theory. Less formally, it's a system where components receive, store, process, and transmit signals (either digital or analogue).

Think of an airplane; the components include sensors, actuators, CPU's, etc. They all speak the language of signals (or information!).

## Task 5

The signals and the components, which can either be memory components or computational components. Again, this is a disrespectful oversimplification of the concept, and I happen to have the audacity to depict it in the UML entity-relationship diagram below.

![](https://raw.githubusercontent.com/khaledismaeel/csn-labs/main/identification-of-a-system/diagrams/information-system.jpg)

## Task 6

There are numerous architectures for distributed file systems. For now, let us discuss one architecture that we studied during the distributed systems course at Innopolis' bachelor's program.

The architecture under consideration provides a standard-compliant interface for accessing storage, regardless of network topology. Therefore, a kernel driver is needed. When the driver attempts to access a certain file, say, `cat.png`, it contacts a name server asking for the physical location of the file. The The name server responds with an address corresponding to the file server hosting the required file. The driver then communicates with the file server to perform the necessary task while user processes have no idea what just happened; for them they just accessed a file.

This process is depicted in the figure below.

![](https://raw.githubusercontent.com/khaledismaeel/csn-labs/main/identification-of-a-system/diagrams/distributed-file-system.jpg)

## Task 7

* **Centralized system:** system functionality is provided by a single component. Example: Counter strike servers; there is a server host and all player communicate with the host directly to synchronize gameplay (and suffer a ton of lag in the process).
* **Decentralized system:** a system which is not centralized. Example: content delivery networks (YouTube, for example); there are many server world-wide for delivering the same content.
* **Distributed system:** a system with numerous inter operating nodes which offer a singular functionality as a whole. All Distributed systems are thus necessarily decentralized, but the converse is not necessarily true. It is possible that a system is decentralized, but the nodes are not inter operating. Example: file sharing systems like bittorrent.

## Task 8

Transparency in a distributed system is the hiding of implementation detail from the interface presented to the end user (hereinafter referred to simple as _the interface_). Different sources list different types of transparency, but here is a debate-free list.

* **Access transparency:** if different storage instances of data correspond to the same resource, the access interface should abstract this away.
* **Location transparency:** the interface should abstract away the physical location of data.
* **Migration transparency:** the interface should abstract away the displacement of a resource from one address to another.
* **Replication transparency:** the interface should abstract away the various copies of the same data unless the copies were set by the user.
* **Concurrency transparency:** the implementation should not change its behavior if entities access the same data.
* **Failure transparency:** the implementation should hide component failure from the user.

## Task 9

Structure documentation depicts the components of the system and their relation to one another. Behavior documentation depicts the response of the system to various input scenarios (either treating the system as a black box or going further and explaining the responses of all components).
