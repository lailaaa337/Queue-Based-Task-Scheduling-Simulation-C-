
#  Task Scheduling Simulation using Queue (C Programming)

##  Overview
This project implements a **task scheduling simulation system** using a **Queue data structure in C**.

The system simulates how tasks are:
- Created  
- Queued  
- Processed over time  

Each task has:
- ID  
- Arrival time  
- Service time  

The simulation models a real-world scenario similar to **CPU scheduling or service systems**, where tasks arrive randomly and are processed sequentially.

---

##  Features

-  Dynamic task generation (random arrivals)  
-  Queue-based task scheduling (FIFO)  
-  Task processing simulation over time  
-  Average waiting time calculation  
-  Real-time queue updates  
-  Custom queue implementation using linked list  

---

##  System Design

###  Data Structures

The system is built using:

- **Queue (Linked List Implementation)**
- **Node Structure**
- **Task Structure (`Laila`)**

Each task contains:
```c
struct Laila {
    int id;
    int arrival;
    int service;
};
````

> Tasks are stored inside nodes forming a linked-list queue .

---

###  Queue Operations

Implemented from scratch:

* `createqueue()` → Initialize queue
* `enqueue()` → Add task to queue
* `dequeue()` → Remove completed task
* `isEmpty()` → Check if queue is empty

---

###  Task Simulation Logic

* Tasks are generated randomly using probability
* If probability < arrival rate → task is created
* Each task gets:

  * Random service time (1–8)
  * Arrival timestamp

> Task creation logic is implemented using random generation .

---

###  Processing (Serve Function)

* The first task in queue is processed
* Service time decreases each cycle
* When service reaches 0 → task is completed and removed

> The `serve()` function simulates real-time execution of tasks .

---

##  How It Works

1. Initialize queue
2. For each time step:

   * Generate new task (probabilistic)
   * Add to queue
   * Process front task
   * Update queue
3. Continue until all tasks are completed
4. Calculate average waiting time

---

##  Example Output

```
TASK ARRIVED with id = 0 and service time = 3
Queue: [0|0|3] =>
SERVE TASK: 0
Queue: [0|0|2] =>
```

---

##  Key Metrics

*  Total waiting time
*  Average waiting time
*  Number of processed tasks

---

##  Technologies Used

* **C Programming**
* Standard Libraries:

  * `stdio.h`
  * `stdlib.h`
  * `time.h`

---

##  Project Structure

```
project/
│── queue.h              # Queue implementation
│── queue.c              # Simulation logic
│── test.c               # Testing file
│── README.md
```

---

##  How to Run

1. Compile the program:

```bash
gcc queue.c -o simulation
```

2. Run:

```bash
./simulation
```

---

##  What I Learned

* Implementing queues using linked lists
* Memory management in C (malloc/free)
* Simulating real-world systems
* Working with randomness and probability
* Performance analysis (waiting time)
* Structuring modular C programs

---

##  Limitations

* No priority scheduling (FIFO only)
* Console-based simulation
* No visualization
* Fixed simulation parameters

---

##  Future Improvements

* Add priority queue (priority scheduling)
* Implement round-robin scheduling
* Add visualization (GUI)
* Improve performance analysis
* Support multiple queues

---

##  Author

**Laila Tarek**

```

