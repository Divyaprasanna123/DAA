#include <stdio.h>

int graph[10][10];
int color[10];

int isSafe(int v, int c, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(graph[v][i] && color[i] == c)
            return 0;
    }
    return 1;
}

int main()
{
    int n = 4;

    graph[0][1] = graph[1][0] = 1;
    graph[1][2] = graph[2][1] = 1;
    graph[2][3] = graph[3][2] = 1;
    graph[3][0] = graph[0][3] = 1;
    graph[0][2] = graph[2][0] = 1;

    int maxColor = 0;

    for(int v = 0; v < n; v++)
    {
        int c;

        for(c = 1; c <= n; c++)
        {
            if(isSafe(v, c, n))
            {
                color[v] = c;
                break;
            }
        }

        if(c > maxColor)
            maxColor = c;
    }

    printf("Minimum Colors Required = %d\n", maxColor);

    for(int i = 0; i < n; i++)
        printf("Vertex %d -> Color %d\n", i, color[i]);

    return 0;
}