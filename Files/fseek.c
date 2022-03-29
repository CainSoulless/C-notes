/* Fseek */
    // used to move files pointer to another position.
    //
    // int fseek(FILE *pointer, long int offset, int position)
    //
    // returns:
    //  zero if successful, fail not-zero
/*  */
#include <stdio.h>

int main(void)
{
    FILE *f = fopen("textfile.txt", "r");

    //  Moving pointer to end.

    if (fseek(f, 0, SEEK_END) == 0)
    {
        printf("Success fseek\n");
    }

    printf("%ld\n", ftell(f));
}
