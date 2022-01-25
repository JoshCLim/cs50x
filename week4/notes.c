/*

-----     Lecture      -----

counting in Computer Science generally uses hexadecimal (base-16)
    0-9, then A-F
    where A = 10, B = 11... F = 15

    1 hexadecimal digit = 4 binary digits

    hexadecimal is used for rgb colours for computers

    usually when writing in hexadecimal, preface the number with a '0x'
        e.g. 0x39 = 57

    
    
    indexes that refer to the computer's memory are in hexadecimal


every section of a computers memory has a corresponding address

    new operators:
        &   extraction operator     returns the address of the memory in which the variable is stored
            
                e.g. &n returns the address of variable n

                use %p to printf a pointer

        *   dereference operator    returns the value stored at the address given

                e.g. *&n returns the value of n


pointers - a data type that stores the address of some other value in memory
    a pointer has a:
        value       the memory address
        type        describes the data-type located at the memory address

    to declare a pointer, use "[data-type] *[variable-name] = [address]"

    pointers tend to take up 8 bytes

    we can pass a pointer to a function to use the function to directly edit the value of a variable

    NULL pointer    a pointer that points to nothing

pointees - things that the pointers point to



strings
    review: a string is an array of chars that ends in \0
        i.e. a set of consecutive addresses in memory
    
    the variable name of the string is pointing to the address of the first char of the string
        this is possible because by definition, the chars are consecutive and the string ends in \0

    thus, a string can be thought of as a pointer


    string is not actually a data type in C
        is actually char *[variable name] = "[string]"
            e.g. char *s = "MY STRING!";

        char *      is equivalent to        string

        s is the pointer to the first char of the string
            so *s will return the first char of the string
                *(s+1) returns the second char of the string etc. etc.
        

    this is true for any array: an array name is a pointer to its first element



segmentation fault = error where you have accessed a certain section of memory that you shouldn't have


----- DYNAMIC MEMORY ALLOCATION -----

malloc(<bytes needed>)      (memory allocation)
    a function that allocates a new section of memory of length equal to input
        e.g. int *b = malloc(4)
    
    malloc returns the address of the first byte of the memory (b is the pointer)
        if malloc cannot give you memory, it will return NULL
    

    every time you use malloc, you need to use 'free' to free up or 'give back' the memory you allocated
        use free(<pointer>);
            e.g. free(b);

    forgetting to free up memory after malloc is called a "memory leak"



important to note the difference:
    NUL (\0)        a character meaning no value (ASCII code 0)
    NULL            a pointer meaning no address / memory at all



valgrind    a program that can be run to find bugs/issues related to memory
    
    command line:      valgrind <program.c>

    "invalid write" = changing memory that you should not be accessing
    "invalid read" = reading memory that you should not be reading
    "leak summary" = forgot to free after malloc



sizeof(<datatype>)
    returns the number of bytes that the datatype takes up


garbage values
    if you yourself did not put a value in a computer's memory, treat it as a "garbage value"
    its useless and you have no idea what it means


memory layout
    when you run a program, the computer stores certain types of memory in different locations
    
        |   machine code    |   global variables    |   heap ->                     <- stack    |
        
        1. the machine code 
        2. the global variables 
        3. the heap 
            memory set aside for memory to be allocated (using malloc)
        4. the stack 
            memory set aside for functions to be called 
             + local variables / parameters from functions etc.

        e.g. |   machine code    |   global variables    |   heap ->       | other function A | main |


stack overflow = where you call a function too many times that you overflow into the heap
    e.g. if you forget the base case in recursion
heap overflow = where you malloc too much memory that you overflow into the stack
buffer overflow = if you go farther than the end of memory that you are using
    e.g. going past an array / malloc memory that you shouldn't have accessed



----- CALL STACK -----

when you call a function, the system sets aside memory for the function to do its work
    
    memory set aside for functions = stack frames / function frames

    only one frame is active at a time 

    frames are arranged in a stack - the frame for the most recently called function is on top

    when a new function is called, a new frame is pushed onto the stack; 
    when it is finished, it is removed and the function below it on the stack (which called it) resumes




----- SCANF -----

scanf("%<datatype>, <address>") = gets input from user (like get_int or something)  
    e.g. scanf("%i", &x);



----- FILE I/O -----

file I/O        taking input/output from files

    files allow us to store "persistent data" - data that does not disappear when the program stops running

    FILE is a datatype/structure that comes with C
        e.g. FILE *file = fopen("filename.csv", "a"); // 'file' becomes the pointer to the file

    fopen(<filename>, <mode>?)
        e.g. fopen("phonebook.csv", "a"); 
             a = append mode - we just want to add stuff to the end of a file
             r = read mode - only read the file
             w = write mode - change the file's contents - overwrites the file
            a+ =
            w+ =
            r+ =
        always make sure the pointer you get returned from this function != NULL

    fclose(<file pointer>)
        closes the file

    fgetc(<file pointer>)       (f get char)
        reads and returns the next character from the file
        only works if the file opened in read (r) mode

    fputc(<character>, <file pointer>)
        writes or appends (depending on the mode) the inputted character to the pointed-to file
        only works if the file opened in append (a) or write (w) mode
    
    fprintf(<pointer to file>, <data to be printed (format string)>, <list of variables>)
        e.g. fprinf(file, "%s,%s\n", name, number);

    fscanf(<pointer to file>, formatted data type (e.g. "%s"), variable to store word in);
        returns EOF if reached end of file

    fread(<ptr>, <size>, <nmemb>, <stream>)
    fwrite(<ptr>, <size>, <nmemb>, <stream>)
            ptr     = pointer to memory to store read/write data
            size    = size of data (in bytes)
            nmemb   = number of data items to read/written
            stream  = pointer to file to be read/written in
        e.g. fread(bytes, sizeof(BYTE), 3, file); // reads 3 BYTES from file 'file' into array 'bytes'

        the function returns the number of items it was able to read successfully
            while (fread(blah blah)) { //do stuff } will therefore run until there is nothing left to read


    



    "buffer"        extra memory that you can load data into? - useful to transfer / copy / swap data





different file types can be manipulated this way, since all of them ultimately are in binary
    .csv = comma separated values

    .jpeg
    .bmp


----- DEFINING CUSTOM TYPES -----
    use typedef to rename a specific datatype to a different name
        
        typedef <old name> <new name>;

        e.g. typedef char * string; // makes string equivalent to char *


*/


