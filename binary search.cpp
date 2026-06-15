#include <stdio.h>
int main() {
    int n, key;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    scanf("%d", &key);
    int low = 0;
    int high = n - 1;
    int comparisons = 0;
    int pos = -1;
    while(low <= high) {
        comparisons++;
        int mid = (low + high) / 2;
        if(arr[mid] == key) {
            pos = mid + 1; 
            break;
        }
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    if(pos != -1) {
        printf("Position = %d\n", pos);
        printf("Comparisons = %d\n", comparisons);
    }
    else {
        printf("Element not found\n");
    }
    return 0;
}