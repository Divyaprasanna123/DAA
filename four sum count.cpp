#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int A[n], B[n], C[n], D[n];
    for(int i=0;i<n;i++) scanf("%d",&A[i]);
    for(int i=0;i<n;i++) scanf("%d",&B[i]);
    for(int i=0;i<n;i++) scanf("%d",&C[i]);
    for(int i=0;i<n;i++) scanf("%d",&D[i]);
    int count = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                for(int l=0;l<n;l++)
                    if(A[i]+B[j]+C[k]+D[l]==0)
                        count++;

    printf("%d",count);
    return 0;
}