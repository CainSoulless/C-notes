#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
}
node_t;

void printAll(node_t *tree)
{
    if (tree == NULL)
    {
        return;
    }    
    printAll(tree->left);
    printf("%d\n", tree->data);
    printAll(tree->right);
}
void free_tree(node_t *tree)
{
    
}
node_t *newNode(int data)
{
    node_t *new = (node_t *)malloc(sizeof(node_t));
    new->data = data;
    new->left = NULL;
    new->right = NULL;

    return new;
}
int main(void)
{
    node_t *root = newNode(1);
    /* We already created the root of the tree:
     *   1
        / \
      NULL NULL
    */
    root->left = newNode(2);
    root->right = newNode(3);
    /*      1
         /    \
        2      3
      /  \    /  \
   NULL NULL NULL NULL*/
    root->left->left = newNode(4);
    printAll(root);
    return 0;
}
