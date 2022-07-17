#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct node
{
    int data;
    struct node *next;
}
node_t;

void addBeg(node_t **head_ref)
{
    node_t *tmp = (node_t *)malloc(sizeof(node_t));
    if (tmp == NULL)
    {
        return;
    }
    printf("Enter value: ");
    scanf("%d", &tmp->data);
    tmp->next = NULL;
    
    if (head_ref == NULL)
    {
        *head_ref = tmp;
    }
    else
    {
        tmp->next = *head_ref;
        *head_ref = tmp;

    }
}
void addEnd(node_t *head_ref)
{
    node_t *tail, *tmp;
    tail = head_ref;
    tmp = (node_t *)malloc(sizeof(node_t));

    printf("Enter new node: ");
    scanf("%d", &tmp->data);
    tmp->next = NULL;
    
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = tmp;
}

void printAll(node_t *head_ref)
{
    node_t *tmp = head_ref;
    while (tmp != NULL)
    {
        printf("%d", tmp->data);
        if (tmp->next != NULL)
        {
            printf("->");
        }
        tmp = tmp->next;
    }
    printf("\n");
}
void countNode(node_t *head_ref)
{
    int count = 0;
    node_t *tmp = (node_t *)malloc(sizeof(node_t));
    if (tmp == NULL)
    {
        exit(1);
    }
    tmp = head_ref;
    while (tmp != NULL) 
    {
        count++;
        tmp = tmp->next;
    }
    printf("Count: %d\n", count);
}
int main(void)
{
    //  Initial node declared.
    node_t *node = (node_t *)malloc(sizeof(node_t));
    //  malloc check.
    if (node == NULL)
    {
        return 1;
    }
     // Initial values.
    node->data = 4;
    node->next = NULL;
   
    int option = 0;

    while(1)
    {
        do {
            printf("**************************"
                    "\nPlease, select an option.\n");
            printf("\t1) Listing entire node.\n"
                    "\t2) Counting nodes.\n"
                    "\t3) Adding new node at the end.\n"
                    "\t4) Adding new node at the beginning.\n"
                    "\t5) Exit.\n");
            printf("Option: ");
            scanf("%d", &option);
            system("clear");
        } while (option < 0 );
        
        int newData = 0;
        switch (option) {
            case 1: /* Print all*/
                // system("clear");
                // for (int i = 0; i < 4; i++)
                // {
                    // printf("\nListing nodes.");
                    // usleep(500000);
                    // printf("%.*s", i, "..");
                    // system("clear");
                // }
                // printf("\n");
                printAll(node);
                break;
            case 2: /* Count nodes */
                countNode(node);
                break;
            case 3: /* End */
                addEnd(node);
                break;
            case 4: /* Beginning */
                addBeg(&node);
                // tmp = node;

                // free(tmp);
                break;
            case 5:
                printf("Bye\n");
                while (node != NULL)
                {
                    node_t *tmp = node->next;
                    free(node);
                    node = tmp;
                }            
                // free(tmp);
                exit(0);
            default:
                printf("No selected. Exit\n");
                return 1;
        }
    }
    return 0;
}
