#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string key);
char rotate(char letter, int key);

int main(int argc, string argv[])
{
    //Checks that a key was entered and that no other keys were entered afterwards
    if (!argv[1] || argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //Checks that key entered is a digit
    bool digit = only_digits(argv[1]);
    if (digit)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //Converts argv[1] from a string to an intiger
    int int_argv = atoi(argv[1]);

    //Gets a plaintext string from the user
    string plaintext = get_string("Plaintext: ");

    //Initialises ciphertext array and builds array with rotated characters
    char ciphertext[strlen(plaintext)];

    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char cipher_char = rotate(plaintext[i], int_argv);
        ciphertext[i] = cipher_char;
    }

    //Indicates end of array using the null terminator and prints ciphered text
    ciphertext[strlen(plaintext)] = '\0';
    printf("ciphertext: %s\n", (string)ciphertext);
    return 0;
}

//Checks that argv[1] is a digit and returns a boolean
bool only_digits(string key)
{
    bool is_digit;

    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (isdigit(key[i]) != 0)
        {
            is_digit = false;
        }
        else
        {
            is_digit = true;
        }
    }
    return is_digit;
}


//Rotates individual characters of the plain text string
char rotate(char letter, int key)
{
    int rotated_char;

    if (isalpha(letter))
    {
        rotated_char = (int)letter;

        for (int i = 0; i < key; i++)
        {
            if ((char)rotated_char == 'z' || (char)rotated_char == 'Z')
            {
                rotated_char -= 25;
            }
            else if (isalpha(rotated_char))
            {
                rotated_char++;
            }
        }
    }
    else
    {
        rotated_char = letter;
    }
    return (char)rotated_char;
}