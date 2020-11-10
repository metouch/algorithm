//
// Created by me_touch on 2020/11/9.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * 给你两个二进制字符串，返回它们的和（用二进制表示）。
   输入为 非空 字符串且只包含数字 1 和 0。

   示例 1:
   输入: a = "11", b = "1"
   输出: "100"

   示例 2:
   输入: a = "1010", b = "1011"
   输出: "10101"

   提示：
   每个字符串仅由字符 '0' 或 '1' 组成。
   1 <= a.length, b.length <= 10^4
   字符串如果不是 "0" ，就都不含前导零。
*/

char * addBinary1(char * a, char * b){
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
        c[length - i] = (char)((result % 2) + '0');
    }
    int remain = lengthA - size;
    if (remain > 0) {
        for (int i = 1; i <= remain; ++i) {
            int index = lengthA - size - i;
            int a1 = a[index] - '0';
            int result = a1 + carry;
            carry = result / 2;
            c[index] = (char)((result % 2) + '0');
        }
    }
    remain = lengthB - size;
    if (remain > 0) {
        for (int i = 1; i <= remain; ++i) {
            int index = lengthB - size - i;
            int b1 = b[index] - '0';
            int result = b1 + carry;
            carry = result / 2;
            c[index] = (char)((result % 2) + '0');
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

unsigned int binaryString2Int(const char *s) {
    unsigned int sum = 0;
    for (int i = 0; s[i] != '\0'; ++ i)
    {
        sum = (s[i] - '0') + (sum << 1);
    }
    return sum;
}

char * int2BinaryString(unsigned int target) {
    if (target == 0) {
        return "0";
    }
    char temp[64];
    int i = 0;
    while (target) {
        temp[i] = (char)(target % 2 + '0');
        target = target / 2;
        i++;
    }
    char *result = (char *)malloc((i + 1) * sizeof(char));
    int j = 0;
    for (j = 0; j < i; ++j)
    {
        result[j] = temp[i - j - 1];
    }
    result[j] = '\0';
    return result;
}

/*
 * 方法2：分别转换成整数相加再转换成2进制数，可能存在整数越界的情况,需要根据字符串的长度定义long, long long,
 * 但依旧无法应对过长的问题
 * 令x = int(a), y = int(b);
 * 则 x + y对应的值为：
 * while(y) {
 *     answer = x ^ y; 放弃进位相加后的值
 *     carry = (x & y) << 1; 进位
 *     x = answer;
 *     y = carry;
 * }
 */

char* addBinary(char * a, char * b){
    unsigned int x = binaryString2Int(a);
    unsigned int y = binaryString2Int(b);
    while (y) {
        unsigned int temp = x ^ y;
        unsigned int carry = (x & y) << 1;
        x = temp;
        y = carry;
    }
    return int2BinaryString(x);
}

int main(int argc, char *argv[]) {
    printf("result = %s\n", addBinary("10", "111"));
    printf("%s", int2BinaryString(15));
}

