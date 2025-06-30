#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int h;
    do
    {
        h = get_int("Height: ");
    }
    while (h <= 0);
    int d = h;
    for (int i = 0; i < h; i++)
    {
        int j = 0;
        int k = 1;
        while (k < d)
        {
            printf(" ");
            k++;
        }
        d--;
        while (j <= i)
        {
            printf("#");
            j++;
        }
        printf("\n");
    }
}
