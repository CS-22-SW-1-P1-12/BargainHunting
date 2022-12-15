//
// Created by Lennart Diego Kahn
//

#include "main.h"

/**
 * This function has the main loop and displays / returns the menu selected.
 */

enum main_menu_options_e {QUIT = 1, INDIVIDUAL_SEARCH, LIST};

void MainMenuScreen(){
    char arr[MAX_OPTIONS][MAX_STRLEN] = {"quit", "Individual Search", "List (load, make and search a list)"};
    int exitProgram = 0;

    while(exitProgram == 0) {
        int result = CreateMenu(arr);
        switch (result) {
            case QUIT:
                // Ending program by letting it return to main and end naturally instead of using (exit)
                printf("Ending program...\n");
                exitProgram = 1;
                break;
            case INDIVIDUAL_SEARCH:
                // Open up the Search menu and start the search function
                printf("Opening Search menu\n");
		        data_t* data = LoadDatabase();
		        ProductSearch(data);
                FreeDatabase(data);
                break;
            case LIST:
                // Open up the List menu and start the List function
                printf("Opening List menu\n");
                ListEditor();
                break;
            default:
                // no valid input got sent..... retrying.
                printf("%d is not a valid input\n", result);
        }
    }
}

int main(){
    MainMenuScreen();
}