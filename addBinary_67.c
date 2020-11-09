//
// Created by me_touch on 2020/11/9.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * addBinary(char * a, char * b){
    int lengthA = (int)strlen(a);
    int lengthB = (int)strlen(b);
    int length = lengthA > lengthB ? lengthA : lengthB;
    int size = lengthB < lengthA ? lengthB : lengthA;
    char *c = (char *)malloc((length + 1) * sizeof(char));
    c[length] = '\0';
    int carry = 0;
    for (int i = 1; i <= size; ++i) {
        int a1 = a[lengthA - i] - '0';
        int b1 = b[lengthB - i] - '0';
        int result = a1 + b1 + carry;
        carry = result / 2;
        c[length - i] = (result % 2) + '0';
    }
    int remain = lengthA - size;
    if (remain > 0) {
        for (int i = 1; i <= remain; ++i) {
            int index = lengthA - size - i;
            int a1 = a[index] - '0';
            int result = a1 + carry;
            carry = result / 2;
            c[index] = (result % 2) + '0';
        }
    }
    remain = lengthB - size;
    if (remain > 0) {
        for (int i = 1; i <= remain; ++i) {
            int index = lengthB - size - i;
            int b1 = b[index] - '0';
            int result = b1 + carry;
            carry = result / 2;
            c[index] = (result % 2) + '0';
        }
    }
    if (carry > 0) {
        char * temp = c;
        c = (char *)malloc((length + 2) * sizeof(int ));
        strcpy(c + 1, temp);
        free(temp);
        c[0] = '1';
    }
    return c;
}

//方法2：分别转换成整数相加再转换成2进制数，可能存在整数越界的情况

int main(int argc, char *argv[]) {
    printf("result = %s", addBinary("10", "111"));
}
