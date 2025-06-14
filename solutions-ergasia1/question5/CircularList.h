#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *cursor;
} CircularList;

CircularList *Create(void);
void Add(CircularList *list, int item);
int Remove(CircularList *list);
void Advance(CircularList *list);
void FreeList(CircularList *list);

#endif
