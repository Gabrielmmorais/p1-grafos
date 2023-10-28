//Gabriel Maciel de Morais - 2112082002
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10001

typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node *adj[MAX_NODES];
int visited[MAX_NODES];
int maxDepth1, maxDepth2;

void addEdge(int u, int v) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->value = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void dfs(int node, int depth) {
    visited[node] = 1;
    if (depth > maxDepth1) {
        maxDepth1 = depth;
        maxDepth2 = node;
    }
    for (Node *neighbor = adj[node]; neighbor != NULL; neighbor = neighbor->next) {
        if (!visited[neighbor->value]) {
            dfs(neighbor->value, depth + 1);
        }
    }
}

int main() {
    int numNodes;
    scanf("%d", &numNodes);

    for (int i = 1; i <= numNodes; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    for (int i = 0; i < numNodes - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }

    maxDepth1 = -1;
    dfs(1, 0);

    for (int i = 1; i <= numNodes; i++)
        visited[i] = 0;

    maxDepth1 = -1;
    dfs(maxDepth2, 0);

    printf("%d\n", maxDepth1);

    return 0;
}