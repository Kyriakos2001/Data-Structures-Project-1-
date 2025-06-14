// File: Deque.c
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
    // Δημιουργία ενός νέου Deque
    Deque *dq = Create();

    // Έλεγχος αν το Deque είναι κενό
    printf("Is the Deque empty? %s\n", IsEmpty(dq) ? "Yes" : "No");

    // Προσθήκη στοιχείων στο τέλος
    Enqueue(dq, 10);
    Enqueue(dq, 20);

    // Προσθήκη στοιχείων στην αρχή
    Push(dq, 5);
    Push(dq, 2);

    // Εκτύπωση του τρέχοντος Deque
    printf("Current Deque: ");
    Print(dq);

    // Μέγεθος του Deque
    printf("Size of Deque: %d\n", SizeOf(dq));

    // Αφαίρεση στοιχείων από το Deque
    printf("Removing from front: %d\n", Pop(dq));
    printf("Removing from rear: %d\n", Dequeue(dq));

    // Εκτύπωση του Deque μετά τις αφαιρέσεις
    printf("Deque after removals: ");
    Print(dq);

    // Έλεγχος αν το Deque είναι κενό
    printf("Is the Deque empty now? %s\n", IsEmpty(dq) ? "Yes" : "No");

    // Αποδέσμευση της μνήμης
    free(dq);

    return 0;
}
