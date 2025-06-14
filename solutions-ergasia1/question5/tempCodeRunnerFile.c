// CircularList.c
#include "CircularList.h"
#include <stdio.h>
#include <stdlib.h>

// Create an empty circular list
CircularList *Create()
{
    CircularList *list = malloc(sizeof(CircularList));
    if (list == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    list->cursor = NULL;
    return list;
}

// Add a new node immediately after the cursor
void Add(CircularList *list, int item)
{
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    newNode->data = item;
    if (list->cursor == NULL)
    {
        newNode->next = newNode; // Points to itself, making it circular
        list->cursor = newNode;
    }
    else
    {
        newNode->next = list->cursor->next;
        list->cursor->next = newNode;
    }
}

// Remove the node immediately following the cursor and return its data
int Remove(CircularList *list)
{
    if (list->cursor == NULL)
        return -1; // List is empty

    Node *temp = list->cursor->next;
    int data = temp->data;
    if (temp == list->cursor)
    { // Only one node in the list
        list->cursor = NULL;
    }
    else
    {
        list->cursor->next = temp->next;
    }
    free(temp);
    return data;
}

// Advance the cursor to the next node in the list
void Advance(CircularList *list)
{
    if (list->cursor != NULL)
    {
        list->cursor = list->cursor->next;
    }
}

// Free the entire list
void FreeList(CircularList *list)
{
    if (list->cursor == NULL)
        return; // List is already empty

    Node *start = list->cursor;
    while (list->cursor->next != start)
    { // Loop until the list circles back to the start
        Remove(list);
    }
    free(list->cursor); // Free the last remaining node
    free(list);
}
