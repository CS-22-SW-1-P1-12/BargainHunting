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

double TotalPricePerKilo(product_t* products){
    double totalPrice = 0;
    for (int i = 0; (strcmp(products[i].name, "END") != 0); ++i) {
        totalPrice += products[i].price;
    }
    return totalPrice;
}

void Calculations (product_t **storeProducts, int numberOfStores, char** stores, const int* numberOfProducts){


    //use Sinas functions to get lengths
    double results[numberOfStores][2]; //10 skal ændres

    printf("cry\n");

    for (int i = 0; i < numberOfStores; i++) {

        char *storeName = storeProducts[i][0].name;

        printf("number of products %d\n", numberOfProducts[i]);

        double totalPrice = TotalPrice(storeProducts[i]);
        double totalPricePerKilo = TotalPricePerKilo(storeProducts[i]);

        printf("cry\n");

        results[i][0] = totalPrice;    //casting to char in order for the price values to be stored in the char array with results
        results[i][1] = totalPricePerKilo;
        printf("results obtained\n");

    }

    MergeSort(storeProducts, 0, numberOfStores - 1, numberOfProducts);

    printf("-------------------------------------------------\n");

    for (int i = 0; i < numberOfStores; ++i) { //fix the thing 10
        if(TotalPrice(storeProducts[i]) > 0){
            printf("-------------------------------------------------");
            printf("%s: ", storeProducts[i][0].store);
            printf("price (total): ");
            printf("%lf ", TotalPrice(storeProducts[i]));
            printf("price per kg: ");
            printf("%lf ", TotalPricePerKilo(storeProducts[i]));
            printf("\n");
        }
    }


}

