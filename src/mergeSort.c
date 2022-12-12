#include <stdio.h>
#include <stdlib.h>
#include "database.h"

void Merge(product_t*** L, int start, int end, int mid);
void MergeSort(product_t*** L, int start, int end);

void Merge(product_t*** L, int start, int end, int mid){
    product_t** L1[mid - start + 1];
    product_t** L2[end - mid];

    for (int i = start; i <= end; ++i) {
        if(i <= mid)
            L1[i-start] = L[i];
        else
            L2[i-mid-1] = L[i];
    }

    int i = 0, j = 0;
    while(i < mid - start + 1 && j < end - mid) {
        if (L1[i] <= L2[j]) {
            L[start + i + j] = L1[i];
            i++;
        } else {
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
}

void MergeSort(product_t*** L, int start, int end){
    if(start < end)
    {
        int mid = (start + end)/2;
        MergeSort(L, start, mid);
        MergeSort(L, mid + 1, end);
        Merge(L, start, end, mid);
    }
}

