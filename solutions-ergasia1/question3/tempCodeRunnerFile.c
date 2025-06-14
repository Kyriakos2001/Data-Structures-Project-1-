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
    char reversed[100] = {0};
    char final[100] = {0};
    int j = 0, count = 0;

    // Αντιστροφή της παράστασης εισόδου
    strcpy(reversed, exp);
    reverseString(reversed);

    // Επανάληψη μέσω της αντιστροφής της παράστασης
    for (int i = 0; i < strlen(reversed); i++)
    {
        if (reversed[i] == ')')
        {
            count++;
        }
        else if (reversed[i] == '(')
        { 
            if (count > 0)
            {
                final[j++] = '(';
                count--;          
            }
        }
        final[j++] = reversed[i]; 
    }

    // Αντιστροφή του string για να παρουμε την τελική παράσταση
    reverseString(final);
    printf("%s\n", final);
}

int main()
{
    char expression[] = "1 + 2 ) * 3 - 4 ) * 5 - 6 ) ) )";
    addLeftParentheses(expression);
    return 0;
}
