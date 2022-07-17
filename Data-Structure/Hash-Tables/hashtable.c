#include <stdio.h>
#include <stdlib.h>
#define SIZE 20

typedef struct dataItem
{
    int data;
    int key;
}
item_t;

item_t *hashArray[SIZE];
item_t *dummyItem;
item_t *item;
/* method used to compute the hash of every index */
int hashCode(int key)
{
    return key % SIZE;
}
/* Search whenever element into the table, with the key. */
item_t *search(int key)
{
    /* Getting the hashcode */
    int hashIndex = hashCode(key);

    /* travelsing until an empty array */
    while (hashArray[hashIndex] != NULL)
    {
        if (hashArray[hashIndex]->key == key)
        {
            return hashArray[hashIndex];        
        }    
        /* next cell */
        ++hashIndex;

        hashIndex %= SIZE;
    }
    return NULL;
}

void insert(int key, int data)
{
    item_t *item = (item_t *)malloc(sizeof(item_t));
    item->data = data;
    item->key = key;

    /* Getting hashcode */
    int hashIndex = hashCode(key);

    /* travelsing */
    while (hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1)
    {
        ++hashIndex;    

        hashIndex %= SIZE;
    }
    hashArray[hashIndex] = item;
    free(item);
}

item_t *delete(item_t *item)
{
    int key = item->key;

    int hashIndex = hashCode(key);

    /* travelsing */
    while (hashArray[hashIndex] != NULL)
    {
        if (hashArray[hashIndex]->key == key) 
        {
            item_t *tmp = hashArray[hashIndex];

            hashArray[hashIndex] = dummyItem;
            return tmp;

        }
        /* Next cell */
        ++hashIndex;

        hashIndex %= SIZE;
    }
    return NULL;
}
void display()
{
    for (int i = 0; i < SIZE; i++) 
    {
        if (hashArray[i] != NULL)
        {
            printf("(%d,%d)", hashArray[i]->key, hashArray[i]->data);
        }
        else 
        {
            printf(" ~~ ");    
        }
    }
    printf("\n");

}
int main(void)
{
    dummyItem = (item_t *)malloc(sizeof(item_t));
    dummyItem->data = -1;
    dummyItem->key = -1;

    insert(1, 20);
    insert(2, 70);
    insert(42, 80);

    display();
    item = search(1);

    if (item != NULL)
    {
        printf("Found: %d\n", item->data);
    }
    else
    {
        printf("Not found.\n");
    }
    free(dummyItem);
    return 0;
}
