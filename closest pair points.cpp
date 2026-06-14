#include <stdio.h>
#include <math.h>
int main() {
    int n;
    printf("Enter number of points: ");
    scanf("%d", &n);
    int x[n], y[n];
    printf("Enter x and y coordinates:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }
    double minDist = 1e9;
    int p1 = 0, p2 = 1;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            double dist = sqrt(
                (x[i] - x[j]) * (x[i] - x[j]) +
                (y[i] - y[j]) * (y[i] - y[j])
            );
            if(dist < minDist) {
                minDist = dist;
                p1 = i;
                p2 = j;
            }
        }
    }
    printf("Closest pair: (%d,%d) - (%d,%d)\n",
           x[p1], y[p1], x[p2], y[p2]);
    printf("Minimum distance: %lf\n", minDist);
    return 0;
}