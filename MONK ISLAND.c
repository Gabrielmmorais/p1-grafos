MONK ISLAND

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    int valor;
    struct no *proximo;
}no;

typedef struct fila{
    no *primeiro;
    no *ultimo;
}fila;

void inicializar(fila *fila){
    fila->primeiro = NULL;
    fila->ultimo = NULL;
}

void enfileirar(fila *fila, int valor){
    no *novo_no = (no*) malloc(sizeof(no));
    novo_no->valor = valor;
    novo_no->proximo = NULL;
    if(fila->primeiro == NULL){
        fila->primeiro = novo_no;
        fila->ultimo = novo_no;
    }else{
        fila->ultimo->proximo = novo_no;
        fila->ultimo = novo_no;
    }
}

int desinfileira(fila *fila){
    if(fila->primeiro == NULL){
        return -1;
    }else{
        no *aux = fila->primeiro;
        int valor = aux->valor;
        fila->primeiro = aux->proximo;
        free(aux);
        return valor;
    }
}

int eh_vazio(fila *fila){
    if(fila->primeiro == NULL){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int casos, 
    vertices, qtdArestas, i, j, x, y, *visitado, *distancia, *matriz_adjacencia; // x e y são as arestas

    fila fila;
    scanf("%d", &casos);
    while(casos--){
        scanf("%d %d", &vertices, &qtdArestas);
        visitado = (int*) malloc(sizeof(int) * vertices);
        distancia = (int*) malloc(sizeof(int) * vertices);
        matriz_adjacencia = (int*) malloc(sizeof(int) * vertices * vertices);
        memset(matriz_adjacencia, 0, sizeof(int) * vertices * vertices);
        memset(visitado, 0, sizeof(int) * vertices);
        memset(distancia, 0, sizeof(int) * vertices);
        for(i = 0; i < qtdArestas; i++){
            scanf("%d %d", &x, &y);
            matriz_adjacencia[x - 1 + (y - 1) * vertices] = 1;
            matriz_adjacencia[y - 1 + (x - 1) * vertices] = 1;
        }
        inicializar(&fila);
        enfileirar(&fila, 0);
        visitado[0] = 1;
        while(!eh_vazio(&fila)){
            x = desinfileira(&fila);
            for(i = 0; i < vertices; i++){
                if(matriz_adjacencia[x + i * vertices] == 1 && visitado[i] == 0){
                    enfileirar(&fila, i);
                    visitado[i] = 1;
                    distancia[i] = distancia[x] + 1;
                }
            }
        }
        printf("%d\n", distancia[vertices - 1]);
    }
    return 0;
}