/** 
 * initials.c for CS50x Problem Set 2
 * Katrina-Mae Teano | kteano2006@my.fit.edu
 * Get the initials of a name.
 */
 
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = GetString();
    while (name != NULL)
    {
        int name_length = strlen(name);
        string initials[name_length];
        string word[name_length];
        int word_length = -1;
        int current_initial = -1;
        //Loop across the string to find 'words'
        for (int i = 0; i < name_length; i++)
        {
            // Find current character in name
            char character = name[i];
            // If character is not blank, word is a little longer
            // and character is added to word
            if (!isblank(character))
            {
                word_length = word_length + 1;
                word[word_length] = character;
            }
            // Else, word is over
            // add first initial of word to initials array
            // reset word and its length
            else
            {
                current_initial = current_initial + 1;
                initials[current_initial] = toupper(word[0]);
                word = "";
                word_length = -1;
            }
        }
        printf("%s\n", initials);
    }
}
