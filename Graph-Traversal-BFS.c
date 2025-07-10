#include <stdio.h>
#define SIZE 10
int queue[SIZE], front = 0, rear = -1;
int visited[SIZE];
void enqueue(int v) {
    queue[++rear] = v;
}
int dequeue() {
    return queue[front++];
}
void bfs(int graph[SIZE][SIZE], int start, int n) {
    enqueue(start);
    visited[start] = 1;
    while (front <= rear) {
        int v = dequeue();
        printf("%d ", v);
        for (int i = 0; i < n; i++) {
            if (graph[v][i] && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}
int main() {
    int graph[SIZE][SIZE] = {
        {0,1,1,0},
        {1,0,1,1},
        {1,1,0,1},
        {0,1,1,0}
    };
    bfs(graph, 0, 4);
    return 0;
}
