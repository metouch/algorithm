//
// Created by me_touch on 2020/12/20.
//
#include <stdio.h>
#include <stdlib.h>
#include "thsort.h"
#include "thutils.h"

// test swap()
void main_swap(){
    int a = 5, b = 10;
    swap(&a, &b);
    printf("%d, %d\n", a, b);
}

void main(){
    int *a = (int *)malloc(sizeof(int) * 5);
    a[0] = 1;
    a[1] = 1;
    a[2] = 3;
    a[3] = 2;
    a[4] = 2;
    quickSort(a, 0, 4);
    printIntNum(a, 5);
}