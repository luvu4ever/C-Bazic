#include <stdio.h>
#include <string.h>

#include "./data_t.h"
#include "./mFile.h"

#define NOT_FOUND -1
#define MAX_SIZE 105

typedef phoneAddr_t T;

// TODO: 
// return index of items where items[index] == key
int linearSearchStr(T items[], int siz, char name2Find[]) {
  for(int i = 0; i < siz; i++){
    if(!strcmp(items[i].name, name2Find)) 
      return i;
  }
  return NOT_FOUND;  // no match
}

int main() {
  const char fname[] = "./test.dat";
  phoneAddr_t a[100];
  
  int n = ReadFromFile(fname, a, MAX_SIZE );
  if(n == -1) 
    return 0;
  showAllData(a, n);
  printf("\n");
  
  char name[] = "B";
  int index = linearSearchStr(a, n, name);

  if (index == NOT_FOUND)
    printf("Not found\n");
  else {
    printf("Found. Index = %d\n", index);
    showData(a[index]);
    write2File("result.dat", a , index);
    printf("\n");
    
    // check
    phoneAddr_t buf[1];
    ReadFromFile("result.dat", buf, 1);
    showData(buf[0]);
  }  

  return 0;
}