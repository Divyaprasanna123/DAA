#include <stdio.h>
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int unique[n];
    int k = 0;
    for(int i = 0; i < n; i++) {
        int found = 0;
        for(int j = 0; j < k; j++) {
            if(arr[i] == unique[j]) {
                found = 1;
                break;
            }
        }
        if(found == 0) {
            unique[k++] = arr[i];
        }
    }
    printf("Unique Elements: ");
    for(int i = 0; i < k; i++) {
        printf("%d ", unique[i]);
    }
    return 0;
}