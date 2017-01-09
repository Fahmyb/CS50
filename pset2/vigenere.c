#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main (int argc, string argv[])

{
    if (argc !=2)
    {
        printf("enter valid key!");
        return 1;
    }
     string key = argv[1] ;
    for (int i =0,a=strlen(key); i<a;i++)
  {    
    if (!isalpha(key[i]))
    {
        printf("invalid!\n");
        return 1;
    }
  }
        string s = GetString();
        int n = strlen(s);
        int i=0;
        for(int j=0; j<n; j++)
       {
               if(ispunct(s[j])||isspace(s[j]))
               {
                   printf("%c", s[j]);
                   continue;
               }
              int o=0;
              o =(i % strlen(key));
              i++;
              int c =0;
            if (isupper(key[o]))
           {  
              if (isupper(s[j]))
              {
                 c = (((s[j] - 65)+(key[o]-65)) % 26)+65;
                 printf("%c", c);
              }     
              else if (islower(s[j]))
              {
                 c = (((s[j] - 97)+(key[o]-65)) % 26)+97;
                 printf("%c", c);
              }
           }  
          if (islower(key[o]))
           {  
              if (isupper(s[j]))
              {
                 c = (((s[j] - 65)+(key[o]-97)) % 26)+65;
                 printf("%c", c);
              }     
              else if (islower(s[j]))
              {
                 c = (((s[j] - 97)+(key[o]-97)) % 26)+97;
                 printf("%c", c);
              }
           }
        }     
            printf("\n");
}
      
