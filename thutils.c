//
// Created by me_touch on 2020/12/20.
//

#include <stdio.h>
#include "thutils.h"

void printIntNum(int *arr, int arrSize){
    for (int i = 0; i < arrSize; ++i) {
        printf("%d, ", arr[i]);
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}