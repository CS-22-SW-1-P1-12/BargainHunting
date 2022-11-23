#include "search.h"
#include "database.h"
#include <stdio.h>


int printDataBase(){
    data_t* data = LoadDatabase();
    product_t*  product = data->firstProduct;
    while(product != NULL)
    {
        printf("name: %s price: %.2lf kr. ppk: %.2lf weight: %.2lf kg store: %s tags: ",product->name,product->price,product->ppk,product->weight,product->store);
        tag_t* tempTag = product->first_tag;
        while(tempTag != NULL)
        {
            printf("%s, ",tempTag->name);
            tempTag = tempTag->nextTag;
        }
        printf("\n");
        product = product->nextProduct;
    }
}