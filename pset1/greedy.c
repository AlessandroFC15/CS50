/**
 * greedy.c
 *
 * Edson Alessandro F. Costa
 * ale-remo@hotmail.com
 *
 * This program first asks the user how much change is owed and then 
 * spits out the minimum number of coins with which said change can be 
 * made.
 */
 
# include <stdio.h>
# include <cs50.h>
# include <math.h>
 
// Prototypes
int count_coins(int change_cents);
 
int main(void)
{
    float change;
    int change_cents;
 
    printf(".: GREEDY ALGORITHM :.");
   
    do 
    {
        printf("\n>> Enter the change: ");
        change = GetFloat();
    } while (change < 0);
    
    // convert the user’s input entirely to cents
    change_cents = roundf(change * 100);
    
    // print the number of coins
    printf("%d\n", count_coins(change_cents));
       
    return 0;
}
 
// FUNCTIONS
 
/*
 * Given the change in cents, returns the minimum number of coins with 
 * which said change can be made.
 */
 
int count_coins(int change_cents)
{
    int num_coins;
    int total_coins = 0;
 
    while (change_cents > 0)
    {
        // Check the number of quarters
        if (change_cents >= 25)
        {
            num_coins = change_cents / 25;
            
            total_coins += num_coins;
            
            change_cents -= num_coins * 25;            
        } 
        // Check the num of dimes
        else if (change_cents >= 10) 
        {
            num_coins = change_cents / 10;
            
            total_coins += num_coins;
            
            change_cents = change_cents - (num_coins * 10);  
        } 
        // Check the num of nickels
        else if (change_cents >= 5) 
        {
            num_coins = change_cents / 5;
            
            total_coins += num_coins;
            
            change_cents = change_cents - (num_coins * 5);
           
        } 
        // Check the num of pennies
        else 
        {     
            total_coins += change_cents;
            change_cents = 0;
        }
    }
    
    return total_coins;
}
 