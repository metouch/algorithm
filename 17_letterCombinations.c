//
// Created by me_touch on 2020/12/30.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *dict[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int arrLen(int index){
    return (index == 5 || index == 7) ? 4 : 3;
}

char ** letterCombinations2(char * digits, int* returnSize){
    if (digits == NULL) {
        *returnSize = 0;
        return NULL;
    }
    int digitsLen = (int)strlen(digits);
    if (digitsLen == 0) {
        *returnSize = 0;
        return NULL;
    }
    int *num = (int *)malloc(sizeof(int) * digitsLen);
    *returnSize = 1;
    for (int i = 0; i < digitsLen; ++i) {
        num[i] = digits[i] - '0' - 2;
        *returnSize *= arrLen(num[i]);
    }
    char **result = (char **)malloc(sizeof(char*) * (*returnSize));
    int size = 0;
    for (int i = 0; i < digitsLen; ++i) {
        char *child = dict[num[i]];
        int childLen = arrLen(num[i]);
        if (i == 0) {
            for (int j = 0; j < childLen; ++j) {
                result[j] = malloc(sizeof(char) * (digitsLen + 1));
                result[j][i] = child[j];
            }
            size = childLen;
        } else {
            for (int j = 0; j < childLen; ++j) {
                for (int k = 0; k < size; ++k) {
                    int index = j * size + k;
                    if (index < size) {
                        result[k][i] = child[j];
                    } else {
                        result[index] = malloc(sizeof(char) * (digitsLen + 1));
                        memcpy(result[index], result[k], sizeof(char) * i);
                        result[index][i] = child[j];
                    }
                }
            }
            size *= childLen;
        }
    }
    for (int l = 0; l < size; ++l) {
        result[l][digitsLen] = '\0';
    }
    return result;
}

char ** letterCombinations1(char * digits, int* returnSize){
    if (digits == NULL || digits[0] == '\0') {
        *returnSize = 0;
        return NULL;
    }
    int len = (int)strlen(digits);
    char **temp = letterCombinations1(digits + 1, returnSize);
    char *arr = dict[digits[0] - '0' - 2];
    int resultLen = (int)(strlen(arr)) * (*returnSize == 0 ? 1 : *returnSize);
    char **result = (char **)malloc(sizeof(char*) * resultLen);
    int arrLen = (int)strlen(arr);
    for (int i = 0; i < arrLen; ++i) {
        if (*returnSize == 0) {
            result[i] = (char *)malloc(sizeof(char));
            result[i][0] = arr[i];
        } else {
            for (int j = 0; j < *returnSize; ++j) {
                int index = i * (*returnSize) + j;
                result[index] = (char *) malloc(sizeof(char) * len);
                memcpy(result[index] + 1, temp[j], len - 1);
                result[index][0] = arr[i];
            }
        }
    }
    if (temp != NULL) {
        for (int i = 0; i < *returnSize; ++i) {
            free(temp[i]);
        }
        free(temp);
    }
    int size = *returnSize == 0 ? arrLen : *returnSize * arrLen;
    *returnSize = size;
    return result;
}


char phoneMap[11][5] = {"\0", "\0", "abc\0", "def\0", "ghi\0", "jkl\0", "mno\0", "pqrs\0", "tuv\0", "wxyz\0"};

char* digits_tmp;
int digits_size;

char** combinations;
int combinations_size;

char* combination;
int combination_size;

void backtrack(int index) {
    if (index == digits_size) {
        char* tmp = malloc(sizeof(char) * (combination_size + 1));
        memcpy(tmp, combination, sizeof(char) * (combination_size + 1));
        combinations[combinations_size++] = tmp;
    } else {
        char digit = digits_tmp[index];
        char* letters = phoneMap[digit - '0'];
        int len = strlen(letters);
        for (int i = 0; i < len; i++) {
            combination[combination_size++] = letters[i];
            combination[combination_size] = 0;
            backtrack(index + 1);
            combination[--combination_size] = 0;
        }
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    combinations_size = combination_size = 0;
    digits_tmp = digits;
    digits_size = strlen(digits);
    if (digits_size == 0) {
        *returnSize = 0;
        return combinations;
    }
    int num = 1;
    for (int i = 0; i < digits_size; i++) num *= 4;
    combinations = malloc(sizeof(char*) * num);
    combination = malloc(sizeof(char*) * digits_size);
    backtrack(0);
    *returnSize = combinations_size;
    return combinations;
}

int main(int argc, char *argv[]) {
    char *arr = "28";
    int returnSize = 0;
    char **result = letterCombinations(arr, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%s\n", result[i]);
    }
}

