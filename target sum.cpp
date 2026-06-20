#include <stdio.h>

int countWays(int nums[], int n, int index, int sum, int target)
{
    if(index == n)
        return (sum == target);

    return countWays(nums, n, index + 1,
                     sum + nums[index], target)
         + countWays(nums, n, index + 1,
                     sum - nums[index], target);
}

int main()
{
    int n, target;

    scanf("%d", &n);

    int nums[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    scanf("%d", &target);

    printf("%d",
           countWays(nums, n, 0, 0, target));

    return 0;
}