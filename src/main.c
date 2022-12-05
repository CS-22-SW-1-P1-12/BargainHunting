//
// Created by Lennart Diego Kahn on 03/11/2022.
//

#include <stdio.h>
#include "main.h"
#include "CreateMenu.h"
#include "database.h"
#include "ListEditor.h"
#include "search.h"
/*
 * This function has the main loop and displays / returns the menu selected.
 * To make your own menu just copy this code and #include "CreateMenu.h"
 * #################################################################
 * # Put your main function into the switch case fitting your code #
 * #################################################################
 */
void MainMenuScreen(){
    char arr[MAX_OPTIONS][MAX_STRLEN] = {"quit", "Individual Search", "List (load, make and search a list)", "Settings (store preferance etc)"};
    int exitProgram = 0;

    while(exitProgram == 0) {
        int result = CreateMenu(arr);
        switch (result) {
            case 1:
                // Ending program by letting it return to main and end naturally instead of using (exit)
                printf("Ending program...\n");
                exitProgram = 1;
                break;
            case 2:
                // Open up the Search menu and start the search function
                printf("Opening Search menu\n");
		        data_t* data = LoadDatabase();
		        ProductSearch(data);
                break;
            case 3:
                // Open up the List menu and start the List function
                printf("Opening List menu\n");
                ListEditor();
                break;
            case 4:
                // Open up the Settings menu and start the Settings function
                printf("Opening Settings menu\n");
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