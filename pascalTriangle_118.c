//
// Created by me_touch on 2020/11/12.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** generate1(int numRows, int* returnSize, int** returnColumnSizes){
    int *columnSize = malloc(sizeof(int) * numRows);
    int **angle = malloc(sizeof(int *) * numRows);
    for (int i = 1; i <= numRows; ++i) {
        columnSize[i - 1] = i;
        int row = i - 1;
        angle[row] = malloc(sizeof(int) * i);
        int k = i >> 1;
        int l = i % 2;
        for (int j = 0; j < i; ++j)
        {
            if (j == 0) {
                angle[row][j] = 1;
                continue;
            }
            if (j < k || (j == k && l == 1)) {
                angle[row][j] = angle[row - 1][j - 1] + angle[row - 1][j];
            } else {
                if (l == 1) {
                    angle[row][j] = angle[row][(k << 1) - j];
                } else {
                    angle[row][j] = angle[row][(k << 1) - j - 1];
                }

            }
        }
    }
    *returnSize = numRows;
    *returnColumnSizes = columnSize;
    return angle;
}

int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int *columnSize = malloc(sizeof(int) * numRows);
    int **angle = malloc(sizeof(int *) * numRows);
    for (int i = 1; i <= numRows; ++i) {
        int row = i - 1;
        *(columnSize + row) = i;
        angle[row] = malloc(sizeof(int) * i);
        for (int j = 0; j < i; ++j)
        {
            if (j == 0 || j == row) {
                angle[row][j] = 1;
            } else {
                angle[row][j] = angle[row - 1][j - 1] + angle[row - 1][j];
            }
        }
    }
    *returnSize = numRows;
    *returnColumnSizes = columnSize;
    return angle;
}

int main(int argc, char *argv[]) {
    int returnSize = 0;
    int **returnColumnSizes = malloc(sizeof(int *));
    int **angle = generate(5, &returnSize, returnColumnSizes);
    for (int i = 0; i < returnSize; ++i)
    {
        int size = *(*returnColumnSizes + i);
        for (int j = 0; j < size; ++j)
        {
            printf("%d, ", angle[i][j]);
        }
        printf("\n");
    }
}