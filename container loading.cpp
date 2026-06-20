#include <stdio.h>

void sortDescending(int a[], int n)
{
    int i, j, temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(a[i] < a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main()
{
    int n, capacity;

    scanf("%d", &n);

    int weights[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &weights[i]);

    scanf("%d", &capacity);

    sortDescending(weights, n);

    int total = 0;

    for(int i = 0; i < n; i++)
    {
        if(total + weights[i] <= capacity)
            total += weights[i];
    }

    printf("%d", total);

    return 0;
}