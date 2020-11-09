//
// Created by me_touch on 2020/11/8.
//
#include <stdio.h>
#include <stdlib.h>

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