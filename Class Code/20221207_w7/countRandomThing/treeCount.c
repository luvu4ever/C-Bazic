#include<stdio.h>

#include"tree.h"

int max(int a, int b){
    return (a>b) ? a:b;
}

int treeHeight(treetype cur){
    if(cur == NULL)
        return 0;
    if(LeftChild(cur) == NULL && RightChild(cur) == NULL)
        return 1;
    return max(treeHeight(LeftChild(cur)), treeHeight(RightChild(cur))) + 1;
}

int treeLeafCount(treetype cur){
    if(cur == NULL)
        return 0;
    if(LeftChild(cur) == NULL && RightChild(cur) == NULL)
        return 1;
    return treeLeafCount(LeftChild(cur)) + treeLeafCount(RightChild(cur));
}

int treeInternalNodeCount(treetype cur){
    if(cur == NULL)
        return 0;
    if(LeftChild(cur) == NULL && RightChild(cur) == NULL)
        return 1;
    return treeInternalNodeCount(LeftChild(cur)) + treeInternalNodeCount(RightChild(cur))+1;
}

int treeRightChildrenCount(treetype cur){
    if(cur == NULL || RightChild(cur) == NULL)
        return 0;
    return treeRightChildrenCount(LeftChild(cur)) + treeRightChildrenCount(RightChild(cur)) + 1;
}

int main(){
    treetype tr;
    makeNullTree(&tr);
    for(int i=0; i<10; i++)
        Add_Left(&tr, 10+i);
    for(int i=0; i<5; i++)
        Add_Right(&tr, 100+i);
    tr = createfrom2(1000, tr, tr);
    printf("Height: %d\nInternal:%d\nLeaf:%d\nRight:%d\n", treeHeight(tr), treeInternalNodeCount(tr), treeLeafCount(tr), treeRightChildrenCount(tr));
    return 0;
}