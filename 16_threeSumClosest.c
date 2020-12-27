//
// Created by me_touch on 2020/12/27.
//
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>
#include "thutils.h"

int compare(const void *a, const void *b) {
    int *c = (int *)a;
    int *d = (int *)b;
    return *c - *d;
}
int threeSumClosest(int* nums, int numsSize, int target){
    qsort((void *)nums, numsSize, sizeof(int), compare);
    int result = 0;
    int minDelta = INT_MAX;
    int iLength = numsSize - 2;
    for (int i = 0; i < iLength; ++i) {
        int j = i + 1;
        int k = numsSize - 1;
        while (j < k) {
            int delta = nums[i] + nums[j] + nums[k] - target;
            int temp = abs(delta);
            if (delta == 0) {
                return target;
            } else if (delta < 0) {
                if (minDelta > temp) {
                    result = delta + target;
                    minDelta = temp;
                }
                j++;
            } else if (delta > 0) {
                if (minDelta > temp) {
                    result = delta + target;
                    minDelta = temp;
                }
                k--;
            }
        }
    }
    return result;
}

int main(){
    int num = 5;
    int *a = (int *)malloc(sizeof(int) * num);
    a[0] = -1;
    a[1] = 2;
    a[2] = 1;
    a[3] = -4;
    int result = threeSumClosest(a, 4, 1);
    printf("%d\n ", result);

}