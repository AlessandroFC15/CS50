/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/
 
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "dictionary.h"
 
#define SIZE 50000
 
typedef struct node
{
    char word[LENGTH + 1];
    struct node* next; 
} node;
 
 
// Create the hashtable and initialize its pointers to NULL
node* hashtable[SIZE] = {NULL};
int num_words = 0;
 
/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // 1st Step
    // Create a lowercase version of the word.
    
    char lower_word[strlen(word)];
    
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        lower_word[i] = tolower(word[i]);
    }
    
    lower_word[strlen(word)] = '\0';
 
    // 2nd Step
    // Find the right bucket
    int index = hash(lower_word);
    
    // 3rd Step
    // Search the bucket for the word
    node* cursor = hashtable[index];
    
    while (cursor != NULL)
    {
        if (strcmp(cursor->word, lower_word) == 0)
        {
            return true;
        }
        
        cursor = cursor->next;
    }
 
    return false;
}
 
/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    
    // Open the dictionary file
    FILE* dict = fopen(dictionary, "r");
    
    if (dict == NULL)
    {
        fclose(dict);
        return false;
    }
    
    // Iterate through every single word in the dictionary.
    while (true)
    {
        // Assign a new node to every word
        node* new_node = malloc(sizeof(node));
        new_node->next = NULL;
        
        // fscanf will read a word from the dictionary and assign to the new node.
        // The loop will break once there isn't anymore words.
        if (fscanf(dict, "%s", new_node->word) != 1)
        {
            free(new_node);
            break;
        }
        
        // 1st Step = Hash the word and get the index
        int index = hash(new_node->word);
        num_words += 1;
        
        // 2nd Step = Insert into the proper linked list
        
        // 2.1 Find the end of the linked list
        
        // Check to see if it is the first insertion
        if (hashtable[index] == NULL)
        {           
            hashtable[index] = new_node;
        } 
        else
        {
            // Else we're going to loop through the list and find the last
            // node, insert next to it.
            
            // Point the parse to the beginning of the linked list
            node* cursor = hashtable[index];
            
             // While the end of the list has not been reached
            while (cursor->next != NULL)
            {
                cursor = cursor->next;
            }
            
            cursor->next = new_node;          
        }              
    }
    
    fclose(dict);
    return true;
    
}
 
/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return num_words;
}
 
/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // Loop through each linked list
    for (int i = 0; i < SIZE; i++)
    {
        node* cursor = hashtable[i];
        
        while (cursor != NULL)
        {
            node* temp = cursor;
            cursor = cursor->next;
            free(temp);
        }      
    }
    
    return true;
}
 
/**
 * Helper Functions
 *
 */
 
unsigned long hash(char* str) {
 
    unsigned long hash = 5381;
    int c;
    
    while ((c = *str++) != 0)
    {
        hash = ((hash << 5) + hash) + c;
    } /* hash * 33 + c */
    
    return hash % SIZE;
}