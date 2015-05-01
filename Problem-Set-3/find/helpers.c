/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
	
	// return false if n is non-positive
	if (n <= 0)
	{
		return false;
	}
	else
	{
        
        int array_start = 0;
        int array_end = n - 1;
        int array_mid = (array_start + array_end) / 2;
        
        // While we have legal start/end points for array
        while (array_start <= array_end)
        {
            
            // If value is in middle, return
            if (value == values[array_mid])
            {
                return true;
            }
            
            // If value is less than middle
            // set end of next array to before middle
            
            else if (value < values[array_mid])
            {
                array_end = array_mid - 1;
            }
            
            else
            {
                array_start = array_mid + 1;
            }
            
            // If I haven't returned by now, 
            // reset the middle
            
            array_mid = (array_start + array_end) / 2;
        }
        
		// After looping through, if I haven't returned
		// then 'value' isn't here.
		
		return false;
	}
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
	
	// Cycle n-1 times
	for (int i = 0; i < n-1; i++)
	{
		// number of swaps I've done this cycle
		int swaps = 0;
		
		// Work within array to 'bubble' values
		for (int j = 0; j < n-i-1; j++)
		{
			
			// Grab the next value.
			int placeholder = values[j+1];
			
			// If the pair is in the wrong order, swap. 
			if (values[j] > placeholder)
			{
				int swap_pair[2] = {placeholder, values[j]};
				
				values[j] = swap_pair[0];
				values[j+1] = swap_pair[1];
				
				swaps = swaps + 1;
			}
		}
		
		// if I haven't done any swaps, I'm done early
		if (swaps == 0)
		{
			return;
		} 

	}
    return;
}
