#include <stdio.h>
int main() {
    int n, k;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int nums[n];
    printf("Enter array elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    printf("Enter k: ");
    scanf("%d", &k);
    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(nums[i] == nums[j] && ((i * j) % k == 0)) {
                count++;
            }
        }
    }
    printf("Number of valid pairs = %d\n", count);
    return 0;
}