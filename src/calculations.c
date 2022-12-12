//
// Created by sinag on 17.11.2022.
//
#include "stdio.h"
#include "database.h"
#include "search.h"
#include "CreateMenu.h"
#include "string.h"
#include "ListSearch.h"
#define MAX_STR_LEN 20

void Calculations (product_t **storeProducts, int numberOfStores, char** stores, const int* numberOfProducts){


    //use Sinas functions to get lengths
    double results[numberOfStores][2]; //10 skal ændres

    printf("cry\n");

    for (int i = 0; i < numberOfStores; i++) {

        double totalPrice = 0, totalPricePerKilo = 0;
        char *storeName = storeProducts[i][0].name;

        printf("number of products %d\n", numberOfProducts[i]);

        for (int x = 0; x < numberOfProducts[i]; ++x) {

            totalPrice += storeProducts[i][x].price;
            totalPricePerKilo += storeProducts[i][x].pricePerKilo;


        }

        printf("cry\n");

        results[i][0] = totalPrice;    //casting to char in order for the price values to be stored in the char array with results
        results[i][1] = totalPricePerKilo;
        printf("results obtained\n");

    }

    int x = 0, counter = 0;
    double temp[1][1];

    while(counter < numberOfStores) { //fix 10

        while (x < numberOfStores) { //fix the length skal være nr of stores og ikke 10

            if (results[x][0] > results[x + 1][0]) {

            //swap index x,0
            temp[0][0] = results[x][0];
            results[x][0] = results[x + 1][0];
            results[x + 1][0] = temp[0][0];

            //swap index x,1
            temp[0][0] = results[x][1];
            results[x][1] = results[x + 1][1];
            results[x + 1][1] = temp[0][0];

            } else {
             ++counter;
            }

        ++x;

        }
        x = 0;          //resets x to loop through array again
        if(counter == numberOfStores){ //checks if array is sorted and starts over if not
            break;
        }else {
            counter = numberOfStores;
        }

    }



    printf("-------------------------------------------------\n");

    for (int i = 0; i < numberOfStores; ++i) { //fix the thing 10
        printf("-------------------------------------------------");
        printf("%s: ", stores[i]);
        printf("price (total): ");
        printf("%lf ", results[i][0]);
        printf("price per kg: ");
        printf("%lf ", results[i][1]);
        printf("\n");


    }


}

