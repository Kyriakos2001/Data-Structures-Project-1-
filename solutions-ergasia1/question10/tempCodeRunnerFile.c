#include "PriorityQueue.h"
#include <stdlib.h>
#include <stdio.h>

PriorityQueue *createPriorityQueue()
{
    PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    pq->head = NULL;
    return pq;
}

void insert(PriorityQueue *pq, int data, int priority)
{
    PriorityQueueNode *newNode = (PriorityQueueNode *)malloc(sizeof(PriorityQueueNode));
    newNode->data = data;
    newNode->priority = priority;

    // Insert node based on its priority
    if (!pq->head || pq->head->priority > priority)
    {
        newNode->next = pq->head;
        pq->head = newNode;
    }
    else
    {
        PriorityQueueNode *temp = pq->head;
        while (temp->next && temp->next->priority <= priority)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

int pop(PriorityQueue *pq)
{
    if (!pq->head)
    {
        printf("Priority Queue is empty\n");
        return -1;
    }
    int data = pq->head->data;
    PriorityQueueNode *temp = pq->head;
    pq->head = pq->head->next;
    free(temp);
    return data;
}

void display(PriorityQueue *pq)
{
    PriorityQueueNode *temp = pq->head;
    while (temp)
    {
        printf("Data: %d, Priority: %d\n", temp->data, temp->priority);
        temp = temp->next;
    }
}

void freePriorityQueue(PriorityQueue *pq)
{
    while (pq->head)
    {
        pop(pq);
    }
    free(pq);
}

int main()
{
    int nums[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    int n = sizeof(nums) / sizeof(nums[0]);

    PriorityQueue *pq = createPriorityQueue();

    // Insert all elements into the priority queue
    for (int i = 0; i < n; i++)
    {
        insert(pq, nums[i], nums[i]); // Here, priority is the same as the data
    }

    // Pop elements to get them in sorted order
    printf("Sorted order:\n");
    while (pq->head)
    {
        printf("%d ", pop(pq));
    }

    freePriorityQueue(pq);
    return 0;
}
