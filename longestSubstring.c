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
    if(s == NULL){
        return 0;
    }
    int i, j, k = 0, length = 0;
    for (i  = 0; s[i] != '\0'; ++ i)
    {
        for (j = k; j < i; ++ j)
        {
            if(s[j] == s[i]){
                if(length < i - k){
                    length = i - k;
                }
                k = j + 1;
                break;
            }
        }
    }
    int last = i - k;
    if(length < last) length = last;
    return length;
}

int main()
{
    char *s = "vdbffdsdff";
    printf("%ld\n", sizeof(*s));
    printf("%d", lengthOfLongestSubstring(s));
    return 0;
}
