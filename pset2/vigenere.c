/**
 * vigenere.c
 *
 * Edson Alessandro F. Costa
 * ale-remo@hotmail.com
 *
 * A program that encrypts messages using Vigenère’s cipher.
 */
 
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
 
void encipher_char(char letter, int k);
void enciphered_message(string text, string keyword);
 
int main(int argc, string argv[])
{
    if (argc != 2)
    {      
        printf(">> Program finished.\n"); 
        return 1;
    }
    
    string keyword = argv[1];
    
    // Checks if the keyword is composed entirely of alphabetical 
    // characters
 
    for (int i = 0, n = strlen(keyword); i < n; i++)
    {
        if (!isalpha(keyword[i]))
        {
            printf(">> Program finished.\n"); 
            return 1;       
        }     
    }
    
    string text = GetString();
    
    enciphered_message(text, keyword);
  
    return 0;
}
 
// FUNCTION
 
/*
 * This function will print the enciphered char, given an letter and the key.
 */
 
void encipher_char(char letter, int k)
{
    int position = tolower(letter) - 97;
 
    int new_position = (position + k) % 26;
    
    // If the char was uppercase
    if (isupper(letter))
    {
        letter = toupper((char) (97 + new_position)); 
        printf("%c", letter); 
    } 
    else 
    {
        letter = (char) (97 + new_position);    
        printf("%c", letter); 
    }           
}
 
/*
 * Function that takes a string and a keyword, and prints the enciphered
 * message, using the helper function encipher_char, to encipher each one
 * of the string's char.
 */
 
void enciphered_message(string text, string keyword)
{
    int key_counter = 0;
    
    for (int i = 0, n = strlen(text), len_key = strlen(keyword); i < n; i++)
    {
        // The char will only be changed if it is a letter
        if (isalpha(text[i]))
        {
            // Find out the position related to the letter in the keyword
            // Like 'a' is 0, 'b' is 1, and etc.
 
            int key_letter_position = tolower(keyword[key_counter]) - 97;
        
            encipher_char(text[i], key_letter_position);
            
            // The key counter will only increase if it is a letter
            key_counter = (key_counter + 1) % len_key;
        }
        else
        {
            printf("%c", text[i]); 
        }  
    } 
    
    printf("\n");
}