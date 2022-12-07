#include<stdio.h>
#include<stdlib.h>

#include"tree.h"

void makeNullTree(treetype *T){
    (*T) = NULL;
}

int isEmptyTree(treetype T){
    return T == NULL;
}

treetype LeftChild(treetype n){
    if(n != NULL)
        return n -> left;
    return NULL;
}

treetype RightChild(treetype n){
    if(n != NULL)
        return n -> right;
    return NULL;
}

treetype createNewNode (data_t data){
    treetype *newNode = (node_type *)malloc*(sizeof(node_type));
    if(newNode == NULL)
        return NULL;
    newNode -> left = NULL;
    newNode ->right = NULL;
    newNode -> data = data;
    return newNode;
}

int isLeaf(treetype node){
    if(node == NULL)
        return -1;
    return (LeftChild(node)==NULL) &&(RightChild(node)==NULL);
}


//------------------------------------------
            //COUNT
//------------------------------------------
int nb_nodes(treetype T){
    if(isEmptyTree(T))
        return 0;
    return 1 + nb_nodes(LeftChild(T)) + nb_nodes(RightChild(T));
}

int nb_leaf(treetype T){
    if(isEmptyTree(T))
        return 0;
    if(isLeaf(T))
        return 1;
    return nb_leaf(LeftChild(T)) + nb_leaf(RightChild(T));
}

int nb_internalNode(treetype T){
    if(isEmptyTree(T))
        return 0;
    if(LeftChild(T) == NULL && RightChild(T) == NULL)
        return 0;
    return 1 + nb_internalNode(LeftChild(T)) + nb_internalNode(RightChild(T));
}

int nb_rightNode(treetype T){
    if(isEmptyTree(T) || RightChild(T) == NULL)
        return 0;
    return 1 + nb_rightNode(LeftChild(T)) + nb_rightNode(RightChild(T));
}

//------------------------------------------
            //TRAVERSAL
//------------------------------------------

//Pre order traversal
void preorderTraversal(treetype T){
    if(isEmptyTree) return;
    //printf("%", T->element);
    preorderTraversal(LeftChild(T));
    preorderTraversal(RightChild(T));
}

//In order traversal
void inorderTraversal(treetype T){
    if(isEmptyTree) return;
    inorderTraversal(LeftChild(T));
    //printf("%", T->element);
    inorderTraversal(RightChild(T));
}

//Post order traversal
void preorderTraversal(treetype T){
    if(isEmptyTree) return;
    postorderTraversal(LeftChild(T));
    postorderTraversal(RightChild(T));
    //printf("%", T->element);
}