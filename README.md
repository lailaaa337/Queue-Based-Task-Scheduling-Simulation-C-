# Queue-Based Task Scheduling Simulation (C)

## Overview

This project simulates a simple task scheduling system using a queue implemented in C. Tasks arrive randomly, get processed one by one, and leave the queue once completed.

## What I did

* Implemented a queue using linked lists
* Created enqueue and dequeue operations
* Simulated task arrival with random values
* Assigned service time for each task
* Processed tasks step by step
* Calculated average waiting time

## How it works

At each time step, a new task may arrive based on probability. Tasks are added to the queue and processed in order. Each task has a service time that decreases until it finishes, then it is removed from the queue.

## Notes

This project helped me understand how queues work in real systems like CPU scheduling and how waiting time can be analyzed.

## Author

Laila Tarek
