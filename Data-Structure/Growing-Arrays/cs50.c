#include <stdio.h>
#include <stdlib.h>

/* Arrays in C has the static handicap of it can't be mutable. In other words, it's not possible to add
 * or remove new data into the same array. Nevertheless, arrays are pointer, so we can use the same
 * notation to add new data.
 *
 * Read more:
 *          https://cs50.harvard.edu/x/2022/notes/5/#growing-arrays
*/
    
int main(void)
{
    int *list = (int *)malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }
    
    for (int i = 0; i < 3; i++) 
    {
        list[i] = i + 1;
    }

    /* We already created a normal array, but what is the algorithm when we can add a new data
     * into the same list? */

    int *tmp = (int *)malloc(4 * sizeof(int));
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }
    for (int i = 0; i < 3; i++) 
    {
        tmp[i] = list[i];
    }
    //  Now we add the new number
    tmp[3] = 4;

    //  Time passes
    
    //  Resize old array to be of size 5;
    int *tmp2 = (int *)realloc(tmp, 5 * sizeof(int));
    if (tmp2
            == NULL)
    {
        free(list);
        return 1;
    }
    tmp2[4] = 5;

    //  Printing all datas
    for (int i = 0; i < 5; i++) 
    {
        printf("%d\n", tmp2[i]);
    }

    return 0;
}
