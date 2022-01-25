#include <cs50.h>
#include <stdio.h>
#include <math.h>


void invalid(void)
{
    printf("INVALID\n");
}


int findLength(long x)
{
    int count = 0;

    do
    {
        x /= 10;
        count++;
    }
    while (x != 0);

    return count;
}


long findDigit(long input, int num)
{
    if (num == 0)
    {
        return 0;
    }
    else
    {

        long multiplier = 1;

        for (int g = 0; g < num - 1; g++)
        {
            multiplier *= 10;
        }
        //printf("Multiplier: %ld\n", multiplier);

        /*long digits = input % multiplier; // multiplier = 10^num



        printf("%i:\n", num);
        printf("%ld\n", digits);

        long digit = digits - findDigit(input, num-1);

        //printf("%ld\n", digit);*/

        long a = input % multiplier;

        return ((input - a) / multiplier) % 10;

    }
}



int lunsAlg(long input, int length, int evenNums)
{

    long singles = 0;

    long doubles = 0;


    for (int r = 1; r < length + 1; r++)
    {
        long digit1 = findDigit(input, r);

        //printf("%ld\n", digit1);

        if (r % 2 == 0)
        {
            if (digit1 < 5)
            {
                doubles += digit1 * 2;
            }
            else if (digit1 >= 5)
            {
                doubles += (digit1 * 2 - 9);
            }
        }
        else
        {
            singles += digit1;
        }
    }

    long total = singles + doubles;

    if (total % 10 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}



int main(void)
{

    long input = get_long("Number: ");

    int length = findLength(input);

    //printf("Length: %i\n", length);





    int evenNums;

    if (length % 2 == 0) // how many digits need to be doubled?
    {
        evenNums = length / 2;
    }
    else
    {
        evenNums = (length - 1) / 2;
    }

    //printf("%i\n", evenNums);

    //printf("First Digit: %ld\n", findDigit(input, 5));

    //printf("Last Digit: %ld\n", input%10);
    //printf("Second-Last Digit: %ld\n", (input%100 - input%10)/10);







    if (lunsAlg(input, length, evenNums))
    {
        //printf("Lun's alg satisfied\n");

        if (length == 15)
        {
            if ((findDigit(input, length) == 3) && ((findDigit(input, length - 1) == 4) || (findDigit(input, length - 1) == 7)))
            {
                printf("AMEX\n");
            }
            else
            {
                invalid();
            }
        }
        else if (length == 13)
        {
            if (findDigit(input, length) == 4)
            {
                printf("VISA\n");
            }
            else
            {
                invalid();
            }
        }
        else if (length == 16)
        {
            if (findDigit(input, length) == 4)
            {
                printf("VISA\n");
            }
            else if (findDigit(input, length) == 5)
            {
                if ((findDigit(input, length - 1) < 6) && (findDigit(input, length - 1) > 0))
                {
                    printf("MASTERCARD\n");
                }
                else
                {
                    invalid();
                }
            }
            else
            {
                invalid();
            }
        }
        else
        {
            invalid();
        }

    }
    else
    {
        invalid();
    }

}