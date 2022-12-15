#include "CreateMenu.h"
#include <stdlib.h>
#include <stdio.h>
#include<string.h>

/**
 * This function counts the elements in the options array used for CreateMenu
 * @param options A string array with statically allocated space
 * @return The number of non-empty strings in the array
 */
int Counter(char options[MAX_OPTIONS][MAX_STRLEN]){
    int count;
    for (count = 0; count < MAX_OPTIONS; ++count) {
        if(options[count][0] == '\0'){  // Check for null terminator instead of NULL
            break;
        }
    }
    return count;
}

/**
 * This function prints a menu containing options and the numbers associated with choosing them
 * @param options A string array with statically allocated space
 */
void Draw(char options[MAX_OPTIONS][MAX_STRLEN]){
    int amountOfElements = Counter(options);
    printf("-------------------------------------------------");

    for (int i = 0; i < amountOfElements; ++i) {
        printf("\n %d) %s\n-------------------------------------------------", i+1, options[i]);
    }
}

/**
 * This option scans for an integer from the user
 * It continuously asks for input until a valid input is entered
 * @param items The max number the user can input
 * @return The user's input
 */
int ScanInput(int items){
    char option[MAX_STRLEN];
    char* ptr;
    int result;

    //An infinite loop unless return is reached by entering valid input
    while(1){
        printf("\n\nPlease input the number corresponding to your desired option: ");

        // Checking if the input contains an integer above 0 but not greater than items
        scanf(" ");
        if (fgets(option, sizeof(option), stdin)) {
            result = strtol(option, &ptr, 10);
            if (result > 0 && result <= items && ptr != option) {
                return result;
            }
        }

        printf("Please input a valid number :( ");
    }
}

/**
 * This function creates a menu from a list of options
 * Then, it asks the user to pick a number corresponding to one of the options
 * @param options A string array with statically allocated space
 * @return The number the user inputs, which corresponds to an option
 */
int CreateMenu(char options[MAX_OPTIONS][MAX_STRLEN]){
    Draw(options);
    return ScanInput(Counter(options));
}