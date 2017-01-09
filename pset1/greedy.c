#include <stdio.h>
#include <cs50.h>
#include <math.h>
int main (void)
{
         float n;
       do 
       {
         printf("plesae enter your change in dollars\n");
         n = GetFloat();
         if (n <= 0) 
              printf("please enter positive value!\n");
       }
       while (n <= 0);
          
         int numOfCoins = 0;
         int in_cents;
         in_cents = roundf((n*100));
         
    while ( in_cents >= 25)
      {
          in_cents = in_cents - 25;
          numOfCoins = numOfCoins + 1;
      }  
    while ( in_cents >= 10)
     {
          in_cents = in_cents - 10;
          numOfCoins = numOfCoins + 1;
     }
    while ( in_cents >= 5)
     {
          in_cents = in_cents - 5;
          numOfCoins = numOfCoins + 1;
     }
    while ( in_cents > 0)
    {
          in_cents = in_cents - 1;
          numOfCoins = numOfCoins + 1;
    }
     printf("%d\n", numOfCoins);
}
