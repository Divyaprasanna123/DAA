#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int target;
    printf("Enter target sum: ");
    scanf("%d", &target);
    int bestSum = 0;
    int minDiff = 1000000;
    for(int mask = 0; mask < (1 << n); mask++) {
        int sum = 0;
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i))
                sum += arr[i];
        }
        int diff = abs(target - sum);
        if(diff < minDiff) {
            minDiff = diff;
            bestSum = sum;
        }
    }
    printf("Closest Sum = %d\n", bestSum);
    return 0;
}