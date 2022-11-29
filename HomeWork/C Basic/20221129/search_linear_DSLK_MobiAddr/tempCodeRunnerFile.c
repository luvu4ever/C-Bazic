    char Asked[32];
    fscanf(f, "%s", Asked);
    node_t *trav = root;
    root = llMoveStudentToTop(root, Asked);