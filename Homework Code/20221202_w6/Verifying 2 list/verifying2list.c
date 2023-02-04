//----------LuvU4ever------------
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define NOT_FOUND (-1)
#define MAX_SIZE (10005)

typedef struct phoneAddr_s{
    char name[20];
    char tel[20];
    char email[32];
} phoneAddr_t;

char ordered[] = "ordered.inp";
char unordered[] = "unordered.inp";

int linearSearch(phoneAddr_t a[], int n, char key[]){
    for(int i = 0; i<n; i++){
        if(!strcmp(a[i].name, key))
            return i;
    }
    return NOT_FOUND;
}

int binarySearch(phoneAddr_t a[], int n, char key[], int start){
    int low = start;
    int high = n-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(strcmp(a[mid].name, key) == 0)
            return mid;
        if(strcmp(a[mid].name, key) < 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void Unordered(phoneAddr_t lst1[], phoneAddr_t lst2[], int n, int m){
    int marked[MAX_SIZE];
    //init
    for(int i=0; i<m; i++) 
        marked[i] = -1;
    // dung` -1 vi` can` luu vi. tri' 0
    // thuoc day 1 ma khong thuoc day 2
    int j;
    for(int i=0; i<n; i++){
        if((j = linearSearch(lst2, m, lst1[i].name)) == NOT_FOUND)
            printf("%s is not in list 2\n", lst1[i].name);
        else
            marked[j] = i;
    }
    // thuoc day 2 ma khong thuoc day 1
    for(int i = 0; i<m; i++){
        if(marked[i] == -1)
            printf("%s is not in list 1\n", lst2[i]);
    }
    // thuoc day 1 va 2 nma cac gia tri khac nhau
    for(int i=0; i<m; i++){
        if(marked[i] != -1){
            j = marked[i];
            if(strcmp(lst1[j].tel, lst2[j].tel) || strcmp(lst1[j].email, lst2[i]. email)){
                printf("%s is on two list but different\nlist1: %-25s%-25s\nlist2: %-25s%-25s\n", lst1[j].name, lst1[j].tel, lst1[j].email, lst2[i].tel, lst2[i].email);
            }
        }
    }
    return;
}

void Ordered(phoneAddr_t lst1[], phoneAddr_t lst2[], int n, int m){
    // O(m+n) in worst case
    int marked[MAX_SIZE];
    //Init
    for(int i=0; i<m; i++) 
        marked[i] = -1;
    // dung` -1 vi` can` luu vi. tri' 0
    //Thuoc day 1 ma khong thuoc day 2
    int j=0;
    for(int i=0; i<n; i++){
        if((j = binarySearch(lst2, m, lst1[i].name, j)) == NOT_FOUND)
        //nhap j cu~ vao` se` lam` giam? so' truong` hop. can` xet', nma cx ko nhieu` vi` la` O(log n)
            printf("%s is not in list 2\n", lst1[i].name);
        else
            marked[j] = i;
    }
    // thuoc day 2 ma khong thuoc day 1
    for(int i = 0; i<m; i++){
        if(marked[i] == -1)
            printf("%s is not in list 1\n", lst2[i]);
    }
    // thuoc day 1 va 2 nma cac gia tri khac nhau
    for(int i=0; i<m; i++){
        if(marked[i] != -1){
            j = marked[i];
            if(strcmp(lst1[j].tel, lst2[j].tel) || strcmp(lst1[j].email, lst2[i]. email)){
                printf("%s is on two list but different\nlist1: %-25s%-25s\nlist2: %-25s%-25s\n", lst1[j].name, lst1[j].tel, lst1[j].email, lst2[i].tel, lst2[i].email);
            }
        }
    }
    return;
}

int main(){
    
    FILE *f = fopen(ordered,"r");
    // e dung` doc. viet' file vi` du~ lieu. dai` qua' em luoi` nhap.
    // unordered cho day chua dc sort
    // ordered cho day da duoc sort
    phoneAddr_t lst1[MAX_SIZE], lst2[MAX_SIZE];
    int ordered, n, m;

    fscanf(f, "%d", &ordered);
    //printf("Ordered? 1 for yes, 0 for no: %d", ordered);
    //printf("Nhap so phan tu thuoc day 1");
    fscanf(f, "%d", &n);
    for(int i=0; i<n; i++){
        fscanf(f, "%s %s %s", lst1[i].name, lst1[i].tel, lst1[i].email);
    }

    //printf("Nhap so phan tu thuoc day 2");
    fscanf(f, "%d", &m);
    for(int i=0; i<m; i++){
        fscanf(f, "%s %s %s", lst2[i].name, lst2[i].tel, lst2[i].email);
    }
    if(ordered == 1)
        Ordered(lst1, lst2, n, m);
    else Unordered(lst1, lst2, n, m);
    return 0;
}