#include "CircularList.h"
#include <stdio.h>
#include <stdlib.h>

// Δημιουργία κενής circular list
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

// Προσθήκη ενός νεου κόμβου μετά τον cursor
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
        newNode->next = newNode; 
        list->cursor = newNode;
    }
    else
    {
        newNode->next = list->cursor->next;
        list->cursor->next = newNode;
    }
}

// Αφαιρεση του κόμβου μετά τον cursor και επιστροφή των δεδομένων του
int Remove(CircularList *list)
{
    if (list->cursor == NULL)
        return -1;

    Node *temp = list->cursor->next;
    int data = temp->data;
    if (temp == list->cursor)
    { 
        list->cursor = NULL;
    }
    else
    {
        list->cursor->next = temp->next;
    }
    free(temp);
    return data;
}

// Προωθηση του cursor στον επόμενο κόμβο της λίστας
void Advance(CircularList *list)
{
    if (list->cursor != NULL)
    {
        list->cursor = list->cursor->next;
    }
}

// Απελευθέρωση της λίστας
void FreeList(CircularList *list)
{
    if (list->cursor == NULL)
        return; 

    Node *start = list->cursor;
    while (list->cursor->next != start)
    { 
        Remove(list);
    }
    free(list->cursor); 
    free(list);
}

#include "CircularList.h"

int main()
{
    CircularList *list = Create();

    printf("Adding elements 1, 2, 3 to the list.\n");
    Add(list, 1);
    Add(list, 2);
    Add(list, 3);

    printf("Current list (starting from cursor): ");
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", list->cursor->data);
        Advance(list);
    }
    printf("\n");

    printf("Removing an element after the cursor.\n");
    Remove(list);

    printf("Current list after removal (starting from cursor): ");
    Node *start = list->cursor;
    do
    {
        printf("%d ", list->cursor->data);
        Advance(list);
    } while (list->cursor != start);
    printf("\n");

    printf("Freeing the list.\n");
    FreeList(list);

    return 0;
}
