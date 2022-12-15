//
// Created by sinag on 02.12.2022.
//

#include "Database.h"

#ifndef BARGAINHUNTING_SEARCH_H
#define BARGAINHUNTING_SEARCH_H

#define MAX_SEARCH_LEN 20
#define MAX_FOUND_PRODUCTS 32

int SearchData(const char* searchTerm, data_t* database, int indexOfFoundProducts[MAX_FOUND_PRODUCTS]);
void GetSearchedProduct(char SearchTerm[MAX_SEARCH_LEN]);
int SearchMenu(data_t* data, const int indexOfFoundProducts[MAX_FOUND_PRODUCTS], int numberOfFoundProducts);
int ProductSearch(data_t* data);
int FindCheapestProduct(data_t* data, const int indexOfProducts[MAX_FOUND_PRODUCTS], int numberOfProducts);

#endif //BARGAINHUNTING_SEARCH_H
