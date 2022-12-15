//
// Created by Lennart Diego Kahn and Mantas Akilanas
//

#include "ListEditor.h"

enum list_menu_e {CREATE_LIST = 1, QUIT};
enum list_editor_e {BACK = 1, SEARCH, ADD};

/**
 * This function opens the shopping list directory and copies every file name into an array
 * Then a menu is created from this array so the user can select a shopping list
 * If 1 is selected, the user can enter a name for a new file to be created
 * If 2 is selected, the user is allowed to go back to the main menu
 * If another number is selected, the function saves its corresponding list to listName
 * @param listName A string containing the name of the selected list
 */
void GetExistingLists(char *listName) {
	char arr[MAX_OPTIONS][MAX_STRLEN] = {"Create New List", "Go Back"};

	int count2 = 2;
	DIR *dr;
	struct dirent *en;
	dr = opendir("./data/shopping_list/"); //open all or present directory
	if(dr) {
        //Reading the files in the directory and copying their names into arr until no more files can be found
		while((en = readdir(dr)) != NULL) {
            //Skipping over the root and home files "." and ".."
			if(strcmp(en->d_name, ".") == 0 || strcmp(en->d_name, "..") == 0) {
				continue;
			}
			strcpy(arr[count2], en->d_name);
			count2 ++;
		}
		closedir(dr); //close all directory
	}

	int result = CreateMenu(arr);

    //If the user inputs 1, allow them to create a new list
	if(result == CREATE_LIST) {
		char newList[MAX_STRLEN];
		printf("Write your list name: \n");
		scanf("%s", newList);
		FILE *filePtr;
		char path[MAX_STRLEN] = "./data/shopping_list/";
		strcat(path, newList);
		filePtr = fopen(path, "w");
		if(filePtr == NULL) {
			exit(EXIT_FAILURE);
		}
		fprintf(filePtr, " ");
		fclose(filePtr);
		strcpy(listName, newList);
	} else if(result == QUIT) {
		//letting function end
        strcpy(listName, "quit");

    } else if(count2 >= result) {
		strcpy(listName, arr[result - 1]);
	}
}


/**
 * This function allows a shopping list to be edited by the user
 * The user can either add or remove an item from a list, or search through the list
 */
void ListEditor() {
    char listName[MAX_STRLEN];
    GetExistingLists(listName);
    //If the listName from GetExistingLists is "quit", return
    if (strcmp(listName, "quit") == 0) {
        return;
    } else {
        char path[MAX_STRLEN] = "./data/shopping_list/";
        strcat(path, listName);

	FILE *filePtr;
	filePtr = fopen(path, "a+");
	if(filePtr == NULL) {
		exit(EXIT_FAILURE);
	}
	char shoppingList[MAX_OPTIONS][MAX_STRLEN] = {"exit", "search", "adding an item"};

	int checkingNextChar;
	int count3 = 3;
    //checking for amount of lines in file to make data array
	do {
		fscanf(filePtr, "%[^\n]", shoppingList[count3]);
		checkingNextChar = getc(filePtr);
		count3 ++;
	} while(checkingNextChar != EOF);
        while (1) {
            printf("\n\n you may now remove or add items to your list \n");
            int result = CreateMenu(shoppingList);
            printf("result is %d\n", result);
            if (result == BACK) {
                fclose(filePtr);
                break;
            } else if (result == SEARCH) {
                ListSearch(filePtr);
                break;
            } else if (result == ADD) {
                //If add is selected, it is printed into the file
                printf("Enter product name\n");
                scanf(" %[^\n]s", shoppingList[count3]);
                fprintf(filePtr, "%s\n", shoppingList[count3]);
                count3++;
            } else {
                //If an item is selected, all items after are moved up to delete the item
                if (result <= count3) {
                    for (int x = result - 1; x <= count3 - 1; x++) {
                        strcpy(shoppingList[x], shoppingList[x + 1]); // assign arr[i+1] to arr[i]
                    }
                    strcpy(shoppingList[count3 - 1], "\0");
                    count3--;
                    fclose(filePtr);
                    fclose(fopen(path, "w"));
                    filePtr = fopen(path, "a+");
                    for (int i = 2; i < count3; ++i) {

                        fprintf(filePtr, "%s", shoppingList[i]);
                        if (i < count3 - 1) {
                            fprintf(filePtr, "\n");
                        }
                    }
                }
            }
        }
    }
}