//
// Created by me_touch on 2020/11/8.
//
#include <stdio.h>
#include <stdlib.h>

/**
 *
   给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
   最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
   你可以假设除了整数 0 之外，这个整数不会以零开头。

   示例 1:
   输入: [1,2,3]
   输出: [1,2,4]
   解释: 输入数组表示数字 123。

   示例 2:
   输入: [4,3,2,1]
   输出: [4,3,2,2]
   解释: 输入数组表示数字 4321。
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int *result = (int *)malloc((digitsSize + 1) * sizeof(int));
    int carry = 0;
    for (int i = digitsSize - 1; i > -1 ; i --) {
        int temp = digits[i] + (i == digitsSize - 1 ? 1 : carry);
        if (temp > 9) {
            carry = temp / 10;
            result[i] = 0;
        } else {
            carry = 0;
            result[i] = temp;
        }
    }
    if (carry > 0) {
        result[0] = 1;
        result[digitsSize] = 0;
        *returnSize = digitsSize + 1;
    } else{
        *returnSize = digitsSize;
    }
    return result;
}


int main(int argc, char *argv[]) {
    int a[] = {9, 9, 9, 9};
    int size = 0;
    int *result = plusOne(a, 4, &size);
    printf("%d\n", size);
    for (int i = 0; i < size; ++i) {
        printf("%d, ", result[i]);
    }
}