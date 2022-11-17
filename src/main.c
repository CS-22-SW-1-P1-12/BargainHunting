//
// Created by Lennart Diego Kahn on 03/11/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tag{
    char name[24];
    struct Tag* next_tag;
};

struct Product{
    char name[24];
    double price;
    double ppk;
    struct Tag* first_tag;
};

#include "main.h"
int main(){


    struct Product milk = {
            "Milk",
            12.0,
            12.0,
            NULL,
    };

    struct Tag* new_tag = (struct Tag*) malloc(sizeof(struct Tag));
    new_tag->next_tag = milk.first_tag;
    strcpy(new_tag->name, "REMA 1000");
    milk.first_tag = new_tag,


    printf("NAME: %s\nPRICE: %lf\nPRICE PER KG: %lf\nSTORE: %s", milk.name, milk.price, milk.ppk, milk.first_tag->name);
}