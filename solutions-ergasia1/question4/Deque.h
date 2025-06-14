#ifndef DEQUE_H
#define DEQUE_H

typedef struct DequeNode
{
    int data;
    struct DequeNode *next;
    struct DequeNode *prev;
} DequeNode;

typedef struct
{
    DequeNode *front;
    DequeNode *rear;
    int size;
} Deque;

#endif 
