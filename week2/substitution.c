#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int duplicheck(string input);
string cipher(string input, string command);
int stralpha(string input);
int main(int argc, string argv[])
{
    string pt;
    string command = argv[1];
    if (argc == 2 && stralpha(command) && duplicheck(command))
    {
        pt = get_string("plaintext: ");
        string ciphertext = cipher(pt, command);
        printf("ciphertext: %s\n", ciphertext);
    }
    else if (argc == 1)
    {
        printf("usage: ./substitution key");
        return 1;
    }
    else
    {
        printf("key must be alphabetical and contain 26 charecter");
        return 1;
    }
}
int stralpha(string input)
{
    int n = strlen(input);
    for (int i = 0; i < n; i++)
    {
        if (!isalpha(input[i]) || n != 26)
        {
            return 0;
        }
    }
    return 1;
}
string cipher(string input, string command)
{
    int chcount = strlen(input);
    char *cipherchar = malloc(chcount + 1);
    for (int i = 0; i < chcount; i++)
    {
        int n = (int) input[i];
        if (isupper(input[i]))
        {
            cipherchar[i] = toupper(command[n - 65]);
        }
        else if (islower(input[i]))
        {
            cipherchar[i] = tolower(command[n - 97]);
        }
        else
        {
            cipherchar[i] = input[i];
        }
    }
    cipherchar[chcount] = '\0';
    return cipherchar;
}
int duplicheck(string input)
{
    int n = strlen(input);
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        int charnumber = (int) input[i];
        for (int j = 0; j < n; j++)
        {
            int lowercharnum = (int) tolower(input[j]);
            int uppercharnum = (int) toupper(input[j]);
            if (charnumber == lowercharnum || charnumber == uppercharnum)
            {
                count += 1;
            }
            else
            {
                count += 0;
            }
            if (count >= 2)
            {
                return 0;
            }
        }
    }
    return 1;
}
