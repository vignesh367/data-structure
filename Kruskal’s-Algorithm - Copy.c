#include <stdio.h>
#include <stdlib.h>
#define V 5
struct Edge {
    int src, dest, weight;
};
int parent[V];
int find(int i) {
    while (i != parent[i])
        i = parent[i];
    return i;
}
void unionSets(int x, int y) {
    int xset = find(x);
    int yset = find(y);
    parent[xset] = yset;
}
int cmp(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}
void kruskal(struct Edge edges[], int E) {
    for (int i = 0; i < V; i++)
        parent[i] = i;
    qsort(edges, E, sizeof(edges[0]), cmp);
    int i = 0, e = 0;
    while (e < V - 1 && i < E) {
        struct Edge next = edges[i++];
        int x = find(next.src);
        int y = find(next.dest);
        if (x != y) {
            printf("%d - %d\n", next.src, next.dest);
            unionSets(x, y);
            e++;
        }
    }
}
int main() {
    struct Edge edges[] = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5},
        {1, 3, 15}, {2, 3, 4}
    };
    int E = sizeof(edges) / sizeof(edges[0]);
    kruskal(edges, E);
    return 0;
}
