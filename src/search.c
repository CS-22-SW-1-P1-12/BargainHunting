//
// Created by sinag on 02.12.2022.
//

#include "search.h"
#include "database.h"
#include <stdio.h>
#include "CreateMenu.h"
#include <string.h>

//REMEMBER TO FREE AT SOME POINT


int ProductSearch(data_t* data){
    int indexOfFoundProducts[MAX_FOUND_PRODUCTS];
    char searchTerm[MAX_SEARCH_LEN];
    int numberOfFoundProducts = 0;
    while(numberOfFoundProducts == 0)
    {
        GetSearchedProduct(searchTerm);
        if(strcmp(searchTerm, "q") != 0)
        {
            numberOfFoundProducts = SearchData(searchTerm, data, indexOfFoundProducts);
            if(numberOfFoundProducts == 0)
            {
                printf("No products matching search\n");
            }
        }
        else
        {
            printf("Going back");
            return -1;
        }
    }
    return SearchMenu(data, indexOfFoundProducts, numberOfFoundProducts);
}

int NumberInArray(int number, const int* array, int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
            if (array[i] == number) {
            return 1;
        }
    }
    return 0;
}

void SearchProduct(const char searchTerm[MAX_SEARCH_LEN], data_t* database, int indexOfFoundProducts[MAX_FOUND_PRODUCTS], int* numberOfFoundProducts){

    for (int i = 0; i < database->productSize; i++) {

        if(!strcmp(database->products[i].name, searchTerm) && !NumberInArray(i, indexOfFoundProducts, *numberOfFoundProducts))
        {
            indexOfFoundProducts[*numberOfFoundProducts] = i;
            *numberOfFoundProducts += 1;
        }
    }

}

void SearchTag(const char searchTerm[MAX_SEARCH_LEN], data_t* database, int indexOfFoundProducts[MAX_FOUND_PRODUCTS], int* numberOfFoundProducts){

    for (int i = 0; i < database->tagSize; ++i) {
        if(!strcmp(database->tags[i].name, searchTerm))
        {
            for (int x = 0; x < database->linkTableSize; ++x) {
                if(database->linkTable[x].indexOfTag == i && !NumberInArray(database->linkTable[x].indexOfProduct, indexOfFoundProducts, *numberOfFoundProducts))
                {
                    indexOfFoundProducts[*numberOfFoundProducts] = database->linkTable[x].indexOfProduct;
                    *numberOfFoundProducts += 1;
                }
            }
        }
    }
}

void BroadSearch(const char searchTerm[MAX_SEARCH_LEN], data_t* database, int indexOfFoundProducts[MAX_FOUND_PRODUCTS], int* numberOfFoundProducts){
    for (int i = 0; i < database->productSize; i++) {

        if(strstr(database->products[i].name, searchTerm) && !NumberInArray(i, indexOfFoundProducts, *numberOfFoundProducts))
        {
            indexOfFoundProducts[*numberOfFoundProducts] = i;
            *numberOfFoundProducts += 1;
        }
    }
    for (int i = 0; i < database->tagSize; ++i) {
        if(strstr(database->tags[i].name, searchTerm))
        {
            for (int x = 0; x < database->linkTableSize; ++x) {
                if(database->linkTable[x].indexOfTag == i && !NumberInArray(database->linkTable[x].indexOfProduct, indexOfFoundProducts, *numberOfFoundProducts))
                {
                    indexOfFoundProducts[*numberOfFoundProducts] = database->linkTable[x].indexOfProduct;
                    *numberOfFoundProducts += 1;
                }
            }
        }
    }
}

int SearchData(const char* searchTerm, data_t* database, int indexOfFoundProducts[MAX_FOUND_PRODUCTS]){
    int numberOfFoundProducts = 0;
    SearchProduct(searchTerm, database, indexOfFoundProducts, &numberOfFoundProducts);
    SearchTag(searchTerm, database, indexOfFoundProducts, &numberOfFoundProducts);
    BroadSearch(searchTerm, database, indexOfFoundProducts, &numberOfFoundProducts);
    return numberOfFoundProducts;
}

void GetSearchedProduct(char SearchTerm[MAX_SEARCH_LEN]){
    printf("Please input the desired product or q for quit >");
    scanf(" %[^\n]s", SearchTerm);
}

int SearchMenu(data_t* data, const int indexOfFoundProducts[MAX_FOUND_PRODUCTS], int numberOfFoundProducts){

    char options[MAX_OPTIONS][MAX_STRLEN];

    for (int i = 0; i < numberOfFoundProducts; ++i) {
        for (int x = 0; x < data->productSize; ++x) {
            if(x == indexOfFoundProducts[i]) {
                snprintf(options[i], sizeof(options[i]), "name: %s price: %.2lf kr. price per kilo: %.2lf weight: %.2lf kg store: %s",data->products[x].name,data->products[x].price,data->products[x].pricePerKilo,data->products[x].weight,data->products[x].store);
            }
        }
    }

    int option = CreateMenu(options) - 1;
    return indexOfFoundProducts[option];
}


int FindCheapestProduct(data_t* data, const int indexOfProducts[MAX_FOUND_PRODUCTS], int numberOfProducts){
    int cheapProduct = 1;
    int cheapestProduct;
    for (int i = 0; i < numberOfProducts; ++i) {
        for (int x = 0; x < i; ++x) {
            if(data -> products[indexOfProducts[i]].pricePerKilo >= data -> products[indexOfProducts[x]].pricePerKilo){
                cheapProduct = 0;
            }
        }
        if(cheapProduct){
            cheapestProduct = indexOfProducts[i];
        }
    }

    return cheapestProduct;
}