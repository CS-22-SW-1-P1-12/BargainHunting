//
// Created by Bruger on 08-12-2022.
//

#include "findCheapestProduct.h"
#include <stdlib.h>
#include <stdio.h>
#include "search.h"
#include "database.h"

int findCheapestProduct(data_t* data, int indexOfProducts[MAX_FOUND_PRODUCTS], int numberOfProducts){
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
