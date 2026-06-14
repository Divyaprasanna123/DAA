#include <stdio.h>
int robLinear(int nums[], int start, int end) {
    int prev1 = 0, prev2 = 0;
    for(int i = start; i <= end; i++) {
        int temp = prev1;

        if(prev2 + nums[i] > prev1)
            prev1 = prev2 + nums[i];

        prev2 = temp;
    }
    return prev1;
}
int main() {
    int n;
    printf("Enter number of houses: ");
    scanf("%d", &n);
    int nums[n];
    printf("Enter money in each house: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    if(n == 1) {
        printf("Maximum money = %d\n", nums[0]);
        return 0;
    }
    int case1 = robLinear(nums, 0, n - 2);
    int case2 = robLinear(nums, 1, n - 1);
    int result;
    if(case1 > case2)
        result = case1;
    else
        result = case2;
    printf("Maximum money = %d\n", result);
    return 0;
}