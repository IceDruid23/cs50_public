/* Program to implement 'Caesar cipher' --
 --rotate eack letter by k positions
INPUT: plain text
OUTPUT: cypher text
Note: lower letters remain lower and upper letters remain upper
      Characters that are not letters remain unchanged
ALGORITHM:
    1)program accepts the number of positions to shift as command line
    argument;
    1b)accept plaintext from user
    2)use an indexed version of letters: A(65 ascii) or a(97 ascii) become 0
    A/a= 0, B,b=1, C,c=2  and so on.
    3)calculate the encrypted value
    4)add to the encrypted string the ascii equivalent of the indexed encrypted letter.
    5)Output the encrypted message.
Usage: ./caesar k - k is the number of positions to shift */


//START OF PROGRAM
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        exit(1);
    }
    int k = atoi(argv[1]); //positions to shift
    int index; //memorizes if letter is lower or upper before transforming letter to index
    int ascii_char; //indexed value of letter
    char plain_text[100] = {};
    char cipher_text[100] = {};
    printf("plaintext: ");
    fgets(plain_text, 100, stdin);
    for (int i = 0, n = strlen(plain_text); i < n; i++)
    {
        if (isupper(plain_text[i]))
        {
            index = 65;
            ascii_char = (int) plain_text[i] % index;
            cipher_text[i] = (char) index + (ascii_char + k) % 26;
        }
        else if (islower(plain_text[i]))
        {
            index = 97;
            ascii_char = (int) plain_text[i] % index;
            cipher_text[i] = (char) index + (ascii_char + k) % 26;
        }
        else
        {
            cipher_text[i] = plain_text[i];
        }
    }
    printf("ciphertext: %s", cipher_text);
}
//END OF PROGRAM