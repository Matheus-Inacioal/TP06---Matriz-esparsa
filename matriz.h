#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int i, j;      
    double valor;  
    struct No* prox; 
} No;


typedef struct {
    int m, n;      
    No* cabeca;     
} Matriz;


Matriz leMatriz(char* arquivo);
void imprimeMatriz(Matriz A);
Matriz somaMatrizes(Matriz A, Matriz B);
