/**
 * initials.c
 *
 * Edson Alessandro F. Costa
 * ale-remo@hotmail.com
 *
 * Prompts the user for their name and then outputs their initials 
 * in uppercase.
 */
 
# include <stdio.h>
# include <cs50.h>
# include <string.h>
# include <ctype.h>
 
// Prototypes
void print_initials(string name);
 
int main(void)
{
    string name = GetString();
    
    print_initials(name);
    
    return 0;   
}
 
// FUNCTIONS
 
void print_initials(string name)
{
    /* Printing the first letter, because it is an initial.
     * This assumption is made based on instructions, which said that
     * the user’s input would contain only letters plus single spaces 
     * BETWEEN words.
     */
    printf("%c", toupper(name[0]));
    
    /* We initialize i with 2, because we don't need to check if the 
     * first char is a blank space, we already assumed it is an initial.
     */
    
    for (int i = 2, n = strlen(name); i < n; i++)
    {
        // If the character before was a blank space, then the current
        // char is an initial
        if (strncmp(&name[i - 1], " ", 1) == 0) 
        {
            printf("%c", toupper(name[i]));
        }
    } 
   
    printf("\n");
 
}