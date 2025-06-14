#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

// Συνάρτηση για εισαγωγή στοιχείου στην κορυφή της στοίβας
void push(Node **top, int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
        return;
    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

// Συνάρτηση για αφαίρεση στοιχείου από την κορυφή της στοίβας
int pop(Node **top)
{
    if (*top == NULL)
    {
        printf("Stack underflow\n");
        return -1;
    }
    Node *temp = *top;
    *top = (*top)->next;
    int poppedData = temp->data;
    free(temp);
    return poppedData;
}

// Συνάρτηση για επιστροφή του στοιχείου στην κορυφή της στοίβας χωρίς αφαίρεση
int isEmpty(Node *top)
{
    return top == NULL;
}

int peek(Node *stack)
{
    if (!isEmpty(stack))
    {
        return stack->data;
    }
    return -1;
}

void sortStack(Node **sourceStack)
{
    Node *tempStack = NULL; 

    while (!isEmpty(*sourceStack))
    {
        int temp = pop(sourceStack); 



        while (!isEmpty(tempStack) && temp < peek(tempStack)) 
        {
            push(sourceStack, pop(&tempStack));
        }

        push(&tempStack, temp);
    }

    while (!isEmpty(tempStack))
    {
        push(sourceStack, pop(&tempStack));
    }
}

int main()
{
    Node *stack = NULL;
    push(&stack, 30);
    push(&stack, -5);
    push(&stack, 18);
    push(&stack, 14);
    push(&stack, -3);

    sortStack(&stack);

    printf("Sorted stack: ");
    while (!isEmpty(stack))
    {
        printf("%d ", pop(&stack));
    }
    return 0;
}
