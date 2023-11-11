#include <stdio.h>
#include "matriz.h"

int main() {
    
    Matriz A = leMatriz("matriz_A.txt");
    Matriz B = leMatriz("matriz_B.txt");

    printf("Matriz A:\n");
    imprimeMatriz(A);

    printf("\nMatriz B:\n");
    imprimeMatriz(B);

    Matriz C = somaMatrizes(A, B);

    printf("\nSoma das matrizes A e B:\n");
    imprimeMatriz(C);

    return 0;
}
