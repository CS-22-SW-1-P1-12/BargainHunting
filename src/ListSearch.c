//
// Created by Bruger on 05-12-2022.
//
// Husk at definere ListSearch i ListEditor.
#include "ListSearch.h"
#include "search.h"
#include "shoppingListLoad.h"
#include "calculations.h"
#include "CreateMenu.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * This function searches through a shopping list
 * It creates a 2D array of stores, containing an array of products found in each store
 * The Calculations function is then called to calculate and sort the prices of the stores
 * @param filePtr A file containing a shopping list, one item per line
 */
void ListSearch(FILE* filePtr){
    rewind(filePtr);
    data_t* data = LoadDatabase();
    //Converting the file to a string array containing each line
    char** shoppingList = LoadFile(filePtr);
    int shoppingListLines = 0;
    //Removing the newline at the end of each string
    for (int i = 0; shoppingList[i] != NULL; ++i) {
            shoppingList[i][GetStrLength(shoppingList[i])-1] = '\0';
            shoppingListLines++;
    }
    int numberOfStores = 0;
    char **stores = ListOfStores(data, &numberOfStores);
    int* numberOfProducts = malloc(sizeof(int) * numberOfStores);
    //Creating a 2D array of product structs
    product_t **storeProducts = malloc(sizeof(product_t*) * numberOfStores);
    for(int i = 0; i < numberOfStores; i++){
        storeProducts[i] = malloc(sizeof(product_t) * data->productSize);
    }
    if(storeProducts == NULL){
        printf("NOT ALLOCATED CORRECTLY");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < numberOfStores; i++) {
        numberOfProducts[i] = 0;
    }
    int indexOfFoundProducts[MAX_FOUND_PRODUCTS];
    //Searching through each string in the shopping list array
    for (int i = 0; i < shoppingListLines; i++){
        int numberOfFoundProducts = SearchData(shoppingList[i], data, indexOfFoundProducts);
        //Going through each store to find the products that match it
        for(int x = 0; x < numberOfStores; x++){
            int* storeProductsTemp = malloc(sizeof(int) * numberOfFoundProducts);
            if(storeProductsTemp == NULL){
                printf("NOT ALLOCATED CORRECTLY");
                exit(EXIT_FAILURE);
            }
            int numberOfTempProducts = 0;
            //Going through each product that matches the search term
            for(int y = 0; y < numberOfFoundProducts; y++) {
                //If the current product matches the current store, add it to an array
                if (strcmp(data->products[indexOfFoundProducts[y]].store, stores[x]) == 0){
                    storeProductsTemp[numberOfTempProducts] = indexOfFoundProducts[y];
                    numberOfTempProducts++;
                }
            }
            //If products match the current store, add the cheapest one to storeProducts
            if(numberOfTempProducts > 0)
            {
                int cheapestProduct = FindCheapestProduct(data, storeProductsTemp, numberOfTempProducts);
                storeProducts[x][numberOfProducts[x]] = data->products[cheapestProduct];
                numberOfProducts[x] += 1;
            }
            storeProducts[x][numberOfProducts[x]].name = "END";
            free(storeProductsTemp);
        }
    }
    for (int i = 0; i < shoppingListLines; ++i) {
        free(shoppingList[i]);
    }
    free(shoppingList);
    //Call the calculations function to find and print the cheapest store
    Calculations(storeProducts, numberOfStores, stores, numberOfProducts, shoppingListLines);
    for (int i = 0; i < data->productSize; ++i) {
        free(stores[i]);
    }
    free(stores);
    for(int i = 0; i < numberOfStores; i++){
        free(storeProducts[i]);
    }
    free(storeProducts);
    free(numberOfProducts);
    exit(EXIT_SUCCESS);
}
