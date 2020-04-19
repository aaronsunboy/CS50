#include <stdio.h>
#include <cs50.h>
#include <math.h>

int CountDigits(long number)
{
    int i = 0;
    float a;
    do
    {
        a = number/pow(10, i);
        i++;
    } while (a>=1);
    return i-1;
}

int PlaceFinder(long number, int place)
{
    for (int i=0; i<place-1; i++){
        number /=10;
    }
    return number%10;
}

bool checkLuhn(long number)
{
    int n = CountDigits(number);
    int digit, ndigit = 1;
    int DigitSum = 0;
    int DigitSum_digit;
    bool flag = false;
    do
    {
        digit = PlaceFinder(number, ndigit);
        if (flag) digit = 2 * digit;
        if (digit>=10)
        {
            DigitSum_digit = PlaceFinder(digit,2)+PlaceFinder(digit,1);
            DigitSum += DigitSum_digit;
        } else DigitSum += digit;
        // printf("DigitSum=%i, ndigit=%i, digit=%i\n",DigitSum, ndigit, digit);

        ndigit ++;
        flag = !(flag);
    } while (ndigit <= n);
    if (DigitSum%10 == 0) return true;
    else return false;
}

int main()
{
    long number = get_long("Number: ");
    string card_type="INVALID";
    int n = CountDigits(number); // total number of digits
    int FirstDigit = PlaceFinder(number, n);
    int SecondDigit;
    bool valid = checkLuhn(number);
    if (n>=1) SecondDigit = PlaceFinder(number, n-1);
 
        if (n == 13){
        if (checkLuhn(number) && FirstDigit == 4) 
            card_type = "VISA"; 
        else card_type = "INVALID";
    } else if (n==15){
        if (checkLuhn(number) && FirstDigit == 3 && (SecondDigit ==4 || SecondDigit ==7)) 
            card_type = "AMEX"; 
        else card_type = "INVALID";
    } else if (n==16){
        if (checkLuhn(number)) {
            if (FirstDigit == 4)
                card_type = "VISA"; 
            else if (FirstDigit == 5 && (SecondDigit >=1 && SecondDigit <= 5))
                card_type = "MASTERCARD";
            else card_type = "INVALID";
        } else card_type = "INVALID";
    } else card_type = "INVALID";

    printf("%s\n",card_type); 
}

