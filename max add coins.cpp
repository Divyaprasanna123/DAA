#include <stdio.h>

void sort(long long a[], int n)
{
    int i, j;
    long long temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
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

int main()
{
    int n, i;
    long long target;

    scanf("%d", &n);

    long long coins[n];

    for(i = 0; i < n; i++)
        scanf("%lld", &coins[i]);

    scanf("%lld", &target);

    sort(coins, n);

    long long reach = 1;
    int added = 0;
    i = 0;

    while(reach <= target)
    {
        if(i < n && coins[i] <= reach)
        {
            reach += coins[i];
            i++;
        }
        else
        {
            reach += reach;
            added++;
        }
    }

    printf("%d", added);

    return 0;
}