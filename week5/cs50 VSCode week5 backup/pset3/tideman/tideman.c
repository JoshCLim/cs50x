#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

//void merge_sort(int length, pair array[]);
bool cycle;
void checkCycle(int source, int end);
void findSource(int start);
int fullWinner;

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        // print ranks
        /*printf("\n-----\nRanks: ");
        for (int m = 0; m < candidate_count; m++)
        {
            printf("%i  ", ranks[m]);
        }
        printf("\n");*/

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }

    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }

    // print preferences
    /*printf("Preferences:\n");
    for (int p = 0; p < candidate_count; p++)
    {
        for (int q = 0; q < candidate_count; q++)
        {
            printf("%i  ", preferences[p][q]);
        }
        printf("\n");
    }*/

    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i]) // i j wins
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (preferences[i][j] < preferences[j][i]) // i j loses
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
            else // equal
            {
                // do nothing
            }
        }
    }

    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    // bubble sort
    int swaps = -1;
    while (swaps != 0)
    {
        swaps = 0;

        for (int q = 0; q < pair_count - 1; q++)
        {
            int currentWinner = pairs[q].winner;
            int currentLoser = pairs[q].loser;
            int currentStrength = preferences[currentWinner][currentLoser];

            int nextWinner = pairs[q + 1].winner;
            int nextLoser = pairs[q + 1].loser;
            int nextStrength = preferences[nextWinner][nextLoser];

            if (currentStrength < nextStrength) // if current strength is less than next strength, then swap
            {
                pair currentPair = pairs[q];
                pair nextPair = pairs[q + 1];

                pairs[q] = nextPair;
                pairs[q + 1] = currentPair;

                swaps++;
            }
        }
    }


    //merge_sort();

    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        int winner = pairs[i].winner;
        int loser = pairs[i].loser;

        cycle = false;

        checkCycle(loser, winner);

        if (cycle == false)
        {
            locked[winner][loser] = true;
        }


    }

    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    int start = pairs[0].loser;

    findSource(start);

    printf("%s\n", candidates[fullWinner]);

    return;
}

/*
void merge_sort(int length, pair pairs[])
{
    pair placeholder[pair_count];

    if (length == 1) // base case
    {
        return;
    }
    else if (length % 2 == 0) // recursion
    {
        merge_sort((length / 2), );

    }
    else if (length % 2 == 1)
    {
        merge_sort((length - 1)/2, );
    }


}
*/


void checkCycle(int source, int end)
{

    if (source == end)
    {
        cycle = true;
    }


    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[source][i] == true)
        {
            checkCycle(i, end);
        }
    }
}

void findSource(int start)
{
    int parentCount = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[i][start] == true)
        {
            findSource(i);
            parentCount++;
        }
    }

    if (parentCount == 0)
    {
        fullWinner = start;
    }
}