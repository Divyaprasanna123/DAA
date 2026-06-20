#include <stdio.h>

struct Edge
{
    int u, v, w;
};

int parent[100];

int find(int i)
{
    while(parent[i] != i)
        i = parent[i];

    return i;
}

void unionSet(int a, int b)
{
    parent[a] = b;
}

void sortEdges(struct Edge edges[], int m)
{
    int i, j;
    struct Edge temp;

    for(i = 0; i < m - 1; i++)
    {
        for(j = i + 1; j < m; j++)
        {
            if(edges[i].w > edges[j].w)
            {
                temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }
}

int main()
{
    int n, m;

    scanf("%d%d", &n, &m);

    struct Edge edges[m];

    for(int i = 0; i < m; i++)
    {
        scanf("%d%d%d",
              &edges[i].u,
              &edges[i].v,
              &edges[i].w);
    }

    for(int i = 0; i < n; i++)
        parent[i] = i;

    sortEdges(edges, m);

    int totalWeight = 0;

    printf("Edges in MST:\n");

    for(int i = 0; i < m; i++)
    {
        int a = find(edges[i].u);
        int b = find(edges[i].v);

        if(a != b)
        {
            printf("(%d,%d,%d)\n",
                   edges[i].u,
                   edges[i].v,
                   edges[i].w);

            totalWeight += edges[i].w;

            unionSet(a, b);
        }
    }

    printf("Total weight of MST: %d",
           totalWeight);

    return 0;
}