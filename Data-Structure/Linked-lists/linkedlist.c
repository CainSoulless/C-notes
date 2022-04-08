/*
Linked Lists.
    Dynamically allocated nodes, getting a value AND one pointer. The pointer always points to the next
    node, or in other words, the another value. All the pointer's nodes has the memory address of the
    next value, but, if the pointer has a NULL value, that means there is the last node.

    list
    ------           ------             -------
    |    |---------> |  1 |        ---> |  2  |
    ------           ------       | |--> -------
                     |    | ------  |   |     |
                     ------         |   -------
                                    |
      n                             |
    ------                          |
    |    |---------------------------
    ------

    Syntax:

typedef struct node
{
    int value;
    struct node *next;      // 1
}
node;

1) Is defined as a recursive struct.
*/


#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};
typedef struct node node_t;

void printList(node_t *head);

int main(void)
{
    node_t n1, n2, n3;
    node_t *head;

    n1.value = 45;
    n2.value = 8;
    n3.value = 32;

    // Link them up
    head = &n3;
    n3.next = &n2;
    n2.next = &n1;
    n1.next = NULL;

    printList(head);

    return 0;
}
void printList(node_t *head)
{
    node_t *tmp = head;

    while (tmp != NULL)
    {
        printf("%d - ", tmp->value);
        tmp = tmp->next;
    }
    if (tmp == NULL)
    {
        printf("NULL");
    }
    printf("\n");
}

