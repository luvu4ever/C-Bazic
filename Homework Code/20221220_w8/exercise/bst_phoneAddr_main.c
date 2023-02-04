// Exercise
// - Create an binary search tree with 10 nodes. Each node contains an random integer.
// - Ask user to input an number and search for it.
// - Print the content of the trees.

//-------------LuvU4ever------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"

#define TREE_SIZE (10)

int main()
{
    tree_t tree = NULL;
    srand(time(NULL));

    // Create an binary search tree with 10 nodes.
    // Each node contains an random integer.
    // --- Your code here ---
    phoneAddr_t in4[TREE_SIZE] = {{"A", "001", "A@"},
                                  {"B", "002", "B@"},
                                  {"C", "003", "C@"},
                                  {"D", "004", "D@"},
                                  {"E", "005", "E@"},
                                  {"F", "006", "F@"},
                                  {"G", "007", "G@"},
                                  {"H", "008", "H@"},
                                  {"I", "009", "I@"},
                                  {"J", "010", "J@"}};
    for (int i = 0; i < TREE_SIZE; i++)
        insertNode(in4[i], &tree);
    // Print the content of the trees.
    prettyPrint(tree);
    printf("\n");

    key_t email_Input[28];
    printf("Enter email: \n");
    scanf("%s", email_Input);
    tree_t temp = search(email_Input, tree);
    if (!temp)
        printf("NOT FOUND !!!\n");
    else
        printf("\nFound:\nemail:%s\nname:%s\ntele:%s\n", temp->data.email, temp->data.name, temp->data.tel);
    freeTree(tree);
    return 1;
}