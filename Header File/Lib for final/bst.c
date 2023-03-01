//------------LuvU4ever-------------

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "bst.h"

tree_t makeTreeNode(data_t data){
    node_t *temp = (node_t *)malloc(sizeof(node_t*));
    temp -> data.key = data.key;
    temp -> left = temp -> right = NULL;

    return temp;
}

tree_t search(key_t key, tree_t node){
    if(node == NULL)
        return NULL;
    if(node -> data.key == key)
        return node;
    if(node -> data.key < key)
        return search(key, node -> right);
    return search(key, node -> left);
}

tree_t insertNode(data_t data, tree_t node){
    //return the new root if needed
    if(node == NULL)
        return  makeTreeNode(data);
    if(data.key < node ->data.key)
        node->left = insertNode(data, node->left);
    else if(data.key > node ->data.key)
        node -> right = insertNode(data, node -> right);
    return node;
}   

tree_t findMinValNode(tree_t node){
    tree_t cur = node;
    while(cur && cur -> left != NULL)
        cur = cur -> left;
    return cur;
}

tree_t deleteNode(key_t key, tree_t root){
    //return the new root
    if(root == NULL)
        return root;
    if(key < root -> data.key)
        root->left = deleteNode(key, root->left);
    else if(key > root->data.key)
        root->right = deleteNode(key, root->right);
    else{
        //key == root->data.key
        if(root -> left == NULL){
            node_t *temp = root -> right;
            free(root);
            return temp;
        }
        else if(root -> right == NULL){
            node_t *temp = root -> left;
            free(root);
            return temp;
        }

        node_t *temp = findMinValNode(root -> right);
        root -> data = temp -> data;
        root -> right = deleteNode(temp -> data.key, root -> right);
        
    }
    return root;
}

void freeTree(tree_t root){
    if(root != NULL){
        freeTree(root -> left);
        freeTree(root -> right);
        free((void*)root);
    }
}

void printOrder(tree_t node){
    if(node == NULL)
        return;
    printOrder(node -> left);
    print("%d", node -> data.key);
    printOrder(node-> right);

    // use alt to switch line between in order, preorder or postorder
}