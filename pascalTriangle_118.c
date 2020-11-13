//
// Created by me_touch on 2020/11/12.
//

#include <stdio.h>
#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    *returnColumnSizes = (int *)malloc(sizeof(int) * numRows);
    int **angle = malloc(sizeof(int *) * numRows);
    for (int i = 1; i <= numRows; ++i) {
        *(returnColumnSizes[i]) = i;
        angle[i - 1] = malloc(sizeof(int) * i);
    }
    *returnSize = numRows;
    return angle;
}

int main(int argc, char *argv[]) {
    int returnSize = 0;
    int *columnSize;
    int **angle = generate(5, &returnSize, &columnSize);
    printf("%ld", sizeof(char *));
}