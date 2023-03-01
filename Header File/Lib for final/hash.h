//---------------LuvU4ever--------------

#ifndef __HASH_H__
#define __HASH_H__

#include<stdio.h>
#include<stdlib.h>

#define MAX_CHAR (11)
#define TABLE_SIZE (13)

typedef struct node_t{
    char key[MAX_CHAR];
    char word[50];
    struct node_t *next;
} element_t;

element_t *ht[TABLE_SIZE];

void init_table(element_t ht[]);
int hash(const char *key);

element_t *findElement(element_t *ht[], char key[]);