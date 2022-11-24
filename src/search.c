#include "search.h"
#include "database.h"
#include <stdio.h>
#include <stdlib.h>
#include "CreateMenu.h"
#include <string.h>
#define MAX_SEARCH_LEN 20


/*
void GetSearchedInput(char* input) {
    printf("\nPlease enter the item you wish to search for: ");
    scanf("%s", input);
}
*/
void SearchDatabase(const char searchTerm[MAX_SEARCH_LEN], data_t* database){
    /*
     * arr[] = {p1 name, p1 price, p1 ppk},
     *         {p2 name, p2 price, p2 ppk}
    */
    product_t* product = database->firstProduct;

    data_t* foundProducts = malloc(sizeof(data_t));
    foundProducts->firstProduct = NULL;

    while(product != NULL){
        if(!strcmp(searchTerm, product->name)){
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

    /*product_t* currentProduct = foundProducts->firstProduct;
    printf("The found products are:\n");
    while(currentProduct != NULL){
        printf("%s", currentProduct->name);
        currentProduct = currentProduct->nextProduct;
    } */

}

int Search(data_t* database){
    char input[MAX_SEARCH_LEN] = "chicken  strips";
    //GetSearchedInput(input); // redefine input to user string

    SearchDatabase(input, database);
}












