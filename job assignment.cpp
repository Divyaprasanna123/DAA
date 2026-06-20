#include <stdio.h>

int jobs[20];
int workers[20];
int n, k;
int answer = 1000000;

void backtrack(int idx)
{
    if(idx == n)
    {
        int i, max = 0;

        for(i = 0; i < k; i++)
            if(workers[i] > max)
                max = workers[i];

        if(max < answer)
            answer = max;

        return;
    }

    int i;

    for(i = 0; i < k; i++)
    {
        workers[i] += jobs[idx];

        if(workers[i] < answer)
            backtrack(idx + 1);

        workers[i] -= jobs[idx];

        if(workers[i] == 0)
            break;
    }
}

int main()
{
    int i;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &jobs[i]);

    scanf("%d", &k);

    backtrack(0);

    printf("%d", answer);

    return 0;
}