//
// Created by me_touch on 20-11-10.
//

#include <stdio.h>

/*
 *
  假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

  每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

  注意：给定 n 是一个正整数。

  示例 1：
  输入： 2
  输出： 2

  解释： 有两种方法可以爬到楼顶。

  1.  1 阶 + 1 阶
  2.  2 阶

  示例 2：
  输入： 3
  输出： 3
  解释： 有三种方法可以爬到楼顶。
  1.  1 阶 + 1 阶 + 1 阶
  2.  1 阶 + 2 阶
  3.  2 阶 + 1 阶

 */

/*
 * 总体思路：
   1.如果起始跳一阶的话，剩余的n-1阶就有 f(n-1) 种跳法；
   2.如果起始跳二阶的话，剩余的n-2阶就有 f(n-2) 种跳法；
   3.如果起始跳三阶的话，剩余的n-2阶就有 f(n-3) 种跳法；
   ...
   n.如果起始跳n阶的话，剩余的n-2阶就有 f(n-n) 种跳法；
   本题中至多跳两阶，故：
   f(n) = f(n - 1) + f(n - 2)
   斐波那契数列
 */

// 斐波那契数列解法，n值稍大时，耗时过长，无法通过leetCode测试用例
int climbStairs1(int n){
    if (n == 0 || n == 1 || n == 2) {
        return n;
    }
    return climbStairs1(n - 1) + climbStairs1(n - 2);
}

// 动态规划
int climbStairs(int n) {
    if (n == 0 || n == 1 || n == 2) {
        return n;
    }
    int last1 = 1, last2 = 2;
    for (int i = 3; i <=n ; ++i)
    {
        int temp = last2;
        last2 = last1 + last2;
        last1 = temp;
    }
    return last2;
}

int main(int argc, char *argv[]) {
    printf("%d", climbStairs(45));
}