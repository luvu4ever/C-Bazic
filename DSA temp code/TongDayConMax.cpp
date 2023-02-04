#include <bits/stdc++.h>
using namespace std;
int main(){
    printf("Tim doan con co tong lon nhat\n");
    printf("Nhap so luong phan tu:\n");
    int n;
    scanf("%d",&n);
    int a[n+1] , i ;
    printf("Nhap day so:\n");
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    
    int maxSum = a[0];
        for (int i=0; i<n; i++) {
            int sum = 0;
            for (int j=i; j<n; j++) {
                sum += a[j];
                if ( sum > maxSum )
                    maxSum = sum;
                }
        }
    printf("Ket qua: %d",maxSum);
    return 0;
}
