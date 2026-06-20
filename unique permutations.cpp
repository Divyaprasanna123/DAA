#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int shouldSwap(int arr[], int start, int curr)
{
    for(int i = start; i < curr; i++)
    {
        if(arr[i] == arr[curr])
            return 0;
    }
    return 1;
}

void permute(int arr[], int l, int r)
{
    if(l == r)
    {
        printf("[");
        for(int i = 0; i <= r; i++)
        {
            printf("%d", arr[i]);
            if(i != r)
                printf(",");
        }
        printf("]\n");
        return;
    }

    for(int i = l; i <= r; i++)
    {
        if(shouldSwap(arr, l, i))
        {
            swap(&arr[l], &arr[i]);
            permute(arr, l + 1, r);
            swap(&arr[l], &arr[i]);
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    permute(arr, 0, n - 1);

    return 0;
}