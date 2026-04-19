#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "queue.h" //hada5al access le file el queue hena

#define TICS 100 // el simulation time 5aleto be 100
#define ARRIVAL_RATE 60 //if less than 60 so no task
#define MAX_SERVICE_TIME 8


int main()
{
 Queue* q = createqueue();
 Laila task;
 task.id = 5;
 task.service = 10;
 task.arrival = 20;

 enqueue(q, task);
 printf("%d\n %d\n %d\n %d\n", q->front->task.id,q->front->task.service,q->front->task.arrival, q->count);

Laila task2;
 task2.id = 3;
 task2.service = 8;
 task2.arrival = 12;

 enqueue(q, task2);
 printf("%d\n %d\n %d\n %d\n", q->front->task.id,q->front->task.service,q->front->task.arrival, q->count);

 dequeue(q);
 printf("%d\n", q->count);
 printf("%d\n %d\n %d\n %d\n", q->front->task.id,q->front->task.service,q->front->task.arrival, q->count);



 void serve()
{
    if(isEmpty(allTasks)) // fi 7alet en el queue kolo fadi
    {
        return;
    }

    int service = allTasks->front->task.service;

    if(service != 0)
    {
        allTasks->front->task.service = service -1;
        printf("SERVE TASK: %d\n", allTasks->front->task.id); // 3amaha bel id 3alashan 23raf anhy task howa el beyt3amalo serve
    }
    else
    {
        printf("SERVE TASK: %d (completed)\n", allTasks->front->task.id);

        int waitingTime = timer - allTasks->front->task.arrival; //3ayza 23ml el timer el haymshi men - el arrival time
        dequeue(allTasks);
        if(isEmpty(allTasks))
        {
            return;
        }
        else
        {
            service = allTasks->front->task.service;
            allTasks->front->task.service = service -1;
            total_waiting_time += waitingTime;
        }
    }

}





    return 0;
}
