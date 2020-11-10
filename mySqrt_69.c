//
// Created by me_touch on 20-11-10.
//

#include <stdio.h>
/**
 * 实现 int sqrt(int x) 函数。
   计算并返回 x 的平方根，其中 x 是非负整数。
   由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

   示例 1:
   输入: 4
   输出: 2

   示例 2:
   输入: 8
   输出: 2
   说明: 8 的平方根是 2.82842...,
 */

//通过2分法的方式求解
int mySqrt1(int x){
    if (x == 0 || x == 1) {
        return x;
    }
    long left = 0;
    long right = x;
    while (right - left > 1) {
        long middle = (left + right) / 2;
        long long sqrt = middle * middle;
        if (sqrt < x) {
            left = middle;
        } else if(sqrt == x) {
            return middle;
        } else {
            right = middle;
        }
    }
    return left;
}

/**
 * 牛顿插值法
 * f(x) ≈ f(x0) + (x-x0)f`(x0)
 * 令x = 0;
 * 则可得 x = x0 - f(x0) / f`(x0)
 * 在此题中：f(x) = x^2 - a (a > 0)
 * 代入可得：
 * x = x0 - (x0^2 + a) / 2x0
 * 简化得 x = (x0 +  a / x0) / 2
 */
int mySqrt(int x){
    long temp = x;
    while (temp * temp > x) {
        temp = (temp + x / temp) / 2;
    }
    return (int)temp;
}

int main(int argc, char *argv[]) {
    printf("%d", mySqrt(110));
}