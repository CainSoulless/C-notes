#include <stdio.h>
#include <stdlib.h>

const char *messages[] = {
    "You are alone.",
    "One is the loneliest number.",
    "Now we're talking.",
    "Now we're talking.",
    "Ah, yeah...",
    "Ah, yeah...",
    "Ah, yeah...",
    "Whoa. violated fire code!"
};

const int NUM_MSG = (sizeof(messages)/sizeof(char *));

void print_party_info(size_t people)
{
    if (people > NUM_MSG)
    {
        printf("%s\n", messages[NUM_MSG - 1]);
    }
    else
    {
        printf("%s\n", messages[people]);
    }
}
int main(void)
{
    for (int i = 0; i < NUM_MSG; i++) 
    {
        print_party_info(i);
    }
    return 0;
}
