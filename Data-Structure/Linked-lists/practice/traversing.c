#include <stdio.h>
#include <stdlib.h>

/* See more: https://www.youtube.com/watch?v=nxtDe6Gq4t4
*/

struct node
{
    int data;                   //4 bytes
    struct node *next;          //4 bytes
};

int countNodes(struct node *head);
struct node* add_beg(struct node* head, int d);

int main()
{
    struct node *head =  (struct node *)malloc(sizeof(struct node));
    if (head == NULL) 
    {
        return 1;
    }
    head->data = 45;
    head->next = NULL;

    struct node *current = malloc(sizeof(struct node));
    if (current != NULL)
    {
        current->data = 95;
        current->next = NULL; 
    }
    head->next = current;

    current = (struct node *)malloc(sizeof(struct node));
    if (current == NULL)
    {
        free(current);
        free(head);
        return 1;
    }
    current->data = 3;
    current->next = NULL;
    head->next->next = current;
    
    current = (struct node *)malloc(sizeof(struct node));
    if (current == NULL)
    {
        free(current);
        free(head);
    }
    current->data = 99;
    current->next = NULL;

    //  The another way to link the latest node with the current node is
    //  creating a tmp var, and get all the values of head var.
    struct node *tmp = head;
    if (tmp == NULL)
    {
        free(tmp);
        return 1;
    }

    //  Then find the latest node using the tmp var. Why not the head instead? Because it must to be overwrited
    //  to find the tail.
    while (tmp->next != NULL)
    {
        //  This line updates the current link, and finishing the loop when it comes to the end.
        tmp = tmp->next;
    }
    tmp->next = current;

    tmp = head;
    while (tmp != NULL) {
        printf("%d\n", tmp->data);
        tmp = tmp->next;
        // if (tmp->next->next == NULL)
        // {
            // tmp->next->next = current;
        // }
        // printf("%d\n", head->data);
        // head = head->next;
    }
    return 0;
}

/*
Traversing the linked list:
    Visiting each nodes, in this case we want to count all the nodes in the linked list
    See more: https://youtu.be/e0s-zmpedYo
*/

int countNodes(struct node *head)
{
    int count = 0;
    if (head == NULL)
    {
        printf("List is empty...\n");
    }
    struct node *ptr= head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

/*
Inserting node at the beginning
    https://www.youtube.com/watch?v=jgqg6Qw68_Q
*/

struct node* add_beg(struct node* head, int d)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        free(ptr);
        free(head);
    }
    ptr->data = d;
    ptr->next = NULL;
    
    ptr->next = head;
    head = ptr;
    return head;
}
