//
// Created by Sina Grün
//

#ifndef BARGAINHUNTING_MERGESORT_H
#define BARGAINHUNTING_MERGESORT_H
#include "Database.h"
#include "Search.h"
#include "Calculations.h"
#include <stdio.h>
#include <stdlib.h>

void Merge(product_t** L, int start, int end, int mid);
void MergeSort(product_t** L, int start, int end);

#endif //BARGAINHUNTING_MERGESORT_H
