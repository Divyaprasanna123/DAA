#include <stdio.h>

int arr[100];

void solve(int candidates[], int n,
           int target, int index, int pos)
{
    if(target == 0)
    {
        printf("[");
        for(int i = 0; i < pos; i++)
        {
            printf("%d", arr[i]);

            if(i != pos - 1)
                printf(",");
        }
        printf("]\n");
        return;
    }

    if(target < 0 || index == n)
        return;

    arr[pos] = candidates[index];

    solve(candidates, n,
          target - candidates[index],
          index, pos + 1);

    solve(candidates, n,
          target,
          index + 1, pos);
}

int main()
{
    int n, target;

    scanf("%d", &n);

    int candidates[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &candidates[i]);

    scanf("%d", &target);

    solve(candidates, n,
          target, 0, 0);

    return 0;
}