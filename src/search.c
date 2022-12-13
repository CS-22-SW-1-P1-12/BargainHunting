//
// Created by sinag on 02.12.2022.
//

#include "search.h"
#include "database.h"
#include <stdio.h>
#include "CreateMenu.h"
#include <string.h>

//REMEMBER TO FREE AT SOME POINT

/**
 * This function asks a user for a product name and searches through a database
 * It then finds all the products that match this search (name or tag)
 * @param data The database as defined in database.h
 * @return It returns the index of one of the found products, chosen by the user. If the user quits, it returns -1
 */
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

/**
 * This helper function searches for an int in an int array
 * @param number The number that will be searched for
 * @param array A pointer to the array
 * @param arraySize The size of the array
 * @return If the int is found in the array, return 1. Else 0
 */
int NumberInArray(int number, const int* array, int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
            if (array[i] == number) {
            return 1;
        }
    }
    return 0;
}

/**
 * This function searches for a product in a database matching a string
 * The product's index is then added to an array
 * @param searchTerm The string that will be searched for
 * @param database The database as defined in database.c
 * @param indexOfFoundProducts An array of product indexes
 * @param numberOfFoundProducts The number of products in the array
 */
void SearchProduct(const char searchTerm[MAX_SEARCH_LEN], data_t* database, int indexOfFoundProducts[MAX_FOUND_PRODUCTS], int* numberOfFoundProducts){
    for (int i = 0; i < database->productSize; i++) {
        //If the name matches the search term and doesn't exist in the array, the product is added to indexOfFoundProducts
        if(!strcmp(database->products[i].name, searchTerm) && !NumberInArray(i, indexOfFoundProducts, *numberOfFoundProducts))
        {
            indexOfFoundProducts[*numberOfFoundProducts] = i;
            *numberOfFoundProducts += 1;
        }
    }

}

/**
 * This function does the same as SearchProduct, but for matching tags instead of names
 * @param searchTerm The string that will be searched for
 * @param database The database as defined in database.c
 * @param indexOfFoundProducts An array of product indexes
 * @param numberOfFoundProducts The number of products in the array
 */
void SearchTag(const char searchTerm[MAX_SEARCH_LEN], data_t* database, int indexOfFoundProducts[MAX_FOUND_PRODUCTS], int* numberOfFoundProducts){

    for (int i = 0; i < database->tagSize; ++i) {
        if(!strcmp(database->tags[i].name, searchTerm))
        {
            //Searching through the linkTable to find a matching tag
            for (int x = 0; x < database->linkTableSize; ++x) {
                //If a matching tag is found, the associated products' indeces are added to the array, provided they are not there already
                if(database->linkTable[x].indexOfTag == i && !NumberInArray(database->linkTable[x].indexOfProduct, indexOfFoundProducts, *numberOfFoundProducts))
                {
                    indexOfFoundProducts[*numberOfFoundProducts] = database->linkTable[x].indexOfProduct;
                    *numberOfFoundProducts += 1;
                }
            }
        }
    }
}

/**
 * This function works similarly to SearchProduct and SearchTag
 * However, it checks if a product contains the search term instead of matching it
 * @param searchTerm The string that will be searched for
 * @param database The database as defined in database.c
 * @param indexOfFoundProducts An array of product indexes
 * @param numberOfFoundProducts The number of products in the array
 */
void BroadSearch(const char searchTerm[MAX_SEARCH_LEN], data_t* database, int indexOfFoundProducts[MAX_FOUND_PRODUCTS], int* numberOfFoundProducts){
    for (int i = 0; i < database->productSize; i++) {
        //strstr is used to find if a product contains the searchTerm
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

/**
 * This function calls the other search functions in order
 * It adds the indexes of the found products to an int array
 * It calls the search function in order of relevance
 * Products that completely match are added first, then products with matching tags
 * Lastly, products whose name/tag contains the search term are added
 * @param searchTerm The string that will be searched for
 * @param database The database as defined in database.c
 * @param indexOfFoundProducts An array of product indexes that will be filled with this function
 * @return The function also returns the number of found products for further use
 */
int SearchData(const char* searchTerm, data_t* database, int indexOfFoundProducts[MAX_FOUND_PRODUCTS]){
    int numberOfFoundProducts = 0;
    SearchProduct(searchTerm, database, indexOfFoundProducts, &numberOfFoundProducts);
    SearchTag(searchTerm, database, indexOfFoundProducts, &numberOfFoundProducts);
    BroadSearch(searchTerm, database, indexOfFoundProducts, &numberOfFoundProducts);
    return numberOfFoundProducts;
}

/**
 * This function asks the user to input a product and then saves this as a string
 * @param SearchTerm The string the user inputs
 */
void GetSearchedProduct(char SearchTerm[MAX_SEARCH_LEN]){
    printf("Please input the desired product or q for quit >");
    scanf(" %[^\n]s", SearchTerm);
}

/**
 * This function uses CreateMenu to allow the user to pick a found product
 * The name, price, price per kg and weight of each product is displayed to the user
 * Then, the user can input which product they desire
 * @param data The database as defined in database.c
 * @param indexOfFoundProducts An array of product indexes
 * @param numberOfFoundProducts The number of products in the array
 * @return The return value is the index of the product the user chooses
 */
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


/**
 * This function uses an array of product indexes
 * It then finds the index that points to the product with the lowest price per kg
 * @param data The database as defined in database.c
 * @param indexOfProducts An array of product indexes that will be filled with this function
 * @param numberOfProducts The number of products in the array
 * @return The index of the cheapest product of the array
 */
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