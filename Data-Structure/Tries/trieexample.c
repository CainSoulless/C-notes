#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define NUM_CHARS 256

/* The Trie nodes are declared with a struct,  */

typedef struct trienode
{
    struct trienode *children[NUM_CHARS];
    bool terminal;
} node_t;

node_t *createnode()
{
    node_t *newNode = (node_t *)malloc(sizeof(node_t));
    
    for (int i = 0; i < NUM_CHARS; i++) 
    {
        newNode->children[i] = NULL;
    }
    newNode->terminal = false;
    return newNode;
}

bool trieInsert(node_t **root, char *signedtext)
{
    if (*root == NULL)
    {
        *root = createnode();
    }

    unsigned char *text = (unsigned char *)signedtext;

    node_t *tmp = *root;

    for (int i = 0; i < (int)strlen(signedtext); i++) 
    {
        if (tmp->children[text[i]] == NULL)
        {
            //  Create a new node.
            tmp->children[text[i]] = createnode();
        }
        tmp = tmp->children[text[i]];
    }

    if (tmp->terminal)
    {
        return false;
    }
    else 
    {
        tmp->terminal = true;
        return true;
    }
}

void printTrie_rec(node_t *node, unsigned char *prefix, int length)
{
    unsigned char newPrefix[length+2];
    memcpy(newPrefix, prefix, length);
    newPrefix[length+1] = 0;

    if (node->terminal)
    {
        printf("WORD: %s\n", prefix);
    }

    for (int i = 0; i < NUM_CHARS; i++) 
    {
        if (node->children[i] != NULL)
        {
            newPrefix[length] = i;
            printTrie_rec(node->children[i], newPrefix, length + 1);
        }
    }
}
void printTrie(node_t *root)
{
    if (root == NULL)
    {
        printf("Empty!.\n");
        return;
    }
    printTrie_rec(root, NULL, 0);

}
int main(void)
{
    node_t *root = NULL;

    trieInsert(&root,"KIT");
    trieInsert(&root,"CATTLE");
    trieInsert(&root,"KIN");
    trieInsert(&root,"CAT");
    trieInsert(&root,"HAPPY");
    printTrie(root);
    return 0;
}
/* No entendi nada */

