//
// Created by me_touch on 20-11-6.
//

/*
 * 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

   你可以假设数组中无重复元素。

   示例 1:
   输入: [1,3,5,6], 5
   输出: 2

   示例 2:
   输入: [1,3,5,6], 2
   输出: 1

   示例 3:
   输入: [1,3,5,6], 7
   输出: 4

   示例 4:
   输入: [1,3,5,6], 0
   输出: 0

*/

#include <stdio.h>

int searchInsert1(int* nums, int numsSize, int target){
    int i = 0;
    for(; i < numsSize; i ++) {
        if (nums[i] == target) {
            return i;
        }
        if (nums[i] > target) {
            break;
        }
    }
    return i;
}

int searchInsert(int* nums, int numsSize, int target){
    if (numsSize == 0) {
        return 0;
    }
    if (nums[0] < target) {
        return 1 + searchInsert(nums + 1, numsSize - 1, target);
    } else {
        return 0;
    }
}

int main(int argc, char *argv[]) {
    int nums[4] = {1, 3, 5, 6};
    int target = 0;
    printf("%d", searchInsert(nums, 4, target));
}