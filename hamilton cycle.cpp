#include <stdio.h>

int graph[5][5] = {
    {0,1,1,1,1},
    {1,0,1,0,0},
    {1,1,0,1,1},
    {1,0,1,0,0},
    {1,0,1,0,0}
};

int path[5];

int isSafe(int v, int pos)
{
    if(graph[path[pos-1]][v] == 0)
        return 0;

    for(int i = 0; i < pos; i++)
        if(path[i] == v)
            return 0;

    return 1;
}

int hamCycle(int pos)
{
    if(pos == 5)
        return graph[path[pos-1]][path[0]];

    for(int v = 1; v < 5; v++)
    {
        if(isSafe(v, pos))
        {
            path[pos] = v;

            if(hamCycle(pos + 1))
                return 1;

            path[pos] = -1;
        }
    }
    return 0;
}

int main()
{
    path[0] = 0;

    for(int i = 1; i < 5; i++)
        path[i] = -1;

    if(hamCycle(1))
    {
        printf("Hamiltonian Cycle Exists\n");
        for(int i = 0; i < 5; i++)
            printf("%d ", path[i]);

        printf("%d", path[0]);
    }
    else
    {
        printf("No Hamiltonian Cycle");
    }

    return 0;
}