// WAP to calculate the sum of n numbers entered by user using different methods of dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int sum = 0;
    int n, i, *ptr;

    // MALLOC
    printf("Enter the no. of terms: ");
    scanf("%d",&n);  

    ptr = (int *) malloc(n * sizeof(int));

    printf("Enter the numbers: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", ptr + i);
        sum = sum + ptr[i];
    }
    printf("Sum of numbers with malloc: %d\n", sum);
    free(ptr);

    sum = 0;

    // CALLOC
    printf("\nEnter the no. of terms: ");
    scanf("%d",&n);

    ptr = (int*) calloc(n, sizeof(int));

    printf("Enter the numbers: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", ptr + i);
        sum = sum + ptr[i];
    }
    printf("Sum of numbers with calloc: %d\n", sum);
    free(ptr);

    sum = 0;

    // REALLOC
    printf("\nEnter the no. of terms: ");
    scanf("%d", &n);

    ptr = (int*) malloc(n * sizeof(int));
    printf("Enter the numbers: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", ptr + i);
        sum += ptr[i];
    }

    printf("Initial sum before realloc: %d\n", sum);

    // Increase size
    int new_n;
    printf("\nEnter the new size (greater than previous): ");
    scanf("%d", &new_n);

    ptr = (int*) realloc(ptr, new_n * sizeof(int));

    printf("Enter the additional numbers: ");
    for (i = n; i < new_n; i++)
    {
        scanf("%d", ptr + i);
        sum += ptr[i];
    }

    printf("Sum of numbers with realloc: %d\n", sum);

    free(ptr);

    return 0;
}