#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int count = 0;
    // Count of digits in the credit card number

    long long credit;
    // Store credit card number

    int digit = 0;
    // Store the current digit

    int sum = 0;
    // Temporary sum for digits > 9

    int total_sum = 0;
    // Total sum for Luhn's Algorithm

    credit = get_long_long("Credit card number: ");
    // Prompt user for credit card number

    long long original_credit = credit;
    // Store the original card number for checks

    while (credit > 0)
    {
        digit = credit % 10;
        // Extract the last digit

        credit /= 10;
        // Remove the last digit

        count++;
        // Increment digit count

        if (count % 2 == 0)
        // Check every second digit from right to left
        {
            digit *= 2;
            // Double the digit

            if (digit > 9)
            // If doubled value is greater than 9
            {
                sum = digit % 10 + digit / 10;
                // Add digits of the result

                total_sum += sum;
                // Add to the total sum
            }
            else
            {
                total_sum += digit;
                // Add directly if single digit
            }
        }
        else
        {
            total_sum += digit;
            // Add directly for non-doubled digits
        }
    }

    long long n = original_credit;
    // Get the first digit of the card number
    while (n >= 10)
    // Keep reducing until first digit
    {
        n /= 10;
    }
    int first_digit = n;
    // Store the first digit

    long long m = original_credit;
    // Get the first two digits of the card number
    while (m >= 100)
    // Keep reducing until first two digits
    {
        m /= 10;
    }
    int first_two_digits = m;
    // Store the first two digits

    if (total_sum % 10 == 0)
    // Luhn's Algorithm check for validity
    {
        if ((first_two_digits == 34 || first_two_digits == 37) && count == 15)
        {
            printf("AMEX\n");
            // AMEX: Starts with 34 or 37, 15 digits
        }
        else if (first_two_digits >= 51 && first_two_digits <= 55 && count == 16)
        {
            printf("MASTERCARD\n");
            // MasterCard: Starts with 51-55, 16 digits
        }
        else if (first_digit == 4 && (count == 13 || count == 16))
        {
            printf("VISA\n");
            // VISA: Starts with 4, 13 , 16 digits
        }
        else
        {
            printf("INVALID\n");
            // Invalid card: Doesn't match any known type
        }
    }
    else
    {
        printf("INVALID\n");
        // Invalid card: Luhn's check fails
    }
}
