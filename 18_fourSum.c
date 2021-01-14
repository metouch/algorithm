//
// Created by me_touch on 2021/1/11.
//
#include <stdio.h>
#include <stdlib.h>

int compare(const void *c, const void *d) {
    int *a = (int *)c;
    int *b = (int *)d;
    return *a - *b;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    int size = numsSize * numsSize;
    int **p = (int **)malloc(sizeof(int *) * size);
    if (numsSize < 4) {
        return p;
    }
    qsort((void *)nums, numsSize, sizeof(int), compare);
    int *columnSizes = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i < numsSize - 3;) {
        int valueI = nums[i];
        if (valueI + nums[numsSize - 1] + nums[numsSize - 2] + nums[numsSize - 3] < target) {
            i++;
            continue;
        }
        if (valueI + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
            break;
        }
        for (int j = i + 1; j < numsSize - 2;) {
            int valueJ = nums[j];
            if (valueI + valueJ + nums[numsSize - 1] + nums[numsSize - 2] < target) {
                j++;
                continue;
            }
            if (valueI + valueJ + nums[j + 1] + nums[j + 2] > target) {
                break;
            }
            int k = j + 1;
            int l = numsSize - 1;
            while (k < l) {
                int valueK = nums[k];
                int valueL = nums[l];
                int sum = valueI + valueJ + valueK + valueL;
                if (sum < target) {
                    while ((++k < l) && nums[k] == valueK);
                } else if (sum > target) {
                    while ((--l > k) && nums[l] == valueL);
                } else {
                    p[*returnSize] = malloc(sizeof(int) * 4);
                    p[*returnSize][0] = nums[i];
                    p[*returnSize][1] = nums[j];
                    p[*returnSize][2] = nums[k];
                    p[*returnSize][3] = nums[l];
                    columnSizes[*returnSize] = 4;
                    while ((++k < l) && nums[k] == valueK);
                    while ((--l > k) && nums[l] == valueL);
                    (*returnSize)++;
                }
            }
            while ((++j < numsSize - 2) && nums[j] == valueJ);
        }
        while ((++i < numsSize - 3) && nums[i] == valueI);
    }
    *returnColumnSizes = columnSizes;
    return p;
}

int main(){
    int *a = (int *)malloc(sizeof(int) * 4);
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    a[3] = 0;
//    a[4] = -2;
//    a[5] = 2;
    int returnSize = 0;
    int **returnColumnSize = (int **)malloc(sizeof(int *));
    int** p = fourSum(a, 4, 0, &returnSize, returnColumnSize);
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