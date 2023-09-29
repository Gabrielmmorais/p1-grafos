BUGS LIFE


#include <stdio.h>
#include <stdbool.h>

#define MAXIMO_BUGS 2000 //Número máximo de bugs

int grafo[MAXIMO_BUGS][MAXIMO_BUGS]; //Representa o grafo de interações entre os bugs
int cor[MAXIMO_BUGS]; //Representa a cor de cada bug (-1 = não visitado, 0 = cor 1, 1 = cor 2)

bool dfs(int numero_de_bugs, int bug) {
    for (int i = 0; i < numero_de_bugs; i++) { 
        if (grafo[bug][i]) {
            if (cor[i] == -1) {
                cor[i] = 1 - cor[bug]; //Se o bug i não foi visitado, atribui a cor oposta ao bug atual
                if (!dfs(numero_de_bugs, i)) {
                    return false; //Se o grafo não for bipartido, retorna false
                }
            } else if (cor[i] == cor[bug]) {
                return false; //Se o bug i já foi visitado e tem a mesma cor do bug atual, retorna false
            }
        }
    }
    return true; //Se o grafo for bipartido, retorna true
}

int main() {
    int numero_cenarios;
    scanf("%d", &numero_cenarios);

    for (int cenario = 1; cenario <= numero_cenarios; cenario++) { 
        int numero_de_bugs, interacoes;
        scanf("%d %d", &numero_de_bugs, &interacoes); 

        // Inicializa o grafo e as cores
        for (int i = 0; i < numero_de_bugs; i++) {
            cor[i] = -1; //Cor -1 significa que o bug não foi visitado
            for (int j = 0; j < numero_de_bugs; j++) {
                grafo[i][j] = 0; //Grafo 0 significa que não há interação entre os bugs
            }
        }

        // Lê as interações entre os bugs
        for (int i = 0; i < interacoes; i++) {
            int bug1, bug2;
            scanf("%d %d", &bug1, &bug2);
            grafo[bug1 - 1][bug2 - 1] = 1; 
            grafo[bug2 - 1][bug1 - 1] = 1; //Grafo 1 significa que há interação entre os bugs
        }

        bool resultado = true;

        // Verifica se o grafo é bipartido
        for (int i = 0; i < numero_de_bugs; i++) {
            if (cor[i] == -1) {
                cor[i] = 0;
                if (!dfs(numero_de_bugs, i)) {
                    resultado = false; //Se o grafo não for bipartido, o resultado é falso
                    break;
                }
            }
        }

        // Imprime o resultado
        printf("Scenario #%d:\n", cenario);
        if (resultado) {
            printf("No suspicious bugs found!\n");
        } else {
            printf("Suspicious bugs found!\n");
        }
    }

    return 0;
}