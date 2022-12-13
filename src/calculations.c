//
// Created by sinag on 17.11.2022.
//
#include "stdio.h"
#include "database.h"
#include "search.h"
#include "CreateMenu.h"
#include "string.h"
#include "ListSearch.h"
#include "mergeSort.h"
#define MAX_STR_LEN 50

double TotalPrice(product_t* products){
    double totalPrice = 0;
    for (int i = 0; (strcmp(products[i].name, "END") != 0); ++i) {
        totalPrice += products[i].price;
    }
    return totalPrice;
}

int NumberOfProducts(product_t* products){
    int numberOfProducts = 0;
    for (int i = 0; (strcmp(products[i].name, "END") != 0); ++i) {
        numberOfProducts++;
    }
    return numberOfProducts;
}

double TotalPricePerKilo(product_t* products){
    double totalPrice = 0;
    for (int i = 0; (strcmp(products[i].name, "END") != 0); ++i) {
        totalPrice += products[i].price;
    }
    return totalPrice;
}

void Calculations (product_t **storeProducts, int numberOfStores, char** stores, const int* numberOfProducts, int numberOfSearches){
    MergeSort(storeProducts, 0, numberOfStores - 1, numberOfProducts);
    printf("-------------------------------------------------\n");
    for (int i = 0; i < numberOfStores; ++i) {
        if(TotalPrice(storeProducts[i]) > 0){
            printf("--------------------------------");
            printf("%s: ", storeProducts[i][0].store);
            printf("found products: ");
            printf("%d/%d, ", NumberOfProducts(storeProducts[i]), numberOfSearches);
            printf("price (total): ");
            printf("%.2lf, ", TotalPrice(storeProducts[i]));
            printf("price per kg: ");
            printf("%.2lf", TotalPricePerKilo(storeProducts[i]));
            printf("\n");
        }
    }
}