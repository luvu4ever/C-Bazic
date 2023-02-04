#include<stdio.h>

char original_filename[] = "class1EF.txt";
char temp_filename[] = "temp.txt";

int main(){
    FILE *read_original = fopen(original_filename, "r");
    FILE *write_temp = fopen(temp_filename, "w");
    if(read_original == NULL){
        printf("Error: Could not open %s\n", original_filename);
        return 1;
    }
    char s[100005];
    while(fgets(s, sizeof(s), read_original) != NULL){
        fprintf(write_temp, "%s", s);
    }
    fclose(read_original);
    fclose(write_temp);
    FILE *write_original = fopen(original_filename, "w");
    FILE *read_temp = fopen(temp_filename, "r");
    while(fgets(s, sizeof(s), read_temp) != NULL){
        fprintf(write_original, "%s\n", s);
    }
    return 0;
}