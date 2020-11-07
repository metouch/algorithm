//
// Created by me_touch on 2020/11/4.
//
/*
  给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

  有效字符串需满足：

  左括号必须用相同类型的右括号闭合。
  左括号必须以正确的顺序闭合。
  注意空字符串可被认为是有效字符串。

  示例 1:
  输入: "()"
  输出: true

  示例 2:
  输入: "()[]{}"
  输出: true

  示例 3:
  输入: "(]"
  输出: false

  示例 4:
  输入: "([)]"
  输出: false

  示例 5:
  输入: "{[]}"
  输出: true
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isPair(char first, char second) {
    return (first == '(' && second ==')') || (first == '[' && second ==']') || (first == '{' && second =='}');
}

bool isValid(char * s){
    int len = (int)strlen(s);
    if (len == 0) {
        return true;
    }
    if (len % 2 != 0) {
        return false;
    }
    int offset = 0;
    char *stack = (char *)malloc((len + 1) * sizeof(char));
    stack[0] = '\0';
    for (int i = 0; s[i] != '\0' ; ++ i) {
        if (stack[0] == '\0') {
            stack[0] = s[i];
            offset ++;
            continue;
        }
        if (isPair(stack[offset - 1], s[i])) {
            offset --;
            stack[offset] = '\0';
        } else{
            offset ++;
            stack[offset - 1] = s[i];
        }
    }
    return offset == 0;
}


int main(int argc, char *argv[]) {
    char *s = "{[]}";
    printf("%d\n", isValid(s));
}