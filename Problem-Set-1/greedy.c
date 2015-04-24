/** 
 * greedy.c for CS50x Problem Set 1
 * Katrina-Mae Teano | kteano2006@my.fit.edu
 * Given a float money amount, use greedy algorithm
 * to give change of that amount
 */
 
// include libraries: Standard IO, CS50, and C Math
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Ask for money amount
    printf("O hai! How much change is owed?\n");
    float change_owed = GetFloat();
    // Check that money amount is legitimate
    if (change_owed == 0)
    {
        return 0;
    }
    while (change_owed < 0)
    {
        printf("Retry: ");
        change_owed = GetFloat();
    }
    
    // Convert to cents and round accordingly
    int cents = (int) round(100 * change_owed);

    // number of quarters
    int quarters = cents / 25;
    cents = cents % 25;
    
    // number of dimes
    int dimes = cents / 10;
    cents = cents % 10;
        
    // number of nickels
    int nickels = cents / 5;
    cents = cents % 5;
    
    // pennies left
    int pennies = cents;
    
    // output
    printf("%i\n", quarters + dimes + nickels + pennies);
}
