//
// Created by sinag on 12.12.2022.
//

#ifndef BARGAINHUNTING_CALCULATIONS_H
#define BARGAINHUNTING_CALCULATIONS_H

#include "database.h"

void Calculations (product_t **storeProducts, int numberOfStores, char** stores, int* numberOfProducts);
double TotalPrice(product_t* products);
double TotalPricePerKilo(product_t* products);

#endif //BARGAINHUNTING_CALCULATIONS_H
