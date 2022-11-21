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
    LoadDatabase();
}
data_t LoadDatabase(){
    FILE* filePtr;
    filePtr = fopen("./data/data.txt","r");
    if(filePtr == NULL)
    {
        exit(-1);
    }
    data_t* data = malloc(sizeof(data_t));
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
        fscanf(filePtr,"%[^,]",&name);
        newProduct->name = malloc(sizeof(char) * GetStrLength(name));
        strcpy(newProduct->name,name);
        fgetc(filePtr);
        fscanf(filePtr,"%lf",&newProduct->price);
        fgetc(filePtr);
        fscanf(filePtr,"%lf",&newProduct->ppk);
        fgetc(filePtr);
        fscanf(filePtr,"%lf",&newProduct->weight);
        fgetc(filePtr);
        fscanf(filePtr,"%[^,]",&store);
        newProduct->store = malloc(sizeof(char) * GetStrLength(store));
        strcpy(newProduct->store,store);
        fgetc(filePtr);
        fgetc(filePtr);
        while(1)
        {
            fscanf(filePtr,"%[^,]",&tag);
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
        printf("%s\n",newProduct->name);
        printf("%.2lf\n",newProduct->price);
        printf("%.2lf\n",newProduct->ppk);
        printf("%.2lf\n",newProduct->weight);
        printf("%s\n",newProduct->store);
        test =fgetc(filePtr);
    }
    fclose(filePtr);
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