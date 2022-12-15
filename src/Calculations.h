//
// Created by sinag on 12.12.2022.
//

#ifndef BARGAINHUNTING_CALCULATIONS_H
#define BARGAINHUNTING_CALCULATIONS_H

#include "Database.h"
#include "stdio.h"
#include "Database.h"
#include "Search.h"
#include "CreateMenu.h"
#include "string.h"
#include "MergeSort.h"
#define MAX_STR_LEN 50

void Calculations (product_t **storeProducts, int numberOfStores, int numberOfSearches);
double TotalPrice(product_t* products);
double TotalPricePerKilo(product_t* products);

#endif //BARGAINHUNTING_CALCULATIONS_H
