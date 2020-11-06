//
// Created by me_touch on 19-8-21.
//
/*
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
   示例 1:
   输入: 123
   输出: 321

   示例 2:
   输入: -123
   输出: -321

   示例 3:
   输入: 120
   输出: 21

   注意:
   假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
 */
#include <stdio.h>
#include <limits.h>

int reverse(int x)
{
    int temp = 0;
    int j = INT_MAX / 10;
    int k = INT_MIN / 10;
    while (x != 0){
        int i = x % 10;
        x = x / 10;
        if(temp > j || (temp == j && i > 7)) return 0;
        if(temp < k || (temp == k && i <- 8)) return 0;
        temp = temp * 10 + i;
    }
    return temp;
}

int reverse2(int x){
    long temp = 0;
    for (; x != 0; temp = temp * 10 + x % 10, x /= 10);
    if(temp > INT_MAX || temp < INT_MIN) return 0;
    return temp;
}
int main(){
    int x = -1234560;
    printf("%d\n", reverse2(x));
    return 0;
}