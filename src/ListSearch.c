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

void ListSearch(FILE* filePtr){
    rewind(filePtr);
    data_t* data = LoadDatabase();
    char** shoppingList = LoadFile(filePtr);
    int shoppingListLines = 0;
    for (int i = 0; shoppingList[i] != NULL; ++i) {
            shoppingList[i][GetStrLength(shoppingList[i])-1] = '\0';
            shoppingListLines++;
    }
    int numberOfStores = 0;
    char **stores = ListOfStores(data, &numberOfStores);
    int* numberOfProducts = malloc(sizeof(int) * numberOfStores);
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
    for (int i = 0; i < shoppingListLines; i++){
        int numberOfFoundProducts = SearchData(shoppingList[i], data, indexOfFoundProducts);
        for(int x = 0; x < numberOfStores; x++){
            int* storeProductsTemp = malloc(sizeof(int) * numberOfFoundProducts);
            if(storeProductsTemp == NULL){
                printf("NOT ALLOCATED CORRECTLY");
                exit(EXIT_FAILURE);
            }
            int numberOfTempProducts = 0;
            for(int y = 0; y < numberOfFoundProducts; y++) {
                if (strcmp(data->products[indexOfFoundProducts[y]].store, stores[x]) == 0){
                    storeProductsTemp[numberOfTempProducts] = indexOfFoundProducts[y];
                    numberOfTempProducts++;
                }
            }
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
