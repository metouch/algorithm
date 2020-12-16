//
// Created by me_touch on 2020/12/12.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverseStr(char *str) {
    int len = strlen(str);
    int remainder = len & 1;
    int middle = len / 2;
    for (int i = 0; i < middle; ++i) {
        int rIndex = middle + i + remainder;
        int lIndex = middle - i - 1;
        char temp = str[rIndex];
        str[rIndex] = str[lIndex];
        str[lIndex] = temp;
    }
}
/**
 *
 * @param num 待转换数字
 * @param str 已转换成的roman
 * @param index 已转化roman的结尾位置
 * @param count 已经迭代的次数
 * @return roman
 */
char *s = "IVXLCDM";
void intToRomanWithStr(int num, char* str, int index, int count) {
    if (num == 0) {
        return;
    }
    int remainder = num % 10;
    int sIndex = count << 1;
    switch (remainder) {
        case 3:
            str[index++] = s[sIndex];
        case 2:
            str[index++] = s[sIndex];
        case 1:
            str[index++] = s[sIndex];
            break;
        case 4:
            str[index++] = s[sIndex + 1];
            str[index++] = s[sIndex];
            break;
        case 5:
            str[index++] = s[sIndex + 1];
            break;
        case 8:
            str[index++] = s[sIndex];
        case 7:
            str[index++] = s[sIndex];
        case 6:
            str[index++] = s[sIndex];
            str[index++] = s[sIndex + 1];
            break;
        case 9:
            str[index++] = s[(count + 1) << 1];
            str[index++] = s[sIndex];
            break;
        default:
            break;
    }
    intToRomanWithStr(num / 10, str, index, count + 1);
}

char * intToRoman(int num){
    if (num < 0 || num > 3999){
        return "";
    }
    char *str = (char *) malloc(16 * sizeof(char));
    memset(str, 0, 16);
    intToRomanWithStr(num, str, 0, 0);
    reverseStr(str);
    return str;
}

int main(int argc, char *argv[]) {
    int num = 1994;
    printf("%s\n", intToRoman(num));
}