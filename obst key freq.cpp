#include <stdio.h>

int main()
{
    int n;

    scanf("%d",&n);

    int freq[n];

    for(int i=0;i<n;i++)
        scanf("%d",&freq[i]);

    int cost[n][n];

    for(int i=0;i<n;i++)
        cost[i][i]=freq[i];

    for(int len=2;len<=n;len++)
    {
        for(int i=0;i<=n-len;i++)
        {
            int j=i+len-1;

            cost[i][j]=99999;

            int sum=0;

            for(int k=i;k<=j;k++)
                sum+=freq[k];

            for(int r=i;r<=j;r++)
            {
                int c=sum;

                if(r>i)
                    c+=cost[i][r-1];

                if(r<j)
                    c+=cost[r+1][j];

                if(c<cost[i][j])
                    cost[i][j]=c;
            }
        }
    }

    printf("%d",cost[0][n-1]);

    return 0;
}