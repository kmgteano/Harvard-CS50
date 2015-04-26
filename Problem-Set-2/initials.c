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
    if (name != NULL)
    {
        int name_length = strlen(name);
        char initials[name_length];
        int current_initial = 0;
		// First initial is always at index 0 of name
		initials[current_initial] = (char) toupper( (int) name[0] ); 
        //Loop across the string to find 'words'
        for (int i = 0; i < name_length; i++)
        {
            // Find current character in name
            char character = name[i];
            // If character is blank, we found the start of another word
            if (isblank(character))
            {
				// The next initial is the character after the space.
                current_initial = current_initial + 1;
                initials[current_initial] = (char) toupper( (int) name[i + 1]);
            }
        }
        printf("%s\n", initials);
    }
	else
	{
		printf("Null passed through getString. Aborting.");
	}	
}
