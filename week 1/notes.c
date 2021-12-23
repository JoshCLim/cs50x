/*

-----     Week 1 Lecture     -----

Three aspects of code:
    1. correctness - does it do what it's meant to
    2. design - how well written is it (e.g. are you repeating yourself)
    3. style - indenting/punctuation/syntax/readability/descriptive variable names




IDE = integrated development environment

compiler = a program that converts source code (written by you) to machine code (binary)
    computers can only understand binary



function = mini-program, code that does something/an action

arguments / parameters = inputs to functions

functions can have two effects:
    1. a "side-effect" (e.g. printing on the screen)
    2. a return value (e.g. input function has an ask side-effect and returns the user's input)






library = code that someone else has written

header file = a file with an extension .h that contains some C function declarations and macro definitions e.g. cs50.h



bug = problems in code correctness



casting / type-casting = telling the computer to convert one data type to another


abstraction = problem solving by making something simpler?



scope (of a variable) = the lines of code where the variable is defined

computers are limited by their ram / number of bits - thus, they cannot count infinitely high nor infinitely precisely

*/








/*
data types:
    string  (string)    64bits  letters,numbers etc.    put between double quotation marks - e.g. "hello world"
    char    (character) 8bits   single characters       put between single quotation marks e.g. 'a'
        e.g. 'A' = 65; 'a' = 97; '0' = 48;

    int     (integer)   32bits  integers                from range -2^31 to 2^31-1
        unsigned int        32bits  positive integers       from range 0 to 2^32-1
    long    (long)      64bits  long integers with more bits

    float   (float)     32bits  a real number with a decimal value
        floats have limited precision because only 32bits are used to store the information
    double  (double)    64bits  a float with more digits

    DOES NOT EXIST IN C:
        bool    (boolean)   64bits  true or false
        structs (structures)
        typedefs

    void                        a placeholder for basically "nothing"        



    "unsigned" - a qualifier (specifies some information about the variable, in this case, that the integers are positive)


operators:
    =       assignment operator
    +       plus
    -       minus
    /       divides
    *       times
    %       modulus (remainder)
    +=      add ___ to variable
    -=      subtract ___ to variable
    *=      multiply variable by ___ 
    /=      divide variable by ___
    ++      add 1 to a variable
    --      subtract 1 from a variable


    ||      or
    &&      and


boolean expression = expression that evaluates to true or false
    in C, every nonzero value is equivalent to true; zero is equivalent to false

    two types of Boolean expressions 
        1. logical operators
            &&      and     is true if BOTH are true, otherwise false
            ||      or      is true if at least one is true
            !       not     reverses the value of the operand

        2. relational operators   
            ==      equal to
            !=      not equal to
            >       greater than
            <       less than
            >=      greater than or equal to
            <=      less than or equal to


terminal commands for UNIX-based systems (Linux and MacOS):
    cd <directory>      
        change directory - go to a directory
            shorthand name for current directory is .
            shorthand name for parent directory is ..

            if <directory> is blank, the directory changes to home directory
    
    cp <source> <destination>
        copy - copy argument 1 (filename) to argument 2 (pathname + filename)

    cp-r <source> <destination>
        copy - copy recusively (copies a directory and everything inside)

    pwd 
        present working directory - shows current directory you are in

    ls
        list - lists all the folders/files in the current directory

    mv <source> <destination>
        move - moves a file from argument 1 (filename) to argument 2 (pathname)

    mkdir <name>
        make directory - creates a folder

    rm <file>
        remove / delete file
            if you add -f after rm, it deletes forcibily (does not ask you to confirm the delete)
            if you add -r after rm, it deletes recursively (everything inside the directory)
            if you add -rf after rm, it deletes recursively and forcibly

    rmdir <directory>
        remove / delete directory/folder

    open <filename>
        opens a file

    touch <filename>
        creates a file

    clear
        clears the command line

    sudo <command>
        super user do - run command as admin
    
    chmod
    ln
    man
    diff
    sudo
    telnet


*/










// code samples


// ----- PRINT / OUTPUT STUFF -----
printf("hello, world"); // prints hello world

printf("%.10f\n", x / y); // prints x / y to 10 decimal places


// ----- DECLARE / INITIALIZE VARIBLES -----
int number; // declares variable "number"

String message = "hello, world"; // assigns string to variable "message"



// ----- CONDITIONALS -----

if (booleanExpression)  // if / else if / else block
{
    // do stuff
}
else if (booleanExpression || booleanExpression)
{
    // do other stuff
}
else 
{
    // error
}

int x = (booleanExpression) ? 5 : 6; // using a ternary operator (?:)
    // if booleanExpression is true, x = 5, else, x = 6;


int x = 0;
switch (x) // switch statement
{
    case 1: // if x == 1
        // do stuff
        break;
    case 2: // if x == 2
        // do stuff
        break;
    default: // no cases above met
        // do stuff
        break;
}


// ----- LOOPS -----

while (true) // infinite while loop
{
    // do stuff
}
while (booleanExpression) // while loop
{
    // do stuff
}

do // do-while statement - a normal while loop checks condition and then runs code, do-while runs code then checks condition
{
    // get input or something   
}
while (booleanExpression);


for (initializeVariable; booleanExpression; increment) // for loop
{
    // do stuff
}


// ----- FUNCTIONS -----

void function1(void) // declare a function in C
{
    // do something
}
void function2(int q) // declare a function with an input
{
    // do something
}
int getNumber(void) // function that returns integer
{
    int n = 1;

    return n;
}






// programs

/*

// -----     print hello world     -----
#include <stdio.h>
int main(void)
{
    printf("Hello World!");
}


// -----     ask user for name input     -----
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string ans = get_string("What is your name? ");
    //printf("hello, world\n");
    printf("hello, %s\n", ans);
}



// -----     divide two numbers     -----
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("x: ");

    int y = get_int("y: ");

    printf("%f\n", (float) x / (float) y); // note that x and y must be converted to floats first before the division
}

*/