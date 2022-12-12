//
// Created by Bruger on 05-12-2022.
//
// Husk at definere ListSearch i ListEditor.
#include "ListSearch.h"
#include "search.h"
#include "shoppingListLoad.h"
#include "calculations.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void InitListSearch(FILE* filePtr){
    rewind(filePtr);
    data_t* data = LoadDatabase();
    char** shoppingList = LoadFile(filePtr);
    int shoppingListLines = 0;
    for (int i = 0; shoppingList[i] != NULL; ++i) {
            shoppingList[i][GetStrLength(shoppingList[i])-1] = '\0';
            printf("%s\n", shoppingList[i]);
            shoppingListLines++;
    }
    int numberOfStores = 0;
    char **stores = ListOfStores(data, &numberOfStores);
    int* numberOfProducts = malloc(sizeof(int) * numberOfStores);
    product_t **storeProducts = malloc(sizeof(product_t*) * numberOfStores);
    for(int i = 0; i < numberOfStores; i++){
        storeProducts[i] = malloc(sizeof(product_t) * data->productSize);
    }
    ListSearch(data, shoppingList, stores, storeProducts, numberOfStores, numberOfProducts, shoppingListLines);
    printf("ListSearch done\n");
    for (int i = 0; i < numberOfStores; i++) {
        printf("Store: %s\n", stores[i]);
        for (int x = 0; x < numberOfProducts[i]; x++) {
            printf("%s \n", storeProducts[i][x].name);
        }
    }
    for (int i = 0; i < numberOfStores; ++i) {
        printf("%d\n", numberOfProducts[i]);
    }
    Calculations(storeProducts, numberOfStores, numberOfProducts);
    /*for (int i = 0; i < data->productSize; ++i) {
        free(stores[i]);
    }
    free(stores);
    for(int i = 0; i < numberOfStores; i++){
        free(storeProducts[i]);
    }
    free(storeProducts);
    free(numberOfProducts);*/
}

void ListSearch(data_t* data, char **shoppingList, char** stores, product_t** storeProducts, int numberOfStores, int* numberOfProducts, int shoppingListLines) {
    for (int i = 0; i < numberOfStores; i++) {
        numberOfProducts[i] = 0;
    }
    printf("cry\n");
    int indexOfFoundProducts[MAX_FOUND_PRODUCTS];
    for (int i = 0; i < shoppingListLines; i++){
        int numberOfFoundProducts = SearchData(shoppingList[i], data, indexOfFoundProducts);
        for(int x = 0; x < numberOfStores; x++){
            int* storeProductsTemp = malloc(sizeof(int) * numberOfFoundProducts);
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
            free(storeProductsTemp);
        }
        printf("a\n");
    }
    printf("b\n");
}