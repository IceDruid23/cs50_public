#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usafe ./vigenere k\n");
        exit(1);
    }
    char *keyword = argv[1];
    int n =  strlen(keyword);
    int key_index[n];
    int i;
    int j = 0;
    int index, ascii_char;
    char plain_text[100] = {};
    char cipher_text[100] = {};
    for ( i = 0; i < n; i++)
    {
        if isalpha(keyword[i])
        {
            key_index[i] = (toupper(keyword[i]) ) % 65;
        }
        else
        {
            printf("Usage ./vigenere k\n");
            exit(1);
        }
    }

    printf("plaintext:");
    fgets(plain_text, 100, stdin);
    int m;
    for ( i = 0, m = strlen(plain_text); i < m; i++)
    {
        if (isupper(plain_text[i]))
        {
            index = 65;
            ascii_char = (int) plain_text[i] % index;
            cipher_text[i] = (char) index + (ascii_char + key_index[j]) % 26;
            j == n -1 ? j = 0 : j++;
        }
        else if (islower(plain_text[i]))
        {
            index = 97;
            ascii_char = (int) plain_text[i] % index;
            cipher_text[i] = (char) index + (ascii_char + key_index[j]) % 26;
            j == n - 1 ? j = 0 : j++;
        }
        else
        {
            cipher_text[i] = plain_text[i];
        }
    }
            printf("ciphertext: %s", cipher_text);

}