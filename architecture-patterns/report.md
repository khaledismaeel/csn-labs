# Architecture patterns

**Khaled Ismaeel, ST-6, k.ismaeel@innopolis.university**

## Task 1

### 1.1

Three definitions of _software architecture_:

- **Philosophical definition**: a structured description of all components of a system and their interactions among each other and with the environment.
- **Bureaucratic definition**: an artifact generated at the design stage of a system that leaves no room for ambiguity during implementation.
- **Programmatic definition**: an artifact that uniquely defines the public interfaces (that is, without defining implementation) of a collection of software components and their dependencies.

### 1.2

For this task we fetched 3 architectures from the industry. The first architecture is a microservice that comes from OpenStack [3].

![](diagrams/openstack-arch-kilo-logical-v1.png)

This architecture depicts a cloud that hosts microservices. Ironically, it is a microservice architecture in itself. There are several services with clearly separate resources and tasks which interact with a well-defined API.

The second example is a layered architecture that comes from the Google Fuchsia project [4].

![](diagrams/fuchsia-architecture.png)

Here each layer utilizes services of the layer below and provides services to the layer above. This is similar to the TCP/IP stack.

The third and final example is a microkernel architecture that comes from the Phantom OS project [5].

![](diagrams/PhantomComponents.svg)

This looks similar to the second example in the sense that there are layers. However, in this architecture there is emphasis on the microkernel architecture. The operating system kernel is relatively small while all drivers are operating as plugins.

### 1.3

Software architecture is concerned with the programmatic side of the system and is often agnostic to the distribution of the program logic onto components. The system architecture is concerned with the components and is often agnostic to the programmatic artifacts under consideration.

### 1.4

**Correctness and robustness**: Software correctness is the software's ability to return the correct results. Software robustness is the software's ability to maintain correctness while operating in a hostile environment.

**Topics and queues**: A message in a topic is delivered to every subscriber to that topic. A message in a queue is only delivered to the entity extracting from the queue.

**Architecture and design**: Architecture is meant to deliver a strategic abstraction of the system, design is meant to deliver an tactical implementation of the system.

**Users, primary stakeholders, and secondary stakeholders**: A user is a client served by the system. A primary stakeholder is an entity with an interest in the system's internal operation (often investors). A secondary stakeholder is an entity with an interest in the systems's external operation (often partners).

**Cohesion and coupling**: Cohesion is the inter dependence of components inside a software module. Coupling is the inter dependence of components between modules.

## Task 2



## References

1. https://resources.sei.cmu.edu/asset_files/factsheet/2010_010_001_513810.pdf
2. https://martinfowler.com/architecture/
3. https://docs.openstack.org/install-guide/get-started-logical-architecture.html
4. https://fuchsia.dev/fuchsia-src/get-started/learn/intro/architecture
5. https://phantomdox.readthedocs.io/en/latest/
