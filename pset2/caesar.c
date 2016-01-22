/**
 * caesar.c
 *
 * Edson Alessandro F. Costa
 * ale-remo@hotmail.com
 *
 * A program that encrypts messages using Caesar’s cipher.
 */
 
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
 
void encipher(string text, int k);
 
int main(int argc, string argv[])
{ 
    if (argc != 2)
    {   
        printf(">> Program finished.\n");
        return 1;
    }
    
    // Get the key
    int k = atoi(argv[1]);
 
    // Get the string
    string text = GetString();
    
    // Encipher
    encipher(text, k);
    
    printf("%s\n", text);
    
    return 0;
}
 
// FUNCTIONS
 
void encipher(string text, int k)
{
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // The char will only be changed if it is a letter
        if (isalpha(text[i]))
        {
            /* 1st Step
             * Discover what position the letter is in the alphabet 
             * (0 to 26). All letters will be considered lowercase, 
             * to make the calculation easier.
             * The 97 is for the ASCII Code for 'a'.
             */
            int position = tolower(text[i]) - 97;
            
            /* 2nd Step
             * Use the formula to find out the new position
             */
            int new_position = (position + k) % 26;
            
            // Because we considered all letters was lowercase earlier,
            // we must check now if the letter is uppercase or not. 
            
            if (isupper(text[i]))
            {
                text[i] = toupper((char) (97 + new_position));
                
            } 
            else 
            {
                text[i] = (char) (97 + new_position);
            }           
        }   
    }
}