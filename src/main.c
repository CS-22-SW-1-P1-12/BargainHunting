//
// Created by Lennart Diego Kahn on 03/11/2022.
//

#include <stdio.h>
#include "main.h"
#include "CreateMenu.h"

/*
 * This function has the main loop and displays / returns the menu selected.
 * To make your own menu just copy this code and #include "CreateMenu.h"
 * #################################################################
 * # Put your main function into the switch case fitting your code #
 * #################################################################
 */
void MainMenuScreen(){
    char arr[20][50] = {"quit", "Individual Search", "List (load, make and search a list)", "Settings (store preferance etc)"};
    int exitProgram = 0;

    while(exitProgram == 0) {
        int result = CreateMenu(arr);
        switch (result) {
            case 1:
                // Ending program by letting it return to main and end naturally instead of using (exit)
                printf("Ending program...");
                exitProgram = 1;
                break;
            case 2:
                // Open up the Search menu and start the search function
                printf("Opening Search menu");
                break;
            case 3:
                // Open up the List menu and start the List function
                printf("Opening List menu");
                break;
            case 4:
                // Open up the Settings menu and start the Settings function
                printf("Opening Settings menu");
                break;
            default:
                // no valid input got sendt..... retrying.
                printf("%d is not a valid input", result);
        }
    }
}

//int main(){
//    MainMenuScreen();

//}