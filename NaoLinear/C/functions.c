#include <stdio.h>
#include <math.h>

#include "initialize.h"
#include "functions.h"

//Funcao para fazer a multiplicacao de matrizes, tendo matrizes quadradas
void multiplica_matriz_quadrada(float matrizA[ROWS][COLUMNS], float matrizB[ROWS][COLUMNS], float resultado[ROWS][COLUMNS]){
    int i,j,k;

    //Calcula a multiplicacao das matrizes
    for(i = 0; i < ROWS; i++){                                                                                          //Percorre linhas das matrizes
        for(j = 0; j < COLUMNS; j++){                                                                                   //Percorre colunas da matriz B
            resultado[i][j] = 0;                                                                                        //Inicializa elemento da matriz resultado com zero
            for(k = 0; k < COLUMNS; k++){                                                                               //Percorre colunas da matriz A
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];                                                       //Armazena o elemento da multiplicacao na matriz resultado
            }
        }
    }

}

//Funcao para fazer a multiplicacao de matrizes, tendo uma matriz coluna
void multiplica_matriz_coluna(float matrizA[ROWS][COLUMNS], float matrizB[ROWS][X_COLUMNS], float resultado[ROWS][X_COLUMNS]){
    int i, j, k;

    //Calcula a multiplicacao das matrizes
    for(i = 0; i < ROWS; i++){                                                                                          //Percorre linhas das matrizes
        for(j = 0; j < X_COLUMNS; j++){                                                                                 //Percorre colunas da matriz B
            resultado[i][j] = 0;                                                                                        //Inicializa elemento da matriz resultado com zero
            for(k = 0; k < COLUMNS; k++){                                                                               //Percorre colunas da matriz A
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];                                                       //Armazena o elemento da multiplicacao na matriz resultado
            }
        }
    }
}

//Realiza a transposicao de matriz
void transpose_quadrada(float principal[ROWS][COLUMNS], float transposta[COLUMNS][ROWS]){
    int i, j;

    for(i = 0; i < ROWS; i++){                                                                                          //Percorre linhas da matriz
        for(j = 0; j < COLUMNS; j++){                                                                                   //Percorre colunas da matriz
            transposta[j][i] = principal[i][j];                                                                         //Transpoe linha por coluna
        }
    }
}

//Realiza a transposicao da matriz H
void transpose_H(float principal[H_ROWS][COLUMNS], float transposta[COLUMNS][H_ROWS]){
    int i, j;

    for(i = 0; i < H_ROWS; i++){                                                                                        //Percorre linhas da matriz
        for(j = 0; j < COLUMNS; j++){                                                                                   //Percorre colunas da matriz
            transposta[j][i] = principal[i][j];                                                                         //Transpoe linha por coluna
        }
    }
}
