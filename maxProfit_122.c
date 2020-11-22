//
// Created by me_touch on 2020/11/16.
//

#include <stdio.h>
#define MAX(a, b) (a > b ? a : b)

/**
 * 动态规划公式
 * dp[i][0]=max{dp[i−1][0],dp[i−1][1]+prices[i]}
 * dp[i][1]=max{dp[i−1][1],dp[i−1][0]−prices[i]}
 */
int maxProfit(int* prices, int pricesSize){
    int profit[pricesSize][2];
    profit[0][0] = 0;
    profit[0][1] = -prices[0];
    for (int i = 1; i < pricesSize; ++i) {
        int pre = i - 1;
        profit[i][0] = MAX(profit[pre][0], profit[pre][1] + prices[i]);
        profit[i][1] = MAX(profit[pre][1], profit[pre][0] - prices[i]);
    }
    return profit[pricesSize - 1][0];
}

//动态规划优化
int maxProfit1(int* prices, int pricesSize){
    int profit[2];
    profit[0] = 0;
    profit[1] = -prices[0];
    for (int i = 1; i < pricesSize; ++i) {
        int next0 = MAX(profit[0], profit[1] + prices[i]);
        int next1 = MAX(profit[1], profit[0] - prices[i]);
        profit[0] = next0;
        profit[1] = next1;
    }
    return profit[0];
}

int main(int argc, char *argv[]) {
    int prices[] = {1, 2, 3, 4, 5};
    printf("%d", maxProfit1(prices, 5));
}