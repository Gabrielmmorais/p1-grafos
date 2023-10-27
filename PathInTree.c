//Gabriel Maciel de Morais - 2112082002
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 10001

struct Node {
    int value;
    struct Node *next;
};

int max(int a, int b) {
    return a > b ? a : b;
}
//Gabriel Maciel de Morais - 2112082002
void addEdge(struct Node *adj[], int u, int v) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->value = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}
//Gabriel Maciel de Morais - 2112082002
int dfs(int u, struct Node *adj[], int visited[]) {
    visited[u] = 1;
    struct Node *ptr = adj[u];
    int max_depth1 = 0, max_depth2 = 0;

    while (ptr != NULL) {
        if (!visited[ptr->value]) {
            int depth = dfs(ptr->value, adj, visited) + 1;
            if (depth > max_depth1) {
                max_depth2 = max_depth1;
                max_depth1 = depth;
            } else if (depth > max_depth2) {
                max_depth2 = depth;
            }
        }
        ptr = ptr->next;
    }

    return max_depth1 + max_depth2;
}
//Gabriel Maciel de Morais - 2112082002
int main() {
    int numNodes;
    scanf("%d", &numNodes);

    struct Node *adj[MAX_NODES];
    int i;
    for (i = 1; i <= numNodes; i++) {
        adj[i] = NULL;
    }

    for ( i = 0; i < numNodes - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        addEdge(adj, v, u);
    }

    int *visited = (int *)calloc((numNodes + 1), sizeof(int));
    int ans = dfs(1, adj, visited);

    printf("%d\n", ans);

    free(visited);
    for (i = 1; i <= numNodes; i++) {
        struct Node *ptr = adj[i];
        while (ptr != NULL) {
            struct Node *temp = ptr;
            ptr = ptr->next;
            free(temp);
        }
    }

    return 0;
}
