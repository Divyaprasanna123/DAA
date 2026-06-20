#include <stdio.h>

void generate(int arr[], int n)
{
    int total = 1 << n;

    for(int i = 0; i < total; i++)
    {
        printf("{ ");

        for(int j = 0; j < n; j++)
        {
            if(i & (1 << j))
                printf("%d ", arr[j]);
        }

        printf("}\n");
    }
}

int main()
{
    int n;

    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    generate(arr, n);

    return 0;
}