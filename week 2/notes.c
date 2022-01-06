/*

SUMMARY

    under-the-hood of compiling the

    debugging

    memory, RAM

    arrays

    command line arguments




-----     Week 2 Lecture     -----     

in CS50 IDE
make = command that compiles the program; it automatically adds command line arguments 

when you run make, it gives this output:
    clang -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow    credit.c  -lcrypt -lcs50 -lm -o credit

clang = the compiler that 'make' calls; clang is a commonly used compiler for C
    a.out (assembly output) is the default name given to an executable file after source code is compiled
    
    clang can be configured to change how it runs

in the command line, you are typing in a command, followed by "command-line arguments"
    e.g. clang -o hello hello.c
            clang = the command
            -o = output 
            hello = file name of output 
            hello.c = program to be compiled

if you compile a program with additional header files, sometimes it is necessary to add more command-line arguments to tell the compiler where to find the library
    e.g. clang -o hello hello.c -lcs50 
            -lcs50 = link the cs50 library

compiling has 4 steps
    1. preprocessing
        looks for lines that start with #
        copies the contents of the library that is linked into the program

    2. compiling
        converts source code into assembly code

        different CPUs understand different commands - they are in the form of assembly code
        Assembly is a different lanuguage - Assembly has a very low level of abstraction

    3. assembling
        converts Assembly code into zeros and ones (machine code / binary)

    4. linking
        links libraries (e.g. stdio.c, cs50.c, etc.) that have been precompiled with your program




GUI = graphical user interface




Crtl + C = terminate the program





debugging = finding problems in your own code
bug = mistake in the program

    printf is a powerful debugging tool - it can show output during steps in your program

    using debug50:
        breakpoints - lines at which the program will pause so you can see value of variables etc.
            set breakpoints by clicking to the left of the line number (the gutter)

        step over - move down to the next line
        step into - jumps into the function

        local variables - shows a list of all local variables and their values and types

        call stack - shows all the functions that the program has called (but not yet returned from)

    rubber duck debugging lol
        talk through the program / what is happening





each data type takes up a fixed amount of space (see wk 1 notes)
primitive types are: bool, char, int, long, float, double, string

Computers use memory to store data 
RAM = random access memory; electronic memory; quickly store and access data / files / memory




arrays = a sequence of values in memory stored back to back 
    arrays start counting at 0


const = constant; declaring a constant variable whose value doesn't change


a string in simply an array of chars 
    \0 = null character; used to represent the end of a string 
    e.g. "HI!" is 4 bytes; 1 for each character and 1 for the null character 

    to access each char in a string, you can use array notation 
        e.g. string[0] is the first character of the string

    if you try to access indexes past the length of the string, you are accessing different parts of the computer's memory
        e.g. if string s = "HI!"; string[400] = 233 is from another part of the computer's memory


in the header file string.h:
    strlen(string) = returns the length of the string
in the header file ctype.h:
    toupper(character) = returns uppercase version of character
    islower(character) = returns true if lowercase, false if not



manual.cs50.io gives commonly used functions in C++



command line arguments 
    if we declare a program with something other than (void) in the "int main(void) {}" section
    we can pass an argument into the command line as input to the main function

    int main(int argc, string argv[]) {}

        argc = argument count 
            integer that counts the number of arguments (the length of the array argv)

            e.g.    ./hello Josh        argc is 2 in this case
                    ./yeet              argc is 1 in this case
                    
        argv = argument vector 
            an array that stores all the inputs that the user types as command line arguments

            argv stores all command line inputs as STRINGS
            
            vector is another word for array

            name of the program is stored in argv[0]
            last argument inputted is argv[argc-1]

    main function is defined using 'int' 
        this is because it returns 0 if the program runs successfully
        we can return 1 in the main function if there is an error

        this return value is called "exit status"

    use the command "echo $?" to see return value of main function



----- cryptography -----
    encrypting: plain text -> cipher -> ciphertext
    decrypting: reverse process

    use a key that only sender + receiver know
    



-----     Shorts     -----

FUNCTIONS
    functions are also known as procedures, methods (in object-oriented programming), subroutines

    function = a black box with a set of 0+ inputs and 1 output 
        black box = we don't care how it is done under-the-hood

    why do we use functions?
        1. organisation 
            break up a problem into more manageable subparts
        2. simplification 
            smaller components are easier to design, implement and debug
        3. reusability 
            functions can be recycled / reused 
    
    how to create a function?
        1. declare the function
            compiler needs to know that the function appears in the code

            return-type name(argument-list);
                return-type = type of variable function will return;
                name = name of function 
                argument-list = comma-separated set of inputs to the function, each with a name and type
        
        2. define the function
            return-type name(argument-list) 
            {
                // function actions
            }

            ensure that the function returns a value of the appropriate type
        
        3. call the function
            name(inputs);

VARIABLE SCOPE
    scope = characteristic of a variable that defines from which functions that variable may be accessed
        local variable = only accessible in the function in which it is created
        
        global variable = accessible anywhere in the program

    to declare a global variable, define it outside any functions (e.g. outside main function)

    when a variable is passed as input into a function, a 'copy' of the variable's value is inputted, not the variable itself
    this is called "passed by value"

ARRAYS
    arrays are a fundamental data structure 
    arrays hold values of the same type at contiguous memory locations
    arrays are partitioned into small, identically-sized blocks of memory called elements
    arrays can store a certain amount of data 
    elements in an array can be accessed by an index

    indexing starts from 0 
        for an array of length x, last element is at index (x-1)

    declaring an array: type name[size];
        type = data type of elements in an array 
        name = name of array 
        size = how many elements array will contain

    defining an array: type name[size] = {element1, element2, element3, ...}; // you dont actually need to define the size if you declare an array in this way


    arrays can be multidimentional
        e.g. to create a 10x10 virtual grid: bool battleship[10][10]

    elements in an array can be treated as variables, but an entire array cannot be treated as a variable


    arrays are not "passed by value" into a function; they are instead "passed by reference" 
    if the function manipulates the array, it changes the original array




*/


// ----- CODE -----
//#include <stdio.h>
//#include <string.h>

typedef char *string;

int main(void)
{


// declare an array and assign its values
int scores[3]; // 3 = length of array
scores[0] = 72; // indexing into the array
scores[1] = 73;
scores[2] = 33;
// OR



const int CONSTANT = 3.14; // declare a constant variable; it is convention to capitalise constants


string s = "lajfksdn";
for (int i = 0; s[i] != '\0'; i++) // loop through every character in a string
{
    // do stuff
}
// OR
for (int i = 0, n = strlen(s); i < n; i++)
{
    // do stuff
}



}

int main(int argc, string argv[])
{
    // do stuff
}