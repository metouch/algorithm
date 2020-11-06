//
// Created by me_touch on 19-8-28.
//

/*
 *
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

示例 1:

输入: 121
输出: true
示例 2:

输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:

输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
 */

#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x){
    if(x < 0 || (x != 0 && x % 10 == 0)) return false;
    int remainder = 0;
    while (remainder < x){
        int value = x % 10;
        remainder = remainder * 10 + value;
        x /= 10;
    }
    if(remainder == x || remainder / 10 == x) return true;
    else return false;

}

int main(){
    printf("%d\n", isPalindrome(10));
}