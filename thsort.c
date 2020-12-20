//
// Created by me_touch on 2020/12/20.
//

#include "thutils.h"
#include "thsort.h"

//快速排序
void quickSort(int* num, int l, int r){
    if (l >= r) {
        return;
    }
    // 1.选取数组[l .. r]中的某个值为基准位置, 互换数组num l与基准位置的值， 则从l位置开始挖坑，从右边开始循环
    //2.选取数组[l .. r]中的某个值为基准位置, 互换数组num r与基准位置的值， 则从r位置开始挖坑，从左边开始循环
    //3.选取数组 l 的值为基准值, 则从l位置开始挖坑，从左边开始循环
    //本题选择第一种方法,seedPos为[l..r]中的任意值
    int seedPos = r;
    int reference = num[seedPos];
    swap(&num[l], &num[seedPos]);
    int i = l, j = r;
    while (i < j) {
        if (i < j && num[j] >= reference) {
            j--;
        }
        if (i < j) {
            num[i] = num[j];
        }
        if (i < j && num[i] <= reference) {
            i++;
        }
        if (i < j){
            num[j] = num[i];
        }
    }
    num[i] = reference;
    quickSort(num, l, i - 1);
    quickSort(num, i + 1, r);
}



