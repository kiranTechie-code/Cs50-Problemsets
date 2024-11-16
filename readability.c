#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Initialize counters for letters, words, and sentences
    int sentence_count = 0;
    int word_count = 1; // Start at 1 because the last word doesn't end with a space
    int letter_count = 0;

    // Prompt the user for input text
    string text = get_string("Text: ");

    // Calculate the length of the input string
    int text_length = strlen(text);

    // Iterate through each character in the text
    for (int i = 0; i < text_length; i++)
    {
        // Count alphabetic characters as letters
        if (isalpha(text[i]))
        {
            letter_count++;
        }
        // Count spaces to calculate the number of words
        else if (text[i] == ' ')
        {
            word_count++;
        }
        // Count sentence-ending punctuation marks
        else if (text[i] == '?' || text[i] == '!' || text[i] == '.')
        {
            sentence_count++;
        }
    }

    // Calculate the average number of letters per 100 words (L)
    float average_letters = (float) letter_count / word_count * 100;

    // Calculate the average number of sentences per 100 words (S)
    float average_sentences = (float) sentence_count / word_count * 100;

    // Compute the Coleman-Liau index
    float readability_index = 0.0588 * average_letters - 0.296 * average_sentences - 15.8;

    // Determine the grade level based on the index
    if (readability_index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (readability_index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        // Round the index to the nearest whole number and print
        printf("Grade %i\n", (int) round(readability_index));
    }
}
