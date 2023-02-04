#include<stdio.h>

#include"tree.h"

elmType giaithua = {'!'};
elmType cong = {'+'};
elmType chia = {'/'};
elmType tru = {'-'};
elmType nhan = {'*'};
elmType a = {'9'};
elmType b = {'8'};
elmType c = {'4'};
elmType d = {'2'};

void PrintOrder(treetype cur){
    if(cur == NULL) return ;
    PrintOrder(cur -> left);
    printf("%c", cur -> element);
    PrintOrder(cur -> right);
}

int TreeCalculate(treetype cur){
    if(cur == NULL) return 0;
    if(cur->element >= '0' && cur->element <='9'){
        return (int) (cur->element - '0');
    }
    if(cur->element == '+')
        return TreeCalculate(LeftChild(cur)) + TreeCalculate(RightChild(cur));
    if(cur->element == '-')
        return TreeCalculate(LeftChild(cur)) - TreeCalculate(RightChild(cur));
    if(cur->element == '*')
        return TreeCalculate(LeftChild(cur)) * TreeCalculate(RightChild(cur));
    if(cur->element == '/')
        return TreeCalculate(LeftChild(cur)) / TreeCalculate(RightChild(cur));
    
}

int main(){
    treetype root = create_node(cong);
    treetype trav = root;
    trav = Add_Left(&root, nhan);
    trav = Add_Right(&trav, a);
    
    trav = root;
    trav = Add_Right(&root, chia);
    trav = Add_Right(&root, d);
    trav = Add_Left(&(root->right), tru);
    trav = Add_Left(&(root->right->left), b);
    trav = Add_Right(&(root->right->left), c);

    //PrintOrder(root);
    printf("\n%d\n", TreeCalculate(root));
    return 0;
}