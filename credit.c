#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void sum_check(int long long n, char card_type[10]);


int main(void)
{
    int long long card_number = 0;
    int card_lenght;
    int first_two;
    char card_string[50];
    int nDigit;
    int lenStr;

    do
    {
        printf("Number:");
        scanf("%s", card_string);
        card_number = atoll(card_string);
        if (card_number <= 0) continue;

        nDigit = (int) log10(card_number) +1;
        lenStr = strlen(card_string);

    } while ( nDigit != lenStr );

    first_two = 10 * (card_string[0] - 48) + (card_string[1] - 48);
    if ((card_string[0] == '4') && (lenStr == 16 || lenStr==13) )
    {
        sum_check(card_number, "VISA");
        exit(0);
    }

    switch(first_two) {
            case 34:
            case 37:
                if (lenStr == 15)
                {
                sum_check(card_number, "AMEX");
                break;
                }
                else
                {
                    printf("INVALID");
                    break;
                }
            case 51:
            case 52:
            case 53:
            case 54:
            case 55:
                if (lenStr == 16)
                {
                sum_check(card_number, "MasterCard");
                break;
                }
                else
                {
                    printf("INVALID");
                    break;
                }
            default:
                printf("INVALID");

    }
}

    void sum_check(int long long n, char card_type[10])
    {
        int x, sum = 0;
        for (int i = 0; n != 0; n/=10 )
        {
            if (i % 2 == 0)
            {
            sum += (n % 10);
            }
            else
            {
                x = 2 * (n % 10);
                if ( x < 10 )
                {
                    sum += x;
                }
                else
                {
                    sum += (x % 10) + (x / 10);
                }
            }
            i++;

        }
        printf("Sum of digits is: %d\n", sum);

        if ( sum % 10 == 0)
        {
            printf("%s", card_type);
        }
        else
        {
            printf("INVALID");
        }
    }



