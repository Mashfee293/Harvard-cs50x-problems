#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int master_card(long input);
int visa(long input, int inputs_digit);
int american_express(long input);
int single_digit_sum(long input, int inputs_digit);
int double_digit_sum(long input, int inputs_digit);
int main(void)
{

    string numbers = get_string("Your card number: ");
    int digit = strlen(numbers);
    long number = atol(numbers);
    if (digit == 13 || digit == 15 || digit == 16)
    {
        int sum = double_digit_sum(number, digit);
        int sum2 = single_digit_sum(number, digit);
        int wholesum = sum + sum2;
        if (wholesum % 10 == 0)
        {
            if (digit == 15 && american_express(number))
            {
                printf("AMEX\n");
            }
            else if (visa(number, digit))
            {
                printf("VISA\n");
            }
            else if (digit == 16 && master_card(number))
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int double_digit_sum(long input, int inputs_digit)
{
    int sum = 0;
    for (long i = 0, j = 100; i < inputs_digit; i = i + 2, j = j * 100)
    {
        long k = j / 10;
        long l = ((input % j) / k) * 2;
        if (l < 10)
        {
            sum = sum + l;
        }
        else if (l >= 10)
        {
            sum = sum + (l / 10) + (l % 10);
        }
    }
    return sum;
}

int single_digit_sum(long input, int inputs_digit)
{
    int sum = 0;
    for (long i = 0, j = 10; i < inputs_digit; i += 2, j *= 100)
    {
        long k = j / 10;
        int l = ((input % j) / k);
        sum = sum + l;
    }
    return sum;
}

int american_express(long input)
{
    if (input / 10000000000000 == 37 || input / 10000000000000 == 34)
    {
        return 1;
    }
    return 0;
}

int visa(long input, int inputs_digit)
{
    if (inputs_digit == 13 && input / 1000000000000 == 4)
    {
        return 1;
    }
    else if (inputs_digit == 16 && input / 1000000000000000 == 4)
    {
        return 1;
    }
    return 0;
}

int master_card(long input)
{
    int numbers[5] = {51, 52, 53, 54, 55};
    for (int i = 0; i < 6; i++)
    {
        if (input / 100000000000000 == numbers[i])
        {
            return 1;
        }
    }
    return 0;
}
