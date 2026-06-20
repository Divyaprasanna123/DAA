#include <stdio.h>

#define INF 99999

int main()
{
    int n,m;

    scanf("%d%d",&n,&m);

    int graph[n+1][n+1];

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            graph[i][j]=INF;
        }
    }

    for(int i=0;i<m;i++)
    {
        int u,v,w;

        scanf("%d%d%d",&u,&v,&w);

        graph[u][v]=w;
    }

    int k;

    scanf("%d",&k);

    int dist[n+1];
    int visited[n+1];

    for(int i=1;i<=n;i++)
    {
        dist[i]=INF;
        visited[i]=0;
    }

    dist[k]=0;

    for(int count=1;count<=n;count++)
    {
        int u=-1,min=INF;

        for(int i=1;i<=n;i++)
        {
            if(!visited[i] &&
               dist[i]<min)
            {
                min=dist[i];
                u=i;
            }
        }

        if(u==-1)
            break;

        visited[u]=1;

        for(int v=1;v<=n;v++)
        {
            if(graph[u][v]!=INF &&
               dist[u]+graph[u][v]
               < dist[v])
            {
                dist[v]=dist[u]
                       + graph[u][v];
            }
        }
    }

    int ans=0;

    for(int i=1;i<=n;i++)
    {
        if(dist[i]==INF)
        {
            printf("-1");
            return 0;
        }

        if(dist[i]>ans)
            ans=dist[i];
    }

    printf("%d",ans);

    return 0;
}