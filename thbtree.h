//
// Created by me_touch on 20-11-12.
//

#ifndef ALGORITHM_TH_BTREE_H
#define ALGORITHM_TH_BTREE_H

typedef struct TreeNode TreeNode;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

};

TreeNode * createTree(int data);

void printTree(TreeNode* p);

TreeNode * arrToTree(int *arr, int arrSize);

void addArrToTree(TreeNode* root, int *arr, int arrSize);

#endif //ALGORITHM_TH_BTREE_H
