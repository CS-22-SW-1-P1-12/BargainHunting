#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE_JUMPS 1
#define MAX_BUFFER 100


char **LoadFile(char *fileName);
void PrintList(char** lines);



//This function opens a text file and returns the contents in a string array called lines
char **LoadUserPreferences(char *fileName){
    FILE *file = fopen(fileName, "r");

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
            char ** newline = realloc(lines, arrayLength * sizeof(char*));
            if(!newline)
            {
                printf("can't reallocate, sorry\n");
                exit(1);
            }
            lines = newline;
        }

        int bufferLength = strlen(buffer); // getting length of buffer

        char *preferences = (char *) malloc((bufferLength + 1) * sizeof(char)); // allocate space for string

        strcpy(preferences, buffer); //copy string from buffer to preferences
        lines[i] = preferences;
        i++;

    }
    lines[i] = NULL;

    printf("done\n");

    return lines;
}

//This function prints every string in a string array as a new line.
void PrintList(char** lines){
    for (int j = 0; lines[j] != NULL; j++)
    {
        printf("%s", lines[j]);
    }
    printf("\n");
}

void * main()
{
    char* fileName = "preferencesTest.txt";
    char** lines = LoadUserPreferences(fileName);
    PrintList(lines);
    return 0;
}