/*
#include<stdio.h>
#include<stdlib.h> 
#include"queue.h"
#include"malloc.h"


void createQueue(PQUEUE Q, int maxsize)
{
	Q->pBase = (int *)malloc(sizeof(int) *maxsize);
	if(NULL == Q->pBase)
	{
		printf("Memory allocation failure");
		exit(-1);
	}
	Q->front = 0;
	Q->rear = 0;
	Q->maxsize = maxsize;

}

void traverseQueue(PQUEUE Q)
{
	int	i = Q->front;
	printf("队中的元素是：\n");
	while(i % Q->maxsize != Q->front)
	{
		printf("%d", Q->pBase[i]);
		i++;
	}
	printf("\n");

}

bool fullQueue(PQUEUE Q)
{
	if(Q->front == (Q->rear+1) % Q->maxsize)
		return true;
	else
		return false;
}

bool emptyQueue(PQUEUE Q)
{
	if(Q->front == Q->rear)
		return true;
	else
		return false;
}

bool insertQueue(PQUEUE Q,int value)
{
	if(fullQueue(Q))
		return false;
	else
	{
		Q->pBase[Q->rear] = value;
		Q->rear = (Q->rear + 1) % Q->maxsize;
		return true;
	}
}

bool deleteQueue(PQUEUE Q, int *value)
{
	if(emptyQueue(Q))
		return false;
	else
	{
		*value = Q->pBase[Q->front];
		Q->front = (Q->front + 1) % Q->maxsize;
		return true;
	}
}
*/
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

void InitQueue(Queue *q) {
    q->base = (Item*)malloc(MAXQSIZE * sizeof(Item));
    if (q->base == NULL)
        exit(OVERFLOW);
    q->front = 0;
    q->rear = 0;
}

/*return the length of the queue*/
unsigned int QueueLength(Queue q) {
    return (q.rear - q.front + MAXQSIZE) % MAXQSIZE;
}
/*Destroy the queue*/
void DestroyQueue(Queue *q) {
    q->base = NULL;
    q->rear = 0;
    q->front = 0;
    free(q->base);
}

/*determine if the queue is empty*/
bool IsEmpty(Queue q) {
    return q.rear == q.front;
}

bool IsFull(Queue q) {
    return (q.rear + 1) % MAXQSIZE == q.front;
}

/*return the head elem of the queue*/
Item Top(Queue q) {
    return q.base[q.front];
}

/*return the back elem of the queue*/
Item Back(Queue q) {
    return q.base[(q.rear - 1 + MAXQSIZE) % MAXQSIZE];
}

/*enqueue, insert the rear*/
bool EnQueue(Queue *q, Item e) {
    if (IsFull(*q))
        return ERROR;
    q->base[q->rear] = e;
    q->rear = (q->rear + 1) % MAXQSIZE;

    return OK;
}
/*dequeue, pop the front*/
bool DeQueue(Queue *q) {
    if(IsEmpty(*q))
        return ERROR;
    q->front = (q->front + 1) % MAXQSIZE;
    return OK;
}

/*print the queue*/
void PrintQueue(Queue q) {
    int i, j;
	printf("队中的元素为：\n");
    for (i = 0, j = q.front; i < QueueLength(q); i++, j = (j + 1) % MAXQSIZE) {
        printf("%d\n",q.base[j]);
    }
}

