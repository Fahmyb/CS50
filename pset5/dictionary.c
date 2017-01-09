/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */
 /**
 * Returns true if word is in dictionary else false.
 */

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include "dictionary.h"
     // declare struct
     typedef struct node
     {
         bool is_word;
         struct node* children[27];
     }
     node;
     // declare root
     node* root = NULL; 
     // globaly maintaining a pointer equal to root
     node* trav = NULL;
     // prototype
     void freeme (struct node* trav);
     // declare number of words in dictionary
     int wordsNum; 
bool check(const char* word)
{
        trav = root;
        // length of word
        int n = strlen(word);
        // declare char 
        char c;
        // iterate per word 
        for(int i = 0; i < n; i++)
        {
            // index of letter
            int index;
            // if letter is uppercase convert to lower to match index
            if(isupper(word[i]))
            {
                // convert tolower 
                c = tolower(word[i]);
                index = c - 'a';
            }
            else
            {
                // check if apostrophe
                if(word[i] == '\'')
                {
                    index = 26;
                }
                // chech if alpha
                else
                {
                index = word[i] - 'a';
                }
            }    
            // if index is NULL then word is miss-spealed
            if(trav -> children[index] == NULL)
            {
                // return trueword is not spelled correctly
                return false;
            }
            // point to next node
            else    
            {
                trav = trav -> children[index];  
            }
        }    
            // check if word exists
            if(trav -> is_word == true)
            {
                //word is spelled correctly
                return true;
            }
            
        return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
 
bool load(const char* dictionary)
{
    // open dictionary file
    FILE* fpd = fopen(dictionary, "r");
    // return error if file not found
    if(fpd == NULL)
    {
        printf("Could not open %s.\n",dictionary);
        return 1;
    }
    // initializing root
    root = calloc(1,sizeof(node));
    // pointer to root
    trav = root;
    // get characters from file and repeat tell EOF
    do
    {
        if(feof(fpd))
        {
            break;
        }
        // iterate per word 
        for(int i = 0; i < 46 ; i++)
        {
            // decalaring the character
            char letter;
            letter = fgetc(fpd);
            // check characters
            if(letter == '\n')
            {
                break;
            }
            else if(letter == EOF)
            {
                // close file
                fclose(fpd);
                return 1;
            }
            // check if EOF
            else 
            {
                // index of the character in the node
                int index;
                // check for apostrophe
                if(letter == '\'') 
                {
                   index = 26;
                }  
                // else if alpha
                else
                {
                    index = letter - 'a';     
                }
                // check if node is not allocated
                if(trav -> children[index] == NULL)
                {
                    // if not then allocate new node and make the ith character "index" point to it
                    node* leaf = calloc(1,sizeof(node)); 
                    trav -> children[index] = leaf; 
                    trav = trav -> children[index];
                }
                // if node is already allocated point to it
                else
                {
                    trav = trav -> children[index]; 
                }
            }    
            
        } 
          // set is word to true
          trav -> is_word = true;
          wordsNum ++;
          // set trav back to top after inserting word (not sure) 
          trav = root;
          
    }
    while (true);
    return true;
}
 
/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // return number of words in dictionary 
    return wordsNum;
    return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
 
bool unload(void)
{
    // free trie
    freeme(root); 
    return true ;
}
// declare freeme function
    void freeme (node* trav)
    {
        for(int i = 0; i < 27; i++)
        {
            if(trav -> children[i] != NULL)
            {
                freeme(trav -> children [i]);
            }
        }
        free (trav);
    }
