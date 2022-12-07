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


data_t* LoadDatabase(){
    FILE* filePtr;
    filePtr = fopen("data/data.txt","r");
    if(filePtr == NULL)
    {
        exit(-1);
    }
    data_t* data = malloc(sizeof(data_t));
    char buffer[100];
    int checkingNextChar;   //hvorfor int?
    data->productSize = 0;
    data->tagSize = 0;
    data->linkTableSize = 0;
    //checking for amount of lines in file to make data array
    do{
        fscanf(filePtr,"%[^\n]",buffer);
        checkingNextChar = getc(filePtr);
        data->productSize++;
    }
    while(checkingNextChar != EOF);
    //remove 1 for the extra line at the top and rewind the file to start
    data->productSize--;
    rewind(filePtr);
    //allocating enough space for the products
    data->products = malloc(sizeof(product_t) * data->productSize);
    //moving pointer 1 line
    fscanf(filePtr,"%[^\n]",buffer);
    checkingNextChar = fgetc(filePtr);
    int i = 0;
    //loop of making product_t with its tag_t and linking them with link_table_t
    while (checkingNextChar != EOF){
        //creating new product
        product_t* newProduct = malloc(sizeof(product_t));
        //variablers to temp hold variable values before storing them in product or tag
        char name[MAX_STR_LEN];
        char store[MAX_STR_LEN];
        char tag[MAX_STR_LEN];
        int checkForEnd;
        //scanning till comma and storing in name
        fscanf(filePtr,"%[^,]",&name[0]);
        newProduct->name = malloc(sizeof(char) * GetStrLength(name));
        strcpy(newProduct->name,name);
        fgetc(filePtr);
        fscanf(filePtr,"%lf",&newProduct->price);
        fgetc(filePtr);
        fscanf(filePtr,"%lf",&newProduct->pricePerKilo);
        fgetc(filePtr);
        fscanf(filePtr,"%lf",&newProduct->weight);
        fgetc(filePtr);
        fscanf(filePtr,"%[^,]",&store[0]);
        newProduct->store = malloc(sizeof(char) * GetStrLength(store));
        strcpy(newProduct->store,store);
        fgetc(filePtr);
        fgetc(filePtr);
        int stopRun = 0;
        //making tags and taglink runs while stoprun is false
        while(!stopRun)
        {
            fscanf(filePtr,"%[^,]",&tag[0]);
            fgetc(filePtr);
            //checking for " after comma if found last run if not move 1 back
            checkForEnd = fgetc(filePtr);
            if(checkForEnd == '\"')
            {
                stopRun = 1;
            }
            else{
                fseek(filePtr, -1, SEEK_CUR);
            }
            //if this is first tag
            if(data->tagSize == 0)
            {
                data->tagSize++;
                data->linkTableSize++;
                tag_t* newTag = malloc(sizeof(tag_t));;
                newTag->name = malloc(sizeof(char) * GetStrLength(tag));
                strcpy(newTag->name,tag);
                data->tags = malloc(sizeof(tag_t) * data->tagSize);
                data->linkTable = malloc(sizeof(link_table_t) * data->linkTableSize);
                link_table_t newLink;
                newLink.indexOfProduct = i;
                newLink.indexOfTag =  data->tagSize -1;
                data->tags[data->tagSize-1] = *newTag;
                data->linkTable[data->linkTableSize-1] = newLink;
            }
            else
            {
                //if not first tag look to see if tag already exists adding +1 to index in case tag on index 0 is found
                int found = 0;
                for (int j = 0; j < data->tagSize; ++j) {
                    if(strcmp(tag,data->tags[j].name) == 0)
                    {
                        found = j+1;
                    }
                }
                //if tag not found allocating for new arrays moving all data releasing space and then moving pointer to data struct
                if(!found)
                {
                    data->tagSize++;
                    data->linkTableSize++;
                    tag_t* newTag = malloc(sizeof(tag_t));
                    newTag->name = malloc(sizeof(char) * GetStrLength(tag));
                    strcpy(newTag->name,tag);
                    tag_t* tags = malloc(sizeof(tag_t) * data->tagSize);
                    for(int j = 0; j < data->tagSize-1; j++ )
                    {
                        tags[j] = data->tags[j];
                    }
                    free(data->tags);
                    data->tags = tags;
                    link_table_t* linkTable = malloc(sizeof(link_table_t) * data->linkTableSize);
                    for(int j = 0; j <data->linkTableSize-1; j++)
                    {
                        linkTable[j] = data->linkTable[j];
                    }
                    free(data->linkTable);
                    data->linkTable = linkTable;
                    link_table_t newLink;
                    newLink.indexOfProduct = i;
                    newLink.indexOfTag = data->tagSize-1;
                    data->tags[data->tagSize-1] = *newTag;
                    data->linkTable[data->linkTableSize-1] = newLink;
                }
                else
                {
                    //if tag found doing same as above just without adding a new tag
                    data->linkTableSize++;
                    link_table_t* linkTable = malloc(sizeof(link_table_t) * data->linkTableSize);
                    for(int j = 0; j <data->linkTableSize-1; j++)
                    {
                        linkTable[j] = data->linkTable[j];
                    }
                    free(data->linkTable);
                    data->linkTable = linkTable;
                    link_table_t newLink;
                    newLink.indexOfProduct = i;
                    newLink.indexOfTag = found-1;
                    data->linkTable[data->linkTableSize-1] = newLink;
                }

            }

        }

        data->products[i] = *newProduct;
        i++;
        checkingNextChar =fgetc(filePtr);
    }
    fclose(filePtr);
    return data;
}
int GetStrLength(const char* string)
{
    int i = 1;
    while(string[i]!= '\0')
    {
        i++;
    }
    return i;
}