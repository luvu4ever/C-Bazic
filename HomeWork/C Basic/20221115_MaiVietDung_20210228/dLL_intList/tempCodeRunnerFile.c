    node_t *nodethu3=root;
    for(int i=0; i<3; i++){
        nodethu3 = nodethu3->next;
    }
    showData(nodethu3);
    dllDelete(root, nodethu3->prev);
    dllDelete(root, nodethu3 -> next);
    PrintDLL(root);