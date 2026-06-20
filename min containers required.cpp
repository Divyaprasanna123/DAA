#include <stdio.h>

int main()
{
    int n, capacity;

    scanf("%d", &n);

    int weights[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &weights[i]);

    scanf("%d", &capacity);

    int containers = 1;
    int currentLoad = 0;

    for(int i = 0; i < n; i++)
    {
        if(currentLoad + weights[i] <= capacity)
        {
            currentLoad += weights[i];
        }
        else
        {
            containers++;
            currentLoad = weights[i];
        }
    }

    printf("%d", containers);

    return 0;
}