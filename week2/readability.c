#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int count_letters(string s);
int count_words(string s);
int count_sentences(string s);

int main(void)
{
    int nletters, nwords, nsentences;
    int index;

    string s = get_string("Text: ");
    nletters = count_letters(s);
    nwords = count_words(s);
    nsentences = count_sentences(s);

    int grade = round(0.0588 * (nletters * 100 / nwords) - 0.296 * (nsentences * 100 / nwords) - 15.8);

    // Prints grade
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string s)
{
    // Counts the number of letters in string s
    int nletters = 0;
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        // checks if the character is a lower or uppercase letter
        if ((s[i] <= 122 && s[i] >= 97) || (s[i] <= 90 && s[i] >= 65))
        {
            nletters++;
        }
    }
    //printf("%d letter(s)\n", nletters);
    return nletters;
}

int count_words(string s)
{
    // Counts the number of words in string s
    int nwords = 1;
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        // checks if the character is a space, or apostraphe
        // if apostraphe, check if s is behind it
        if (s[i] == 32 || (s[i] == 39 && !(s[i + 1] == 115)))
        {
            nwords++;
        }
    }
    //printf("%d word(s)\n", nwords);
    return nwords;
}

int count_sentences(string s)
{   
    // Counts the number of sentences in string s
    int nsentences = 0;
    int length = strlen(s);
    for (int i = 0; i < length; i++)
    {
        // checks if the character is a period, exclamation mark, or question mark
        if (s[i] == 46 || s[i] == 33 || s[i] == 63)
        {
            nsentences++;
        }
    }
    //printf("%d sentence(s)\n", nsentences);
    return nsentences;
}