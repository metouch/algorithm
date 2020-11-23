//
// Created by me_touch on 2020/11/23.
//
#include <stdio.h>
#include <zconf.h>
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int maxArea(int* height, int heightSize){
    if (heightSize < 2) {
        return 0;
    }
    int area = INT_MIN;
    int l = 0, r = heightSize - 1;
    while (l < r) {
        int length = 0;
        int width = r - l;
        if (height[l] < height[r]) {
            length = height[l];
            l++;
        } else {
            length = height[r];
            r--;
        }
        area = MAX(area, width * length);
    }
    return area;
}

int maxArea1(int* height, int heightSize){
    if (heightSize < 2) {
        return 0;
    }
    int area = INT_MIN;
    for (int i = 0; i < heightSize - 1; ++i) {
        for (int j = 1; j < heightSize; ++j) {
            int length = MIN(height[i], height[j]);
            area = MAX(area, (j - i) * length);
        }
    }
    return area;
}

int main(int argc, char *argv[]) {
    int height[] = {1,8,6,2,5,4,8,3,7};
    printf("%d", maxArea(height, 9));
}