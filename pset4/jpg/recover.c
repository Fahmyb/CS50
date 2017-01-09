/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */
#include <stdint.h> 
#include <stdio.h>

typedef uint8_t  BYTE;
int main(int argc, char* argv[])
{
    // Open memory card file
  
    FILE* inptr = fopen("card.raw", "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", "card.raw");
        return 2;
    }
    //declare array of the number of bytes in block 
    BYTE buffer [512];
    // declare char array to store string 
    char title  [50];
     //open file to write jpgs
       FILE* img = NULL;
    //variable to count jpgs
      int num=0;
   
    //iterate through file every 512 bytes tell the eof 
    
   while (fread(&buffer ,sizeof(BYTE),512,inptr) != 0)
     {
        // check for signature
        if(buffer[0] == 0xff && buffer[1] ==  0xd8 && buffer[2] ==  0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1|| buffer[3] == 0xe2||
        buffer[3] == 0xe3|| buffer[3] == 0xe4|| buffer[3] == 0xe5|| buffer[3] == 0xe6|| buffer[3] == 0xe7|| buffer[3] == 0xe8||
        buffer[3] == 0xe9|| buffer[3] == 0xea|| buffer[3] == 0xeb|| buffer[3] == 0xec
        || buffer[3] == 0xed|| buffer[3] == 0xee|| buffer[3] == 0xef ))
        {
         //check if file is already opened
         if (img != NULL)
         {
             fclose(img); 
         }
            sprintf(title,"%03d.jpg",num);
          
            img = fopen(title, "w");
            num++;

          //keep writing tell the beggining of new jpg
              
              fwrite(&buffer ,sizeof(BYTE),512,img);
         }
        else if (num >0)
        {
              fwrite(&buffer ,sizeof(BYTE),512,img);
        } 
     }
     fclose(img); 
     fclose(inptr); 
}