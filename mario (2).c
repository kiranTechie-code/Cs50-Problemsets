#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    int i;
    int space;
    int hashes;
    int gap;
    int hashesright;
    // Promt the user for an input in the range of 1 - 8.
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    // printing spaces.
    for (i = 0; i < height; i++)
    {
        // Space for printing left pyramid.
        for (space = 0; space < height - i - 1; space++)
        {
            printf(" ");
        }
        // For printing left pyramid.
        for (hashes = 0; hashes < i + 1; hashes++)
        {
            printf("#");
        }
        // For the gap between two pyramids.
        for (gap = 0; gap < 2; gap++)
        {
            printf(" ");
        }
        // For printing the right pyramid.
        for (hashesright = 0; hashesright <= i; hashesright++)
        {
            printf("#");
        }
        printf("\n");
    }
}
