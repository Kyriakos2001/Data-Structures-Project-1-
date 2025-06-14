#include "Deque.h"
#include <stdio.h>
#include <stdlib.h>

// Συνάρτηση για την δημιουργία ενος κενού deque
Deque *Create()
{
    Deque *dq = (Deque *)malloc(sizeof(Deque));
    dq->front = dq->rear = NULL;
    dq->size = 0;
    return dq;
}

// Συνάρτηση για έλεγχο του deque αν είναι κενό
int IsEmpty(Deque *dq)
{
    return dq->size == 0;
}

// Συνάρτηση για εισαγωγή στοιχείου στην αρχή
void Push(Deque *dq, int item)
{
    DequeNode *newNode = (DequeNode *)malloc(sizeof(DequeNode));
    newNode->data = item;
    newNode->next = dq->front;
    newNode->prev = NULL;
    if (IsEmpty(dq))
    {
        dq->front = dq->rear = newNode;
    }
    else
    {
        dq->front->prev = newNode;
        dq->front = newNode;
    }
    dq->size++;
}

// Συνάρτηση για εισαγωγή στοιχείου στο τέλος
void Enqueue(Deque *dq, int item)
{
    DequeNode *newNode = (DequeNode *)malloc(sizeof(DequeNode));
    newNode->data = item;
    newNode->next = NULL;
    newNode->prev = dq->rear;
    if (IsEmpty(dq))
    {
        dq->front = dq->rear = newNode;
    }
    else
    {
        dq->rear->next = newNode;
        dq->rear = newNode;
    }
    dq->size++;
}

// Συνάρτηση για αφαίρεση και επιστροφή του πρώτου στοιχείου
int Pop(Deque *dq)
{
    if (IsEmpty(dq))
        return -1;
    int item = dq->front->data;
    DequeNode *temp = dq->front;
    dq->front = dq->front->next;
    if (dq->front == NULL)
        dq->rear = NULL;
    else
        dq->front->prev = NULL;
    free(temp);
    dq->size--;
    return item;
}

// Συναρτηση για αφαίρεση και επιστροφή του τελευταίου στοιχείου
int Dequeue(Deque *dq)
{
    if (IsEmpty(dq))
        return -1;
    int item = dq->rear->data;
    DequeNode *temp = dq->rear;
    dq->rear = dq->rear->prev;
    if (dq->rear == NULL)
        dq->front = NULL;
    else
        dq->rear->next = NULL;
    free(temp);
    dq->size--;
    return item;
}

// Συνάρτηση για επιστροφή του μεγέθους του deque
int SizeOf(Deque *dq)
{
    return dq->size;
}

// Συνάρτηση για εκτύπωση του deque
void Print(Deque *dq)
{
    DequeNode *current = dq->front;
    printf("Deque: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

#include "Deque.h"

int main()
{
    Deque *dq = Create();

    printf("Is the Deque empty? %s\n", IsEmpty(dq) ? "Yes" : "No");

    Enqueue(dq, 10);
    Enqueue(dq, 20);

    Push(dq, 5);
    Push(dq, 2);

    printf("Current Deque: ");
    Print(dq);

    printf("Size of Deque: %d\n", SizeOf(dq));

    printf("Removing from front: %d\n", Pop(dq));
    printf("Removing from rear: %d\n", Dequeue(dq));

    printf("Deque after removals: ");
    Print(dq);

    printf("Is the Deque empty now? %s\n", IsEmpty(dq) ? "Yes" : "No");

    free(dq);

    return 0;
}
