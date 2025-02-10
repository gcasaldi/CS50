/*
 * recover.c
 *
 * Anthony Catantan
 * Harvard Computer Science 50
 * Week 4 Problem Set
 *
 * Implements a program that recovers JPEGs from a forensic image.
 */

#include <stdio.h>

int main(int argc, char *argv[])
{

    //ensure proper usage
    if(argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // initialization and remembering filenames
    unsigned char buffer[512] = {0};
    char filename[8] = {0};
    int counter = 0;

    // open input and output file
    // set output file to NULL as of now
    FILE *inptr = fopen(argv[1], "r");
    FILE *outptr = NULL;

    // ensure safety in opening input file
    if(inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }

    // initialize loop
    while(fread(buffer, sizeof(buffer), 1, inptr) == 1)
    {

        // find JPEG
        if(buffer[0] == 0xff && buffer [1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
        {

            // correct filenaming of recovered JPEGs
            sprintf(filename, "%03d.jpg", counter);

            // opening and reinitialization of output file
            outptr = fopen(filename, "w");

            // writing recovered JPEG to output file by block
            fwrite(buffer, sizeof(buffer), 1, outptr);

            // increase counter and filename order
            counter++;

        }

        else

        {
            // continue to read and write to buffer if it is not beginning of file
            if(outptr != NULL)
            {
                fwrite(buffer, sizeof(buffer), 1, outptr);
            }
        }
    }

    fclose(outptr);
    fclose(inptr);

    return 0;
}