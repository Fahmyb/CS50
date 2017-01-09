#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main (int argc, string argv[])
{
    string key = argv[1] ;
    if ( argc != 2)
    {
      printf("please enter valid number");
      return 1;
    }
    else
     { 
        int k = atoi(key);
        string s = GetString();
        for(int j=0, n = strlen(s); j<n; j++)
            {
              int c =0;
              if (isupper(s[j]))
              {
                 c = (((s[j] - 65)+k)%26)+65;
                 printf("%c", c);
              }     
              else if (islower(s[j]))
              {
                 c = (((s[j] - 97)+k) % 26)+97;
                 printf("%c", c);
              }
              else 
              {
                printf("%c", s[j]);
              }
            }
        printf("\n");
      }
          
}