#include <stdio.h>

#define INF 99999

void floyd(int n,int dist[n][n])
{
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
}

int main()
{
    int n=6;

    int dist[6][6]={
    {0,1,5,INF,INF,INF},
    {1,0,2,1,INF,INF},
    {5,2,0,INF,3,INF},
    {INF,1,INF,0,1,6},
    {INF,INF,3,1,0,2},
    {INF,INF,INF,6,2,0}
    };

    floyd(n,dist);

    printf("A to F Before Failure = %d\n",
           dist[0][5]);

    dist[1][3]=INF;
    dist[3][1]=INF;

    floyd(n,dist);

    printf("A to F After Failure = %d\n",
           dist[0][5]);

    return 0;
}