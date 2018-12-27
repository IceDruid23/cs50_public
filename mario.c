#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//program to draw a half pyramid
int main(void)
{
    int n = -1; //max number of blocks
    char m[20]; // used for integer corectness only


    //prompt user for input
    do
    {
        printf("Height: ");
        scanf("%s", m); // read number as string
        if (strncmp(m, "0", 1) == 0) // exit if number 0
        {
            break;
        }
        n = atoi(m); // convert to integer

    }
    while (n <= 0 || n > 23);

    //building the pyramid
    for (int i = 0; i < n; i++)
    {
        for (int j = n; j > 0; j--) //first half of pyramid
        {
            j > i + 1 ? printf(" ") : printf("#");
        }

        printf("  ");

        for (int j = 0; j < n; j++) //second half of pyramid
        {
            if (j < i + 1) printf("#");
        }

        printf("\n");
    }
}