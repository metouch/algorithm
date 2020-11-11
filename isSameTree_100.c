//
// Created by me_touch on 20-11-11.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * 给定两个二叉树，编写一个函数来检验它们是否相同。

   如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

   示例 1:
   输入:       1         1
             / \       / \
            2   3     2   3

           [1,2,3],   [1,2,3]
    输出: true

    示例 2:
    输入:      1          1
              /           \
             2             2

           [1,2],     [1,null,2]

    输出: false
 */

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

};

void showTree(struct TreeNode* p){
    if (p == NULL)
    {
        printf("NULL, ");
        return;
    }
    printf("%d, ", p->val);
    showTree(p->left);
    showTree(p->right);
}

struct TreeNode* arr2Tree(int *arr, int index, int arrSize) {

}


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if (p == NULL && q == NULL) {
        return true;
    }
    if (p == NULL || q == NULL){
        return false;
    }
    if (p->val != q->val) {
        return false;
    }
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(int argc, char *argv[]) {
    struct TreeNode* p = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    p->val = 1;

    struct TreeNode* pl = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    pl->val = 2;
    struct TreeNode* pr = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    pr->val = 3;
    p->left = pl;
    p->right = pr;

    struct TreeNode* p11 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    p11->val = 4;
    struct TreeNode* p12 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    p12->val = 5;
    pl->left = p11;
    pl->right = p12;

    struct TreeNode* p13 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    p13->val = 6;
    struct TreeNode* p14 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    p14->val = 7;
    pr->left = p13;
    pr->right = p14;

    struct TreeNode* q = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    q->val = 1;

    struct TreeNode* ql = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    ql->val = 2;
    struct TreeNode* qr = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    qr->val = 3;
    q->left = ql;
    q->right = qr;

    struct TreeNode* q11 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    q11->val = 4;
    struct TreeNode* q12 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    q12->val = 5;
    ql->left = q11;
    ql->right = q12;

    struct TreeNode* q13 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    q13->val = 6;
    struct TreeNode* q14 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    q14->val = 7;
    qr->left = q13;
    qr->right = q14;

    printf("%d\n", isSameTree(p, q));
    showTree(p);
}