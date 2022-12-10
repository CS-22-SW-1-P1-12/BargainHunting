#include <stdio.h>
#include <stdlib.h>

void Merge(int L[], int start, int end, int mid);
void MergeSort(int L[], int start, int end);
void printList(int L[], int size);

void Merge(int L[], int start, int end, int mid){
    int L1[mid - start + 1];
    int L2[end - mid];

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

void MergeSort(int L[], int start, int end){
    if(start < end)
    {
        int mid = (start + end)/2;
        MergeSort(L, start, mid);
        MergeSort(L, mid + 1, end);
        Merge(L, start, end, mid);
    }
}

void printList(int L[], int size){
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", L[i]);
    printf("\n");
}

