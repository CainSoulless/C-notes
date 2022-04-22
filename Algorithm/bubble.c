/* Bubble Sort.
    The program searches the smallest number first, and them shift that number at the beginning of index,
    and the process keeps on repeating with the next smallest number.

    Read more:  https://www.educba.com/sorting-in-c/
                https://www.youtube.com/watch?v=YqzNgaFQEh8
 */

#include <stdio.h>

int main(void)
{
    int total_count = 5, swap_var;
    int array[] = {4,6,3,8,1};

    //  This loop is controlling the number of passes through the array.
    for (int counter = 0; counter < total_count; counter++)   
    {
        //  This loop i doing the passes themselves and swapping elements.
        //  The reason why is - 1, is because the last element has no sense be compared with the next
        //  element, because there is not next element.
        for (int counter1 = 0; counter1 < (total_count - 1); counter1++) 
        {
            printf("Second for, total_count: %d\ncounter: %d\n", total_count, counter);
            printf("All together: %d\n", total_count - counter - 1);

            //  This if compares both elements in the array.
            if (array[counter1] > array[counter1+1])
            {
                //  swap_var stores the first element.
                swap_var = array[counter1];
                //  and we overwrite the same value with the next values. in this case, 6.
                array[counter1] = array[counter1+1];
                //  And this element is overwrite with the first stored element in swap_var, in this case, 4.
                array[counter1+1] = swap_var;

                /* So, if the first element is biggest than the second element, is feasible make the swapping. */
            } 
        }
    }

    //  The last loop just prints all the elements previously swapped.
    printf("Below is the list of elements sorted in ascending order:\n");
    for (int counter = 0; counter < total_count; counter++) 
    {
        printf("%d\n", array[counter]);
    }
}


