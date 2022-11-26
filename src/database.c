//
// Created by sinag on 17.11.2022.
//
//
// Created by Lennart Diego Kahn on 03/11/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "database.h"

int main(){
    clock_t start, end;
    /* Store start time here */
    start = clock();
    data_t* data = LoadDatabase();
//    product_t*  product = data->firstProduct;
//    while(product != NULL)
//    {
//        printf("name: %s price: %.2lf kr. ppk: %.2lf weight: %.2lf kg store: %s tags: ",product->name,product->price,product->ppk,product->weight,product->store);
//        tag_t* tempTag = product->first_tag;
//        while(tempTag != NULL)
//        {
//            printf("%s, ",tempTag->name);
//            tempTag = tempTag->nextTag;
//        }
//        printf("\n");
//        product = product->nextProduct;
//    }
    end = clock();
    product_t tempProduct;
    tag_t tempTag;
    for (int i = 0; i < data->productSize; ++i) {
        tempProduct = data->products[i];
        tempProduct;
        for (int j = 0; j < data->linkTableSize; ++j) {
            if(i == data->linkTable[j].indexOfProduct)
            {
                tempTag = data->tags[data->linkTable[j].indexOfTag];
                tempTag;
            }
        }
        printf("\n");
    }

    double duration = ((double)end - start)/CLOCKS_PER_SEC;
    printf("Time taken to execute in seconds : %f \n", duration);
    return 0;
}
data_t* LoadDatabase(){
    FILE* filePtr;
    filePtr = fopen("data/data.txt","r");
    if(filePtr == NULL)
    {
        exit(-1);
    }
    data_t* data = malloc(sizeof(data_t));
    char buffer[100];
    int test;
    data->productSize = 0;
    data->tagSize = 0;
    data->linkTableSize = 0;
    do{
        fscanf(filePtr,"%[^\n]",buffer);
        test = getc(filePtr);
        data->productSize++;
    }
    while(test != EOF);
    data->productSize--;
    rewind(filePtr);

    data->products = malloc(sizeof (product_t) * data->productSize-1);

    fscanf(filePtr,"%[^\n]",buffer);
    test =fgetc(filePtr);
    int i = 0;
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
        int stopRun = 0;

        while(!stopRun)
        {
            fscanf(filePtr,"%[^,]",&tag[0]);
            fgetc(filePtr);
            checkForEnd = fgetc(filePtr);
            if(checkForEnd == '\"')
            {
                stopRun = 1;
            }
            else{
                fseek(filePtr, -1, SEEK_CUR);
            }
//            tag_t* newTag = malloc(sizeof(tag_t));;
//            newTag->name = malloc(sizeof(char) * GetStrLength(tag));
//            strcpy(newTag->name,tag);
//
//            newTag->nextTag = newProduct->first_tag;
//            newProduct->first_tag = newTag;
            if(data->tagSize == 0)
            {
                data->tagSize++;
                data->linkTableSize++;
                tag_t* newTag = malloc(sizeof(tag_t));;
                newTag->name = malloc(sizeof(char) * GetStrLength(tag));
                strcpy(newTag->name,tag);
                data->tags = malloc(sizeof(tag_t)*data->tagSize);
                data->linkTable = malloc(sizeof(link_table_t)*data->linkTableSize);
                link_table_t newLink;
                newLink.indexOfProduct = i;
                newLink.indexOfTag =  0;
                data->tags[data->tagSize-1] = *newTag;
                data->linkTable[data->linkTableSize-1] = newLink;
            }
            else
            {
                int found = 0;
                for (int j = 0; j < data->tagSize; ++j) {
                    if(strcmp(tag,data->tags[j].name) == 0)
                    {
                        found = j+1;
                    }
                }
                if(!found)
                {
                    data->tagSize++;
                    data->linkTableSize++;
                    tag_t* newTag = malloc(sizeof(tag_t));;
                    newTag->name = malloc(sizeof(char) * GetStrLength(tag));
                    strcpy(newTag->name,tag);
                    tag_t* tags = malloc(sizeof(tag_t)*data->tagSize);
                    for(int j = 0; j <data->tagSize-1; j++ )
                    {
                        tags[j] = data->tags[j];
                    }
                    free(data->tags);
                    data->tags = tags;
                    link_table_t* linkTable = malloc(sizeof(link_table_t)*data->linkTableSize);
                    for(int j = 0; j <data->linkTableSize-1; j++ )
                    {
                        linkTable[j] = data->linkTable[j];
                    }
                    free(data->linkTable);
                    data->linkTable = linkTable;
                    link_table_t newLink;
                    newLink.indexOfProduct = i;
                    newLink.indexOfTag =  data->tagSize-1;
                    data->tags[data->tagSize-1] = *newTag;
                    data->linkTable[data->linkTableSize-1] = newLink;
                }
                else
                {
                    data->linkTableSize++;
                    link_table_t* linkTable = malloc(sizeof(link_table_t)*data->linkTableSize);
                    for(int j = 0; j <data->linkTableSize-1; j++ )
                    {
                        linkTable[j] = data->linkTable[j];
                    }
                    free(data->linkTable);
                    data->linkTable = linkTable;
                    link_table_t newLink;
                    newLink.indexOfProduct = i;
                    newLink.indexOfTag =  found-1;
                    data->linkTable[data->linkTableSize-1] = newLink;
                }

            }

        }

        data->products[i] = *newProduct;
        i++;
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