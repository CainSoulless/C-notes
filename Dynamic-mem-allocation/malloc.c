/* Dynamic memory allocation. (stdlib.h) */
//
// When we have an array of 9 elements and we want to add 5 more, the size of array are not 9 anymore, but adding
// the 5 elements result in a array with 14 elements, instead only 9. This is named dyamic memory allocation.
//
//
// malloc():
//     Allocate new memory requested by the programmer, returning a pointer with the address of the new memory
//     requested, but return a NULL if there is not posible to get more memory.
//
//     int *ptr = (int*)malloc(5 * sizeof(int));
//     ptr = ___________
//             20 bytes
/*  */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    //  Pointer that will hold the address of the new mem. block.
    int *ptr;
    int n;
    
    //  Malloc is usen when we don't know how many object could be needed.
    printf("Number of elements: ");
    scanf("%d", &n);

    ptr = (int*)malloc(n * sizeof(int));
    //  Check if the memomy has been succesfully allocated
    if (ptr == NULL) {
        printf("Memory not allocated\n");
        exit(0);
    }

    //  Now is posible to get new elements into this variable. 
    for (int i = 0; i < n; i++) 
    {
        ptr[i] = i;
    }
    
    //  Printing elements.
    printf("Printing elemens: ");
    for (int i = 0; i < n; i++) 
    {
        printf("%d, ", ptr[i]);
    }
    return 0;
}