// ----- CODE -----
typedef char *string; // line in cs50 library that creates 'fake' data type "string" to replace "char *"

int n = 50; 
int *p = &n; // p is the pointer that stores the address of an int n

int main(void)
{
    // string = char *
    char *s = "HI!";    // which is the same as... 
    string s = "HI!";
    printf("%p\n", s);  // prints address of first char of string
    printf("%c\n", *s); // prints first char of string



    // ----- copy.c -----
        // program that copies a string into another variable

        //  the wrong version
        char *a = "hi!";
        char *b = a;

            // consider this:
            b[0] = "H";
            
            printf("a: %s\n", a); // output     a: Hi!
            printf("b: %s\n", b); // output     b: Hi!
            // because b is an "alias" of "a", where a is the pointer and b is a copy of pointer
            // thus a and b point to the same location in the computer's memory


        // the correct version
        char *a = "hi!";
        char *b = malloc(strlen(s) + 1); // note "+ 1" because nul character (\0) must be considered
        for (int i = 0, n = strlen(s); i <= n; i++) // note "<= n" because nul character
        {
            b[i] = a[i];
        }
        free(b);
        // OR
        char *b = malloc(strlen(s) + 1); // note "+ 1" because null character must be considered
        strcpy(a,b); // in string.h (I think), and handles all copying procedures
        free(b);




    // scanf.c
        int x;
        printf("Enter a number: ");
        scanf("%i", &x);
        printf("x: %i\n", x);


    // file I/O
        typedef long BYTE;//some bs code to prevent errors in VS Code lol
        typedef int FILE;//some bs code to prevent errors in VS Code lol

        FILE *file = fopen("filename.csv", "a");
        FILE *phonebook = fopen("phonebook.csv", "a"); // a = append mode - we just want to add stuff to the file
        string name = "Josh";
        string number = "+61 424 326 745";
        fprinf(file, "%s,%s\n", name, number);

        int bytes[3];
        fread(bytes, sizeof(BYTE), 3, file); // reads 3 BYTES from file 'file' into array 'bytes'


        // copy source to destination, one BYTE at a time
            BYTE buffer; // create a buffer (extra memory that we temporarily use to copy a file from source to destination)

            FILE *source = *file;
            FILE *destination = *phonebook;

            while (fread(&buffer, sizeof(BYTE), 1, source))
            {
                fwrite(&buffer, sizeof(BYTE), 1, destination);
            }

        // read all file characters one by one and print in terminal window
            char ch;
            while ((ch = fgtc(file)) != EOF) // EOF = end of file
            {
                printf("%c", ch);
            }

    

    // dynamic memory allocation
        // let us create an array of floats of length 5

        float stack_array[5]; // creates an array of floats on the stack

        float *heap_array = malloc(5 * sizeof(float)); // creates an array of floats on the heap
}