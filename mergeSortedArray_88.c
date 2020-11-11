//
// Created by me_touch on 20-11-11.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 *
   给你两个有序整数数组 nums1 和 nums2，请你将 nums2 合并到 nums1 中，使 nums1 成为一个有序数组。

   说明：
   初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
   你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。

   示例：
   输入：
   nums1 = [1,2,3,0,0,0], m = 3
   nums2 = [2,5,6],       n = 3
   输出：[1,2,2,3,5,6]

   提示：
   -10^9 <= nums1[i], nums2[i] <= 10^9
   nums1.length == m + n
   nums2.length == n
*/

//以归并排序的思想合并
void merge1(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int temp[m + n];
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < m && j < n) {
        if (nums1[i] < nums2[j]) {
            temp[k ++] = nums1[i++];
        } else {
            temp[k++] = nums2[j++];
        }
    }
    while (i < m) {
        temp[k++] = nums1[i++];
    }
    while (j < n) {
        temp[k++] = nums2[j++];
    }
    memcpy(nums1, temp, sizeof(int) * (m + n));
}

/**
 * 倒序合并，不适合归并
 */
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i = m - 1;
    int j = n - 1;
    while (j >= 0) {
        if (i < 0) {
            nums1[i + j + 1] = nums2[j];
            j --;
        } else {
            if(nums1[i] < nums2[j]) {
                nums1[i + j + 1] = nums2[j];
                j--;
            } else {
                nums1[i + j + 1] = nums1[i];
                i--;
            }
        }
    }
}

int main(int argc, char *argv[]){
    int *num1 = (int *)malloc(10 * sizeof(int));
    num1[0] = 2;
    num1[1] = 0;
//    num1[2] = 3;
//    num1[3] = 5;
//    num1[4] = 9;
//    num1[5] = 15;
    int *num2 = (int *)malloc(4 * sizeof(int));
    num2[0] = 1;
//    num2[1] = 5;
//    num2[2] = 6;
//    num2[3] = 12;
    merge(num1, 10, 1, num2, 4, 1);
    for (int i = 0; i < 10; ++i)
    {
        printf("%d, ", num1[i]);
    }

}