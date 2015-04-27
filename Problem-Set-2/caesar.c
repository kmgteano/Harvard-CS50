/**
 * caesar.c for CS50x Problem Set 2
 * Katrina-Mae Teano | kteano2006@my.fit.edu
 * do the Caesar cipher for a specified integer value
 * on a given string
 */
 
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // Checking if the argument passed in is legitimate
    // if legitimate, calculate k.

    // Too many arguments, throw error
    if (argc != 2)
    {
        printf("Incorrect number of arguments, aborting.\n");
        return 1;
    }    
    else
    {
        string argument = argv[1];
        int arg_len = strlen(argument);   
        
        // Check non-numerical argument
        for (int i = 0; i < arg_len; i++)
        {

            // Get current character in argument; cast as int ASCII value
            char arg_char = argument[i];
            int arg_int = (int) arg_char; 
        
            // if outside of ASCII digits, throw error
            if (!isdigit(arg_int))
            {
                printf("Non-numerical input. Aborting.\n");
                return 1;
            }
        }
        
        int key = atoi(argument) % 26;
    
        // Get string from user
        string message = GetString();
        int msg_len = strlen(message);
        char ciphertext[msg_len];
        
        for (int j = 0; j < msg_len; j++)
        {
            char msg_char = message[j];
            int msg_int = (int) msg_char;
            
            // Case 1: capital letter.
            if (isupper(msg_int))
            {
                // get ASCII value of cipher letter
                // and add to ciphertext
                int cip_int = ( (msg_int - 64 + key) % 26) + 64;
                ciphertext[j] = (char) cip_int;
            }
            
            // Case 2: lowercase letter
            else if (islower(msg_int))
            {
                int cip_int = ( (msg_int - 96 + key) % 26) + 96;
                ciphertext[j] = (char) cip_int;
            }
            
            // Case 3: not a letter
            else
            {
                ciphertext[j] = msg_char;
            }
        }
        
        // End ciphertext and print
        ciphertext[msg_len] = (char) 0;
        printf("%s\n", ciphertext);
    }
    
}
