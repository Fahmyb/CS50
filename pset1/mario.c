#include <stdio.h>
#include <cs50.h>
int main (void)

{
    int n;
    do 
    {
        printf("please enter the pyramid height less than 24\n");
        n = GetInt();
        if (n==0)
        {
            return 0;
        }
    }
    while (n <1 || n>23);
    
    for (int i =0; i <n; i++)
       {

          for (int space =0; space <(n-i)-1; space++)
           {
               printf(" ");
           }
           for (int hash = 0; hash <= i+1; hash++)
           {
               printf("#");
           }
           printf("\n");
       }
}
