//
// Created by me_touch on 19-7-18.
//

// 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
/*
 * 示例 1：

   输入: "babad"
   输出: "bab"
   注意: "aba" 也是一个有效答案。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lengthOfPalindrome(const char *s, int start, int next){
    int l = start, r = next;
    while (l >= 0 && s[r] != '\0' && s[l] == s[r]){
        l --;
        r ++;
    }
    return r - l - 1;
}
char * longestPalindrome(char * s){
    if(s == NULL) return NULL;
    int i = 0, start = 0, end = 0;
    int len = 0;
    int size = (int)strlen(s);
    int length = 0;
    for (i = 0; i + length < size; ++ i)
    {
        int len1 = lengthOfPalindrome(s, i, i + 1);
        int len2 = lengthOfPalindrome(s, i, i);
        len = len1 > len2 ? len1 : len2;
        length = end - start + 1;
        if(len > length){
            start = i - (len - 1)/ 2;
            end = i + len / 2;
        }
    }
    len = end - start + 1;
    if(len <= 1) return NULL;
    char * dest = (char *)malloc((len + 1) * sizeof(char));
    if(dest != NULL){
        strncpy(dest, s + start, (unsigned int)len);
        dest[len] = '\0';
    }
    return dest;
}

int main(){
    char *s = "\"a\"";
    printf("%s", longestPalindrome(s));
    return 0;
}