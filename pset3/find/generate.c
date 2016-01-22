/***************************************************************************
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 ***************************************************************************/
 
// standard libraries
#define _XOPEN_SOURCE
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
// constant
#define LIMIT 65536
 
int main(int argc, string argv[])
{
    // Tests to see if the user inputed parameters. If the number
    // of parameters is different than 2 and 3, then, the 
    // program finishes.
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }
 
    // Converts the second parameter, the number of random numbers
    // desired to an int, as it is original a string.
    int n = atoi(argv[1]);
 
    // In the case there are 3 parameters, it means that the user
    // inputed the seed and in that case, the input is used as the
    // seed in the srand48 command.
    //
    // Otherwise, if the seed wasn't provided, it will be the time
    // that has passed. 
    //
    // It is necessary to initialize srand48 first, before using
    // drand48.
   
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }
 
    // Prints the n pseudo-random numbers
    // The drand48 function will return a float between 0.0
    // and 1.0, including. Therefore, by multiplying by the limit,
    // we make sure we get a value between 0 and the limit itself.
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }
 
    // success
    return 0;
}