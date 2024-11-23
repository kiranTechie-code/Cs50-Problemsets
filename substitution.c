#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Check command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];
    int key_length = strlen(key);

    // Validate the key length
    if (key_length != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Validate key content
    bool seen[26] = {false};
    for (int i = 0; i < key_length; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }

        int index = tolower(key[i]) - 'a';
        if (seen[index])
        {
            printf("Key must not contain repeated characters.\n");
            return 1;
        }
        seen[index] = true;
    }

    // Get plaintext from user
    string plaintext = get_string("plaintext: ");
    int length = strlen(plaintext);

    // Encrypt the plaintext
    printf("ciphertext: ");
    for (int i = 0; i < length; i++)
    {
        if (islower(plaintext[i]))
        {
            // Handle lowercase letters
            int index = plaintext[i] - 'a';         // Get index of the letter
            char cipher_char = tolower(key[index]); // Substitute using the key
            printf("%c", cipher_char);
        }
        else if (isupper(plaintext[i]))
        {
            // Handle uppercase letters
            int index = plaintext[i] - 'A';         // Get index of the letter
            char cipher_char = toupper(key[index]); // Substitute using the key
            printf("%c", cipher_char);
        }
        else
        {
            // Non-alphabetic characters remain unchanged
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");
    return 0;
}
