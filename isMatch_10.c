//
// Created by me_touch on 20-12-9.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isCharMatch(const char * s, int i, const char * p, int j) {
    if (i == 0) {
        return false;
    }
    if (p[j - 1] == '.'){
        return true;
    }
    return s[i - 1] == p[j - 1];
}

bool isMatch(char * s, char * p){
    if (*p == '\0') {
        return *s == '\0';
    }
    bool matched = *s && (*s == *p || *p == '.');
    if (*(p + 1) == '*') {
        return isMatch(s, p + 2) || (matched && isMatch(++s, p));
    } else {
        return matched && isMatch(++s, ++p);
    }
}

/**
 * 动态规划思路：
 * 令f[i][j]为字符串s前i个字符与字符串p前j个字符串的匹配结果，即f[0][0]表示空字符串s与空字符串p的匹配结果
 * f[0][j]表是空字符串s与字符串p[0..j]的匹配结果
 * 当p[j-1] == '*'时, 且s[i-1] != p[j-2],则f[i][j] = f[i][j - 2]
 * 当p[j-1] == '*'时, 且s[i-1] == p[j-2],则f[i][j] = f[i][j - 2] || f[i-1][j]
 * 当p[j-1] != '*'时, 且s[i-1] == p[j-1]，则f[i][j] = f[i-1][j-1]
 * 否则f[i][j] = false;
 * @param s
 * @param p
 * @return
 */
bool isMatch1(char * s, char * p){
    int sLen = (int)strlen(s);
    int pLen = (int)strlen(p);
    bool f[sLen + 1][pLen + 1];
    memset(f, 0, sizeof(f));
    f[0][0] = true;
    for (int i = 0; i <= sLen; ++i)
    {
        for (int j = 1; j <= pLen; ++j)
        {
            if (p[j - 1] == '*') {
                f[i][j] = f[i][j - 2];
                if (isCharMatch(s, i, p, j - 1)) {
                    f[i][j] = f[i][j] || f[i - 1][j];
                }
            } else if (isCharMatch(s, i, p, j)){
                f[i][j] = f[i - 1][j - 1];
            } else {
                f[i][j] = false;
            }
        }
    }
    return f[sLen][pLen];
}

int main(int argc, char *argv[]) {
    char *s = "mississippi";
    char *p = "mis*is*p*.";
    printf("%d\n", isMatch1(s, p));
    return 0;
}
