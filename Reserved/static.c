/* Static
 *      Static variables are persistent throughout the program is running.
 */


#include <stdio.h>

int func();
int funcWithStatic();

int main()
{
    printf("Without:\t%d", func());
    printf("\t%d", func());
    printf("\nWith:\t\t%d", funcWithStatic());
    printf("\t%d\n", funcWithStatic());

    return 0;
}

int func()
{
    int count = 0;
    count++;

    return count;
}
/* When the function ends, but in another moment it is running agains, the static variable
 * save the variables's value, or in other words, it's "remember" the last value of the variable.
 * */
    
int funcWithStatic()
{
    static int count = 0;
    count++;

    return count;
}
