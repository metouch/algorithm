//
// Created by me_touch on 20-11-4.
//

/*
   编写一个函数来查找字符串数组中的最长公共前缀。
   如果不存在公共前缀，返回空字符串 ""。

   示例 1:

   输入: ["flower","flow","flight"]
   输出: "fl"

   示例 2:
   输入: ["dog","racecar","car"]
   输出: ""

   解释: 输入不存在公共前缀。

   说明:
   所有输入只包含小写字母 a-z 。

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *commonPrefix(const char *one, const char *two)
{
    char *prefix = (char *) malloc((strlen(one) + 1) * sizeof(char));
    int i = 0;
    for (i = 0; one[i] != '\0' && two[i] != '\0'; ++i)
    {
        if (one[i] != two[i])
        {
            prefix[i] = '\0';
        } else
        {
            prefix[i] = one[i];
        }
    }
    prefix[i] = '\0';
    return prefix;
}

char *longestCommonPrefix1(char **strs, int strsSize)
{
    if (strsSize < 1)
    {
        return "";
    }
    char *prefix = strs[0];
    for (int i = 1; i < strsSize; ++i)
    {
        char *pt = prefix;
        prefix = commonPrefix(prefix, *(strs + i));
        if (i > 1)
        {
            free(pt);
        }

    }
    return prefix;
}

char *longestCommonPrefix(char **strs, int strsSize)
{
    if (strsSize == 0) return "";
    size_t length = strlen(strs[0]) + 1;
    char *dest = (char *)malloc(length * sizeof(char));
    memcpy(dest, strs[0], length);
    dest[length - 1] = '\0';
    int i, j;
    for (i = 1; i < strsSize; i++)
    {
        j = 0;
        for (; dest[j] != '\0' && strs[i][j] != '\0'; j++)
        {
            if (dest[j] != strs[i][j]) break;
        }
        dest[j] = '\0';
    }
    return dest;
}

int main(int argc, char *argv[])
{
    char *strs[3] = {"flower", "floow", "floght"};

//    printf("romanToInt = %s", commonPrefix("abdf", "abce"));
    printf("romanToInt = %s", longestCommonPrefix(strs, 3));
}
