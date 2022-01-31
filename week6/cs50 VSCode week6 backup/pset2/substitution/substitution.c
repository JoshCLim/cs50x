#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, string argv[])
{
    //check for valid input
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }



    string key = argv[1];


    int alreadySeen[26];

    for (int h = 0; h < 26; h++)
    {
        alreadySeen[h] = 0;
    }


    int numKey[26];

    for (int i = 0; i < 26; i++)
    {
        int letterCode = key[i];

        if (isupper(letterCode))
        {
            if (alreadySeen[letterCode - 65] == 1)
            {
                printf("Repeated Letter in Key!\n");
                return 1;
            }
            else
            {
                alreadySeen[letterCode - 65] = 1;
            }

            numKey[i] = letterCode - (i + 65); // calculate difference in position between current letter and desired letter
        }
        else if (islower(letterCode))
        {
            if (alreadySeen[letterCode - 97] == 1)
            {
                printf("Repeated Letter in Key!\n");
                return 1;
            }
            else
            {
                alreadySeen[letterCode - 97] = 1;
            }

            numKey[i] = letterCode - (i + 97); // calculate difference in position between current letter and desired letter
        }
        else
        {
            printf("Invalid Key!\n");
            return 1;
        }


    }

    string input = get_string("plaintext: "); // get input

    int inputLen = strlen(input);

    printf("ciphertext: ");

    for (int q = 0; q < inputLen; q++) // loop through input; for each character, encode based on numKey
    {
        int inputVal = input[q];

        if (isupper(inputVal))
        {
            int outputVal = inputVal + numKey[inputVal - 65];
            printf("%c", (char) outputVal);
        }
        else if (islower(inputVal))
        {
            int outputVal = inputVal + numKey[inputVal - 97];
            printf("%c", (char) outputVal);
        }
        else
        {
            printf("%c", (char) inputVal);
        }
    }

    printf("\n");
    return 0;


}