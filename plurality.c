#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 9 // Maximum number of candidates

// Candidate structure: holds the name and vote count of each candidate
typedef struct
{
    string name; // Candidate's name
    int votes;   // Number of votes received
} candidate;

// Function prototypes
bool vote(string name);
void print_winner(void);

// Array of candidates and the total number of candidates
candidate candidates[MAX];
int candidate_count;

int main(int argc, string argv[])
{
    // Check for invalid usage
    candidate_count = argc - 1;
    if (argc < 2)
    {
        printf("Usage: plurality [candidates...]\n");
        return 1;
    }

    // Ensure the number of candidates does not exceed the maximum limit
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    // Initialize candidates from command-line arguments
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1]; // Assign name from arguments
        candidates[i].votes = 0;          // Initialize votes to 0
    }

    // Prompt user for the number of voters
    int voter_count = get_int("Number of voters: ");

    // Loop over all voters to collect their votes
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: "); // Get the voter's choice

        // Check if the vote is valid
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Print the winner(s) of the election
    print_winner();
}

// Update vote totals for a valid candidate
bool vote(string name)
{
    // Iterate through the list of candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // Compare the input name with each candidate's name
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++; // Increment vote count if matched
            return true;
        }
    }
    return false; // Return false if no match is found
}

// Print the winner(s) of the election
void print_winner(void)
{
    int max_votes = 0; // Variable to track the highest vote count

    // Determine the maximum number of votes received
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    // Print all candidates who received the maximum votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}
