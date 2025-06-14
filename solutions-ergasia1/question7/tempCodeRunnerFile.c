#include <stdio.h>
#include <stdlib.h>

void printCombinations(int set[], int n, int N)
{
    for (int i = 0; i < (1 << N); i++)
    { // Loop from 0 to 2^N - 1
        // Print current subset
        for (int j = 0; j < N; j++)
        {
            if (i & (1 << j))
            { // Check if jth element is included in subset
                printf("%d ", set[j]);
            }
        }
        printf("\n");
    }
}

void generateSet(int N)
{
    int *set = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
    {
        set[i] = i + 1; // Fill set with numbers 1 through N
    }
    printCombinations(set, N, N);
    free(set);
}

int main()
{
    int N;
    printf("Enter N: ");
    scanf("%d", &N);
    generateSet(N);
    return 0;
}
