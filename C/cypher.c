#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc == 1)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }


    if (strlen(argv[1]) == 26)
    {
        for(int i = 0; i < 26; i++) {
            if (isalpha(argv[1][i]) == 0) {
                printf("Usage: %s key\n", argv[0]);
                return 1;
            }
            for(int j = i + 1; j < 26; j++) {
                if (argv[1][i] == argv[1][j]) {
                    printf("Usage: %s key\n", argv[0]);
                    return 1;
                }
            }
        }
    }
    else
    {
        printf("Key must contain 26 characters.");
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    for(int i = 0; i < strlen(plaintext); i++) {
        if(plaintext[i] >= 65 && plaintext[i] <= 90) {
            plaintext[i] = argv[1][plaintext[i] - 65];
        } else if (plaintext[i] >= 97 && plaintext[i] <= 122) {
            plaintext[i] = argv[1][plaintext[i] - 97] + 32;
        }
    }

    printf("ciphertext: %s\n", plaintext);
}