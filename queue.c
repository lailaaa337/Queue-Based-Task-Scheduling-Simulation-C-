#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "queue.h" //hada5al access le file el queue hena

#define TICS 10 // el simulation time 5aleto be 10
#define ARRIVAL_RATE 60 //if less than 60 so no task
#define MAX_SERVICE_TIME 8 //service time from 1 to 8
//-------------------------------------------------------------------------------------------------
Queue* allTasks; //samet el queue beta3ti alltasks (global variable)
int id = 0; //have to initiate el id 3alashan may7otesh garbage value
int timer; //ha3ml bih el loop el kebira el fiha el simulation
int total_waiting_time = 0; //3alashan 23raf 27sseb el avg
//-------------------------------------------------------------------------------------------------
void add_task(int i)
{
    int servTime = rand() %7 +1; //3ayza el servtime yekoun from 1 to 8;

    Laila task;
    task.id = id;
    task.arrival = i; //el i dah el counter beta3 el arrival
    task.service = servTime;

    enqueue(allTasks, task);//ana bab3at el pointer msh el value el gowa el pointer ha3ml enq le node esmaha task fiiha object laila
    printf("TASK ARRIVED with id = %d and service time = %d\n",id , servTime); // task is an instance but allTasks is a pointer so ->
    id++; //hazawed el id 3alashan a3ed el nodes w kol wa7da yeb2a liha rakam mo5talef
}
//-------------------------------------------------------------------------------------------------
void new_task(int id, int i)
{
    int prob = rand() % 100;

    if(prob < ARRIVAL_RATE)
    {
        add_task(i);
    }
    else
    {
        printf("NO TASK ARRIVED\n");
    }
}
//-------------------------------------------------------------------------------------------------
void serve()
{
	if(isEmpty(allTasks))   // fi 7alet en el queue kolo fadi
	{
		return;
	}


	int service = allTasks->front->task.service;

	allTasks->front->task.service = service -1;

	if(service-1 == 0)
	{
		printf("SERVE TASK: %d (completed)\n", allTasks->front->task.id+1);// 3amaha bel id 3alashan 23raf anhy task howa el beyt3amalo serve

        int waitingTime = timer - allTasks->front->task.arrival;  //3ayza 23ml el timer el haymshi men - el arrival time
		total_waiting_time += waitingTime;
		dequeue(allTasks);
	}
	else
	{
		 printf("SERVE TASK: %d\n", allTasks->front->task.id);
	}
}

//-------------------------------------------------------------------------------------------------
void printQueue()
{
    printf("Queue: ");
    Node* Lola = allTasks->front; //ha3ml pointer esmo lola zay el temp keda beymshi 3ala el queue w ye print el values
    while(Lola != NULL)
    {
        printf("[%d|%d|%d] => ", Lola->task.id, Lola->task.arrival, Lola->task.service);
        Lola = Lola->next;
    }
    printf("\n");
}
//-------------------------------------------------------------------------------------------------
double averageTime()
{
    double num = total_waiting_time / id;
    return num;
}
//-------------------------------------------------------------------------------------------------
int main()
{
    srand(time(NULL)); //keda haytala3li rakam random

    allTasks = createqueue(); //ha3ml ba2a el queue el esmaaha allTasks

    for(timer = 0; timer < TICS; timer++)
    {
        printf("-------------------------------------------------%d\n",timer);
        new_task(id,timer); //el howa howa el i bec dah counter
        if(!isEmpty(allTasks))
        {
            printQueue();
        }
        serve();
        printQueue();
    }

    while(!isEmpty(allTasks))
    {
        printf("-------------------------------------------------%d\n",timer++);
        serve();
        printQueue();
    }

    double avg_waiting_time = averageTime();
    printf("Average waiting Time: %.2f\n", avg_waiting_time);


    return 0;
}



