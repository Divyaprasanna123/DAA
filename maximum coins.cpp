#include <stdio.h>
void sort(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main() {
    int n;
    printf("Enter number of piles: ");
    scanf("%d", &n);
    int piles[n];
    printf("Enter pile values: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &piles[i]);
    }
    sort(piles, n);
    int coins = 0;
    int left = 0;
    int right = n - 1;
    while(left < right) {
        right--;               
        coins += piles[right]; 
        right--;
        left++;                
    }
    printf("Maximum coins = %d\n", coins);
    return 0;
}