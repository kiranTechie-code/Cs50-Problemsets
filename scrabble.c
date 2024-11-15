#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Initialize total scores for both players
    int total_score1 = 0;
    int total_score2 = 0;

    // Score table for each letter (a-z)
    int scores[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    // Prompt players for their words
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    // Calculate score for Player 1
    int n = strlen(player1);
    for (int i = 0; i < n; i++)
    {
        if (isalpha(player1[i]))
        {
            player1[i] = tolower(player1[i]); // Convert to lowercase
            int index = player1[i] - 'a';     // Calculate index in score array
            int score1 = scores[index];       // Get score from array
            total_score1 += score1;           // Add to total score
        }
    }

    // Calculate score for Player 2
    int m = strlen(player2);
    for (int i = 0; i < m; i++)
    {
        if (isalpha(player2[i])) // isalpha is used to check if a character is an alphabetic letter
        {
            player2[i] = tolower(player2[i]); // Convert to lowercase
            int index = player2[i] - 'a';     // Calculate index in score array
            int score2 = scores[index];       // Get score from array
            total_score2 += score2;           // Add to total score
        }
    }

    // Determine and print the winner
    if (total_score1 > total_score2)
    {
        printf("Player 1 wins\n");
    }
    else if (total_score2 > total_score1)
    {
        printf("Player 2 wins\n");
    }
    else
    {
        printf("Tie\n");
    }
}
