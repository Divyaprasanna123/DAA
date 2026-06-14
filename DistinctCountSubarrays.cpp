#include <stdio.h>
int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int nums[n];
    printf("Enter array elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    int sum = 0;
    for(int i = 0; i < n; i++) {
        int freq[101] = {0}; 
        int distinct = 0;
        for(int j = i; j < n; j++) {
            if(freq[nums[j]] == 0) {
                distinct++;
            }
            freq[nums[j]]++;
            sum += distinct * distinct;
        }
    }
    printf("Sum of squares of distinct counts = %d\n", sum);
    return 0;
}