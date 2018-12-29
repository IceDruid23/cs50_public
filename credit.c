//PROGRAM TO CALCULATE THE CHECKSUM FOR A CREDIT CARD NUMBER
//BASED ON LUHN'S ALGORITHM
//INPUT: credit card number - digits only
//OUTPUT:
//      if valid: credit type card
//      if not valid print INVALID

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void sum_check(int long long n, char card_type[10]); //function to calculate checksum


int main(void)
{
    int long long card_number = 0;
    int card_lenght;
    int first_two;
    char card_string[50];
    int nDigit;
    int lenStr;
    //check for input corectness -only digits
    do
    {
        printf("Number:");
        scanf("%s", card_string);
        card_number = atoll(card_string);
        if (card_string[0] < '0' || card_string[0] > '9') continue;

        nDigit = (int) log10(card_number) +1;
        lenStr = strlen(card_string);

    } while ( nDigit != lenStr );
    //compare first two digits of credit type number to figure out
    //the type of card
    first_two = 10 * (card_string[0] - 48) + (card_string[1] - 48);
    if ((card_string[0] == '4') && (lenStr == 16 || lenStr==13) )
    {
        sum_check(card_number, "VISA\n");
        exit(0);
    }

    switch(first_two) {
            case 34:
            case 37:
                if (lenStr == 15)
                {
                sum_check(card_number, "AMEX\n");
                break;
                }
                else
                {
                    printf("INVALID\n");
                    break;
                }
            case 51:
            case 52:
            case 53:
            case 54:
            case 55:
                if (lenStr == 16)
                {
                sum_check(card_number, "MASTERCARD\n");
                break;
                }
                else
                {
                    printf("INVALID\n");
                    break;
                }
            default:
                printf("INVALID\n");

    }
}
    //the checksum calculus, valid if last digit of the checksum is 0
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

        if ( sum % 10 == 0)
        {
            printf("%s", card_type);
        }
        else
        {
            printf("INVALID\n");
        }
    }
    //END OF PROGRAM



