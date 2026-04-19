#include<stdio.h>
#include<stdlib.h> //lel malloc
#ifndef QUEUE_H
#define QUEUE_H  //header guard to not duplicate in the same source file which can cause error

typedef struct Laila Laila;
struct Laila
{
    int id;
    int arrival;
    int service;
};
//-------------------------------------------------------
typedef struct Node Node;
struct Node
{
    Laila task; //kol node hayb2a hateb2a 3obara 3an task w el task fih laila(id , arrival and service)
    Node* next;
};
//-------------------------------------------------------
typedef struct Queue Queue;
struct Queue
{
    Node* front;
    Node* rear;
    int count; //3alashan 2a3ed kol node fel queue el hateb2a 3andi
};
//-------------------------------------------------------
Queue* createqueue(void); //function hateb2a mawgoda fel .c 3alashan a creat el node
void enqueue(Queue* q, Laila task); //function 23ml enqueue
void dequeue(Queue* q); //function lel dequeue kolo in .c w int bec hatraga3li value
int isEmpty(Queue* q); //int because hatraga3 ya 1 ya 0
//-------------------------------------------------------
Queue* createqueue()
{
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->rear = q->front = NULL; //lazem a set it to null bec heya lessa empty
    q->count = 0; //bcause lessa mafish wala node so 0
    return q;
}
//----------------------------------------------------
void enqueue(Queue* q, Laila task) //el fun dih eny a add new task fih laila(id etc..) fel queue
{
    Node* new_node = (Node*)malloc(sizeof(Node)); //pointer temp points to Node
    new_node->task = task; // dah el task el ana already ha3mlo
    new_node->next = NULL; // a5er node akeed hatshawer to NULL

    if(isEmpty(q))
    {
        q->front = q->rear = new_node; //akeed law mafish wala node sa3etha rear w front hayshwro 3ala el temp
    }
    else
    {
        q->rear->next = new_node;
        q->rear = new_node;
    }
    q->count = q->count +1; //hazawed el count 3alashan fi node gedida da5alet
}
//----------------------------------------------------
void dequeue(Queue* q)
{
    if(isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }
    Node* temp = q->front;
    q->front =  q->front->next;
    if(q->front == NULL) //lama 23ml dequeue w teb2a el list fadia
    {
        q->rear = NULL; //lazem a set sa3etha el rear be NULL
        return;
    }
    free(temp);
    q->count = q->count -1; // hana2ass ba2a men el counter 1 3alashan ha del node
}
//----------------------------------------------------
int isEmpty(Queue* q)
{
    if(q->front == NULL)
    {
        return 1;
    }
    return 0;
}
//---------------------------------------------------
#endif // QUEUE_H dih 3alashan te2fel el header guard

// el file dah hasta5demo fe another fil esmo .c

