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
    bool matched = (*s == *p) || (*p == '.');
    if (*p == '*') {
        return isMatch()
    } else {
        return matched && isMatch(++s, ++p);
    }
}

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
    char *s = "aa";
    char *p = "a";
    printf("%d\n", isMatch(s, p));
    return 0;
}
