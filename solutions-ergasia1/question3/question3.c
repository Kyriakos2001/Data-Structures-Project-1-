#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Συνάρτηση αντιστροφή string
void reverseString(char *str)
{
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++)
    {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

// Συνάρτηση προσθήκης αριστερής παρένθεσης
void addLeftParentheses(char *exp)
{
    int len = strlen(exp);
    char temp[200] = {0};   
    char result[200] = {0}; 
    int tempIndex = 0;
    int openNeeded = 0;

    reverseString(exp);

    for (int i = 0; i < len; i++)
    {
        if (exp[i] == ')')
        {
            temp[tempIndex++] = exp[i];
            openNeeded++;
        }
        else if (exp[i] == '(')
        {
            if (openNeeded > 0)
            {
                temp[tempIndex++] = ')';
                openNeeded--;
            }
        }
        else
        {
            temp[tempIndex++] = exp[i];
        }
    }

    while (openNeeded > 0)
    {
        temp[tempIndex++] = '(';
        openNeeded--;
    }

    temp[tempIndex] = '\0';

    strcpy(result, temp);
    reverseString(result);

    printf("%s\n", result);
}

int main()
{
    char expression[] = "1 + 2 ) * 3 - 4 ) * 5 - 6 ) ) )";
    addLeftParentheses(expression);
    return 0;
}
