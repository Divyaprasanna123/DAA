#include <stdio.h>

#define N 5

int minCost = 999999;

void tsp(int graph[N][N], int visited[],
         int currPos, int count, int cost) {

    if(count == N) {
        cost += graph[currPos][0];

        if(cost < minCost)
            minCost = cost;

        return;
    }

    for(int i = 0; i < N; i++) {

        if(!visited[i] && graph[currPos][i] != 0) {

            visited[i] = 1;

            tsp(graph, visited, i,
                count + 1,
                cost + graph[currPos][i]);

            visited[i] = 0;
        }
    }
}

int main() {

    int graph[N][N] = {
        {0,10,15,20,25},
        {10,0,35,25,30},
        {15,35,0,30,20},
        {20,25,30,0,15},
        {25,30,20,15,0}
    };

    int visited[N] = {0};

    visited[0] = 1;

    tsp(graph, visited, 0, 1, 0);

    printf("Minimum Distance = %d\n", minCost);

    return 0;
}