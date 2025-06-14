#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void selectionSortLinkedList(Node **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return; // List is empty or has one element

    Node *curr, *min, *beforeMin, *prev;

    for (curr = *head; curr != NULL && curr->next != NULL; curr = curr->next)
    {
        min = curr;
        beforeMin = NULL;
        for (prev = curr; prev->next != NULL; prev = prev->next)
        {
            if (prev->next->data < min->data)
            {
                min = prev->next;
                beforeMin = prev;
            }
        }

        if (min != curr)
        {
            int temp = curr->data; // Use an int variable for swapping data
            curr->data = min->data;
            min->data = temp;
        }
    }
}
