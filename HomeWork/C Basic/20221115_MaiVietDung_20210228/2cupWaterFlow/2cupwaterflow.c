#include<stdio.h>
#include"queue.h"

int check[1005][1005];
int par[1005][1005];
int count = 0;

void BFS(int max1, int max2, int wanted){
    Queue q;
    initialize(&q);
    EnQueue(0, &q);
    while(!Empty_Queue(q)){
        int t = DeQueue(&q);
        int cur1 = t / 100;
        int cur2 = t - cur1 * 100;
        //printf("%d %d %d\n", cur1, cur2, count);
        if(check[cur1][cur2]) continue;
        if(cur1 + cur2 == wanted || cur1==wanted || cur2 == wanted){
            //printf("%d %d %d\n", cur1, cur2, count);
            int temp = cur1 * 100 + cur2;
            int count = 1;
            while(temp != 0){
                printf("%d %d %d\n", temp/100, temp%100, count++);
                temp = par[temp/100][temp%100];
            }
            break;
        }
        check[cur1][cur2] = 1;
        int cursum = cur1 + cur2;
        //do tu coc 1 sang coc 2
        if(max2 >= cursum){
            if(!check[0][cursum]){
                par[0][cursum] = cur1 * 100 + cur2;
                int temp = 0*100 + cursum;
                EnQueue(temp, &q);
            }
        }
        else if(!check[cursum-max2][max2]){
            par[cursum - max2][max2] = cur1 * 100 + cur2;
            int temp = (cursum-max2)*100 + max2;
            EnQueue(temp, &q);
        }

        if(max1 >= cursum){
            if(!check[cursum][0]){
                par[cursum][0] = cur1 * 100 + cur2;
                int temp = 0 + cursum*100;
                EnQueue(temp, &q);
            }
        }
        else if(!check[max1][cursum-max1]){
            par[max1][cursum-max1] = cur1 * 100 + cur2;
            int temp = (cursum-max1) + max1*100;
            EnQueue(temp, &q);
        }  


        if(!check[0][cur2]){
            par[0][cur2] = cur1 * 100 + cur2;
            int temp = 0*100 + cur2;
            EnQueue(temp, &q);
        }
        if(!check[cur1][0]){
            par[cur1][0] = cur1 * 100 + cur2;
            int temp = 0 + cur1*100;
            EnQueue(temp, &q);
        }
        if(!check[max1][cur2]){
            par[max1][cur2] = cur1 * 100 + cur2;
            int temp = max1*100 + cur2;
            EnQueue(temp, &q);
        }
        if(!check[cur1][max2]){
            par[cur1][max2] = cur1 * 100 + cur2;
            int temp = cur1*100 + max2;
            EnQueue(temp, &q);
        }
    }
}

int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    BFS(a,b,c);
}