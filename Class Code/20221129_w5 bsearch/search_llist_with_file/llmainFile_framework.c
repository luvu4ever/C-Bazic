#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "./data_t.h"
#include "./mFile.h"
#include "./ll.h"

#define NOT_FOUND -1
#define MAX_ARRAY 100

typedef phoneAddr_t T;

// TODO: 
// return index of items where items[index] == key
int linearSearchStr(root_t root, char name2Find[]) {
  int index = 0;
  for(node_t *p = root; p != NULL; p = p->next){
    if(!strcmp(p-> data.name, name2Find))
      return index;
    index++;
  }
  return NOT_FOUND;  // no match
}

int main() {
  const char fname[] = "./test.dat";
  phoneAddr_t a[100];
  
  int n = ReadFromFile(fname, a, MAX_ARRAY);
  showAllData(a, n);
  printf("\n");

  root_t lst = llInit();
  node_t *p = lst;
  for(int i=0; i<n; i++){
    if(!i){
      lst = llInsertHead(lst, a[i]);
      p = lst;
      continue;
    }
    p = llInsert(p, a[i]);
  }
  char name[] = "B";
  int index = linearSearchStr(lst, name);

  if (index == NOT_FOUND)
    printf("Not found\n");
  else {
    printf("Found. Index = %d\n", index);
    node_t *p = llSeek(lst, index);
    showData(p->data);
    //showData(a[index]);
    write2File("result.dat", p, index);
    printf("\n");
    // check
    phoneAddr_t buf[1];
    ReadFromFile("result.dat", buf, 1);
    showData(buf[0]);
  }  
  lst = llDeleteAll(lst);
  return 0;
}