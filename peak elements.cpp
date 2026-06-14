#include <stdio.h>
int findPeakElement(int nums[], int n) {
    int low = 0, high = n - 1;
    while(low < high) {
        int mid = low + (high - low) / 2;
        if(nums[mid] > nums[mid + 1])
            high = mid;
        else
            low = mid + 1;
    }

    return low;
}
int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int nums[n];
    printf("Enter array elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    int peakIndex = findPeakElement(nums, n);
    printf("Peak Element Index = %d\n", peakIndex);
    printf("Peak Element = %d\n", nums[peakIndex]);
    return 0;
}