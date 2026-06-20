#include <stdio.h>

int main()
{
    int n, x;

    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &x);

    int total = 1 << n;

    for(int i = 0; i < total; i++)
    {
        int found = 0;

        for(int j = 0; j < n; j++)
        {
            if((i & (1 << j)) && arr[j] == x)
                found = 1;
        }

        if(found)
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

    return 0;
}