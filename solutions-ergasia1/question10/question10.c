#include "PriorityQueue.h"
#include <stdlib.h>
#include <stdio.h>

// Δημιουργία κενής ουράς προτεραιότητας
PriorityQueue *createPriorityQueue()
{
    PriorityQueue *pq = (PriorityQueue *)malloc(sizeof(PriorityQueue));
    pq->head = NULL;
    return pq;
}

// Εισαγωγή στοιχείου στην ουρά προτεραιότητας
void insert(PriorityQueue *pq, int data, int priority)
{
    PriorityQueueNode *newNode = (PriorityQueueNode *)malloc(sizeof(PriorityQueueNode));
    newNode->data = data;
    newNode->priority = priority;

    
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

// Αφαίρεση και επιστροφή του πρώτου στοιχείου
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

// Εμφάνιση των στοιχείων της ουράς προτεραιότητας
void display(PriorityQueue *pq)
{
    PriorityQueueNode *temp = pq->head;
    while (temp)
    {
        printf("Data: %d, Priority: %d\n", temp->data, temp->priority);
        temp = temp->next;
    }
}

// Απελευθέρωση της μνήμης της ουράς προτεραιότητας
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

    
    for (int i = 0; i < n; i++)
    {
        insert(pq, nums[i], nums[i]); 
    }

    printf("Sorted order:\n");
    while (pq->head)
    {
        printf("%d ", pop(pq));
    }

    freePriorityQueue(pq);
    return 0;
}
