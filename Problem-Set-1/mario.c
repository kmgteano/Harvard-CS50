/** 
 * mario.c for CS50x Problem Set 1
 * Katrina-Mae Teano | kteano2006@my.fit.edu
 * Given an integer height 1 <= height <= 23
 * print a half pyramid of hashes that height
 */
 
 // include standard IO and CS50 libraries
#include <stdio.h>
#include <cs50.h>
 
int main(void)
{
    // Ask for height
    printf("height: ");
    int height = GetInt();
    // Check if height is in allowed values
    if (height == 0)
    {
        return 0;
    }
    while (height < 1 || height > 23)
    {
        printf("Retry: ");
        height = GetInt();
    }
    for (int row = 1; row <= height; row++)
    // looping for each row
    {
        // How many hashes and spaces do we need for this row?
        int hashes = row + 1;
        int spaces = height - row;
        // printing out the right number of hashes and spaces
        if (spaces > 0)
        {
            for (int i = 1; i <= spaces; i++)
            {
                printf(" ");
            }
        }
        for (int j = 1; j <= hashes; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
