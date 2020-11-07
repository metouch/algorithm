//
// Created by me_touch on 2020/11/5.
//
/*
   给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
   不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
   元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

   示例 1:
   给定 nums = [3,2,2,3], val = 3,
   函数应该返回新的长度 2, 并且 nums 中的前两个元素均为 2。
   你不需要考虑数组中超出新长度后面的元素。

   示例 2:
   给定 nums = [0,1,2,2,3,0,4,2], val = 2,
   函数应该返回新的长度 5, 并且 nums 中的前五个元素为 0, 1, 3, 0, 4。

   注意这五个元素可为任意顺序。
   你不需要考虑数组中超出新长度后面的元素。
*/
#include <stdio.h>
#include <string.h>

int removeElement1(int *nums, int numsSize, int val) {
    int step = 0;
    for (int i = 0; i < numsSize - step; ++i) {
        if (nums[i] == val) {
            step++;
            for (int j = i; j < numsSize - 1; ++j) {
                nums[j] = nums[j + 1];
            }
            i--;
        }
    }
    return numsSize - step;
}

int removeElement2(int *nums, int numsSize, int val) {
    int step = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != val) {
            nums[step] = nums[i];
            step ++;
        }
    }
    return step;
}

int removeElement(int *nums, int numsSize, int val) {
    if (numsSize == 0) {
        return 0;
    }
    if (nums[0] == val) {
        memcpy(nums, nums + 1, numsSize - 1);
        return removeElement(nums, numsSize - 1, val);
    } else {
        return 1 + removeElement(nums + 1, numsSize - 1, val);
    }
}

int main(int argc, char *argv[]) {
    int a[5] = {1, 2, 2, 3, 2};
    int size = removeElement(a, 5, 2);
    printf("%d\n", size);
    for (int i = 0; i < size; ++i) {
        printf("%d, ", a[i]);
    }
}