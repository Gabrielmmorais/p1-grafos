ARVORE

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 10000
#define MAX_EDGES 20000

int graph[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];
int N, M;

void dfs(int node) {
    visited[node] = true;
    for (int i = 1; i <= N; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(i);
        }
    }
}

bool isTree() {
    // Check if the graph has exactly N-1 edges
    int edgeCount = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (graph[i][j]) {
                edgeCount++;
            }
        }
    }
    
    if (edgeCount != N - 1) {
        return false;
    }
    
    // Check if the graph is connected using DFS
    dfs(1);
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1; // Since the graph is undirected
    }
    
    if (isTree()) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    
    return 0;
}