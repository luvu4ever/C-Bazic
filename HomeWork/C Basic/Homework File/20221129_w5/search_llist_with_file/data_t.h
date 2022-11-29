#ifndef __DATA_T_H__
#define __DATA_T_H__

typedef struct {
  char name[20], tel[20], email[32];
} phoneAddr_t;

typedef phoneAddr_t data_t;

typedef struct node_s {
  data_t data;
  struct node_s *next;
} node_t, *root_t;

// Must Adapt to new problem
void showData(const data_t data);
void showAllData(data_t a[], int elemNbr);
// data_t convert(int i);

#endif