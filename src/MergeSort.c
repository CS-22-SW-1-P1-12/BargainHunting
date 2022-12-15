#include <stdio.h>
#include <stdlib.h>
#include "Database.h"
#include "Search.h"
#include "Calculations.h"
#include "MergeSort.h"

/**
 * The merge sort algorithm fitted to be used on product_t* arrays
 * The arrays will at the end of the function be sorted from lowest to highest total price
 * @param L The array in question
 * @param start The starting index of the part of the array to be sorted
 * @param end The ending index of the part of the array to be sorted
 */
void MergeSort(product_t** L, int start, int end){
    if(start < end)
    {
        int mid = (start + end)/2;
        MergeSort(L, start, mid);
        MergeSort(L, mid + 1, end);
        Merge(L, start, end, mid);
    }
}

/**
 * The merge part of the merge sort algorithm fitted to be used on product_t* arrays
 * The arrays are sorted based on their total price found with the TotalPrice function
 * @param L The array in question
 * @param start The starting index of the part of the array to be sorted
 * @param end The ending index of the part of the array to be sorted
 * @param mid The index in the middle of start and end
 */
void Merge(product_t** L, int start, int end, int mid){
    product_t** L1 = malloc((mid - start + 1) * sizeof(product_t*));
    for (int i = 0; i < mid - start + 1; ++i) {
        L1[i] = malloc (sizeof(product_t) * MAX_FOUND_PRODUCTS);
    }
    product_t** L2 = malloc((end - mid) * sizeof(product_t*));
    for (int i = 0; i < end - mid; ++i) {
        L2[i] = malloc (sizeof(product_t) * MAX_FOUND_PRODUCTS);
    }

    for (int i = start; i <= end; ++i) {
        if(i <= mid)
            L1[i-start] = L[i];
        else
            L2[i-mid-1] = L[i];
    }

    int i = 0, j = 0;
    while(i < mid - start + 1 && j < end - mid) {
        if (TotalPrice(L1[i]) <= TotalPrice(L2[j])) {
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
    for (int x = 0; x < mid - start + 1; ++x) {
        L1[x] = NULL;
        free(L1[x]);
    }
    L1 = NULL;
    free(L1);
    for (int x = 0; x < end - mid; ++x) {
        L2[x] = NULL;
        free(L2[x]);
    }
    L2 = NULL;
    free(L2);
}
