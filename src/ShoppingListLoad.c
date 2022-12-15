//
// Created by Alexander Winther Moldt and Ida Marie Hem
//

#include "ShoppingListLoad.h"

/**
 * This function converts the contents of a text file into a string array
 * @param file A text file that is already open
 * @return A string array containing every line in the file
 */

char **LoadFile(FILE* file){

    //If the file is not found, print an error and return nothing
    if(!file)
    {
        printf("can't open");
        return NULL;
    }

    int arrayLength = SIZE_JUMPS;

    char **lines = (char**) malloc(arrayLength * sizeof(char*));//allocate space for chars

    char buffer[MAX_BUFFER];
    int i = 0;

    //This loop continues until there are no more strings in the file
    while(fgets(buffer,MAX_BUFFER,file))
    {
        //If the current line is greater than the max number of lines, allocate space for another
        if (i == arrayLength)
        {
            arrayLength += SIZE_JUMPS;
            char** newLines = realloc(lines, arrayLength * sizeof(char*));
            if(!newLines)
            {
                printf("can't reallocate, sorry\n");
                exit(1);
            }
            lines = newLines;
        }

        int bufferLength = strlen(buffer); // getting length of buffer

        char *item = (char *) malloc((bufferLength + 1) * sizeof(char)); // allocate space for string
        strcpy(item,buffer); //copy string from buffer to item
        lines[i] = item;
        i++;
    }
    lines[i] = NULL;
    return lines;
}