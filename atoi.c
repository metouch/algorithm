//
// Created by me_touch on 19-8-27.
//
/*
 *请你来实现一个 atoi 函数，使其能将字符串转换成整数
 * 说明：

 假设我们的环境只能存储 32 位大小的有符号整数，那么其数值范围为 [−231,  231 − 1]。如果数值超过这个范围，
 请返回  INT_MAX (231 − 1) 或 INT_MIN (−231) 。

 示例 1:

 输入: "42"
 输出: 42
 示例 2:

 输入: "   -42"
 输出: -42
 解释: 第一个非空白字符为 '-', 它是一个负号。
     我们尽可能将负号与后面所有连续出现的数字组合起来，最后得到 -42 。
 示例 3:

 输入: "4193 with words"
 输出: 4193
 解释: 转换截止于数字 '3' ，因为它的下一个字符不为数字。
 示例 4:

 输入: "words and 987"
 输出: 0
 解释: 第一个非空字符是 'w', 但它不是数字或正、负号。因此无法执行有效的转换。

 示例 5:

 输入: "-91283472332"
 输出: -2147483648
 解释: 数字 "-91283472332" 超过 32 位有符号整数范围。因此返回 INT_MIN (−231) 。
 */
#include <stdio.h>
#include <limits.h>

int myAtoi(char * str){
    if(str == NULL) return 0;
    char isMinus = 0;
    long number = 0;
    int i = 0;
    if(str[0] == ' '){
        for (i = 1; str[i] == ' ' ; ++ i);
    }
    if(str[i] == '-') {
        isMinus = 1;
        i ++;
    } else if(str[i] == '+') i ++;
    if(str[i] != '\0'){
        int v = str[i] - '0';
        if(v < 0 || v > 9) return 0;
    }
    int max = 0x7fffffff, min = 0x80000000;
    for (; str[i] != '\0' ; ++ i)
    {
        int value = str[i] - '0';
        if(value < 0 || value > 9) break;
        if(isMinus){
            number = 10 * number - value;
        } else{
            number = number * 10 + value;
        }
        if(number > max) return max;
        if(number < min) return min;
    }
    return (int)number;
}

int main(){
    printf("%d", myAtoi("-+1"));
}