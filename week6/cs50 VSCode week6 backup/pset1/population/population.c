#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size

    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    // TODO: Prompt for end size

    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold

    int popCount = start;
    int counter = 0;

    while (popCount < end)
    {
        int growthRate = (popCount / 3) - (popCount / 4);
        popCount += growthRate;
        counter++;
    }


    // TODO: Print number of years

    printf("Years: %i\n", counter);

}