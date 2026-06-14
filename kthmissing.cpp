#include <stdio.h>
int main() {
    int n, k;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter k: ");
    scanf("%d", &k);
    int current = 1;
    int i = 0;
    while(k > 0) {
        if(i < n && arr[i] == current) {
            i++;
        } else {
            k--;
            if(k == 0) {
                printf("Kth Missing Positive Integer = %d\n", current);
                break;
            }
        }
        current++;
    }
    return 0;
}