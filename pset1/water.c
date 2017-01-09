#include <stdio.h>
#include <cs50.h>
int main (void)
{
 int n;
 do
   {
    printf ("Please state your shower duration in minutes\n");
    n = GetInt();
   }
   while (n < 1);
   int x;
     {
       x = n*192/16;
       
       printf("your number of bottles is %i\n", x);
     }
}

