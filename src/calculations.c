//
// Created by sinag on 17.11.2022.
//
#include "stdio.h"
#include "database.h"
#include "search.h"
#include "CreateMenu.h"
#include "string.h"
#include "mergeSort.h"
#define MAX_STR_LEN 50

/**
 * This function calculates the total price of a product array
 * @param products An array containing products, where the end is signalled by the product name "END"
 * @return The total price of all the products
 */
double TotalPrice(product_t* products){
    double totalPrice = 0;
    for (int i = 0; (strcmp(products[i].name, "END") != 0); ++i) {
        totalPrice += products[i].price;
    }
    return totalPrice;
}

/**
 * This function calculates the number of products in a product array
 * @param products An array containing products, where the end is signalled by the product name "END"
 * @return The number of products in the array
 */
int NumberOfProducts(product_t* products){
    int numberOfProducts = 0;
    for (int i = 0; (strcmp(products[i].name, "END") != 0); ++i) {
        numberOfProducts++;
    }
    return numberOfProducts;
}

/**
 * This function calculates the total price per kg of a product array
 * @param products An array containing products, where the end is signalled by the product name "END"
 * @return The total price per kg of all the products
 */
double TotalPricePerKilo(product_t* products){
    double totalPrice = 0;
    for (int i = 0; (strcmp(products[i].name, "END") != 0); ++i) {
        totalPrice += products[i].price;
    }
    return totalPrice;
}

/**
 * This function sorts an array of product arrays by their total price and then prints them
 * For each array the function prints its store, total price and total price per kilo
 * Additionally, the number of products found in the store compared to the products originally searched after is printed
 * @param storeProducts A 2D array of products, where the first index signifies products with the same store
 * @param numberOfStores The number of unique stores in the storeProducts array
 * @param numberOfSearches The number of products initially searched after
 */
void Calculations (product_t **storeProducts, int numberOfStores, int numberOfSearches){
    MergeSort(storeProducts, 0, numberOfStores - 1);
    printf("-------------------------------------------------\n");
    for (int i = 0; i < numberOfStores; ++i) {
        //If the total price is 0, the store has none of the desired products and won't be printed
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