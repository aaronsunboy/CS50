#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    int coins = 0;
    float dollars;
    // Asks for amount of money
    do
    {
        dollars = get_float("Change owed: ");
    } while (dollars <= 0);

    // Changes dollars to cents
    int cents = round(dollars * 100);
    // Does operation with quarters
    coins = cents/25 + coins;
    cents = cents%25;
    // Does operation with dimes
    coins = cents/10 + coins;
    cents = cents%10;
    // Does operation with nickels
    coins = cents/5 + coins;
    cents = cents%5;
    // Does operation with pennies
    coins = coins + cents;
    // Prints final amount of coins
    printf("%i\n", coins);
}
