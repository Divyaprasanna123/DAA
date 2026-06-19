#include <stdio.h>

int main() {
    int n, key;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter sorted array elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter search key: ");
    scanf("%d", &key);

    int low = 0, high = n - 1;
    int position = -1;

    while(low <= high) {

        int mid = (low + high) / 2;

        printf("low=%d high=%d mid=%d value=%d\n",
               low, high, mid, arr[mid]);

        if(arr[mid] == key) {
            position = mid + 1; 
            break;
        }
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if(position != -1)
        printf("Element found at position %d\n", position);
    else
        printf("Element not found\n");

    return 0;
}