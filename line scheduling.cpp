#include <stdio.h>
int min(int a, int b) {
    return (a < b) ? a : b;
}
int main() {
    int n;
    printf("Enter number of stations: ");
    scanf("%d", &n);
    int a1[n], a2[n];
    int t1[n-1], t2[n-1];
    printf("Enter station times for Line 1:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &a1[i]);
    printf("Enter station times for Line 2:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &a2[i]);
    printf("Enter transfer times from Line1 to Line2:\n");
    for(int i = 0; i < n - 1; i++)
        scanf("%d", &t1[i]);
    printf("Enter transfer times from Line2 to Line1:\n");
    for(int i = 0; i < n - 1; i++)
        scanf("%d", &t2[i]);
    int e1, e2, x1, x2;
    printf("Enter entry times e1 and e2: ");
    scanf("%d %d", &e1, &e2);
    printf("Enter exit times x1 and x2: ");
    scanf("%d %d", &x1, &x2);
    int f1[n], f2[n];
    f1[0] = e1 + a1[0];
    f2[0] = e2 + a2[0];
    for(int i = 1; i < n; i++) {
        f1[i] = min(
            f1[i-1] + a1[i],
            f2[i-1] + t2[i-1] + a1[i]
        );
        f2[i] = min(
            f2[i-1] + a2[i],
            f1[i-1] + t1[i-1] + a2[i]
        );
    }
    int answer = min(
        f1[n-1] + x1,
        f2[n-1] + x2
    );
    printf("Minimum time required = %d\n", answer);
    return 0;
}