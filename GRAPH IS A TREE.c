GRAPH IS A TREE

/*The first line of the input file contains two integers N and M --- number of nodes and number of edges in the graph (0 < N <= 10000, 0 <= M <= 20000). Next M lines contain M edges of that graph --- Each line contains a pair (u, v) means there is an edge between node u and node v (1 <= u, v <= N).

Output
Print YES if the given graph is a tree, otherwise print NO.*/

#include <stdio.h>
#include <stdbool.h>

#define MAX_NOS 10001
#define MAX_ARESTAS 20001

int pai[MAX_NOS];
bool visitados[MAX_NOS];

// Função para procurar a raiz de um ramo
int procura(int no) {
    if (pai[no] == -1)
        return no;
    return procura(pai[no]);
}

// Funcao para juntar dois ramos, colocando um como o pai do outro
void junta(int a, int b) {
    int raizA = procura(a);
    int raizB = procura(b);
    if (raizA != raizB)
        pai[raizA] = raizB;
}

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    // Inicializa o vetor pai
    for (int i = 1; i <= N; i++) {
        pai[i] = -1;
        visitados[i] = false;
    }

    bool isArvore = true;

    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        if (procura(u) == procura(v)) {
            // Se u e v tem o mesmo pai, forma um ciclo
            isArvore = false;
            break;
        }

        junta(u, v);
    }

    // Verifica se o grafo está conectado
    int raiz = procura(1);
    for (int i = 2; i <= N; i++) {
        if (procura(i) != raiz) {
            isArvore = false;
            break;
        }
    }

    if (isArvore && M == N - 1)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
    // Verifica se o grafo está conectado
    int raiz = procura(1);
    for (int i = 2; i <= N; i++) {
        if (procura(i) != raiz) {
            isArvore = false;
            break;
        }
    }

    if (isArvore && M == N - 1)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}