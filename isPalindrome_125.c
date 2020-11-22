//
// Created by me_touch on 2020/11/22.
//
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

char toLowerCase(char c) {
    if ((c >= 48 && c <= 57) || (c >= 97 && c <= 122)) {
        return c;
    }
    if (c >= 65 && c <= 90) {
        return (char)(c + 32);
    }
    return '\0';
}

bool isPalindrome1(char * s){
    int len = (int)strlen(s);
    int i = 0, j = len - 1;
    while (1) {
        if (i >= j) {
            break;
        }
        char left = toLowerCase(s[i]);
        char right = toLowerCase(s[j]);
        if (left == '\0') {
            i++;
            continue;
        }
        if (right =='\0') {
            j --;
            continue;
        }
        int delta = left - right;
        if (delta != 0 && delta != 32 && delta != -32) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

bool isPalindrome(char * s){
    int i = 0, j = ((int)strlen(s)) - 1;
    while (1) {
        if (i >= j) {
            break;
        }
        if (!isalnum(s[i])){
            i++;
            continue;
        }
        if (!isalnum(s[j])){
            j--;
            continue;
        }
        if (tolower(s[i++]) != tolower(s[j--])) {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[]) {
    char *s = "A man, a plan, a canal: Panama";
    printf("%d\n", isPalindrome(s));
}
