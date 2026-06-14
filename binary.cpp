#include <stdio.h>
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;

        else if(arr[mid] < key)
            low = mid + 1;

        else
            high = mid - 1;
    }
    return -1;
}
int main() {
    int arr[] = {-9,3,4,6,8,9,10,30};
    int n = 8;
    int key = 10;
    int result = binarySearch(arr, n, key);
    if(result != -1)
        printf("Element %d is found at position %d", key, result + 1);
    else
        printf("Element %d is not found", key);

    return 0;
}