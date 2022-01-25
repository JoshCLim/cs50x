// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];
//FILE *hehe = NULL;
int sizeA = 0;

/*for (int i = 0; i < N; i++) // set everything to NULL
{
    table[N] = NULL;
}*/

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    int bucketNumber = hash(word);

    node *start = table[bucketNumber];

    for (node *tmp = start; tmp != NULL; tmp = tmp->next)
    {
        if (strcasecmp(tmp->word, word) == 0)
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    FILE *dicPointer = fopen(dictionary, "r");
    //hehe = dicPointer;


    if (dicPointer == NULL)
    {
        return false;
    }

    char word[45];
    int bucketNum = 0;

    while (fscanf(dicPointer, "%s", word) != EOF)
    {
        node *tmp = malloc(sizeof(node));
        if (tmp == NULL)
        {
            return false;
        }

        strcpy(tmp->word, word);

        bucketNum = hash(word);

        tmp->next = table[bucketNum];
        table[bucketNum] = tmp;

        sizeA++;
    }

    fclose(dicPointer);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return sizeA;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *list = table[i];
        while (list != NULL)
        {
            node *tmp = list->next;
            free(list);
            list = tmp;
        }
    }
    //free(hehe);
    return true;
}
