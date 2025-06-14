#include <stdio.h>
#include <stdlib.h>

// Δομή για τον κόμβο της λίστας
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

// Συνάρτηση για την ταξινόμηση μιας συνδεδεμένης λίστας με την μέθοδο της επιλογής
void selectionSortLinkedList(Node **head)
{
    if (*head == NULL || (*head)->next == NULL)
        return; 

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
            int temp = curr->data; 
            curr->data = min->data;
            min->data = temp;
        }
    }
}

// Συνάρτηση για εισαγωγή στοιχείου στην αρχή της λίστας
void insert(Node **head, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Συνάρτηση για εκτύπωση της λίστας
void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Συνάρτηση για απελευθέρωση της μνήμης της λίστας
void freeList(Node *head)
{
    Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    Node *head = NULL;

    
    insert(&head, 6);
    insert(&head, 11);
    insert(&head, 7);
    insert(&head, 5);
    insert(&head, 12);
    insert(&head, 3);

    printf("Original list: \n");
    printList(head);

    selectionSortLinkedList(&head);

    printf("Sorted list: \n");
    printList(head);

    freeList(head);

    return 0;
}