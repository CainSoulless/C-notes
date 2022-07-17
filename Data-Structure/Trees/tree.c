#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}
node;

void print_tree(node *root);
void free_tree(node *root);

int main(void)
{
    node *tree = NULL;

    node *n = (node *)malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }
    n->data = 2;
    n->left = NULL;
    n->right = NULL;

    //  Now all the data are stored on tree node.
    tree = n;

    //  When we want to add new data, first we must to allocate more memory.
    n = (node *)malloc(sizeof(node));
    if (n == NULL)
    {
        free_tree(tree);
        return 1;
    }
    n->data = 1;
    n->left = NULL;
    n->right = NULL;
    //  Adding new child of the root node.
    tree->left = n;

    print_tree(tree);
    free_tree(tree);
    return 0;
}

void print_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    print_tree(root->left);
    printf("%i\n", root->data);
    print_tree(root->right);
}

void free_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root);
}
