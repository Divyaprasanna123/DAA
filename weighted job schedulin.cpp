#include <stdio.h>

struct Job
{
    int start;
    int end;
    int profit;
};

void sort(struct Job jobs[], int n)
{
    int i, j;
    struct Job temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(jobs[i].end > jobs[j].end)
            {
                temp = jobs[i];
                jobs[i] = jobs[j];
                jobs[j] = temp;
            }
        }
    }
}

int latestNonConflict(struct Job jobs[], int i)
{
    int j;

    for(j = i - 1; j >= 0; j--)
    {
        if(jobs[j].end <= jobs[i].start)
            return j;
    }

    return -1;
}

int main()
{
    int n, i;

    scanf("%d", &n);

    struct Job jobs[n];

    for(i = 0; i < n; i++)
        scanf("%d", &jobs[i].start);

    for(i = 0; i < n; i++)
        scanf("%d", &jobs[i].end);

    for(i = 0; i < n; i++)
        scanf("%d", &jobs[i].profit);

    sort(jobs, n);

    int dp[n];

    dp[0] = jobs[0].profit;

    for(i = 1; i < n; i++)
    {
        int incl = jobs[i].profit;

        int l = latestNonConflict(jobs, i);

        if(l != -1)
            incl += dp[l];

        dp[i] = (incl > dp[i - 1]) ? incl : dp[i - 1];
    }

    printf("%d", dp[n - 1]);

    return 0;
}