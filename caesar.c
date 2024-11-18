#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Main function takes command-line arguments
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        return 1;
    }
    // Get the length of the command-line argument (key)
    int n = strlen(argv[1]);

    // Validate that the command-line argument is a positive integer
    for (int i = 0; i < n; i++)
    {
        // Check if each character in the argument is a digit
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n"); // Print usage message if validation fails
            return 1;                        // Exit the program
        }
    }

    // If the key is valid, print a confirmation message
    printf("Key is valid\n");

    // Convert the command-line argument to an integer (key for the cipher)
    int key = atoi(argv[1]);

    // Prompt the user to input plaintext for encryption
    string plaintext = get_string("Plaintext: ");

    // Get the length of the plaintext
    int len = strlen(plaintext);

    // Loop through each character in the plaintext
    for (int i = 0; i < len; i++)
    {
        // Check if the character is an alphabetic letter
        if (isalpha(plaintext[i]))
        {
            // Handle uppercase letters
            if (isupper(plaintext[i]))
            {
                // Shift the character by the key and wrap around using modulo
                plaintext[i] = ((plaintext[i] - 'A' + key) % 26) + 'A';
            }
            // Handle lowercase letters
            else if (islower(plaintext[i]))
            {
                // Shift the character by the key and wrap around using modulo
                plaintext[i] = ((plaintext[i] - 'a' + key) % 26) + 'a';
            }
        }
        // Non-alphabetic characters remain unchanged
    }

    // Print the resulting ciphertext after encryption
    printf("ciphertext: %s\n", plaintext);
}
