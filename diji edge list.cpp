#include <stdio.h>

#define INF 99999

int main()
{
    int n, m;

    scanf("%d%d", &n, &m);

    int graph[n][n];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            graph[i][j] = INF;

    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w;
    }

    int source, target;
    scanf("%d%d", &source, &target);

    int dist[n], visited[n];

    for(int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    for(int i = 0; i < n - 1; i++)
    {
        int min = INF, u = -1;

        for(int j = 0; j < n; j++)
        {
            if(!visited[j] && dist[j] < min)
            {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for(int v = 0; v < n; v++)
        {
            if(graph[u][v] != INF &&
               dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("%d", dist[target]);

    return 0;
}