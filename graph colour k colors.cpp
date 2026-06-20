#include <stdio.h>

int graph[10][10] = {
    {0,1,1,1},
    {1,0,1,0},
    {1,1,0,1},
    {1,0,1,0}
};

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

int solve(int v, int n, int k)
{
    if(v == n)
        return 1;

    for(int c = 1; c <= k; c++)
    {
        if(isSafe(v, c, n))
        {
            color[v] = c;

            if(solve(v + 1, n, k))
                return 1;

            color[v] = 0;
        }
    }

    return 0;
}

int main()
{
    int n = 4;
    int k = 3;

    if(solve(0, n, k))
    {
        printf("Solution Exists\n");

        for(int i = 0; i < n; i++)
            printf("Vertex %d -> Color %d\n",
                   i, color[i]);
    }
    else
    {
        printf("No Solution");
    }

    return 0;
}