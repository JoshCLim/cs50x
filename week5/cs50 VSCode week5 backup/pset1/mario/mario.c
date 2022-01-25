#include <cs50.h>
#include <stdio.h>



void printAgain(int x, string a) // a function that prints a string 'a', 'x' times
{
    for (int n = 0; n < x; n++)
    {
        printf("%s", a);
    }
}



int main(void)
{

    int x;

    do // get user input
    {
        x = get_int("Height: ");
    }
    while (x <= 0 || x >= 9);

    for (int q = 1; q < x + 1; q++)
    {

        printAgain(x - q, " "); // print spaces before

        printAgain(q, "#"); // print #s

        printf("  "); // print spaces between

        printAgain(q, "#"); // print right side hashes

        printf("\n"); // new line
    }

}