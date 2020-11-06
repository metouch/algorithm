//
// Created by me_touch on 19-8-23.
//
/*
 * 将一个给定字符串根据给定的行数，以从上往下、从左到右进行 Z 字形排列。

   比如输入字符串为 "LEETCODEISHIRING" 行数为 3 时，排列如下：

   L   C   I   R
   E T O E S I I G
   E   D   H   N
   之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："LCIRETOESIIGEDHN"。

   请你实现这个将字符串进行指定行数变换的函数：

   string convert(string s, int numRows);

   示例 1:

   输入: s = "LEETCODEISHIRING", numRows = 3
   输出: "LCIRETOESIIGEDHN"

   示例 2:

   输入: s = "LEETCODEISHIRING", numRows = 4
   输出: "LDREOEIIECIHNTSG"
   解释:

   L     D     R
   E   O E   I I
   E C   I H   N
   T     S     G
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char * convert(char * s, int numRows){
    size_t size = strlen(s);
    if(numRows == 1) return s;
    char *rows[numRows];
    for (int i = 0; i < numRows; ++i)
    {
        rows[i] = (char *)calloc((size_t)size, sizeof(char));
    }
    int i, j, l = -1;
    int total = numRows - 1;
    for(i = 0, j = 0; i < size; i ++){
        strncat(rows[j], &s[i], 1);
        if(j == 0 || j == total){
            l = -l;
        }
        j += l;
    }
    l = 0;
    char *r = malloc((size + 1)* sizeof(char));
    for (i = 0; i < numRows; i ++){
        j = 0;
        while (*(rows[i] + j) != '\0'){
            r[l ++] = *(rows[i] + j ++);
        }
        free(rows[i]);
    }
    r[size] = '\0';
    return r;
}

char * convert2(char * s, int numRows){
    size_t size = strlen(s);
    if(size <= numRows || numRows == 1) return s;
    char *r = (char *)malloc(size + 1);
    int k = 0;
    for (unsigned int i = 0; i < numRows; ++ i)
    {
        int j = i, index = 0;
        int added = 0;
        while (j < size && s[j] != '\0'){
            r[k ++] = s[j];
            if(i == 0 || i == numRows - 1){
                added = (numRows - 1) << 1;
            } else{
                added = index ? i << 1 : (numRows - i - 1) << 1;
            }
            j += added;
            index = !index;
        }
    }
    r[size] = '\0';
    return r;
}

int main(){
    char *s = "LEETCODEISHIRING";
    printf("%s\n", convert2(s, 4));
}