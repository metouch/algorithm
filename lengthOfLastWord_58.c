//
// Created by me_touch on 2020/11/8.
//

#include <stdio.h>
#include <limits.h>

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
