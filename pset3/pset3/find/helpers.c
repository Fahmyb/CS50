/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"
/**
 * Returns true if value is in array of n values, else false.
 */
bool binarysearch (int value, int values[], int min, int max)
{
       if (min > max)
    {
            return false;
    }
    else
    {
    int mid = (min +max)/2;
    if (value > values[mid])
    {
       return binarysearch (value, values,  mid + 1,  max);
    }
    else if (value < values[mid])
    {
        return binarysearch ( value, values, min, mid - 1);
    }
    else
    {
        return values[mid];
    }
    }
}
bool search(int value, int values[],int n)
{
   int min = 0;
   int max = n-1;
   return binarysearch (value, values, min, max);
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    for (int i=0;i<(n-1);i++)
    {
        
        for(int c=0;c<n; c++)
    {
        if (values[c]>values[c+1])
        {
            int a = values[c];
            values[c] = values [c+1];
            values[c+1] =a;
       }
       else
       {
           break;
       }
    }  
     
    }
}