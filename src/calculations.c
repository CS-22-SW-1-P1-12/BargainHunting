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

void Calculations (product_t **storeProducts){


    //use Sinas functions to get lengths
    char results[10][3]; //10 skal ændres


    for (int i = 0; storeProducts[i] != NULL  ; ++i) {

        double totalPrice = 0, totalPricePerKilo = 0;
        char *storeName = storeProducts[i]->name;

        for (int j = 0; j < 5; ++j) { //fix the length thing!!

            if (storeProducts[j]->store == storeProducts[j-1]->store || j == 0) { //checks if store name is the same and increments total prices for this store if true
                totalPrice += storeProducts[i]->price;
                totalPricePerKilo += storeProducts[i]->pricePerKilo;
            }

        }

        results[i][0] = *storeName;
        results[i][1] = (char)totalPrice;    //casting to char in order for the price values to be stored in the char array with results
        results[i][2] = (char)totalPricePerKilo;


    }


    int x = 0, counter = 0;
    char temp[1][1];



    while(counter < 10) { //fix 10

        while (x < 10) { //fix the length skal være nr of stores og ikke 10

            if (results[x][1] > results[x + 1][1]) {

            //swap index x,0
            temp[0][0] = results[x][0];
            results[x][0] = results[x + 1][0];
            results[x + 1][0] = temp[0][0];

            //swap index x,1
            temp[0][0] = results[x][1];
            results[x][1] = results[x + 1][1];
            results[x + 1][1] = temp[0][0];

            //swap index x,2
            temp[0][0] = results[x][2];
            results[x][2] = results[x + 1][2];
            results[x + 1][2] = temp[0][0];
            } else {
             ++counter;
            }

        ++x;

        }
        x = 0;          //resets x to loop through array again
        if(counter == 10){ //checks if array is sorted and starts over if not
            break;
        }else {
            counter = 0;
        }

    }



    printf("-------------------------------------------------");

    for (int i = 0; i < 10; ++i) { //fix the thing 10
        printf("-------------------------------------------------");
        for (int j = 0; j < MAX_STR_LEN; ++j) {

            printf("%c", results[i][j]);

        }
        printf("\n");


    }


}

