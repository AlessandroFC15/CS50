/** WORKING VERSION
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include "helpers.h"
 
int smallest_element (int values[], int i, int n);
 
/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if (n <= 0)
    {
        return false;
    }
    
    int lower_bound = 0, higher_bound = n - 1;
    
    while (n >= 1)
    {
        // 1st Step
        // Find the midpoint
        
        int midpoint = (n/2) + lower_bound;
        
        if (value < values[midpoint]) // Go left
        {
            higher_bound = midpoint - 1;
        } else if (value > values[midpoint]) // Go right
        {
            lower_bound = midpoint + 1;
        } else // The value is the midpoint
        {
            return true;
        }     
        
        n = higher_bound - lower_bound + 1;
     }
    
    return false;
}
 
/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // Selection sort
    
    // 1st Step
    // Select the smallest number
 
    for (int i = 0; i < n - 1; i++)
    {
        
        // Find index of the smallest element
        int min_index = smallest_element(values, i, n);
        
        // If the smallest number is not in its right place,
        // we procede to make the swap
        
        // If the min_index is the same number as i, we would
        // be trying to swap the same locations.
        
        if (min_index != i)
        {
            int x = values[i];
            values[i] = values[min_index];
            values[min_index] = x;
        }
        
    }
    return;
}
 
// FUNCTIONS
 
int smallest_element (int values[], int i, int n)
{
    int min_index = i;
 
    for (int j = i + 1; j < n; j++)
    {
        if (values[j] < values[min_index])
        {
            min_index = j;
        }
    }
        
    return min_index;
}