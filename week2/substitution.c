#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool is_key_alphabet(string key);

int main(int argc, string argv[])
{
    if (argc != 2) //  no or more than one command-line arguments?
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    if (!is_key_alphabet(key)) // Is the key valid?
    {
        printf("Key must contain 26 letters.\n");
        exit(1);
    }
 
    char upper_key[26];
    char lower_key[26];
    
    for (int j = 0; j < 26; j++)
    {
        if (key[j] <= 122 && key[j] >= 97) //Lowercase
        {
            upper_key[j] = toupper(key[j]); // convert lowercase to uppercase
        }
        else
        {
            upper_key[j] = key[j];
        }
    
        if (key[j] <= 90 && key[j] >= 65) //Uppercase
        {
            lower_key[j] = tolower(key[j]); // convert uppercase to lowercase
        }
        else
        {
            lower_key[j] = key[j];
        }
    }
 
    string text = get_string("plaintext:  ");
    int length = strlen(text);
    string code = text;
    int a, b;
   
    for (int k = 0; k < length; k++)
    {
        if (text[k] <= 122 && text[k] >= 97) 
        {
            a = (int)(text[k]) - 97;
            code[k] = lower_key[a];
        }
        else if (text[k] <= 90 && text[k] >= 65)
        {
            b = (int)(text[k]) - 65;
            code[k] = upper_key[b];
        }
    }
    printf("ciphertext: %s\n", code);
}

bool is_key_alphabet(string key)
{
    // check the validity of the key
    int len = strlen(key);
    if (len != 26) // Is the key of length 26?
    {
        return false;
    }
    for (int i = 0; i < len; i++)
    {
        if (!isalpha(key[i])) // Is every character a letter?
        {
            return false;
        }
        for (int j = 0; j < i; j++)
        {
            if (key[j] == key[i]) // Does any letter repeat?
            {
                return false;
            }
        }
    }
    return true;
}
