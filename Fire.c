#include <stdio.h>
#include <stdlib.h>

#define MOD 1000000007
// Arrays com tamanhos pré-definidos
int parent[100001];
long long sizes[100001];

int find(int u) {
    if (u != parent[u])
        parent[u] = find(parent[u]);
    return parent[u];
}

void mergeSets(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (sizes[u] < sizes[v]) {
            int temp = u;
            u = v;
            v = temp;
        }
        parent[v] = u;
        sizes[u] += sizes[v];
    }
}

int main() { // 2322082012 - THIAGO MOREIRA SCHULZ
    int numTestCases;
    scanf("%d", &numTestCases);

    while (numTestCases--) {
        int numNodes, numEdges;
        scanf("%d %d", &numNodes, &numEdges);

        for (int i = 1; i <= numNodes; i++) {
            parent[i] = i;
            sizes[i] = 1;
        }

        for (int i = 0; i < numEdges; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            mergeSets(u, v);
        }

        int maxRoutes = 0;
        long long captains = 1;

        for (int i = 1; i <= numNodes; i++) {
            if (parent[i] == i) {
                maxRoutes++;
                captains = (captains * sizes[i]) % MOD;
            }
        }

        printf("%d %lld\n", maxRoutes, captains);
    }

    return 0;
}
