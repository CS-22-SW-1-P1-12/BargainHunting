#include "ListEditor.h"
#include "CreateMenu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

/*
 * todo:
 *  shoppingList[20][50] is shitty
 */

void getExistingLists(char *test) {
    char arr[20][50] = {"Create New List"};

    int count2 = 1;
    DIR *dr;
    struct dirent *en;
    dr = opendir("./data/shopping_list/"); //open all or present directory
    if (dr) {
        while ((en = readdir(dr)) != NULL) {
            if (strcmp(en->d_name,".") == 0 || strcmp(en->d_name,"..") == 0){
                continue;
            }
            strcpy(arr[count2], en->d_name);
            count2++;
        }
        closedir(dr); //close all directory
    }


    int result = CreateMenu(arr);
    for (int i = 0; i < count2 - 1; ++i) {
        if (i == result) {
            //printf("%s", arr[i-1]);
            if(result == 1){

            }
            strcpy(test, arr[i - 1]);
        }
    }
}
/*
 * making a selection list to get the user to select the list they want to modify
 *
 * todo: then printing out everything inside of the list
 */
void ListEditor() {
    char listName[50];
    getExistingLists(listName);
    //printf("%s", listName);
    char path[50] = "./data/shopping_list/";
    strcat(path, listName);

    /*
     * printing out the contents of the selected list
     */
    FILE *filePtr;
    filePtr = fopen(path, "a+");
    if (filePtr == NULL) {
        exit(EXIT_FAILURE);
    }
    char shoppingList[20][50] = {"exit", "adding an item"};

    int checkingNextChar;
    //checking for amount of lines in file to make data array
    int count = 2;
    do {
        fscanf(filePtr, "%[^\n]", shoppingList[count]);
        checkingNextChar = getc(filePtr);
        printf("%s\n", shoppingList[count]);
        count++;
    } while (checkingNextChar != EOF);

    while (1) {
        printf("\n\n you may now remove or add items to your list \n");
        int result = CreateMenu(shoppingList);
        printf("result is %d\n", result);
        if (result == 1) {
            fclose(filePtr);
            break;
        } else if (result == 2) {
            printf("Enter product name");
            scanf("%s", shoppingList[count]);
            fprintf(filePtr, "\n%s", shoppingList[count]);
            count++;
        } else {
            if (result <= count) {
                //char tempShoppingList[20][50] = {};
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