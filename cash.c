#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Define a value of each coin in cents
    int quarters = 25;
    int dimes = 10;
    int nickels = 5;
    int pennies = 1;
    int cash;

    // Promt the user for change required
    do
    {
        cash = get_int("Change: ");
    }
    while (cash < 0);

    // Initialize the count variable to 0, increment everytime it reflect the coin
    int count = 0;
    // Count the number of quarters needed
    while (cash >= quarters)
    {
        cash = cash - quarters;
        count++; // Increment count to reflect the coin used
    }
    // Count the number of dimes needed
    while (cash >= dimes)
    {
        cash = cash - dimes;
        count++;
    }
    // Count the number of nickels needed
    while (cash >= nickels)
    {
        cash = cash - nickels;
        count++;
    }
    while (cash >= pennies)
    // Count the number of pennies needed
    {
        cash = cash - pennies;
        count++;
    }
    // Calculte the total number of count used.
    printf("Coins needed: %i\n", count);
}
