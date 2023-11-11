#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"

Matriz leMatriz(char* arquivo) {
    Matriz A;
    FILE* file = fopen(arquivo, "r");

    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    
    fscanf(file, "%d %d", &A.m, &A.n);

    
    A.cabeca = NULL;

    
    int i, j;
    double valor;
    while (fscanf(file, "%d %d %lf", &i, &j, &valor) == 3) {
        
        No* novo = (No*)malloc(sizeof(No));
        novo->i = i;
        novo->j = j;
        novo->valor = valor;
        novo->prox = A.cabeca;

        
        A.cabeca = novo;
    }

    fclose(file);
    return A;
}

void imprimeMatriz(Matriz A) {
    for (int i = 0; i < A.m; i++) {
        for (int j = 0; j < A.n; j++) {
            No* atual = A.cabeca;
            while (atual != NULL) {
                if (atual->i == i && atual->j == j) {
                    printf("%.2f\t", atual->valor);
                    break;
                }
                atual = atual->prox;
            }
            if (atual == NULL) {
                printf("0.00\t");
            }
        }
        printf("\n");
    }
}

Matriz somaMatrizes(Matriz A, Matriz B) {
    Matriz C;
    C.m = A.m;
    C.n = A.n;
    C.cabeca = NULL;

    for (int i = 0; i < C.m; i++) {
        for (int j = 0; j < C.n; j++) {
            No* atualA = A.cabeca;
            No* atualB = B.cabeca;
            double soma = 0.0;

            while (atualA != NULL || atualB != NULL) {
                if (atualA != NULL && atualA->i == i && atualA->j == j) {
                    soma += atualA->valor;
                    atualA = atualA->prox;
                }
                if (atualB != NULL && atualB->i == i && atualB->j == j) {
                    soma += atualB->valor;
                    atualB = atualB->prox;
                }
            }

            if (soma != 0.0) {
                No* novo = (No*)malloc(sizeof(No));
                novo->i = i;
                novo->j = j;
                novo->valor = soma;
                novo->prox = C.cabeca;
                C.cabeca = novo;
            }
        }
    }

    return C;
}
