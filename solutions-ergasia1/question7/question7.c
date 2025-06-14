#include <stdio.h>
#include <stdlib.h>

// Συνάρτηση για την εκτύπωση των συνδυασμών των στοιχείων ενός πίνακα
void printCombinationRecursive(int arr[], int data[], int start, int end, int index, int r)
{
    if (index == r)
    {
        for (int j = 0; j < r; j++)
            printf("%d ", data[j]);
        printf("\n");
        return;
    }

    for (int i = start; i <= end && end - i + 1 >= r - index; i++)
    {
        data[index] = arr[i];
        printCombinationRecursive(arr, data, i + 1, end, index + 1, r);
    }
}

// Συνάρτηση για την εκτύπωση των συνδυασμών των στοιχείων ενός πίνακα
void printCombinations(int arr[], int n)
{
    printf("0\n"); 
    for (int r = 1; r <= n; r++)
    {
        int data[r];
        printCombinationRecursive(arr, data, 0, n - 1, 0, r);
    }
}

int main()
{
    int N;
    printf("Enter N: ");
    scanf("%d", &N);
    int *arr = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        arr[i] = i + 1;
    }
    printCombinations(arr, N);
    free(arr);
    return 0;
}
