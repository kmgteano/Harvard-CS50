/**
 * vigenere.c for CS50x Problem Set 2
 * Katrina-Mae Teano | kteano2006@my.fit.edu
 * do the Vigenere cipher for a specified keyword value
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
    
    string argument = argv[1];
    int arg_len = strlen(argument);

    // Too many arguments, throw error
    if (argc != 2)
    {
        printf("Incorrect number of arguments, aborting.\n");
        return 1;
    }
    else
    {
        for (int i = 0; i < arg_len; i++)
        {
            if (!isalpha(argument[i]))
            {
                printf("Non-alphabetic keyword, aborting.\n");
                return 1;
            }
        }

        int key_len = strlen(argument);
        
        // Turn keyword into array of integers
        
        int key_array[key_len];
        for (int j = 0; j < key_len; j++)
        {
            key_array[j] = ( (int) toupper(argument[j]) ) - 65;
        }
        
        // Ask for message
        
        string message = GetString();
        int msg_len = strlen(message);
        int key_index = 0;
        string ciphertext = "";
        
        for (int k = 0; k < msg_len; k++)
        {
            
            // Case 1: non-alphabetical. 
            if (!isalpha(message[k]))
            {
                ciphertext[k] = message[k];
            }
            
            // Case 2: uppercase. 
            else if (isupper(message[k]))
            {
                int cip_int = ( (msg_int - 64 + key_array[key_index]) % 26) + 64;
                ciphertext[j] = (char) cip_int;
                
                // Advance index of key, but wrap if necessary. 
                key_index = (key_index + 1) % key_len;
            }
            
            // Case 3: lowercase.
            else 
            {
                int cip_int = ( (msg_int - 96 + key_array[key_index]) % 26) + 96;
                ciphertext[j] = (char) cip_int;
                
                key_index = (key_index + 1) % key_len;
            }
        }
        
        ciphertext[msg_len] = (char) 0;
        printf("%s\n", ciphertext);
    }
}
