//
// Created by me_touch on 19-7-13.
//
/*给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
  示例 1:
  输入: "abcabcbb"
  输出: 3
  解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
 */
#include <stdio.h>
#include <string.h>
#include <math.h>

int search(const char s[], char target, int size)
{
    for (int i = 0; i < size; ++i)
    {
        if(s[i] == target) return i;
    }
    return -1;
}

int lengthOfLongestSubstring(char *s)
{
    if (s == NULL)
    {
        return 0;
    }
    size_t length = strlen(s);
    if (length == 0)
    {
        return 0;
    }
    char sArr[length];
    sArr[0] = s[0];
    int beforeSize = 0;
    unsigned int size = 1;
    int i = 0;
    for (int start = 1; i <= length && start < length; start ++)
    {
        char target = s[start];
        int k = search(sArr, target, size);
        if (k < 0)
        {
            sArr[size] = target;
            size++;
        } else
        {
            beforeSize = size > beforeSize ? size : beforeSize;
            memset(sArr, '0', size);
            i = i + k;
            sArr[0] = s[++ i];
            start = i;
            size = 1;
        }
    }
    return size > beforeSize ? size : beforeSize;
}

int main()
{
    char *s = "vdbffdsdff";
    printf("%d", lengthOfLongestSubstring(s));
//    printf("%d", binarySearch("kew", 'w', 3));
    return 0;
}
