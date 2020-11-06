//
// Created by me_touch on 20-7-1.
// 最大子数组之和
//
#include <stdio.h>
#include <limits.h>

int min(int a, int b)
{
    return a > b ? b : a;
}

int max(int a, int b)
{
    return a < b ? b : a;
}

int maxSumOfSubArr(int arr[], int start, int end)
{
    if (start >= end)
    {
        return arr[start];
    }
    int middleIndex = (start + end) / 2;
    int s1 = maxSumOfSubArr(arr, start, middleIndex);
    int s2 = maxSumOfSubArr(arr, middleIndex + 1, end);
    int sum = 0;
    int leftMax = INT_MIN;
    for (int i = middleIndex; i >= start ; --i)
    {
        sum += arr[i];
        leftMax = max(leftMax, sum);
    }
    sum = 0;
    int rightMax = INT_MIN;
    for (int j = middleIndex + 1; j <= end; ++j)
    {
        sum += arr[j];
        rightMax = max(rightMax, sum);
    }
    int s3 = leftMax + rightMax;
    return max(s3, max(s1, s2));
}

int main()
{
    int arr[] = {-1, -2, 3, -4, -5};
    printf("%d\n", maxSumOfSubArr(arr, 0, 4));
}
