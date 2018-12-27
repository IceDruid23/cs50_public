#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


//program to calculate change to give
//INPUT: sum to calculate
//OUTPUT: the smallest number of coins needed to give change
int main(void)
{
    double n = 0; //change to give
    char m[20]; // used for float corectness only
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;

    //prompt user for input
    do
    {
        printf("Change owned ");
        scanf("%s", m); // read number as string
        n = atof(m); // convert to string

    }
    while (n <= 0);

    int x = 100 * n;

    quarters = (x / 25);
    x %= 25;

    dimes = (x / 10);
    x = fmod(x, 10);


    nickels = (int) ( x / 5);
    x = fmod(x, 5);

    pennies = (int) ( x / 1 );




    printf("%d\n", quarters + dimes + nickels + pennies);
}
