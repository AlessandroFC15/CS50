/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
 
int main(int argc, char* argv[])
{
    /* 1st Step
     * Open the card file.
     */
     
    typedef uint8_t BYTE;  
    int files_found = 0;  
    char title [10];
    FILE* output = NULL; 
     
    FILE* card = fopen("card.raw", "r");
    if (card == NULL)
    {
        printf("Could not open card.\n");
        return 1;
    }
    
    BYTE buffer[512];
    
    while (fread(buffer, 512, 1, card) == 1)
    {
        // If it is the beginning of a new file
        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] == 0xe0) || (buffer[3] == 0xe1)))
        {
           // If some jpeg has been found
           if (files_found > 0)
           {
               // Close the current file.
               fclose(output);
           }
           
           // Create a new jpeg file.
           
           sprintf(title, "%03d.jpg", files_found);
               
           output = fopen(title, "w");
               
           fwrite(buffer, 512, 1, output);     
           
           files_found += 1;
           
        } else // If it isn't the start of a new jpeg
        {
            // If we are in the middle of a jpeg file.
            if (files_found > 0)
            {
                fwrite(buffer, 512, 1, output);
            }
        }
    }
    
    fclose(card);
    fclose(output);
    
    return 0;
}