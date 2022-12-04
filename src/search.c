//
// Created by sinag on 02.12.2022.
//

#include "search.h"
#include "database.h"
#include <stdio.h>
#include <stdlib.h>
#include "CreateMenu.h"
#include <string.h>
#define MAX_SEARCH_LEN 20
#define MAX_FOUND_PRODUCTS 100

//REMEMBER TO FREE AT SOME POINT

int SearchData(const char searchTerm[MAX_SEARCH_LEN], data_t* database, int indexOfFoundProducts[MAX_FOUND_PRODUCTS]);
void GetSearchedProduct(data_t* database, char SearchTerm[MAX_SEARCH_LEN]);
void SearchMenu(data_t* data, int indexOfFoundProducts[MAX_FOUND_PRODUCTS], int numberOfFoundProducts);

int main(){
    data_t* data = LoadDatabase();

    printf("Successfully loaded database\n");

    int indexOfFoundProducts[MAX_FOUND_PRODUCTS];
    char SearchTerm[MAX_SEARCH_LEN];

    int numberOfFoundProducts = 0;

    while(numberOfFoundProducts == 0)
    {
        GetSearchedProduct(data, SearchTerm);
        numberOfFoundProducts = SearchData(SearchTerm, data, indexOfFoundProducts);
        if(numberOfFoundProducts == 0)
        {
            printf("No products matching search\n");
        }
    }

    SearchMenu(data, indexOfFoundProducts, numberOfFoundProducts);

    /*
    printf("Successfully searched for products\n");
    int x = 0;
    for (int i = 0; i < data->productSize; ++i) {

        if(i == indexOfFoundProducts[x])
        {
            printf("name: %s price: %.2lf kr. price per kilo: %.2lf weight: %.2lf kg store: %s tags: ",data->products[i].name,data->products[i].price,data->products[i].pricePerKilo,data->products[i].weight,data->products[i].store);

            for (int j = 0; j < data->linkTableSize; ++j) {
                if(i == data->linkTable[j].indexOfProduct)
                {
                    printf("%s, ",data->tags[data->linkTable[j].indexOfTag].name);
                }
            }
            printf("\n");
            x++;
        }

    }*/
    return 0;
}

void SearchProduct(const char searchTerm[MAX_SEARCH_LEN], data_t* database, int indexOfFoundProducts[MAX_FOUND_PRODUCTS], int* numberOfFoundProducts){

    for (int i = 0; i < database->productSize; i++) {

        if(!strcmp(searchTerm, database->products[i].name))
        {
            indexOfFoundProducts[*numberOfFoundProducts] = i;
            *numberOfFoundProducts += 1;
        }
    }

}

void SearchTag(const char searchTerm[MAX_SEARCH_LEN], data_t* database, int indexOfFoundProducts[MAX_FOUND_PRODUCTS], int* numberOfFoundProducts){

    for (int i = 0; i < database->tagSize; ++i) {
        if(!strcmp(searchTerm, database->tags[i].name))
        {
            for (int x = 0; x < database->linkTableSize; ++x) {
                if(database->linkTable[x].indexOfTag == i)
                {
                    indexOfFoundProducts[*numberOfFoundProducts] = database->linkTable[x].indexOfProduct;
                    *numberOfFoundProducts += 1;
                }
            }
        }
    }
}

int SearchData(const char searchTerm[MAX_SEARCH_LEN], data_t* database, int indexOfFoundProducts[MAX_FOUND_PRODUCTS]){
    int numberOfFoundProducts = 0;
    SearchProduct(searchTerm, database, indexOfFoundProducts, &numberOfFoundProducts);
    SearchTag(searchTerm, database, indexOfFoundProducts, &numberOfFoundProducts);
    return numberOfFoundProducts;
}

void GetSearchedProduct(data_t* database, char SearchTerm[MAX_SEARCH_LEN]){
    printf("Please input the desired product >");
    scanf("%s", SearchTerm);
}

void SearchMenu(data_t* data, int indexOfFoundProducts[MAX_FOUND_PRODUCTS], int numberOfFoundProducts){

    char options[MAX_OPTIONS][MAX_STRLEN];

    /*for (int i = 0; i <= numberOfFoundProducts; ++i) {
        snprintf(options[i], sizeof(options[i]), "name: %s price: %.2lf kr. price per kilo: %.2lf weight: %.2lf kg store: %s tags: ",data->products[i].name,data->products[i].price,data->products[i].pricePerKilo,data->products[i].weight,data->products[i].store);
    }*/

    int x = 0;
    for (int i = 0; i < data->productSize; ++i) {

        if(i == indexOfFoundProducts[x])
        {
            snprintf(options[x], sizeof(options[x]), "name: %s price: %.2lf kr. price per kilo: %.2lf weight: %.2lf kg store: %s",data->products[i].name,data->products[i].price,data->products[i].pricePerKilo,data->products[i].weight,data->products[i].store);
            x++;
        }
    }

    printf("now creating menu");
    CreateMenu(options);
}