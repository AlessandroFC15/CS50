/**
 * mario.c
 *
 * Edson Alessandro F. Costa
 * ale-remo@hotmail.com
 *
 * This program program recreates the half-pyramid using hashes 
 * (#) for blocks and accepts a maximum height of 23.
 */
 
# include <stdio.h>
# include <cs50.h>
 
// Prototypes
void print_pyramid(int height);
 
int main(void)
{
    int height;
 
    printf(".: HALF-PYRAMID MARIO :.");
    
    do 
    {
        printf("\n>> Enter the half-pyramids height (Max 23): ");
        height = GetInt();
    } while ((height < 0) || (height > 23));
    
    print_pyramid(height);
    
    return 0;
}
 
// FUNCTIONS
 
/*
 * Given the height, prints the half-pyramid.
 */
 
void print_pyramid(int height)
{
    int hashes = 2, blank_spaces = height - 1;
 
    // looping through each row
    for (int i = 0; i < height; i++)
    {
        // printing the blank spaces
        for (int j = 0; j < blank_spaces; j++)
        {
            printf(" ");
        }
 
        // printing the hashes
        for (int j = 0; j < hashes; j++)
        {
            printf("#");
        }
 
        hashes += 1;
        blank_spaces -= 1;
        printf("\n");
    }
}