//
// Created by me_touch on 20-7-1.
// 最大子数组之和
//
/*
   给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

   示例:
   输入: [-2,1,-3,4,-1,2,1,-5,4]
   输出: 6
   解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

   进阶:
   如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
 */
#include <stdio.h>
#include <limits.h>

int min(int a, int b) {
    return a > b ? b : a;
}

int max(int a, int b) {
    return a < b ? b : a;
}

int maxSumOfSubArr(int arr[], int start, int end) {
    if (start >= end) {
        return arr[start];
    }
    int middleIndex = (start + end) / 2;
    int s1 = maxSumOfSubArr(arr, start, middleIndex);
    int s2 = maxSumOfSubArr(arr, middleIndex + 1, end);
    int sum = 0;
    int leftMax = INT_MIN;
    for (int i = middleIndex; i >= start; --i) {
        sum += arr[i];
        leftMax = max(leftMax, sum);
    }
    sum = 0;
    int rightMax = INT_MIN;
    for (int j = middleIndex + 1; j <= end; ++j) {
        sum += arr[j];
        rightMax = max(rightMax, sum);
    }
    int s3 = leftMax + rightMax;
    return max(s3, max(s1, s2));
}

/**
 *  动态规划公式：
 *  sum[i] = MAX(sum[i - 1] + num[i], num[i])
 *  表示以a[i]作为连续子数组末尾的字串的最大和
 *  本题中需要找到整个数组中最大子数组之和，
 *  所以需要在sum数组中遍历一次，找到最大值
 * @param nums
 * @param numsSize
 * @return
 */
int maxSubArray1(int *nums, int numsSize) {
    int sums[numsSize];
    sums[0] = nums[0];
    int maxNum = sums[0];
    for (int i = 1; i < numsSize; ++i) {
        sums[i] = max(sums[i - 1] + nums[i], nums[i]);
        maxNum = max(sums[i], maxNum);
    }
    return maxNum;
}


int maxSubArray(int *nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    if (numsSize == 1) {
        return nums[numsSize - 1];
    }
    int *p = nums;
    int *q = nums;
    int mid = numsSize / 2;
    q += mid;
    int *midP = q;
    int s1 = maxSubArray(p, mid);
    int s2 = maxSubArray(q, numsSize - mid);
    int sum = 0;
    int leftMax = INT_MIN;
    while ((q - p) > 0) {
        sum += *(--q);
        leftMax = max(leftMax, sum);
    }
    sum = 0;
    int rightMax = INT_MIN;
    while ((midP - nums) < numsSize) {
        sum += *(midP++);
        rightMax = max(rightMax, sum);
    }
    return max(s1, max(s2, leftMax + rightMax));
}


int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
//    printf("%d\n", maxSumOfSubArr(arr, 0, 8));
    printf("%d\n", maxSubArray1(arr, 9));
}
