#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strnum(string input);
string ct(int num, string text);
int main(int argc, string argv[])
{
    string prek = argv[1];
    if (argc == 2 && strnum(prek))
    {
        int k = atoi(prek) % 26;
        string pt = get_string("plaintext: ");
        string cipher_text = ct(k, pt);
        printf("ciphertext: %s\n", cipher_text);
    }
    else if (argc == 1)
    {
        printf("usage: ./caesar key\n");
        return 1;
    }
    else
    {
        printf("Error: more than one command line is not allowed and command line should be a  "
               "decimal");
        return 1;
    }
}

string ct(int num, string text)
{
    int n = 0;
    int l = strlen(text);
    char *cipher = malloc(l + 1);
    for (int i = 0; i < l; i++)
    {
        if (isalpha(text[i]))
        {
            char ch = text[i];
            if (isupper(ch))
            {
                n = 65;
            }
            else
            {
                n = 97;
            }
            int p = (int) ch - n;
            int c = (p + num) % 26;
            text[i] = n + c;
            cipher[i] = text[i];
        }
        else
        {
            cipher[i] = text[i];
        }
    }
    cipher[l] = '\0';
    return cipher;
}
int strnum(string input)
{
    int n = strlen(input);
    for (int i = 0; i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            return 0;
        }
    }
    return 1;
}
