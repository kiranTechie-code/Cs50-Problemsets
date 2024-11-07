#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x;
    // Make a mario version wall using hashes
    // We have to promt user for if height is lesser than 1 or greater than 8.
    do
    {
        x = get_int("Height: ");
    }
    while (x < 1 || x > 8);

    for (int i = 0; i < x; i++)
    {
        // For spaces.
        for (int k = 0; k < x - i - 1; k++)
        {
            printf(" ");
        }
        // For Hashes.
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
