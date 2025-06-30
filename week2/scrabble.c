#include <cs50.h>
#include <stdio.h>
#include <string.h>

int scorecounter(string word);

int main(void)
{
    string word1 = get_string("Player1: ");
    string word2 = get_string("Player2: ");
    int score1 = scorecounter(word1);
    int score2 = scorecounter(word2);
    if (score1 > score2)
    {
        printf("Player 1 Wins!");
    }
    else if (score1 == score2)
    {
        printf("Tie");
    }
    else
    {
        printf("Player 2 Wins!");
    }
    printf("\n");
}

int scorecounter(string word)
{
    int score = 0;
    int lettercount = strlen(word);
    for (int i = 0; i < lettercount; i++)
    {
        if (word[i] == 'A' || word[i] == 'a' || word[i] == 'E' || word[i] == 'e' ||
            word[i] == 'I' || word[i] == 'i' || word[i] == 'O' || word[i] == 'o' ||
            word[i] == 'U' || word[i] == 'u' || word[i] == 'L' || word[i] == 'l' ||
            word[i] == 'N' || word[i] == 'n' || word[i] == 'R' || word[i] == 'r' ||
            word[i] == 'S' || word[i] == 's' || word[i] == 'T' || word[i] == 't')
        {
            score += 1;
        }
        else if (word[i] == 'D' || word[i] == 'd' || word[i] == 'G' || word[i] == 'g')
        {
            score += 2;
        }
        else if (word[i] == 'B' || word[i] == 'b' || word[i] == 'C' || word[i] == 'c' ||
                 word[i] == 'M' || word[i] == 'm' || word[i] == 'P' || word[i] == 'p')
        {
            score += 3;
        }
        else if (word[i] == 'F' || word[i] == 'f' || word[i] == 'H' || word[i] == 'h' ||
                 word[i] == 'V' || word[i] == 'v' || word[i] == 'W' || word[i] == 'w' ||
                 word[i] == 'Y' || word[i] == 'y')
        {
            score += 4;
        }
        else if (word[i] == 'K' || word[i] == 'k')
        {
            score += 5;
        }
        else if (word[i] == 'J' || word[i] == 'j' || word[i] == 'X' || word[i] == 'x')
        {
            score += 8;
        }
        else if (word[i] == 'Q' || word[i] == 'q' || word[i] == 'Z' || word[i] == 'z')
        {
            score += 10;
        }
        else
        {
            score += 0;
        }
    }
    return score;
}
