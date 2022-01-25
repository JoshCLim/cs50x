#include "helpers.h"

#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int red = image[h][w].rgbtRed;
            int green = image[h][w].rgbtGreen;
            int blue = image[h][w].rgbtBlue;

            float average = (red + green + blue) / 3.0;
            int rounded = round(average);

            image[h][w].rgbtRed = rounded;
            image[h][w].rgbtGreen = rounded;
            image[h][w].rgbtBlue = rounded;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int halfway;

    if ((width % 2) == 0)
    {
        halfway = width / 2;
    }
    else
    {
        halfway = (width - 1) / 2;
    }

    for (int h = 0; h < height; h++) // loop through rows
    {
        for (int i = 0; i < halfway; i++)
        {
            RGBTRIPLE left = image[h][i];
            RGBTRIPLE right = image[h][width - 1 - i];

            image[h][i] = right;
            image[h][width - 1 - i] = left;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE new[height][width];

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int totalRed = image[h][w].rgbtRed;
            int totalGreen = image[h][w].rgbtGreen;
            int totalBlue = image[h][w].rgbtBlue;
            int counter = 1;


            if (h != 0)
            {
                totalRed += image[h - 1][w].rgbtRed;
                totalBlue += image[h - 1][w].rgbtBlue;
                totalGreen += image[h - 1][w].rgbtGreen;
                counter++;
            }
            if (h != (height - 1))
            {
                totalRed += image[h + 1][w].rgbtRed;
                totalBlue += image[h + 1][w].rgbtBlue;
                totalGreen += image[h + 1][w].rgbtGreen;
                counter++;
            }
            if (w != 0)
            {
                totalRed += image[h][w - 1].rgbtRed;
                totalBlue += image[h][w - 1].rgbtBlue;
                totalGreen += image[h][w - 1].rgbtGreen;
                counter++;
            }
            if (w != (width - 1))
            {
                totalRed += image[h][w + 1].rgbtRed;
                totalBlue += image[h][w + 1].rgbtBlue;
                totalGreen += image[h][w + 1].rgbtGreen;
                counter++;
            }
            if ((w != (width - 1)) && (h != (height - 1)))
            {
                totalRed += image[h + 1][w + 1].rgbtRed;
                totalBlue += image[h + 1][w + 1].rgbtBlue;
                totalGreen += image[h + 1][w + 1].rgbtGreen;
                counter++;
            }
            if ((w != 0) && (h != (height - 1)))
            {
                totalRed += image[h + 1][w - 1].rgbtRed;
                totalBlue += image[h + 1][w - 1].rgbtBlue;
                totalGreen += image[h + 1][w - 1].rgbtGreen;
                counter++;
            }
            if ((w != 0) && (h != 0))
            {
                totalRed += image[h - 1][w - 1].rgbtRed;
                totalBlue += image[h - 1][w - 1].rgbtBlue;
                totalGreen += image[h - 1][w - 1].rgbtGreen;
                counter++;
            }
            if ((w != (width - 1)) && (h != 0))
            {
                totalRed += image[h - 1][w + 1].rgbtRed;
                totalBlue += image[h - 1][w + 1].rgbtBlue;
                totalGreen += image[h - 1][w + 1].rgbtGreen;
                counter++;
            }


            double averageRed = (double) totalRed / counter;
            double averageBlue = (double) totalBlue / counter;
            double averageGreen = (double) totalGreen / counter;

            int roundedRed = round(averageRed);
            int roundedBlue = round(averageBlue);
            int roundedGreen = round(averageGreen);

            new[h][w].rgbtRed = roundedRed;
            new[h][w].rgbtBlue = roundedBlue;
            new[h][w].rgbtGreen = roundedGreen;

            /*image[h][w].rgbtRed = averageRed;
            image[h][w].rgbtBlue = averageBlue;
            image[h][w].rgbtGreen = averageGreen;*/
        }
    }

    for (int q = 0; q < height; q++)
    {
        for (int m = 0; m < width; m++)
        {
            image[q][m].rgbtRed = new[q][m].rgbtRed;
            image[q][m].rgbtBlue = new[q][m].rgbtBlue;
            image[q][m].rgbtGreen = new[q][m].rgbtGreen;
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE edges[height][width];

    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int rGx = 0;
            int rGy = 0;

            int bGx = 0;
            int bGy = 0;

            int gGx = 0;
            int gGy = 0;


            if (h != 0)
            {
                rGy += (-2) * image[h - 1][w].rgbtRed;
                bGy += (-2) * image[h - 1][w].rgbtBlue;
                gGy += (-2) * image[h - 1][w].rgbtGreen;
            }
            if (h != (height - 1))
            {
                rGy += 2 * image[h + 1][w].rgbtRed;
                bGy += 2 * image[h + 1][w].rgbtBlue;
                gGy += 2 * image[h + 1][w].rgbtGreen;
            }
            if (w != 0)
            {
                rGx += (-2) * image[h][w - 1].rgbtRed;
                bGx += (-2) * image[h][w - 1].rgbtBlue;
                gGx += (-2) * image[h][w - 1].rgbtGreen;
            }
            if (w != (width - 1))
            {
                rGx += 2 * image[h][w + 1].rgbtRed;
                bGx += 2 * image[h][w + 1].rgbtBlue;
                gGx += 2 * image[h][w + 1].rgbtGreen;
            }
            if ((w != (width - 1)) && (h != (height - 1)))
            {
                rGx += image[h + 1][w + 1].rgbtRed;
                bGx += image[h + 1][w + 1].rgbtBlue;
                gGx += image[h + 1][w + 1].rgbtGreen;

                rGy += image[h + 1][w + 1].rgbtRed;
                bGy += image[h + 1][w + 1].rgbtBlue;
                gGy += image[h + 1][w + 1].rgbtGreen;
            }
            if ((w != 0) && (h != (height - 1)))
            {
                rGx += (-1) * image[h + 1][w - 1].rgbtRed;
                bGx += (-1) * image[h + 1][w - 1].rgbtBlue;
                gGx += (-1) * image[h + 1][w - 1].rgbtGreen;

                rGy += image[h + 1][w - 1].rgbtRed;
                bGy += image[h + 1][w - 1].rgbtBlue;
                gGy += image[h + 1][w - 1].rgbtGreen;
            }
            if ((w != 0) && (h != 0))
            {
                rGx += (-1) * image[h - 1][w - 1].rgbtRed;
                bGx += (-1) * image[h - 1][w - 1].rgbtBlue;
                gGx += (-1) * image[h - 1][w - 1].rgbtGreen;

                rGy += (-1) * image[h - 1][w - 1].rgbtRed;
                bGy += (-1) * image[h - 1][w - 1].rgbtBlue;
                gGy += (-1) * image[h - 1][w - 1].rgbtGreen;
            }
            if ((w != (width - 1)) && (h != 0))
            {
                rGx += image[h - 1][w + 1].rgbtRed;
                bGx += image[h - 1][w + 1].rgbtBlue;
                gGx += image[h - 1][w + 1].rgbtGreen;

                rGy += (-1) * image[h - 1][w + 1].rgbtRed;
                bGy += (-1) * image[h - 1][w + 1].rgbtBlue;
                gGy += (-1) * image[h - 1][w + 1].rgbtGreen;
            }


            double sqrtRed = sqrt(((float) rGx * (float) rGx) + ((float) rGy * (float) rGy));
            double sqrtBlue = sqrt(((float) bGx * (float) bGx) + ((float) bGy * (float) bGy));
            double sqrtGreen = sqrt(((float) gGx * (float) gGx) + ((float) gGy * (float) gGy));

            int roundedRed = round(sqrtRed);
            int roundedBlue = round(sqrtBlue);
            int roundedGreen = round(sqrtGreen);

            if (roundedRed > 255)
            {
                roundedRed = 255;
            }
            if (roundedBlue > 255)
            {
                roundedBlue = 255;
            }
            if (roundedGreen > 255)
            {
                roundedGreen = 255;
            }

            edges[h][w].rgbtRed = roundedRed;
            edges[h][w].rgbtBlue = roundedBlue;
            edges[h][w].rgbtGreen = roundedGreen;
        }
    }

    for (int q = 0; q < height; q++)
    {
        for (int m = 0; m < width; m++)
        {
            image[q][m].rgbtRed = edges[q][m].rgbtRed;
            image[q][m].rgbtBlue = edges[q][m].rgbtBlue;
            image[q][m].rgbtGreen = edges[q][m].rgbtGreen;
        }
    }

    return;
}
