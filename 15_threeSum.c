//
// Created by me_touch on 2020/12/14.
//
#include <stdio.h>
#include <stdlib.h>
#include "thsort.h"

void threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int m = numsSize / 3;
    int n = 3;
    int p[m][n];
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
                printf("[%d, %d, %d]\n", nums[i], nums[j], nums[k]);
                while ((j + 1 < k) && (nums[j] == nums[j + 1])){
                    j++;
                }
                j++;
                while ((k - 1 > j) && (nums[k] == nums[k - 1])){
                    k--;
                }
                k--;
            }
        }
        while (i + 1 < numsSize - 2 && (nums[i] == nums[i + 1])){
            i++;
        }
    }
}

int main(){
    int *a = (int *)malloc(sizeof(int) * 5);
    a[0] = 0;
    a[1] = 0;
    a[2] = 0;
    a[3] = 0;
    a[4] = 0;
    a[5] = 0;
    int *p[3];
    int returnSize = 0;
    threeSum(a, 6, &returnSize, NULL);

}