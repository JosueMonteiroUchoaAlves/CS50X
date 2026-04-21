#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // every_other_digit_sum = 4 0 0 3 6 0 0 0 0 0 0 0 0 0 1 4
    //                         -   -   -   -   -   -   -   -
    //                         5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 <- counting from zero
    // in this direction
    long card = 0;        
    int size = 0, n, totalSum = 0, firstDigit = 0, secondFirstDigit = 0;
    while (!card)
    {
        card = get_long("Number: ");
    }
    /*
    American Express uses 15-digit numbers, 
    MasterCard uses 16-digit numbers, 
    and Visa uses 13- and 16-digit numbers.
    */

    while (card > 0)
    {
        // I will acess the last item every time I do n % 10 
        n = card % 10;    // get the last number
        card = card / 10; // discard the last number in the card variable

        // if the number is in a odd index (0-indexed)
        if (size % 2 == 1) 
        {
            if (n < 5)
            {
                // a multiplicacao nao tera 2 digitos
                totalSum += n * 2; 
            }
            else
            {
                // primeiro digito + segundo digito
                totalSum += ((n * 2) / 10) + ((n * 2) % 10); 
            }
        }
        else
        {
            totalSum += n;
        }
        // Last digit is now the second and the actual N is the new last digit
        // If the card has like 1 number this will not even matter, so we can cope with an wrong
        // digit the first time...
        secondFirstDigit = firstDigit;
        firstDigit = n;
        size++;
    }

    if (totalSum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    if (firstDigit == 4 && (size == 13 || size == 16))
    {
        printf("VISA\n");
    }
    else if ((firstDigit == 3 && (secondFirstDigit == 4 || secondFirstDigit == 7)) && size == 15)
    {
        printf("AMEX\n");
    }
    else if ((firstDigit == 5 && (secondFirstDigit >= 1 && secondFirstDigit <= 5)) && size == 16)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
    
    return 0;
}
