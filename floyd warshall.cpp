#include <stdio.h>

#define INF 99999

int main()
{
    int n,m;

    scanf("%d%d",&n,&m);

    int dist[n][n];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                dist[i][j]=0;
            else
                dist[i][j]=INF;
        }
    }

    for(int i=0;i<m;i++)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);

        dist[u][v]=w;
        dist[v][u]=w;
    }

    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(dist[i][k]+dist[k][j]
                   < dist[i][j])
                {
                    dist[i][j]=dist[i][k]
                              + dist[k][j];
                }
            }
        }
    }

    printf("Distance Matrix:\n");

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",dist[i][j]);

        printf("\n");
    }

    return 0;
}