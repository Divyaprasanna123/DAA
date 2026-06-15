#include <stdio.h>
void quickSort(int arr[], int low, int high) {
    int i = low;
    int j = high;
    int pivot = arr[(low + high) / 2];
    while(i <= j) {
        while(arr[i] < pivot)
            i++;
        while(arr[j] > pivot)
            j--;
        if(i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    printf("Partition: ");
    for(int k = low; k <= high; k++)
        printf("%d ", arr[k]);
    printf("\n");
    if(low < j)
        quickSort(arr, low, j);
    if(i < high)
        quickSort(arr, i, high);
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    quickSort(arr, 0, n - 1);
    printf("Sorted Array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}