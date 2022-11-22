#include "CreateMenu.h"
#include <stdlib.h>
#include <stdio.h>
#include<string.h>

// return the amount of elements inside of options
int Counter(char options[MAX_OPTIONS][MAX_STRLEN]){
    int count;
    for (count = 0; count < MAX_OPTIONS; ++count) {
        if(options[count][0] == NULL){
            break;
        }
    }
    return count;
}


// Draw the entire ui in a pretty way
void Draw(char options[MAX_OPTIONS][MAX_STRLEN]){
    int amountOfElements = Counter(options);
    printf(KWHT "\n-------------------------------------------------");

    for (int i = 0; i < amountOfElements; ++i) {
        printf(KNRM "\n %d) ", i+1);
        printf(KGRN "%s", options[i]);
        printf(KNRM "\n-------------------------------------------------");
    }
}


// return the selected option (1,2,3,4,....)
int ScanInput(){
    printf("\n\nPlease input the number corrisponding to your desired option: ");

    int result;
    char strInput[100]; // 100 to prevent a segfault from happening if grandpa writes his life story
    scanf("%s", strInput);

    //strtol is used to attempt to convert string to int, removes chars and saves int if any in input. If no ints found returns 0
    result = strtol(strInput, NULL, 10);
    return result;
}


// the main function for this block.
int CreateMenu(char options[MAX_OPTIONS][MAX_STRLEN]){
    Draw(options);
    return ScanInput();
}



