#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);

    float freq[n];

    for(int i=0;i<n;i++)
        scanf("%f",&freq[i]);

    float cost[n][n];

    for(int i=0;i<n;i++)
        cost[i][i]=freq[i];

    for(int L=2;L<=n;L++)
    {
        for(int i=0;i<=n-L;i++)
        {
            int j=i+L-1;

            cost[i][j]=9999;

            float sum=0;

            for(int k=i;k<=j;k++)
                sum+=freq[k];

            for(int r=i;r<=j;r++)
            {
                float c=sum;

                if(r>i)
                    c+=cost[i][r-1];

                if(r<j)
                    c+=cost[r+1][j];

                if(c<cost[i][j])
                    cost[i][j]=c;
            }
        }
    }

    printf("%.2f\n",cost[0][n-1]);

    return 0;
}