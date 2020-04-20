#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool is_positive_int(string s);

int main(int argc, string argv[])
{
    string key = argv[1];
    
    if (argc != 2) //  no or more than one command-line arguments?
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    if (!is_positive_int(key)) // key is not a positive integer
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int key_value = atoi(key);
    key_value = key_value % 26; // handles the case where key > 26
    string text = get_string("plaintext:  ");
    int length = strlen(text);
    string code = text;
    
    for (int i = 0; i < length; i++)
    {
        if (ispunct(text[i]) || text[i] == 32) // when the char is not a letter
        {
            code[i] = text[i];
        }
        else
        {
            code[i] = text[i] + key_value;
            if (!isalpha(code[i])) // when ciphertext is not a letter
            {
                code[i] = code[i] - 26;
            }
        }
    }
    printf("ciphertext: %s\n", code);
}

bool is_positive_int(string s)
{
    // check if s is a positive integer
    int length = strlen(s);
    
    for (int i = 0; i < length; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}