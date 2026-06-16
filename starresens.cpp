#include <stdio.h>
int main() {
    int A[2][2], B[2][2], C[2][2];
    printf("Enter Matrix A (2x2):\n");
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            scanf("%d", &A[i][j]);
    printf("Enter Matrix B (2x2):\n");
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            scanf("%d", &B[i][j]);
    int a=A[0][0], b=A[0][1], c=A[1][0], d=A[1][1];
    int e=B[0][0], f=B[0][1], g=B[1][0], h=B[1][1];
    int M1 = (a+d)*(e+h);
    int M2 = (c+d)*e;
    int M3 = a*(f-h);
    int M4 = d*(g-e);
    int M5 = (a+b)*h;
    int M6 = (c-a)*(e+f);
    int M7 = (b-d)*(g+h);
    C[0][0] = M1 + M4 - M5 + M7;
    C[0][1] = M3 + M5;
    C[1][0] = M2 + M4;
    C[1][1] = M1 - M2 + M3 + M6;
    printf("Result Matrix C:\n");
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}