#include <stdio.h>
#include <stdlib.h>

int graph[100][100];
int color[100];

int isSafe(int node, int c, int n) {
    for (int i = 1; i <= n; i++) {
        if (graph[node][i] && color[i] == c) {
            return 0;
        }
    }
    return 1;
}

void graphColoring(int node, int n, int m) {
    if (node > n) {
        for (int i = 1; i <= n; i++) {
            printf("%d ", color[i]);
        }
        printf("\n");
        return;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(node, c, n)) {
            color[node] = c;
            graphColoring(node + 1, n, m);
            color[node] = 0; // backtrack
        }
    }
}

int main() {
    int n, m;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    printf("Coloring solutions are:\n");
    graphColoring(1, n, m);

    return 0;
}
