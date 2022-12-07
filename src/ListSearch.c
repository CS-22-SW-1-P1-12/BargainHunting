//
// Created by Bruger on 05-12-2022.
//
// Husk at definere ListSearch i ListEditor.
#include "ListSearch.h"
#include "database.h"
#include "search.h"
#include <stdlib.h>

void ListSearch(data_t* data, char **shoppingList) {
    int indexOfFoundProducts[MAX_FOUND_PRODUCTS];
    for (int i = 0; shoppingList[i] != NULL; i++){
        int numberOfFoundProducts = SearchData(shoppingList[i], data, indexOfFoundProducts);

        char stores[MAX_STR_LEN];
        for(int x = 0; numberOfFoundProducts > x; x++){

        }
    }


}
