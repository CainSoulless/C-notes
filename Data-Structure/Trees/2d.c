#include <stdio.h>
#include <stdlib.h>
#define COUNT 1

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}
node_t;

node_t *newNode(int data)
{
    node_t *tmp = (node_t *)malloc(sizeof(node_t));
    tmp->data = data;
    tmp->right = NULL;
    tmp->left = NULL;
    return tmp;
}

void printTree(node_t *root, int space)
{
    if (root == NULL)
    {
        return;
    }
    space += COUNT;
    printTree(root->right, space);
    for (int i = COUNT; i < space; i++)
    {
        printf("\t");
    }
    printf("%d\n", root->data);
    printTree(root->left, space);
}

int main(void)
{
    node_t *root = (node_t *)malloc(sizeof(node_t));
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left = newNode(8);
    root->left->left->right = newNode(9);
    root->left->right->left = newNode(10);
    root->left->right->right = newNode(11);
    root->right->left->left = newNode(12);
    root->right->left->right = newNode(13);
    root->right->right->left = newNode(14);
    root->right->right->right = newNode(15);


    printTree(root, 0);
    free(root);
}
