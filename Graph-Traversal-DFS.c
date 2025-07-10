#include <stdio.h>
#define SIZE 10
int visited[SIZE];
void dfs(int graph[SIZE][SIZE], int v, int n) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++)
        if (graph[v][i] && !visited[i])
            dfs(graph, i, n);
}
int main() {
    int graph[SIZE][SIZE] = {
        {0,1,1,0},
        {1,0,1,1},
        {1,1,0,1},
        {0,1,1,0}
    };
    dfs(graph, 0, 4);
    return 0;
}
