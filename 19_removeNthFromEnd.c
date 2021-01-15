//
// Created by me_touch on 21-1-15.
//

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * 双指针方式定位倒数第n个节点
 * first指针先移动到第n个节点，然后first和second节点同时移动，当first节点移动到尾节点时，second节点即位于倒数第n个节点
 * 当second初始定位到virtual节点时，则在first节点移动到尾节点时，second节点正好位于倒数第n+1个节点
 * @param head
 * @param n
 * @return
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* first = head;
    for (int i = 1; i < n; ++i)
    {
        first = first->next;
    }
    struct ListNode* virtual = malloc(sizeof(struct ListNode));
    virtual->val = 0;
    virtual->next = head;
    struct ListNode* second = virtual;
    while (first->next != NULL) {
        second = second->next;
        first = first->next;
    }
    struct ListNode* next =second->next;
    free(next);
    second->next = second->next->next;
    next = virtual->next;
    free(virtual);
    return next;
}

struct ListNode* removeNthFromEnd1(struct ListNode* head, int n){
    struct ListNode* first = head;
    struct ListNode* second = head;
    int i = 0;
    while (first->next != NULL) {
        first = first->next;
        if (i++ >= n) {
            second = second->next;
        }
    }
    if (i == n - 1) {
        second = head->next;
        free(head);
        return second;
    }
    first = second->next;
    second->next = first->next;
    free(first);
    return head;

}

int main(int argc, char *argv[])
{
    struct ListNode *l1 = (struct ListNode *) malloc(sizeof(struct ListNode));
    l1->val = 1;
    struct ListNode *n1 = (struct ListNode *) malloc(sizeof(struct ListNode));
    n1->val = 2;
    l1->next = n1;
    n1->next = NULL;
    struct ListNode *n2 = (struct ListNode *) malloc(sizeof(struct ListNode));
    n2->val = 3;
    n1->next = n2;
    n2->next = NULL;
    struct ListNode *n3 = (struct ListNode *) malloc(sizeof(struct ListNode));
    n3->val = 4;
    n2->next = n3;
    struct ListNode *n4 = (struct ListNode *) malloc(sizeof(struct ListNode));
    n4->val = 5;
    n3->next = n4;
    struct ListNode *n5 = (struct ListNode *) malloc(sizeof(struct ListNode));
    n5->val = 6;
    n4->next = n5;
    struct ListNode *n6 = (struct ListNode *) malloc(sizeof(struct ListNode));
    n6->val = 7;
    n5->next = n6;
    n6->next = NULL;

    struct ListNode *p = removeNthFromEnd1(l1, 2);
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