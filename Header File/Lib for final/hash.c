//---------------LuvU4ever-------------

#include "hash.h"

#include <string.h>

element_t *D[TABLE_SIZE];
// Hash Code Maps
// Component Sum
static const int transform(const char *key) {
  int number;
  for (number = 0; (*key) != 0; key++) number += *key;
  return number;
}

// Compression map
int hash(const char *key) { 
  return (transform(key) % TABLE_SIZE); 
}


void init_table(element_t *ht[]) { 
  clear(ht);
}

void clear(element_t *ht[]) {
  for (int i = 0; i < TABLE_SIZE; i++) {
    clearbucket(ht, i);
  }
}

void clearbucket(element_t *ht[], int i) {
  while(ht[i]){
    Node *temp = ht[i];
    ht[i] = ht[i] -> next;
    free(temp);
  }
}

element_t *findElement(element_t *ht[], char key[]) {
  const int hash_value = hash(key);
  if (ht[hash_value] == NULL)
    return NULL;
  Node* cur = ht[hash_value];
  while(cur != NULL){
    if(!strcmp(cur->key, key))
      return cur;
    cur = cur -> next;
  }
  return NULL;
}

int insertItem(element_t *ht[], element_t o) {
  int hash_value = hash(o.key);
  element_t *pNewElement = (element_t *)malloc(sizeof(element_t) * 1);
  strcpy(pNewElement->key, o.key);
  strcpy(pNewElement->word, o.word);
  pNewElement->next = NULL;

  if (ht[hash_value] == NULL){
    ht[hash_value] = pNewElement;
    return TRUE;
  }
  Node *cur = ht[hash_value];
  while(cur -> next != NULL)
    cur = cur -> next;
  cur -> next = pNewElement;
  return TRUE;
}

int removeElement(element_t *ht[], char key[]) {
  int hash_value = hash(key);
  element_t *cur = ht[hash_value];
  //Null case
  if (cur == NULL)
    return -1;  //cant find
  //First node case
  if(!strcmp(cur->key, key)){
    ht[hash_value] = cur -> next;
    free(cur);
    return TRUE;
  }
  //Other
  Node *prev;
  while(cur != NULL && strcmp(cur -> key, key)){
    prev = cur;
    cur = cur -> next;
  }
  if(cur == NULL)
    return -1;  //cant find
  prev -> next = cur -> next;
  free(cur);
  return TRUE;
}

int isEmpty(element_t *ht[]) {
  for (int i = 0; i < TABLE_SIZE; i++)
    if (ht[i] != NULL) return FALSE;
  return TRUE;
}

void traverse(element_t *ht[]) {
  for (int b = 0; b < TABLE_SIZE; b++) {
    printf("\nBucket %d\n", b);               
    _traversebucket(ht, b);
  }
}

void _traversebucket(element_t *ht[], int b) {
  if(ht[b] == NULL){
    printf("Empty.\n");
    return;
  }
  Node *cur = ht[b];
  while(cur -> next != NULL){
    printf("%s ------>", cur -> key);
    cur = cur -> next;
  }
  printf("%s\n", cur -> key);
  return;
}