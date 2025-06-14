#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

typedef struct PriorityQueueNode
{
    int data;     
    int priority; 
    struct PriorityQueueNode *next;
} PriorityQueueNode;

typedef struct PriorityQueue
{
    PriorityQueueNode *head; 
} PriorityQueue;

PriorityQueue *createPriorityQueue();
void insert(PriorityQueue *pq, int data, int priority);
int pop(PriorityQueue *pq);
void display(PriorityQueue *pq);
void freePriorityQueue(PriorityQueue *pq);

#endif
