#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main (int argc, char * argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar k\n");
        exit(1);
    }
    int k = atoi(argv[1]);
    int index;
    int ascii_char;
    char plain_text[100]={};
    char cipher_text[100]={};
    printf("plaintext: ");
    fgets(plain_text, 100, stdin);
    for (int i = 0, n =strlen(plain_text); i < n; i++)
        {
            if (isupper(plain_text[i]))
            {
                index = 65;
                ascii_char = (int) plain_text[i] % index;
                //printf("%d", ascii_char);
                cipher_text[i] = (char) index + (ascii_char + k) % 26;
                //printf("%c\n", cipher_text[i]);
            }
            else if (islower(plain_text[i]))
            {
                index = 97;
                ascii_char = (int) plain_text[i] % index;
//printf("%d", ascii_char);
                cipher_text[i] = (char) index + (ascii_char + k) % 26;
                //printf("%c\n", cipher_text[i]);
            }
            else
            {
                cipher_text[i] = plain_text[i];
            }
        }


    //printf("key to use %d\n", k);
    printf("ciphertext: %s", cipher_text);
}