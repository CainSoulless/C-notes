#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int index = 0;
    int *marks = (int*)malloc(sizeof(int));

    if (marks == NULL) 
    {
        exit(0);
    }

    printf("Mem successfully allocated.\n");
    printf("\n marks = %p\n", marks);
    
    int ans = 0;
    do {
        printf("Enter marks\n");
        scanf("%d", &marks[index]);
        printf("Would you like to add more(1/0)");
        scanf("%d", &ans);
    
        if (ans == 1)
        {
            index++;

            // Dynamically reallocate mem using realloc
            marks = (int*)realloc(marks, (index + 1) * sizeof(int));

            if (marks == NULL)
            {
                printf("Mem cannot be allocated\n");
            }
            else
            printf("Mem has been succefully allocated using realloc.\n"); 
            printf("Base address of marks are: %pc\n", marks);
        }
    } 
    while (ans == 1);
    //  Print marks.
    for (int i = 0; i <= index; i++) 
    {
        printf("Marks of students %d are: %d\n", i, marks[i]);
    }
    free(marks);
    return 0;
}
