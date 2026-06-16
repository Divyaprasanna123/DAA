#include <stdio.h>
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int target;
    printf("Enter exact sum: ");
    scanf("%d", &target);
    int found = 0;
    for(int mask = 0; mask < (1 << n); mask++) {
        int sum = 0;
        for(int i = 0; i < n; i++) {
            if(mask & (1 << i))
                sum += arr[i];
        }
        if(sum == target) {
            found = 1;
            break;
        }
    }
    if(found)
        printf("true\n");
    else
        printf("false\n");
    return 0;
}