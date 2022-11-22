//
// Created by sinag on 17.11.2022.
//
//
// Created by Lennart Diego Kahn on 03/11/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"

int main(){
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
data_t* LoadDatabase(){
    FILE* filePtr;
    filePtr = fopen("./data/data.txt","r");
    if(filePtr == NULL)
    {
        exit(-1);
    }
    data_t* data = malloc(sizeof(data_t));
    data->firstProduct = NULL;
    char buffer[100];
    int test = 0;
    fscanf(filePtr,"%[^\n]",buffer);
    test =fgetc(filePtr);
    while (test != EOF){
        product_t* newProduct= malloc(sizeof(product_t));
        char name[20];
        char store[20];
        char tag[20];
        int checkForEnd;
        fscanf(filePtr,"%[^,]",&name[0]);
        newProduct->name = malloc(sizeof(char) * GetStrLength(name));
        strcpy(newProduct->name,name);
        fgetc(filePtr);
        fscanf(filePtr,"%lf",&newProduct->price);
        fgetc(filePtr);
        fscanf(filePtr,"%lf",&newProduct->ppk);
        fgetc(filePtr);
        fscanf(filePtr,"%lf",&newProduct->weight);
        fgetc(filePtr);
        fscanf(filePtr,"%[^,]",&store[0]);
        newProduct->store = malloc(sizeof(char) * GetStrLength(store));
        strcpy(newProduct->store,store);
        fgetc(filePtr);
        fgetc(filePtr);
        newProduct->first_tag = NULL;
        while(1)
        {
            fscanf(filePtr,"%[^,]",&tag[0]);
            fgetc(filePtr);
            checkForEnd = fgetc(filePtr);
            if(checkForEnd != '\"')
            {
                tag_t* newTag = malloc(sizeof(tag_t));;
                newTag->name = malloc(sizeof(char) * GetStrLength(tag));
                strcpy(newTag->name,tag);
                if(newProduct->first_tag == NULL)
                {
                    newTag->nextTag = NULL;
                    newProduct->first_tag = newTag;
                }
                else{
                    newTag->nextTag = newProduct->first_tag;
                    newProduct->first_tag = newTag;
                }
                fseek(filePtr, -1, SEEK_CUR);
            }
            else{
                break;
            }
        }
        newProduct->nextProduct = data->firstProduct;
        data->firstProduct = newProduct;
        test =fgetc(filePtr);
    }
    fclose(filePtr);
    return data;
}
int GetStrLength(const char* string)
{
    int i= 1;
    while(string[i]!= '\0')
    {
        i++;
    }
    return i;
}