#include "CircularList.h"
#include <stdio.h>
#include <stdlib.h>

// Αρχικοποίηση μια νεας circular list
CircularList *createCircularList()
{
    CircularList *list = malloc(sizeof(CircularList));
    if (!list)
    {
        perror("Failed to create list");
        exit(EXIT_FAILURE);
    }
    list->cursor = NULL;
    list->size = 0;
    return list;
}

// Προσθήκη ενός νέου κόμβου στην λίστα με τα δεδομένα
void addNode(CircularList *list, int data)
{
    Node *newNode = malloc(sizeof(Node));
    if (!newNode)
    {
        perror("Failed to add node");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;

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
    list->size++;
}

// Αφαίρεση του κόμβου δίπλα από τον cursor από την λίστα και επιστροφή των δεδομένων του
int removeNextNode(CircularList *list)
{
    if (list->cursor == NULL || list->size == 0)
    {
        printf("List is empty\n");
        return -1;
    }

    Node *toBeDeleted = list->cursor->next;
    int data = toBeDeleted->data;

    if (toBeDeleted == list->cursor)
    {
        list->cursor = NULL;
    }
    else
    {
        list->cursor->next = toBeDeleted->next;
    }

    free(toBeDeleted);
    list->size--;
    return data;
}

// Προώθηση του cursor στον επόμενο κόμβο της λίστας
void advanceCursor(CircularList *list)
{
    if (list->cursor != NULL)
    {
        list->cursor = list->cursor->next;
    }
}

// Προωθηση του cursor στην θέση P της λίστας πριν την αρχή της απομάκρυνσης
void positionCursor(CircularList *list, int P)
{
    for (int i = 0; i < P; i++)
    {
        advanceCursor(list);
    }
}

// Αναθεώρηση του προβλήματος του Josephus λαμβάνοντας υπόψη τον αριθμό των ατόμων, το βήμα της απομάκρυνσης και την αρχική θέση (N, M και P)
void solveJosephusProblem(int N, int M, int P)
{
    CircularList *list = createCircularList();


    for (int i = 1; i <= N; i++)
    {
        addNode(list, i);
    }

    // Τοποθέτηση του cursor στην αρχική θέση P
    positionCursor(list, P);

    // Διαδικασία απομάκρυνσης των ατόμων
    printf("Order of removal: ");
    while (list->size > 1)
    { 
        for (int count = 1; count < M; count++)
        {
            advanceCursor(list); 
        }
        int removed = removeNextNode(list);
        printf("%d, ", removed);
    }

    // Εκτύπωση του τελευταίου ατόμου που παραμένει
    if (list->size == 1)
    {
        printf("The last person standing is: %d\n", list->cursor->data);
    }

    free(list); 
}


int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s N M P\n", argv[0]);
        return 1;
    }

    int N = atoi(argv[1]);
    int M = atoi(argv[2]);
    int P = atoi(argv[3]);

    solveJosephusProblem(N, M, P);
    return 0;
}