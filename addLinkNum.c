//
// Created by me_touch on 19-7-12.
//
/*给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

  如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

  您可以假设除了数字 0 之外，这两个数都不会以 0 开头

  示例：
  输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
  输出：7 -> 0 -> 8
  原因：342 + 465 = 807
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    if (l1 == NULL)
    {
        return l2;
    }
    if (l2 == NULL)
    {
        return l1;
    }
    struct ListNode *n1 = l1;
    struct ListNode *n2 = l2;
    struct ListNode *head = (struct ListNode *) malloc(sizeof(struct ListNode));
    int sum = n1->val + n2->val;
    int carry = sum / 10;
    head->val = sum % 10;
    struct ListNode *temp = head;
    for (;;)
    {

        n1 = n1->next;
        n2 = n2->next;
        if (n1 != NULL && n2 != NULL)
        {
            sum = n1->val + n2->val + carry;
            carry = sum / 10;
            struct ListNode *node = (struct ListNode *) malloc(sizeof(struct ListNode));
            node->val = sum % 10;
            temp->next = node;
            temp = node;
        } else if (n1 == NULL)
        {
            while (carry != 0)
            {
                if (n2 != NULL)
                {
                    sum = n2->val + carry;
                    carry = sum / 10;
                    struct ListNode *node = (struct ListNode *) malloc(sizeof(struct ListNode));
                    node->val = sum % 10;
                    temp->next = node;
                    temp = node;
                    n2 = n2->next;
                } else
                {
                    struct ListNode *node = (struct ListNode *) malloc(sizeof(struct ListNode));
                    node->val = carry;
                    temp->next = node;
                    temp = node;
                    carry = 0;
                }

            }
            temp->next = n2;
            break;
        } else
        {
            while (carry != 0)
            {
                if (n1 != NULL)
                {
                    sum = n1->val + carry;
                    carry = sum / 10;
                    struct ListNode *node = (struct ListNode *) malloc(sizeof(struct ListNode));
                    node->val = sum % 10;
                    temp->next = node;
                    temp = node;
                    n1 = n1->next;
                } else
                {
                    struct ListNode *node = (struct ListNode *) malloc(sizeof(struct ListNode));
                    node->val = carry;
                    temp->next = node;
                    temp = node;
                    carry = 0;
                }
            }
            temp->next = n1;
            break;
        }
    }
    return head;
}

int main()
{
    struct ListNode *l1 = (struct ListNode *) malloc(sizeof(struct ListNode));
    l1->val = 1;
    struct ListNode *node1 = (struct ListNode *) malloc(sizeof(struct ListNode));
    node1->val = 2;
    struct ListNode *node2 = (struct ListNode *) malloc(sizeof(struct ListNode));
    node2->val = 8;
    l1->next = node1;
    node1->next = node2;
    node2->next = NULL;
    struct ListNode *l2 = (struct ListNode *) malloc(sizeof(struct ListNode));
    l2->val = 1;
    struct ListNode *node11 = (struct ListNode *) malloc(sizeof(struct ListNode));
    node11->val = 2;
    struct ListNode *node22 = (struct ListNode *) malloc(sizeof(struct ListNode));
    node22->val = 2;
    l2->next = node11;
    node11->next = node22;
    node22->next = NULL;
    struct ListNode *temp = addTwoNumbers(l1, l2);
    while (temp != NULL)
    {
        printf("\t%d", temp->val);
        temp = temp->next;
    }
    return 0;
}