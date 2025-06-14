#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_SIZE 100


int numStack[MAX_SIZE];
int numTop = -1;

char opStack[MAX_SIZE];
int opTop = -1;

// Συνάρτηση για εισαγωγή αριθμού στην στοίβα
void pushNum(int num)
{
    if (numTop == MAX_SIZE - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    numStack[++numTop] = num;
}

// Συνάρτηση για αφαίρεση αριθμού από την στοίβα
int popNum()
{
    if (numTop == -1)
    {
        printf("Stack underflow\n");
        return -1;
    }
    return numStack[numTop--];
}

// Συνάρτηση για εισαγωγή τελεστή στην στοίβα
void pushOp(char op)
{
    if (opTop == MAX_SIZE - 1)
    {
        printf("Stack overflow\n");
        return;
    }
    opStack[++opTop] = op;
}

// Συνάρτηση για αφαίρεση τελεστή από την στοίβα
char popOp()
{
    if (opTop == -1)
    {
        printf("Stack underflow\n");
        return '\0';
    }
    return opStack[opTop--];
}

// Συνάρτηση για προτεραιότητα τελεστή
int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

// Συνάρτηση για εφαρμογή τελεστή
int applyOp(int a, int b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return b ? a / b : 0;
    default:
        return 0;
    }
}

// Συνάρτηση για αξιολόγηση της έκφρασης
int evaluateExpression(char *expr)
{
    int i;
    for (i = 0; i < strlen(expr); i++)
    {
        if (expr[i] == ' ')
            continue;

        if (isdigit(expr[i]))
        {
            int val = 0;
            while (i < strlen(expr) && isdigit(expr[i]))
            {
                val = (val * 10) + (expr[i] - '0');
                i++;
            }
            pushNum(val);
            i--; 
        }
        else
        {
            while (opTop != -1 && precedence(opStack[opTop]) >= precedence(expr[i]))
            {
                int val2 = popNum();
                int val1 = popNum();
                char op = popOp();

                pushNum(applyOp(val1, val2, op));
            }
            pushOp(expr[i]);
        }
    }

    while (opTop != -1)
    {
        int val2 = popNum();
        int val1 = popNum();
        char op = popOp();

        pushNum(applyOp(val1, val2, op));
    }

    return popNum();
}

int main()
{
    char expr[] = "10 + 2 * 6";
    printf("Expression Evaluation: %d\n", evaluateExpression(expr));
    return 0;
}
