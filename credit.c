#include <stdio.h>
#include <cs50.h>
bool check_validity(long long credit_card_number);
bool checksum(long long ccn);
int find_length(long long n);
void print_credit_card_brand(long long ccn);

int main(void)
{
    long long credit_card_number;
    do
    {
        credit_card_number = get_long_long("Number: ");
    }
    while (credit_card_number < 0);

    if (check_validity(credit_card_number) == true)
    {
        print_credit_card_brand(credit_card_number);
    }
    else
    {
        printf("INVALID\n");
    }

}

// Evaluating the credit card number
bool check_validity(long long credit_card_number)
{
    int len = find_length(credit_card_number);
    return (len == 13 || len == 15 || len == 16) && checksum (credit_card_number);
}

// Finding the length
int find_length(long long n)
{
    int len;
    for (len = 0; n != 0; n /= 10, len++);
    return len;
}

// Checksum using Luhn's Algorithm
bool checksum(long long ccn)
{
    int sum = 0;
    for (int i = 0; ccn != 0; i++, ccn /= 10)
    {
        if (i % 2 == 0)
        {
            sum += ccn % 10;
        }
        else
        {
            int digit = 2 * (ccn % 10);
            sum += digit / 10 + digit % 10;
        }
    }
    return (sum % 10) == 0;
}

// Printing the credit card brands
void print_credit_card_brand(long long ccn)
{
    // AMEX
    if ((ccn >= 34e13 && ccn < 35e13) || (ccn >= 37e13 && ccn < 38e13))
    {
        printf("AMEX\n");
    }
    // MASTERCARD
    else if (ccn >= 51e14 && ccn < 56e14)
    {
        printf("MASTERCARD\n");
    }
    // VISA
    else if ((ccn >= 4e12 && ccn < 5e12) || (ccn >= 4e15 && ccn < 5e15))
    {
        printf("VISA\n");
    }
    // IF NONE OF THOSE
    else
    {
        printf("INVALID\n");
    }
}