#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int sentencecounter(string T);
int wordcounter(string T);
int lettercounter(string T);
int main(void)
{
    string text = get_string("Text: ");
    int letter = lettercounter(text);
    int W = wordcounter(text);
    int sentence = sentencecounter(text);
    // average number of letters per 100 word
    float L = ((float) letter / W) * 100;
    // average number of sentences per 100 words
    float S = ((float) sentence / W) * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(index));
    }
}

int lettercounter(string T)
{
    int letters = 0;
    for (int i = 0; i < strlen(T); i++)
    {
        if (isalpha(T[i]))
        {
            letters += 1;
        }
    }
    return letters;
}
int wordcounter(string T)
{
    int words = 1;
    int count = strlen(T);
    for (int i = 0; i < count; i++)
    {
        if (T[i] == ' ')
        {
            words += 1;
        }
    }
    return words;
}
int sentencecounter(string T)
{
    int sentences = 0;
    int c = strlen(T);
    for (int i = 0; i < c; i++)
    {
        if (T[i] == '.' || T[i] == '?' || T[i] == '!')
        {
            sentences += 1;
        }
    }
    return sentences;
}
