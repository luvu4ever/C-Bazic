//------------LuvU4ever----------------
#include<stdio.h>
#include<string.h>
#include "bst.h"

#define MAX_WORD_LENGTH 105

int isValid(char key){
    if(('a'<= key && key <= 'z') || ('A'<= key  && key<= 'Z') || ('0'<= key  && key<= '9'))
        return 1;
    return 0;
}

char toUppercase(char key){
    if(('a'<= key && key<= 'z'))
        return (key - 'a' + 'A');
    return key;
}

int main(int argc, char *argv[]){

    if(argc != 3){
        printf("Syntax error. \n");
        printf("Example: wordcount input.txt output.txt\n");
        return 0;
    }

    FILE *fin = fopen(argv[1], "r");
    if(fin == NULL){
        printf("Error: Couldn't open input file.\n");
        return 0;
    }

    FILE *fout = fopen(argv[2], "w");
    if(fout == NULL){
        printf("Error: Couldn't open output file.\n");
        return 0;
    }

    char input = '\0';
    tree_t tree = NULL;

    while(fscanf(fin, "%c", &input) != EOF){
        char word[MAX_WORD_LENGTH] = "\0";

        if(isValid(input)){
            input = toUppercase(input);
            if(!strlen(word)) word[0] = input;
                else word[strlen(word)] = input;
        }
        else continue;

        while(fscanf(fin, "%c", &input) != EOF && isValid(input)){
            input = toUppercase(input);
            if(!strlen(word)) word[0] = input;
                else word[strlen(word)] = input;
        }

        tree_t pWord = Search(tree, word);
        if(pWord != NULL){
            //found word
            pWord -> data.count ++;
            continue;
        }
        //unfound
        data_t tmpData;
        strcpy(tmpData.word, word);
        tmpData.count = 1;            
        insertNode(tmpData, &tree);
    }

    printTree(tree, fout);

    freeTree(tree);
    fclose(fin);
    fclose(fout);

    return 0;
}