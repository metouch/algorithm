//
// Created by me_touch on 19-7-15.
//
/*
  给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
  请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 */
/*
  示例 1:
  nums1 = [1, 3]
  nums2 = [2]
  则中位数是 2.0

  示例 2:
  nums1 = [1, 2]
  nums2 = [3, 4]
  则中位数是 (2 + 3)/2 = 2.5
 */
// 解法参考：https://www.cnblogs.com/grandyang/p/4465932.html
#include <stdio.h>
#include <limits.h>

int findKPos(int *nums1, int start1, int nums1Size, int *nums2, int start2, int nums2Size, int k){
    if(start1 >= nums1Size) return nums2[start2 + k - 1];
    if(start2 >= nums2Size) return nums1[start1 + k - 1];
    if(k == 1) return nums1[start1] > nums2[start2] ? nums2[start2] : nums1[start1];
    int midVal1 = (start1 + k / 2 - 1 < nums1Size) ? nums1[start1 + k / 2 - 1] : INT_MAX;
    int midVal2 = (start2 + k / 2 - 1 < nums2Size) ? nums2[start2 + k / 2 - 1] : INT_MAX;
    if(midVal1 < midVal2){
        return findKPos(nums1, start1 + k / 2, nums1Size, nums2, start2, nums2Size, k - k / 2);
    } else{
        return findKPos(nums1, start1, nums1Size, nums2, start2 + k / 2, nums2Size, k - k / 2);
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int left = (nums1Size + nums2Size + 1) / 2;
    int right = (nums1Size + nums2Size + 2) / 2;
    if(left == right){
        return (double)findKPos(nums1, 0, nums1Size, nums2, 0, nums2Size, left);
    } else {
        int result = findKPos(nums1, 0, nums1Size, nums2, 0, nums2Size, left) +
                findKPos(nums1, 0, nums1Size, nums2, 0, nums2Size, right);
        return result / (double)2;
    }
}

int main(){
    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6};
    printf("%.1f", findMedianSortedArrays(arr1, 3, arr2, 3));
}