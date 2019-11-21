/*
#ifndef _QUEUE_H
#define _QUEUE_H

typedef struct queue
{
	int *pBase;
	int front;
	int rear;
	int maxsize;
}QUEUE,*PQUEUE;

void createQueue(PQUEUE Q, int maxsize);
void traverseQueue(PQUEUE Q);
bool fullQueue(PQUEUE Q);
bool empryQueue(PQUEUE Q);
bool insertQueue(PQUEUE Q, int value);
bool deleteQueue(PQUEUE Q, int *value);


#endif
*/
#ifndef QUEUE_H_
#define QUEUE_H_

#define MAXQSIZE 10000
#define OK 1
#define ERROR 0
#define OVERFLOW -1

typedef int Item;

typedef struct {
    Item *base;
    int front;
    int rear;
}Queue;

/*initialize the queue*/
void InitQueue(Queue *q);

/*return the length of the queue*/
unsigned int QueueLength(Queue q);

/*Destroy the queue*/
void DestroyQueue(Queue *q);

/*determine if the queue is empty*/
bool IsEmpty(Queue q);

/*determine if the queue is full*/
bool IsFull(Queue q);

/*return the head elem of the queue*/
Item Top(Queue q);

/*return the back elem of the queue*/
Item Back(Queue q);

/*enqueue, insert the rear*/
bool EnQueue(Queue *q, Item e);

/*dequeue, pop the front*/
bool DeQueue(Queue *q);

/*print the queue*/
void PrintQueue(Queue q);

#endif
