//
// Created by Bruger on 05-12-2022.
//
// Husk at definere ListSearch i ListEditor.
#include "ListSearch.h"
#include "database.h"
#include "search.h"
#include <stdlib.h>
#include <string.h>

void ListSearch(data_t* data, char **shoppingList) {
    int numberOfStores = 0;
    char **stores = ListOfStores(data, &numberOfStores);

    product_t **storeProducts = malloc(sizeof(product_t*) * numberOfStores);
            for(int i = 0; numberOfStores > i; i++){
                storeProducts[i] = malloc(sizeof(product_t) * data->productSize);
            }

    int indexOfFoundProducts[MAX_FOUND_PRODUCTS];
    for (int i = 0; shoppingList[i] != NULL; i++){
        int numberOfFoundProducts = SearchData(shoppingList[i], data, indexOfFoundProducts);


        for(int x = 0; numberOfFoundProducts > x; x++){
            for(int q = 0; numberOfStores > q; q++) {
                if (strcmp(data->products[x].store, stores[q]) == 0){

                }
            }

        }
    }


}
