//
// Created by me_touch on 20-11-13.
//

#include <stdio.h>
#include <stdlib.h>

//顺序
int* getRow1(int rowIndex, int* returnSize){
    rowIndex += 1;
    *returnSize = rowIndex;
    int *row = (int *)malloc((rowIndex) * sizeof(int));
    row[0] = 1;
    for (int i = 1; i < rowIndex; ++i)
    {
        int k = (i + 1) >> 1;
        int l = (i + 1) & 1;
        int temp1 = 0, temp2 = 0;
        for (int j = 1; j <= i; ++j)
        {
            if (j < k || (j == k && l == 1)) {
                temp2 = row[j];
                int added = j - 1 > 0 ? temp1 : row[j - 1];
                row[j] = row[j] + added;
                temp1 = temp2;
            } else {
                if (l == 1) {
                    row[j] = row[2*k - j];
                } else {
                    row[j] = row[2*k - j - 1];
                }
            }
        }
    }
    return row;
}

// 逆序
int* getRow(int rowIndex, int* returnSize) {
    rowIndex += 1;
    *returnSize = rowIndex;
    int *row = (int *)malloc((rowIndex) * sizeof(int));
    for (int i = 0; i < rowIndex; ++i)
    {
        row[i] = 1;
        for (int j = i - 1; j > 0 ; j --)
        {
            row[j] = row[j] + row[j - 1];
        }
        row[0] = 1;
    }
    return row;
}

int main(int argc, char *argv[]) {
    int returnSize = 0;
    int *row = getRow(4, & returnSize);
    for (int i = 0; i < returnSize; ++i)
    {
        printf("%d, ", row[i]);
    }
}