/*
 * resize.c
 *
 * Anthony Catantan
 * Harvard Computer Science 50
 * Week 4 Problem Set
 *
 * Implements a program that resizes BMPs.
 */

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./copy infile outfile\n");
        return 1;
    }


    // remember filenames
    int factor = atoi(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];

     if(factor <= 0 || factor > 100)
    {
        fprintf(stderr, "Please provide a positiver integer less than or equal to 100.\n");
        return 1;
    }

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // initialized initial width and height as the width and height from infile
    // this is easier than making another variable for new width and height for outfile
    int initialWidth = bi.biWidth;
    int initialHeight = bi.biHeight;

    // because of initialization above, biWidth and biHeight can be safely manipulated (or updated)
    bi.biWidth *= factor;
    bi.biHeight *= factor;


    // determine padding for scanlines
    int initialPadding = (4 - (initialWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int finalPadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // additional update
    // can't be put above padding codes since this needs the padding variables being declared and computed first
    bi.biSizeImage = ((bi.biWidth *sizeof(RGBTRIPLE) + finalPadding) * abs(bi.biHeight));
    bf.bfSize = (bi.biSizeImage + 54);


    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);


    // iterate over infile's scanlines, specifically, the height
    for (int i = 0; i < abs(initialHeight); i++)
    {

        // height has to be recopied *factor times
        for(int j = 0; j < factor; j++)
        {

            // cover remaining padding from infile
            fseek(inptr, (54 + ((initialWidth * 3 + initialPadding) * i)), SEEK_SET);


            // iterate over pixels in scanline, specifically, the width
            for (int k = 0; k < initialWidth; k++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // to write RGB triple *factor times
                for(int l = 0; l < factor; l++)
                {

                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }

            // put padding for outfile
            for (int m = 0; m < finalPadding; m++)
            {
                fputc(0x00, outptr);
            }

        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
