//
// Created by me_touch on 20-11-6.
//
/*
 * 实现 strStr() 函数。

   给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

   示例 1:
   输入: haystack = "hello", needle = "ll"
   输出: 2

   示例 2:
   输入: haystack = "aaaaa", needle = "bba"
   输出: -1

   说明:
   当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
   对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。

*/

#include <stdio.h>

int strStr(const char *haystack, const char *needle)
{
    if (haystack == NULL || needle == NULL)
    {
        return -1;
    }
    if (needle[0] == '\0')
    {
        return 0;
    }
    int index = -1;
    int i = 0;
    for (; haystack[i] != '\0'; ++i)
    {
        int j = 0;
        for (; needle[j] != '\0'; ++j)
        {
            char c = haystack[i + j];
            if (c == '\0')
            {
                return -1;
            }
            if (c != needle[j])
            {
                break;
            }
        }
        if (needle[j] == '\0') {
            index = i;
            break;
        }
    }
    return index;
}

int main(int argc, char *argv[]) {
    char *haystack = "bbbaa";
    char *needle = "";
    printf("%d", strStr(haystack, needle));
}