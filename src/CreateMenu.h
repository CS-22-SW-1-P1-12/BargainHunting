//
// Created by Lennart Diego Kahn on 21/11/2022.
//

#ifndef BARGAINHUNTING_CREATEMENU_H
#define BARGAINHUNTING_CREATEMENU_H

#define MAX_OPTIONS 20
#define MAX_STRLEN 100

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

int CreateMenu(char options[MAX_OPTIONS][MAX_STRLEN]);


#endif //BARGAINHUNTING_CREATEMENU_H

