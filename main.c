#include <string.h>
#include <stdio.h>
#include <stdlib.h>

const int sizejumps = 20;
char **loadfile(char *filename, int *len);

/*int main(int argc, char *argv[])
{
    if(argc == 1)
    {
        printf("not your day huh?");
        exit(1);
    }

    int length = 0;
   char **listFile = loadfile(argv[1],&length);

    printf("%d\n",length);


}*/

void * main()
{
    FILE *file = fopen("listFile.txt", "r");

    if(!file)
    {
        printf("can't open");
        return NULL;
    }

    int arraylenght = sizejumps;

    char **line = (char**) malloc(arraylenght * sizeof(char*));//allocate space for chars

    char buffer[100];
    int i = 0;

    while(fgets(buffer,100,file))
    {
        if (i == arraylenght)
        {
            arraylenght +=sizejumps;
            char ** newline = realloc(line,arraylenght * sizeof(char*));
            if(!newline)
            {
                printf("can't reallocate, sorry\n");
                exit(1);
            }
            line = newline;
        }

        int blen = strlen(buffer); // getting length of buffer

        char *item = (char *) malloc((blen+1) * sizeof(char));// alocate space for string

        strcpy(item,buffer);//copy string from buffer to item
        line[i]=item;
        i++;

    }
    line[i] = NULL;
    for (int j = 0; line[i] != NULL ;j++)
    {
        printf("%s\n",line[j]);
    }
    printf("done\n");

    return line;

}





