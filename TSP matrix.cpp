#include <stdio.h>
#define V 4
int minCost = 999999;
void tsp(int graph[V][V], int visited[], int currPos,
         int count, int cost) {
    if (count == V) {
        cost += graph[currPos][0]; 
        if (cost < minCost)
            minCost = cost;
        return;
    }
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            tsp(graph, visited, i,
                count + 1,
                cost + graph[currPos][i]);
            visited[i] = 0;
        }
    }
}
int main() {
    int graph[V][V];
    printf("Enter 4x4 cost matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    int visited[V] = {0};
    visited[0] = 1; 
    tsp(graph, visited, 0, 1, 0);
    printf("Minimum Path Distance = %d\n", minCost);
    return 0;
}