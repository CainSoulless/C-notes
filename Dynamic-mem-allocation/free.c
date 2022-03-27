/* Free * */
    // Dynamically de-allocate the memory. All the memory allocated using malloc or calloc would not be
    // put back in a 'passive state'. Free function helps to reduce wastage of memory, or leak memory
    // after the program was ran.
    //
    /* free(ptr); */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ptr, *ptr1;
    int n = 5;

    printf("Number of elements: %d\n", n);

    //  Using malloc.
    ptr = (int*)malloc(n * sizeof(int));

    //  Using calloc.
    ptr1 = (int*)calloc(n, sizeof(int));

    //  Checking return.
    if (ptr == NULL || ptr1 == NULL) 
    {
        exit(0);
    }

    //  Free the memory
    free(ptr);
    printf("Malloc memory freed.\n");


    free(ptr1);
    printf("Calloc memory freed.\n");
}
