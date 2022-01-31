#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    /*
    if (argc != 2)
    {
        printf("Usage: ./recover.c IMAGE\n");
        return 1;
    }

    FILE *filePtr = fopen(argv[1], "r");

    if (filePtr == NULL)
    {
        printf("Could not read file.\n");
        return 2;
    }



    char *fileNameBuffer = "000.jpg";

    BYTE blockbuffer[512];

    int counter = 0;
    sprintf(fileNameBuffer, "%03i.jpg", counter);


    while (fread(blockbuffer, sizeof(BYTE), 512, filePtr) == 512)
    {
        if ((blockbuffer[0] == 0xff) && (blockbuffer[1] == 0xd8) && (blockbuffer[2] == 0xff) && ((blockbuffer[3] >= 0xe0) && (blockbuffer[3] <= 0xef)))
        { // if start of jpeg
            if (counter != 0)
            {
                fclose(outputPtr); // close the old one
            }

            counter++;

            sprintf(fileNameBuffer, "%03i.jpg", counter - 1); // update the file name buffer

            FILE *outputPtr = fopen(fileNameBuffer, "w"); // open a file with this name
            fwrite(blockbuffer, sizeof(BYTE), 512, outputPtr); // write to this file
        }
        else if (counter != 0)
        {
            //FILE *outputPtr = fopen(fileNameBuffer, "a");
            fwrite(blockbuffer, sizeof(BYTE), 512, outputPtr);
        }
    }
    fclose(outputPtr);

    */

    // if improper command line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover.c IMAGE\n");
        return 1;
    }



    FILE *inputPtr = fopen(argv[1], "r");



    // if file does not exist
    if (inputPtr == NULL)
    {
        printf("Could not read file.\n");
        return 2;
    }


    int counter = 0;

    BYTE *blockBufferPtr = malloc(512);
    char *fileNamePtr = malloc(8);

    //FILE *prevOutputPtr = NULL;
    FILE *outputPtr = NULL;

    while (fread(blockBufferPtr, sizeof(BYTE), 512, inputPtr) == 512)
    {
        if ((blockBufferPtr[0] == 0xff) && (blockBufferPtr[1] == 0xd8) && (blockBufferPtr[2] == 0xff)
            && ((blockBufferPtr[3] >= 0xe0) && (blockBufferPtr[3] <= 0xef)))
        {
            // if its a jpeg

            if (outputPtr != NULL)
            {
                fclose(outputPtr);
            }

            sprintf(fileNamePtr, "%03i.jpg", counter); // update the fileNamePtr
            counter++;

            outputPtr = fopen(fileNamePtr, "w");
            fwrite(blockBufferPtr, sizeof(BYTE), 512, outputPtr);

        }
        else if (counter != 0)
        {
            if (outputPtr != NULL)
            {
                fwrite(blockBufferPtr, sizeof(BYTE), 512, outputPtr);
            }
            else
            {
                printf("Error\n");
                return 3;
            }
        }
    }

    fclose(outputPtr);


    free(blockBufferPtr);
    free(fileNamePtr);
}