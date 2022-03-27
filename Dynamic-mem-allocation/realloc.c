/* Realloc */
    // Re-allocation, if the memory previously allocated with functions like malloc, or calloc, realloc can respect the original value,
    // and then 'sum' the new mem. requested to the malloc pointer var.
    //
    // int *ptr = (int*)malloc(5 * sizeof(int));
    // ptr = ____________
    //       20B
    //
    // ptr = realloc(ptr, 10 * sizeof(int));
    //
    // ptr = ______________________
    //       40B
/*  */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //  Is a good practice declare a pointer with a NULL value,
    //  In case you don't have the exact address to be assigned.
    int *ptr = NULL;
    int n = 5;

    ptr = (int*)calloc(n, sizeof(int));

    //  Check.
    if (ptr == NULL)
    {
        exit(0);
    }

    printf("Memory succesfully allocated using calloc.\n");
    
    //  Get elements into array.
    for (int i = 0; i < n; i++) 
    {
        ptr[i] = i;
    }
    
    //  Get the new size for the array.
    printf("New size of array is : %d\n", n);

    //  Realloc().
    ptr = realloc(ptr, n * sizeof(int));
    for (int i = 0; i < n; i++) 
    {
        ptr[i] = i;
    }

    //  Printing elements.
    printf("Elements: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d\n", ptr[i]);
    }

    //  Remember always free mem allocated.
    free(ptr);
    return 0;
}
