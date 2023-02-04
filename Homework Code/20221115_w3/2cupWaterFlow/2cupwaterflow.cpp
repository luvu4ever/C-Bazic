#include<bits/stdc++.h>

#define forr(i,a,b) for(int i=a; i<=b; ++i)
#define MAXN 1005


using namespace std;



int check[MAXN][MAXN];

void BFS(int max1, int max2, int wanted){
    int last = 1;
    int pos1[MAXN];
    int pos2[MAXN];
    pos1[1] = 0;
    pos2[1] = 0;
    int count = 0;
    while(last != 0){
        count++;
        int cur1 = pos1[last];
        int cur2 = pos2[last];
        last --;
        if(check[cur1][cur2]) continue;
        printf("%d %d\n", cur1, cur2);
        if(cur1 + cur2 == wanted){
            printf("%d %d %d\n", cur1, cur2, count);
            return;
        }
        int cursum = cur1 + cur2;
        printf("%d\n", cursum);
        //do tu coc 1 sang coc 2
        if(max2 >= cursum){
            if(!check[0][cursum]){
                last++;
                pos1[last] = 0;
                pos2[last] = cursum;
            }
        }
        else{
            if(!check[cursum-max2][max2]){
                last++;
                pos1[last] = cursum - max2;
                pos2[last] = max2;
            }
        }
        //do tu coc 2 sang coc 1
        if(max1 >= cursum){
            if(!check[cursum][0]){
                last++;
                pos1[last] = cursum;
                pos2[last] = 0;
            }
        }
        else{
            if(!check[max1][cursum - max1]){
                last++;
                pos1[last] = max1;
                pos2[last] = cursum - max1;
            }
        }
        //do coc 1 di
        if(!check[0][cur2])
            {last++;
            pos1[last] = 0;
            pos2[last] = cur2;}
        //do coc 2 di
        if(!check[cur1][0])
            {last++;
            pos2[last] = 0;
            pos1[last] = cur1;
        if(!check[max1][cur2]){
            last++;
            pos1[last] = max1;
            pos2[last]= cur2;
        }
        if(!check[cur1][max2]){
            last++;
            pos1[last] = cur1;
            pos2[last]= max2;
        }
        check[cur1][cur2] = 1;
    }
    }
}

int main(){
    int max1, max2, wanted;
    cin >> max1 >> max2 >> wanted;
    BFS(max1, max2, wanted);
}