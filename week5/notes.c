/*

-----     Lecture     -----

data structures - using the computer's memory in more versatile ways

arrays
    contiguous chunks of memory

    insertion: adding a number to a data set (an array)
        takes O(n) and Ω(1) time as we need to copy the array to a new location with more memory if necessary

        ||| pseudocode |||      to append new element to list of length x
                allocate x+1 units of memory somewhere else
                loop through old list, copying values to new allocated memory
                add new element to new allocated memory
                set the variable that was pointing to the old location to the new location



    realloc(<address>, <number of bytes to be allocated)
            
            address = address of old memory that must be reallocated
            number = number of bytes of new chunk of memory in the heap
        
        reallocates memory to a new address with a new size and returns a pointer to the address of the memory
        automatically frees old memory 



linked lists
    basically an array that uses pointers to point to the next item in a list
        but not formally an array because the memory does not need to be contiguously arranged

        in the computer's memory, data is stored in pairs: first byte stores the value and next byte stores the address to the next value
        for the final value, "the next address" is 0x0 (or 0 or NULL) due to convention, denoting the end of the linked list

    arrow notation
        |1|
        | | -> |2|
               | | -> |3   |
                      |NULL|

    linked lists use 2x as much memory as a normal array

node = a "capsule" that stores some sort of data (e.g. the linked list above has 3 nodes)

    linked list time complexities:
        linear search       O(n) and Ω(1)       we must loop through all the nodes 

        insertion           O(1) and Ω(1)       assuming you don't need the list to be sorted
                            O(n) and Ω(1)       assuming you need the list to be sorted
                


trees
    same concept as linked lists - using pointers to point to the next value

    however, trees have multiple branches (a linked list is essentially a single branch of a tree)

    binary search tree
        every node has up to 2 pointers
            
            the left child is always less than the parent
            the right child is always greater than the parent

        terminology is intuitive:
            root
            parent
            children
            grandchildren

        allows us to binary search but uses more memory as each node has 2 pointers plus its stored value

        binary search tree time complexities:
            binary search          O(log n) and Ω(1)        a nice balanced tree
                                   O(n) and Ω(1)            if the tree isnt evenly balanced 


hash tables
    e.g. initialise an array of length 26; each index representing a letter, instantly jump to that spot

    basically rows of linked lists; a hash table is thus an array storing linked lists

    | | -> | Albus | -> | ArryPotter | -> | AlexandertheGreat |
    | | -> | Harry | -> | Hermoine | -> | Hagrid |
    
    each "pointer" that is the 'root' of the linked list is called a "bucket"


    hash function = a function that takes an input and returns the index of the bucket in which to place it
        e.g. "Harry" -> [hash function] -> [1]
        e.g. "Albus" -> [hash_function] -> [0]

    hash table time complexities:
        search          O(n) and Ω(1)        if the chain is very long, the hash table acts like a linked list
                    however, the average runtime is less ( technically is O(n/26) )


tries
    trees that give us constant time lookup

    a try is a tree of arrays (each node is an array), where each array contains pointers

    try table time complexities:
        search          O(1) and Ω(1)        with a try, search is constant time; however, uses the most memory


abstract data structures

    queues 
        FIFO property (first-in-first-out)

        enqueue - add something to a queue
        dequeue - remove something from a queue

        e.g. sending something to the printer

    stacks
        LIFO property (last-in-first-out)

        push - add something to a stack
        pop - remove something from a stack

        e.g. emails

    dictionaries
        an 'array' with Keys and Values



in CS, usually less runtime wanted = more memory needed

            


                

*/



// -----     Code     -----

// creating a linked list + looping through it + freeing it
void creatingALinkedList(void)
{

    typedef struct node // defining a linked list node
    {
        int number;
        struct node *next; // pointer to the next node
    }
    node;

    node *list = NULL; // declare the pointer that will eventually point to the first node
    
    node *n = malloc(sizeof(node)); // n is a temp pointer;

    if (n != NULL) // if n can be created (there is memory available)
    {
        (*n).number = 1; // set the value of the address to 1
        // OR
        n->number = 1; // set the value of the address to 1

        n->next = NULL; // set the pointer of the address to NULL (0) to signify end of the list
    }
    list = n; // set pointer to point to the same place as the temporary pointer

    //#2
    n = malloc(sizeof(node)); // find more memory to store next node
    if (n != NULL)
    {
        n->number = 2;
        n->next = NULL;

        list->next = n; // store address of node#2 
    }

    //#3
    n = malloc(sizeof(node)); // find more memory
    if (n != NULL)
    {
        n->number = 3;
        n->next = NULL;

        list->next->next = n;
    }
    else // in case of error
    {
        free(list->next);
        free(list); // ALWAYS free list->next before list
        return 1;
    }


// loop through a linked list
    for (node *tmp = list; tmp != NULL; tmp = tmp->next)
    {
        printf("%i\n", tmp->number);
    }



// free a linked list
    while (list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }

    return 0;

}




// creating a binary search tree
void creatingABinarySearchTree(void)
{
    typedef struct node
    {
        int number;
        struct node *left;
        struct node *right;
    }
    node;

    node *tree = NULL;

    node *n = malloc(sizeof(node));
    if (n != NULL)
    {
        n->number = 2;
        n->left = NULL;
        n->right = NULL;
        tree = n;
    }

    node *n = malloc(sizeof(node));
    if (n != NULL)
    {
        n->number = 1;
        n->left = NULL;
        n->right = NULL;
        tree->left = n;
    }

    node *n = malloc(sizeof(node));
    if (n != NULL)
    {
        n->number = 3;
        n->left = NULL;
        n->right = NULL;
        tree->right = n;
    }

    // creates this:
    /*
        2
       / \
      1   3

    */
}

// print a binary tree
void print_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    print_tree(root->left);
    printf("%i\n", root->number);
    print_tree(root->right);
}

// free a binary tree
void free_tree(node *root)
{
    if (root == NULL)
    {
        return;
    }
    free_tree(root->left);
    free_tree(root->right);
    free(root); // important to do this last
}

// search for int number in sorted tree
bool search(node *tree, int number)
{
    if (tree == NULL)
    {
        return false;
    }
    else if (number < tree->number)
    {
        return search(tree->left, number);
    }
    else if (number > tree->number)
    {
        return search(tree->right, number);
    }
    else (number == tree->number)
    {
        return true;
    }
}



// creating a hash table
void creatingAHashTable(void)
{
    const int LONGEST_WORD = 100;
    const int NUMBER_OF_BUCKETS = 26;

    typedef struct node
    {
        char word[LONGEST_WORD + 1];
        struct node *next;
    }
    node;

    // create an array of pointers
    node *hash_table[NUMBER_OF_BUCKETS];
}

// creating a try
void creatingATry(void)
{
    int SIZE_OF_ALPHABET = 26;

    typedef struct node
    {
        bool is_word;
        struct node *children[SIZE_OF_ALPHABET];
    }
    node;
}

