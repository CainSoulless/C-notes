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

typedef struct node
{
    int value;
    struct node *next;
}
node_t;

void print_list(node_t *list);
void push(node_t *list, int value);
void add_beginning(node_t ** list, int val);

int main(void)
{
    //  List of size 0
    node_t *list = NULL;

    //  Allocating mem. space in a new temp var.
    node_t *n = (node_t*)malloc(sizeof(node_t));
    //  Cheking.
    if (n == NULL)
    {
        return 1;
    }
    //  First value in the list. next has a NULL value, because is the last variable for now.
    n->value = 1;
    n->next = NULL;

    //  Update list to point to new node.
    list = n;
    
    //  Creating a new temp. variable which will contain the next number.
    n = malloc(sizeof(node_t));
    if (n == NULL)
    {
        free(list);
        return 1;
    }
    n->value = 2;
    n->next = NULL;
    list->next = n;
    
    print_list(list);

    push(list, 3);

    print_list(list);

    add_beginning(&list, 4);

    print_list(list);
}

//  Function maded for print all the elements into the linked list.
void print_list(node_t *list)
{
    node_t *current = list;
    while (current != NULL)
    {
        printf("Value: \t%d\n", current->value);
        printf("Next: \t%p\n", current->next);
        current = current->next;
    }
    printf("---------------------\n");
}

//  Adding an item to the end of the list.
void push(node_t *list, int value)
{
    node_t *current = list;
    while (current->next != NULL)
    {
        current = current->next;
    }
    
    current->next = (node_t*)malloc(sizeof(node_t));
    current->next->value = value;
    current->next->next = NULL;
}

void add_beginning(node_t ** list, int value)
{
    node_t * new_node;
    new_node = (node_t *) malloc(sizeof(node_t));

    new_node->value = value;
    new_node->next = *list;
    *list = new_node;
}


