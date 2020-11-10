//
// Created by me_touch on 20-11-9.
//

#include <stdio.h>
#include <stdlib.h>

/*
 * 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。

   示例 1:
   输入: 1->2->3->3->4->4->5
   输出: 1->2->5

   示例 2:
   输入: 1->1->1->2->3
   输出: 2->3

*/

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *deleteDuplicates2(struct ListNode *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    struct ListNode *next = head->next;
    char a = 0;
    while (next != NULL && next->val == head->val)
    {
        struct ListNode *temp = next;
        next = next->next;
        head->next = next;
        free(temp);
        a = 1;
    }
    if (a == 0)
    {
        head->next = deleteDuplicates2(next);
    } else
    {
        head = deleteDuplicates2(next);
    }
    return head;
}

struct ListNode *deleteDuplicates1(struct ListNode *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    struct ListNode *f = NULL;
    struct ListNode *p = head;
    struct ListNode *q = p->next;
    struct ListNode *r = NULL;
    char count = 0;
    while (q != NULL)
    {
        if (q->val == p->val)
        {
            free(p);
            p = q;
            q = q->next;
            count = 1;
        } else
        {
            if (count == 0)
            {
                if (f == NULL)
                {
                    f = p;
                    r = f;
                } else
                {
                    r->next = p;
                    r = r->next;
                }
            } else
            {
                free(p);
            }
            p = q;
            q = q->next;
            count = 0;
        }
    }
    if (count == 0)
    {
        if (f == NULL)
        {
            f = p;
        } else
        {
            r->next = p;
        }
    } else
    {
        free(p);
        if (r != NULL)
        {
            r->next = NULL;
        }
    }
    return f;
}

struct ListNode *deleteDuplicates(struct ListNode *head)
{
    struct ListNode* first = NULL;
    struct ListNode* below = NULL;
    struct ListNode* p = head;
    char count = 0;
    while (p != NULL) {
        struct ListNode* next = p->next;
        while (next != NULL && next->val == p->val) {
            struct ListNode* temp = next;
            next = next->next;
            free(temp);
            count = 1;
        }
        if (count == 0) {
            if (first == NULL) {
                first = p;
                below = first;
            } else {
                below->next = p;
                below = below->next;
            }
        } else {
            free(p);
        }
        p = next;
        count = 0;
    }
    if (below != NULL) {
        below->next = NULL;
    }
    return first;
}

int main(int argc, char *argv[])
{
    struct ListNode *l1 = (struct ListNode *) malloc(sizeof(struct ListNode));
    l1->val = 1;
    struct ListNode *n1 = (struct ListNode *) malloc(sizeof(struct ListNode));
    n1->val = 1;
    l1->next = n1;
    n1->next = NULL;
    struct ListNode *n2 = (struct ListNode *) malloc(sizeof(struct ListNode));
    n2->val = 2;
    n1->next = n2;
    n2->next = NULL;
    struct ListNode *n3 = (struct ListNode *) malloc(sizeof(struct ListNode));
    n3->val = 3;
    n2->next = n3;
    struct ListNode *n4 = (struct ListNode *) malloc(sizeof(struct ListNode));
    n4->val = 4;
    n3->next = n4;
    struct ListNode *n5 = (struct ListNode *) malloc(sizeof(struct ListNode));
    n5->val = 4;
    n4->next = n5;
    struct ListNode *n6 = (struct ListNode *) malloc(sizeof(struct ListNode));
    n6->val = 4;
    n5->next = n6;
    n6->next = NULL;

    struct ListNode *p = deleteDuplicates(l1);
    while (p != NULL)
    {
        printf("%d", p->val);
        p = p->next;
        if (p != NULL)
        {
            printf(" -> ");
        }
    }
}