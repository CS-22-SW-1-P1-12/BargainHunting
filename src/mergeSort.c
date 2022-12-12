#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"
#include "search.h"
#include "calculations.h"


void Merge(product_t** L, int start, int end, int mid, const int* numberOfProducts){
    product_t** L1 = malloc((mid - start + 1) * sizeof(product_t*));
    for (int i = 0; i < mid - start + 1; ++i) {
        L1[i] = malloc (sizeof(product_t) * MAX_FOUND_PRODUCTS);
    }
    product_t** L2 = malloc((end - mid) * sizeof(product_t*));
    for (int i = 0; i < end - mid; ++i) {
        L2[i] = malloc (sizeof(product_t) * MAX_FOUND_PRODUCTS);
    }
    for (int i = 0; i < end - mid; ++i) {
        L2[i][0].name = "END";
    }
    printf("malloced\n");

    for (int i = start; i <= end; ++i) {
        if(i <= mid)
            L1[i-start] = L[i];
        else
            L2[i-mid-1] = L[i];
    }

    int i = 0, j = 0;
    while(i < mid - start + 1 && j < end - mid) {
        printf("going to compare\n");
        printf("%lf", TotalPrice(L1[i]));
        printf("%lf", TotalPrice(L2[j]));
        if (TotalPrice(L1[i]) <= TotalPrice(L2[j])) {
            printf("Left is not bigger");
            L[start + i + j] = L1[i];
            i++;
        } else {
            printf("Left is bigger");
            L[start + i + j] = L2[j];
            j++;
        }
    }
    if(i == mid - start + 1) {
        for (int k = j; k <= end - mid - 1; k++) {
            L[start + i + k] = L2[k];
        }
    } else {
        for (int k = i; k <= mid - start; k++) {
            L[start + j + k] = L1[k];
        }
    }
    printf("trying to free\n");
    for (int x = 0; x < mid - start + 1; ++x) {
        L1[x] = NULL;
        free(L1[x]);
    }
    printf("freed1\n");
    L1 = NULL;
    free(L1);
    for (int x = 0; x < end - mid; ++x) {
        L2[x] = NULL;
        free(L2[x]);
    }
    L2 = NULL;
    free(L2);
    printf("freed\n");
}

void MergeSort(product_t** L, int start, int end, const int* numberOfProducts){
    if(start < end)
    {
        int mid = (start + end)/2;
        MergeSort(L, start, mid, numberOfProducts);
        MergeSort(L, mid + 1, end, numberOfProducts);
        Merge(L, start, end, mid, numberOfProducts);
    }
}

