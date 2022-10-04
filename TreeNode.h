//
//  TreeNode.h
//  C
//
//  Created by seungjin oh on 2022/10/05.
//

#ifndef TreeNode_h
#define TreeNode_h


#endif /* TreeNode_h */
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "Circular-Queue-Array.h"
#ifndef max
#define max(a,b) (((a) > (b)) ? (a) : (b))
#endif


typedef TreeNode* element;

TreeNode* init(int data){
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL; node->right = NULL;
    return node;
}

void linking(TreeNode* root,TreeNode* left, TreeNode* right){
    root->left = left;
    root->right = right;
}

void preOrder(TreeNode* root){ // 전위 순회
    if (root != NULL) {
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(TreeNode* root){ // 중위 순회
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

void postOrder(TreeNode* root){ // 후위 순회
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
}

void levelOrder(TreeNode* root){
    QueueType q;
    init_queue(&q);
    if (root == NULL) {
        exit(1);
    }
    enqueue(&q, root);
    while(is_empty(&q) == false) {
        TreeNode* ptr = dequeue(&q);
        printf("%d ",ptr->data);
        if (ptr->left != NULL) {
            enqueue(&q, ptr->left);
        }
        if (ptr->right != NULL) {
            enqueue(&q, ptr->right);
        }
    }
}

int get_node_count(TreeNode* root){
    int count = 0;
    if (root != NULL) {
        count = 1 + get_node_count(root->left) + get_node_count(root->right);
    }
    return count;
}

int get_leaf_count(TreeNode* root){
    if (root != NULL) {
        if (root->left == NULL && root->right == NULL) {
            return 1;
        }
        return get_leaf_count(root->left) + get_leaf_count(root->right);
    }
    return 0;
}

int get_height(TreeNode* root){
    int height = 0;
    if (root != NULL) {
        height = 1 + max(get_height(root->right), get_height(root->left));
    }
    return height;
}
