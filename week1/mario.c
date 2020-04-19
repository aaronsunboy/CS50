#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Asks for height and checks if is between 1 and 8
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    // Each loop is one line
    for (int i = 0; i < height; i++)
    {
        // Print the spaces
        for (int j = 0; j < height - i - 1; j++)
            printf(" ");
        // Print the hash marks
        for (int j = 0; j < i+1; j++)
            printf("#");
        // Print the space in between
        printf("  ");
        // Other side of pyramid
        for (int k = 0; k < i+1; k++)
            printf("#");
        // Next Line
        printf("\n");
    }
}
