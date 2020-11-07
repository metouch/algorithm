//
// Created by me_touch on 20-11-5.
//
/**
   将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

 

   示例：

   输入：1->2->4, 1->3->4
   输出：1->1->2->3->4->4

 */

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void showNodeListValue(struct ListNode *node)
{
    while (1)
    {
        printf("%d", node->val);
        node = node->next;
        if (node != NULL)
        {
            printf(" -> ");
        } else
        {
            break;
        }
    }
    printf("\n");
}

struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    if (l1 == NULL || l2 == NULL)
    {
        return l1 != NULL ? l1 : l2;
    }
    if (l1->val <= l2->val)
    {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else
    {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}

struct ListNode *mergeTwoLists1(struct ListNode *l1, struct ListNode *l2)
{
    if (l1 == NULL || l2 == NULL)
    {
        return l1 != NULL ? l1 : l2;
    }
    struct ListNode *curNode, *node2, *head;
    head = NULL;
    curNode = l1;
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val <= l2->val)
        {
            if (head == NULL)
            {
                head = l1;
                curNode = head;
            } else {
                curNode->next = l1;
                curNode = curNode->next;
            }
            l1 = l1->next;
        } else {
            if (head == NULL) {
                head = l2;
                curNode = head;
            } else {
                curNode -> next = l2;
                curNode = curNode->next;
            }
            l2 = l2->next;
        }
    }
    if (l1 != NULL) {
        curNode->next = l1;
    }
    if (l2 != NULL) {
        curNode->next = l2;
    }
    return head;
}

int main(int argc, char *argv[])
{
    struct ListNode *l1 = (struct ListNode *) malloc(sizeof(struct ListNode));
    l1->val = 1;
    struct ListNode *n1 = (struct ListNode *) malloc(sizeof(struct ListNode));
    n1->val = 2;
    l1->next = n1;
    struct ListNode *n2 = (struct ListNode *) malloc(sizeof(struct ListNode));
    n2->val = 4;
    n1->next = n2;
    n2->next = NULL;

    struct ListNode *l2 = (struct ListNode *) malloc(sizeof(struct ListNode));
    l2->val = 1;
    n1 = (struct ListNode *) malloc(sizeof(struct ListNode));
    n1->val = 3;
    l2->next = n1;
    n2 = (struct ListNode *) malloc(sizeof(struct ListNode));
    n2->val = 4;
    n1->next = n2;
    n2->next = NULL;

    showNodeListValue(l1);
    showNodeListValue(l2);
    struct ListNode *head = mergeTwoLists1(l1, l2);
    showNodeListValue(head);
}