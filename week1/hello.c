#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Asks for name
    string name = get_string("What is your name?\n");
    // Says hello to person
    printf("Hello, %s\n", name);
}
