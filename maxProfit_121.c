//
// Created by me_touch on 2020/11/14.
//

#include <stdio.h>
#include <math.h>
#include <zconf.h>

int maxProfit1(int* prices, int pricesSize){
    int max = 0;
    for (int i = 0; i < pricesSize - 1; ++i) {
        for (int j = i + 1; j < pricesSize; ++j) {
            int profit = prices[j] - prices[i];
            max = max >= profit ? max : profit;
        }
    }
    return max;
}

int maxProfit(int* prices, int pricesSize){
    int min = INT_MAX;
    int max = 0;
    for (int i = 0; i < pricesSize; ++i) {
        if (prices[i] < min) {
            min = prices[i];
        }
        int profit = prices[i] - min;
        max = max < profit ? profit : max;
    }
    return max;
}

int main(int argc, char *argv[]){
    int prices[] = {7,1,5,3,6,4};
    printf("%d", maxProfit(prices, 6));
}
