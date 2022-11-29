#include<stdio.h>

#include"mFile.h"
#include"data_t.h"

void write2File(const char fname[], node_t *p, const int n){
    FILE *fout = fopen(fname, "w");
    if(fout == NULL){
        printf("ERROR: Could not open output file \n");
        //fclose(fout);
        return ;
    }
    fwrite(&p->data, sizeof(data_t), 1, fout);
    fclose(fout);
}

int ReadFromFile(const char fname[], data_t buf[], int elemSize){
    FILE *fin = fopen(fname, "r");
    if(fin == NULL){
        printf("ERROR: Could not open input file\n");
        fclose(fin);
        return -1;
    }
    int count = 0;
    while(fread(&buf[count],sizeof(data_t),1,fin)){
        count++;
        if(count==elemSize) break;
    }
    fclose(fin);
    return count;
}