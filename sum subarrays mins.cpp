#include <stdio.h>

int main()
{
    int n;

    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    long long sum = 0;

    for(int i = 0; i < n; i++)
    {
        int min;

        for(int j = i; j < n; j++)
        {
            if(j == i)
                min = arr[j];
            else if(arr[j] < min)
                min = arr[j];

            sum += min;
        }
    }

    printf("%lld", sum);

    return 0;
}