//
// Created by Lennart Diego Kahn
//

#ifndef BARGAINHUNTING_CREATEMENU_H
#define BARGAINHUNTING_CREATEMENU_H
#include <stdlib.h>
#include <stdio.h>
#define MAX_OPTIONS 20
#define MAX_STRLEN 255

int ScanInput(int items);
int CreateMenu(char options[MAX_OPTIONS][MAX_STRLEN]);

#endif //BARGAINHUNTING_CREATEMENU_H