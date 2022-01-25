#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int countLetters(string input)
{
    int counter = 0;

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        int letterCode = input[i];

        if ((letterCode >= 65 && letterCode <= 90) || (letterCode >= 97 && letterCode <= 122))
        {
            counter++;
        }
    }

    return counter;
}


int countWords(string input)
{
    int counter = 1;

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        int letterCode = input[i];

        if (letterCode == 32)
        {
            counter++;
        }
    }

    return counter;
}


int countSentences(string input)
{
    int counter = 0;

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        int letterCode = input[i];

        if ((letterCode == 33) || (letterCode == 46) || (letterCode == 63))
        {
            counter++;
        }
    }

    return counter;
}


int main(void)
{
    string input = get_string("Text: ");

    int lettersNum = countLetters(input);
    //printf("Letter(s): %i\n", lettersNum);

    int wordsNum = countWords(input);
    //printf("Words(s): %i\n", wordsNum);

    int sentencesNum = countSentences(input);
    //printf("Sentences(s): %i\n", sentencesNum);

    float multiplier = 100.0 / wordsNum;

    //printf("Multiplier: %f\n", multiplier);


    int index = round((0.0588 * lettersNum * multiplier) - (0.296 * sentencesNum * multiplier) - 15.8);


    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}