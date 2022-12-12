//
// Created by Bruger on 05-12-2022.
//
// Husk at definere ListSearch i ListEditor.
#include "ListSearch.h"
#include "search.h"
#include "shoppingListLoad.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

product_t** InitListSearch(FILE* filePtr){
    rewind(filePtr);
    data_t* data = LoadDatabase();
    char** shoppingList = LoadFile(filePtr);
    for (int i = 0; shoppingList[i] != NULL; ++i) {
        if(shoppingList[i+1] != NULL){
            shoppingList[i][GetStrLength(shoppingList[i])-1] = '\0';
        }
    }
    for (int i = 0; shoppingList[i] != NULL; ++i) {
        printf("%s\n", shoppingList[i]);
    }
    int numberOfStores = 0;
    char **stores = ListOfStores(data, &numberOfStores);
    int* numberOfProducts = malloc(sizeof(int) * numberOfStores);
    product_t **storeProducts = malloc(sizeof(product_t*) * numberOfStores);
    for(int i = 0; i < numberOfStores; i++){
        storeProducts[i] = malloc(sizeof(product_t) * data->productSize);
    }
    ListSearch(data, shoppingList, stores, storeProducts, numberOfStores, numberOfProducts);
    return storeProducts;
}

void ListSearch(data_t* data, char **shoppingList, char** stores, product_t** storeProducts, int numberOfStores, int* numberOfProducts) {
    for (int i = 0; i < numberOfStores; i++) {
        numberOfProducts[i] = 0;
    }
    int indexOfFoundProducts[MAX_FOUND_PRODUCTS];
    for (int i = 0; shoppingList[i] != NULL; i++){
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
                numberOfProducts[x]++;
            }
            free(storeProductsTemp);

        }
    }
}