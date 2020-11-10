//
// Created by me_touch on 2020/11/8.
//

#include <stdio.h>
#include <limits.h>

/**
 * 给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。
   如果不存在最后一个单词，请返回 0 。
   说明：一个单词是指仅由字母组成、不包含任何空格字符的 最大子字符串。

   示例:
   输入: "Hello World"
   输出: 5
 */

int max(int a, int b) {
    return  a > b ? a : b;
}

int lengthOfLastWord1(char * s){
    if (s == NULL) {
        return 0;
    }
    char *p =s;
    char *q = s;
    int length = 0;
    int last = 0;
    while (*q != '\0') {
        if (*q == ' ') {
            last = (int)(q - p);
            if (last != 0) {
                length = last;
            }
            p = q + 1;
        }
        q++;
    }
    last = (int)(q - p);
    return last != 0 ? last : length;
}

int lengthOfLastWord(char * s){
    int length = 0;
    while (*s != '\0') {
        if (*s == ' ' && *(s + 1) != '\0' && *(s + 1) != ' ') {
            length = 0;
        } else if (*s != ' '){
            length ++;
        }
        s++;
    }
    return length;
}

int main(int argc, char *argv[]) {
    printf("%d", lengthOfLastWord(" a"));
}
