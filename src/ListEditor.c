#include "ListEditor.h"
#include "CreateMenu.h"
#include "ListSearch.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void GetExistingLists(char *test) {
	char arr[MAX_OPTIONS][MAX_STRLEN] = {"Create New List", "Go Back"};

	int count2 = 2;
	DIR *dr;
	struct dirent *en;
	dr = opendir("./data/shopping_list/"); //open all or present directory
	if(dr) {
		while((en = readdir(dr)) != NULL) {
			if(strcmp(en->d_name, ".") == 0 || strcmp(en->d_name, "..") == 0) {
				continue;
			}
			strcpy(arr[count2], en->d_name);
			count2 ++;
		}
		closedir(dr); //close all directory
	}


	int result = CreateMenu(arr);

	if(result == 1) {
		char newlist[MAX_STRLEN];
		printf("Write your list name: \n");
		scanf("%s", newlist);
		FILE *filePtr;
		char path[MAX_STRLEN] = "./data/shopping_list/";
		strcat(path, newlist);
		filePtr = fopen(path, "w");
		if(filePtr == NULL) {
			exit(EXIT_FAILURE);
		}
		fprintf(filePtr, " ");
		fclose(filePtr);
		strcpy(test, newlist);
	} else if(result == 2) {
		//letting function end
        strcpy(test, "quit");

    } else if(count2 >= result) {
		strcpy(test, arr[result - 1]);
	}
}


/*
 * making a selection list to get the user to select the list they want to modify
 *
 * todo: then printing out everything inside of the list
 */
void ListEditor() {
    char listName[MAX_STRLEN];
    GetExistingLists(listName);
    //printf("%s", listName);
    if (strcmp(listName, "quit") == 0) {
        return;
    } else {
        char path[MAX_STRLEN] = "./data/shopping_list/";
        strcat(path, listName);

	/*
	 * printing out the contents of the selected list
	 */
	FILE *filePtr;
	filePtr = fopen(path, "a+");
	if(filePtr == NULL) {
		exit(EXIT_FAILURE);
	}
	char shoppingList[MAX_OPTIONS][MAX_STRLEN] = {"exit", "search", "adding an item"};

	int checkingNextChar;
	//checking for amount of lines in file to make data array
	int count = 3;
	do {
		fscanf(filePtr, "%[^\n]", shoppingList[count]);
		checkingNextChar = getc(filePtr);
		printf("%s\n", shoppingList[count]);
		count ++;
	} while(checkingNextChar != EOF);

        while (1) {
            printf("\n\n you may now remove or add items to your list \n");
            int result = CreateMenu(shoppingList);
            printf("result is %d\n", result);
            if (result == 1) {
                fclose(filePtr);
                break;
            } else if (result == 2) {
                InitListSearch(filePtr);
                break;
            } else if (result == 3) {
                printf("Enter product name\n");
                scanf("%s", shoppingList[count]);
                fprintf(filePtr, "%s\n", shoppingList[count]);
                count++;
            } else {
                if (result <= count) {
                    //char tempShoppingList[MAX_OPTIONS][MAX_STRLEN] = {};
                    for (int x = result - 1; x <= count - 1; x++) {
                        strcpy(shoppingList[x], shoppingList[x + 1]); // assign arr[i+1] to arr[i]
                    }
                    strcpy(shoppingList[count - 1], "\0");
                    count--;
                    fclose(filePtr);
                    fclose(fopen(path, "w"));
                    filePtr = fopen(path, "a+");
                    for (int i = 2; i < count; ++i) {

                        fprintf(filePtr, "%s", shoppingList[i]);
                        if (i < count - 1) {
                            fprintf(filePtr, "\n");
                        }
                    }
                }
            }
        }
    }
}