#include <stdio.h>
#include <cs50.h>


int main(void)
{
    long long card_num = get_long_long("Card Number: ");
    int check_sum = 0;
    int length = 0;
    int first_num = 0;
    int second_num = 0;

    for (int i = 1; card_num > 0; i++)
    {
        if (card_num < 10)
        {
            first_num = card_num;
        }

        if (card_num < 100)
        {
            second_num = card_num;
        }

        int last_digit = card_num % 10;

        if (i % 2 == 0)
        {
            int product = (last_digit * 2 % 10) + (last_digit * 2 / 10);

            check_sum = check_sum + product;
        }
        else
        {
            check_sum = check_sum + last_digit;
        }

        card_num = card_num / 10;

        length++;
    }

    if (check_sum % 10 == 0)
    {
        if (length == 13 || (length == 16 && first_num == 4))
        {
            printf("VISA\n");
        }
        else if (length == 16 && first_num == 5 && (second_num > 0 && second_num < 6))
        {
            printf("MASTERCARD\n");
        }
        else if(length == 15 && first_num == 3 && (second_num == 4 || second_num == 7))
        {
            printf("AMEX\n");
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

