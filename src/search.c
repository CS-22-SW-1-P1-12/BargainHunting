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

void SearchData(const char searchTerm[MAX_SEARCH_LEN], data_t* database, int indexOfFoundProducts[MAX_FOUND_PRODUCTS]);

int main(){
    data_t* data = LoadDatabase();

    printf("Successfully loaded database\n");

    int indexOfFoundProducts[MAX_FOUND_PRODUCTS];

    SearchData("meat", data, indexOfFoundProducts);

    for (int i = 0; i < 3; ++i) {
        printf("number %d: %d\n", i, indexOfFoundProducts[i]);
    }

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

    }
    return 0;
}

/*
void GetSearchedInput(char* input) {
    printf("\nPlease enter the item you wish to search for: ");
    scanf("%s", input);
}
*/
/*void SearchDatabase(const char searchTerm[MAX_SEARCH_LEN], data_t* database){

     * arr[] = {p1 name, p1 price, p1 ppk},
     *         {p2 name, p2 price, p2 ppk}

    int indexOfMatchingProducts[MAX_OPTIONS] = {0};

    product_t* product = database->firstProduct;

    data_t* foundProducts = malloc(sizeof(data_t));
    foundProducts->firstProduct = NULL;

    int i = 0;
    while(product != NULL){
        if(!strcmp(searchTerm, product->name)){

            indexOfMatchingProducts[i] = product->index;
            i++;

            printf("\n%s product matched our input\n", product->name);
            printf( "Name: %s, price: %lf kr. ppk: %lf kr/kg, store: %s\n", product->name,product->price,product->ppk,product->store);

            product_t* newMatchingProduct = malloc(sizeof(product_t));

            newMatchingProduct = product;

            newMatchingProduct->nextProduct = foundProducts->firstProduct;
            foundProducts->firstProduct = newMatchingProduct;
        }
        // printf("name: %s, price: %.2lf kr., ppk: %.2lf, weight: %.2lf kg, store: %s tags: ",product->name,product->price,product->ppk,product->weight,product->store);
        tag_t* tempTag = product->first_tag;
        while(tempTag != NULL){
            //printf("%s, ",tempTag->name);
            tempTag = tempTag->nextTag;
        }
        //printf("\n");
        product = product->nextProduct;
    }

    for (int j = 0; j < MAX_OPTIONS; ++j) { //printing to test if index field of product struct is saved

        if(indexOfMatchingProducts[j] != 0){
            printf("this is saved index of nr %d product matching search: %d\n", j+1, indexOfMatchingProducts[j]);
        }
    }
     product_t* currentProduct = foundProducts->firstProduct;
    printf("The found products are:\n");
    while(currentProduct != NULL){
        printf("%s", currentProduct->name);
        currentProduct = currentProduct->nextProduct;
    }

}*/

void SearchProduct(const char searchTerm[MAX_SEARCH_LEN], data_t* database, int indexOfFoundProducts[MAX_FOUND_PRODUCTS], int* numberOfFoundProducts){


    for (int i = 0; i < database->productSize; i++) {

        if(!strcmp(searchTerm, database->products[i].name))
        {
            indexOfFoundProducts[*numberOfFoundProducts] = i;
            *numberOfFoundProducts += 1;
            printf("found product!\n");
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
                    printf("found product!\n");
                }
            }
        }
    }
}

void SearchData(const char searchTerm[MAX_SEARCH_LEN], data_t* database, int indexOfFoundProducts[MAX_FOUND_PRODUCTS]){
    int numberOfFoundProducts = 0;

    printf("Beginning search\n");
    SearchProduct(searchTerm, database, indexOfFoundProducts, &numberOfFoundProducts);
    printf("Beginning tag search\n");
    SearchTag(searchTerm, database, indexOfFoundProducts, &numberOfFoundProducts);
}

/*int Search(data_t* database){
    char input[MAX_SEARCH_LEN] = "chickenstrips";
    //GetSearchedInput(input); // redefine input to user string

    SearchDatabase(input, database);
}*/
