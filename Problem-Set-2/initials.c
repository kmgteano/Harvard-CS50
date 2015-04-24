/** 
 * initials.c for CS50x Problem Set 2
 * Katrina-Mae Teano | kteano2006@my.fit.edu
 * Get the initials of a name.
 */
 
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

string one_word_initial(string word);

int main(void)
{
    string name = GetString();
    string initials = "";
    string word = "";
    //Loop across the string to find 'words'
    for (int i = 0; i < strlen(name); i++)
    {
        string character = name[i];
        if (isblank(character) == FALSE)
        {
            strcat(word, name[i];
        }
        else
        {
            strcat(initials, one_word_initial(word));
            word = "";
        }
    }
    printf("%s\n", initials);
}

string one_word_initial(string word)
{
    string letter = word[0];
    initial_of_choice = toupper(letter);
    return initial_of_choice;
}
