/* calloc (contiguous allocation). */
    //
    // The differences between malloc are:
    //     -   It initializes each block with a default value 0.
    //     -   It has two parameters or arguments as compare to malloc.
    //                                 _________ 4 bytes
    //                             ____|______
    // int *ptr = (int*)calloc(5, sizeof(int));
    //        ______________
    // ptr = |__|__|__|__|__|
    //       |4B|
    //       |______________|
    //        20 B of memory;
    //
/*  */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *ptr;
    int n = 5;

    printf("Total amount of elements :%d\n", n);

    //  Dynamically allocate memory using calloc()
    ptr = (int*)calloc(n, sizeof(int));

    //  Check
    if (ptr == NULL) 
    {
        printf("Memory not allocated.\n");
        exit(0);
    }

    for (int i = 0; i < n; i++) 
    {
        ptr[i] = i;
    }

    printf("Elements into ptr: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d, ", ptr[i]);
    }
    printf("\n");
    return 0;
}
