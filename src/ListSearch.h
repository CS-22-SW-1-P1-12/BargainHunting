//
// Created by Bruger on 05-12-2022.
//

#ifndef BARGAINHUNTING_LISTSEARCH_H
#define BARGAINHUNTING_LISTSEARCH_H

#include "database.h"
#include "ListEditor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void ListSearch(data_t* data, char** shoppingList, char** stores, product_t** storeProducts, int numberOfStores, int* numberOfProducts);
product_t** InitListSearch(FILE* filePtr);

#endif //BARGAINHUNTING_LISTSEARCH_H
