#include "CreateMenu.h"
#include <stdlib.h>
#include <stdio.h>
#include<string.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define MAX_OPTIONS 20
#define MAX_STRLEN 50




// return the amount of elements inside of options
int Counter(char options[MAX_OPTIONS][MAX_STRLEN]){
    int count;
    for (count = 0; count < MAX_OPTIONS; ++count) {
        if(options[count][0] == NULL){
            break;
        }

    }
    return count;
}

// Draw the entire ui in a pretty way
void Draw(char options[MAX_OPTIONS][MAX_STRLEN]){
    int amountOfElements = Counter(options);
    printf("-------------------------------------------------");

    for (int i = 0; i < amountOfElements; ++i) {
        printf(KNRM "\n %d) ", i+1);
        printf(KGRN "%s", options[i]);
        printf(KNRM "\n-------------------------------------------------");

    }
}

// return the selected option (1,2,3,4,....)
int ScanInput(int items){
    int result;
    while(1){
        printf("\n\nPlease input the number corrisponding to your desired option: ");
        scanf("%d", &result); // replace with a better scanning method
        if(result > 0 && result <= items){
            return result;
        }
        else{
            printf("Please input a valid number :( ");
        }
    }


}


// the main function for this block.
int CreateMenu(char options[MAX_OPTIONS][MAX_STRLEN]){
    Draw(options);
    return ScanInput(Counter(options));
}



