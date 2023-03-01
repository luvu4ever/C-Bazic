//---------------LuvU4ever--------------

#ifndef __HASH_H__
#define __HASH_H__

#include<stdio.h>
#include<stdlib.h>

#define MAX_CHAR (11)
#define TABLE_SIZE (13)

enum { FALSE, TRUE };

typedef struct node_t {
  char key[MAX_CHAR];
  char word[50];
  struct node_t* next;
} element_t, Node;

void init_table(element_t* ht[]);
int hash(const char *key);

element_t* findElement(element_t* ht[], char key[]);
int insertItem(element_t* ht[], element_t o);
int removeElement(element_t* ht[], char key[]);

int isEmpty(element_t* ht[]);

void clear(element_t* ht[]);

void traverse(element_t* ht[]); 

void _traversebucket(element_t *ht[], int b);

void clearbucket(element_t *ht[], int b);
void clear(element_t *ht[]);
#endif __HASH_H__