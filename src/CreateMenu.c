#include "CreateMenu.h"
#include <stdlib.h>
#include <stdio.h>
#include<string.h>

// return the amount of elements inside of options
int Counter(char options[MAX_OPTIONS][MAX_STRLEN]){
    int count;
    for (count = 0; count < MAX_OPTIONS; ++count) {
        if(options[count][0] == '\0'){  // Check for null terminator instead of NULL
            break;
        }
    }
    return count;
}

// Draw the entire ui in a pretty way
void Draw(char options[MAX_OPTIONS][MAX_STRLEN]){
    int amountOfElements = Counter(options);
    printf("-------------------------------------------------");

    for (int i = 0; i < amountOfElements; ++i) {
        printf("\n %d) %s\n-------------------------------------------------", i+1, options[i]);
    }
}

// return the selected option (1,2,3,4,....)
int ScanInput(int items){
    char option[MAX_STRLEN];
    char* ptr;
    int result;

    while(1){
        printf("\n\nPlease input the number corresponding to your desired option: ");

        // Use fgets to read user input and check for valid input
        if (fgets(option, sizeof(option), stdin)) {
            result = strtol(option, &ptr, 10);
            if (result > 0 && result <= items && ptr != option) {
                return result;
            }
        }

        printf("Please input a valid number :( ");
    }
}

// the main function for this block.
int CreateMenu(char options[MAX_OPTIONS][MAX_STRLEN]){
    Draw(options);
    return ScanInput(Counter(options));
}