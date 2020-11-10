//
// Created by me_touch on 20-11-9.
//

#include <stdio.h>
#include <stdlib.h>

/*
 * 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

   示例 1:
   输入: 1->1->2
   输出: 1->2

   示例 2:
   输入: 1->1->2->3->3
   输出: 1->2->3
*/

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates2(struct ListNode* head){
    if (head == NULL) {
        return NULL;
    }
    struct ListNode* next = head->next;
    while (next != NULL && next->val == head->val) {
        struct ListNode* temp = next;
        next = next->next;
        head -> next = next;
        free(temp);
    }
    head->next = deleteDuplicates2(next);
    return head;
}

struct ListNode* deleteDuplicates1(struct ListNode* head){
    if (head == NULL) {
        return NULL;
    }
    struct ListNode* next = head->next;
    struct ListNode* p = deleteDuplicates1(next);
    if (p != NULL && head->val == p->val) {
        head->next = p->next;
    } else {
        head->next = p;
    }
    return head;
}

struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* pre = head;
    struct ListNode* cur = NULL;
    while (pre) {
        cur = pre->next;
        if (cur != NULL && cur->val == pre->val) {
            pre->next = cur->next;
            free(cur);
        } else {
            pre = cur;
        }
    }
    return head;
}

int main(int argc, char *argv[]) {
    struct ListNode *l1 = (struct ListNode *) malloc(sizeof(struct ListNode));
    l1->val = 1;
    struct ListNode *n1 = (struct ListNode *) malloc(sizeof(struct ListNode));
    n1->val = 2;
    l1->next = n1;
    struct ListNode *n2 = (struct ListNode *) malloc(sizeof(struct ListNode));
    n2->val = 2;
    n1->next = n2;
    struct ListNode *n3 = (struct ListNode *) malloc(sizeof(struct ListNode));
    n3->val = 2;
    n2->next = n3;
    struct ListNode *n4 = (struct ListNode *) malloc(sizeof(struct ListNode));
    n4->val = 4;
    n3->next = n4;
    n4->next = NULL;
    struct ListNode *n5 = (struct ListNode *) malloc(sizeof(struct ListNode));
    n5->val = 4;
    n4->next = n5;
    n5->next = NULL;

    struct ListNode* p = deleteDuplicates1(l1);
    while (p != NULL) {
        printf("%d", p->val);
        p = p->next;
        if (p != NULL) {
            printf(" -> ");
        }
    }
}