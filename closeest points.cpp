#include <stdio.h>
int main() {
    int n, k;
    printf("Enter number of points: ");
    scanf("%d", &n);
    int x[n], y[n];
    printf("Enter points:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    printf("Enter k: ");
    scanf("%d", &k);
    int dist[n];
    for(int i = 0; i < n; i++)
        dist[i] = x[i]*x[i] + y[i]*y[i];
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(dist[j] > dist[j+1]) {
                int temp = dist[j];
                dist[j] = dist[j+1];
                dist[j+1] = temp;
                int tx = x[j];
                x[j] = x[j+1];
                x[j+1] = tx;
                int ty = y[j];
                y[j] = y[j+1];
                y[j+1] = ty;
            }
        }
    }
    printf("Closest Points:\n");
    for(int i = 0; i < k; i++)
        printf("[%d,%d]\n", x[i], y[i]);
    return 0;
}