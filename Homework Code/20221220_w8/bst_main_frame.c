// Exercise 
// - Create an binary search tree with 10 nodes. 
// - Each node contains an random data which includes email, name and telephone number. 
// - Ask user to input an email and search for it.
// - Print the content of the trees. 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"
int main() {
  tree_t tree = NULL;
  srand(time(NULL));

  // Create an binary search tree with 10 nodes.
  // Each node contains an random data.
  phoneAddr_t A[10] = { {"E","011","E@"},
                        {"D","010","D@"},
                        {"A","012","A@"},
                        {"H","022","H@"},
                        {"J","021","J@"},
                        {"B","066","B@"},
                        {"I","099","I@"},
                        {"C","032","C@"},
                        {"F","055","F@"},
                        {"G","088","G@"}    
  };

  //insert
  for(int i = 0 ; i < 10 ; i++ ) insertNode(A[i],&tree);

  // Print the content of the trees. 
  prettyPrint(tree);  printf("\n");

  key_t email_Input;  //user's input

  // Ask user to input an email and search for it.
  printf("Enter key (email) to search: ");
  scanf("%s",email_Input);
  printf("%c",email_Input);
  // Search
  tree_t p = search( email_Input , tree );
  // if( !p ) printf("NOT FOUND !!!\n");
  // else printf("\nResult:\nemail:%s\nname:%s\ntele:%s\n",p->data.email,p->data.name,p->data.tel);

  //free  
  freeTree(tree);

  return 1;
}