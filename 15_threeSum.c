//
// Created by me_touch on 2020/12/14.
//
#include <stdio.h>
#include <stdlib.h>
#include "thsort.h"

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int m = numsSize * numsSize;
    int n = 3;
    if (m < 1) {
        *returnSize = 0;
        return NULL;
    }
    int **p = (int **)malloc(sizeof(int *) * m);
    int *columnSize = (int *)malloc(sizeof(int) * m);
    *returnSize = 0;
    quickSort(nums, 0, numsSize - 1);
    for (int i = 0; i < numsSize - 2; ++i) {
        int j = i + 1;
        int k = numsSize - 1;
        while (j < k) {
            int sum = nums[j] + nums[k] + nums[i];
            if (sum < 0) {
                j++;
            } else if (sum > 0) {
                k --;
            } else {
                p[*returnSize] = (int *)malloc(sizeof(int) * 3);
                p[*returnSize][0] = nums[i];
                p[*returnSize][1] = nums[j];
                p[*returnSize][2] = nums[k];
                columnSize[*returnSize] = n;
                while (nums[j] == nums[j + 1]){
                    j++;
                }
                j++;
                while (nums[k] == nums[k - 1]){
                    k--;
                }
                k--;
                *returnSize += 1;
            }
        }
        while (i + 1 < numsSize - 2 && (nums[i] == nums[i + 1])){
            i++;
        }
    }
    *returnColumnSizes = columnSize;
    return p;
}

int main(){
    int *a = (int *)malloc(sizeof(int) * 5);
    a[0] = -2;
    a[1] = 0;
    a[2] = 1;
    a[3] = 1;
    a[4] = 2;
    int returnSize = 0;
    int **returnColumnSize = (int **)malloc(sizeof(int *));
    int** p = threeSum(a, 5, &returnSize, returnColumnSize);
    for (int i = 0; i < returnSize; ++ i) {
        int size = *(*returnColumnSize + i);
        printf("[");
        for (int j = 0; j < size; ++j) {
            printf("%d, ", p[i][j]);
        }
        printf("]");
        printf("\n");
    }
}