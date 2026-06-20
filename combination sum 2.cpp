#include <stdio.h>

int result[100];

void sort(int a[], int n)
{
    int temp;

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void solve(int arr[], int n,
           int target, int start, int pos)
{
    if(target == 0)
    {
        printf("[");
        for(int i = 0; i < pos; i++)
        {
            printf("%d", result[i]);

            if(i != pos - 1)
                printf(",");
        }
        printf("]\n");
        return;
    }

    for(int i = start; i < n; i++)
    {
        if(i > start && arr[i] == arr[i - 1])
            continue;

        if(arr[i] > target)
            break;

        result[pos] = arr[i];

        solve(arr, n,
              target - arr[i],
              i + 1, pos + 1);
    }
}

int main()
{
    int n, target;

    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &target);

    sort(arr, n);

    solve(arr, n,
          target, 0, 0);

    return 0;
}