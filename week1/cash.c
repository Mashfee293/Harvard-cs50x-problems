#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    int change;
    do
    {
        change = get_int("Change owed: ");
    }
    while (change <= 0);
    int quarters = change / 25;
    int tens = (change - 25 * quarters) / 10;
    int fives = (change - 25 * quarters - 10 * tens) / 5;
    int ones = (change - 25 * quarters - 10 * tens - 5 * fives) / 1;
    int total = quarters + tens + fives + ones;
    printf("%i\n", total);
}
