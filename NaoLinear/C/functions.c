#include <stdio.h>
#include <math.h>

#include "initialize.h"
#include "functions.h"

//Funcao para somar matrizes. Matrizes 6x6
void soma_matriz_quadrada01(float matrizA[ROWS][COLUMNS], float matrizB[ROWS][COLUMNS], float resultado[ROWS][COLUMNS]){
    int i, j, k;

    //Calcula a soma das matrizes
    for(i = 0; i < ROWS; i++){                                                                                          //Percorre linhas das matrizes
        for(j = 0; j < COLUMNS; j++){                                                                                   //Percorre colunas da matriz B
            resultado[i][j] = 0;                                                                                        //Inicializa elemento da matriz resultado com zero, para nao ter lixo
            resultado[i][j] = matrizA[i][j] + matrizB[i][j];                                                            //Armazena o elemento da soma na matriz resultado
        }
    }

}

//Funcao para somar matrizes. Matrizes 2x2
void soma_matriz_quadrada02(float matrizA[H_ROWS][dHt_COLUMNS], float matrizB[H_ROWS][dHt_COLUMNS], float resultado[H_ROWS][dHt_COLUMNS]){
    int i, j, k;

    //Calcula a soma das matrizes
    for(i = 0; i < H_ROWS; i++){                                                                                        //Percorre linhas das matrizes
        for(j = 0; j < dHt_COLUMNS; j++){                                                                               //Percorre colunas da matriz B
            resultado[i][j] = 0;                                                                                        //Inicializa elemento da matriz resultado com zero, para nao ter lixo
            resultado[i][j] = matrizA[i][j] + matrizB[i][j];                                                            //Armazena o elemento da soma na matriz resultado
        }
    }

}

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
            resultado[i][j] = 0;                                                                                        //Inicializa elemento da matriz resultado com zero, para nao ter lixo
            for(k = 0; k < COLUMNS; k++){                                                                               //Percorre colunas da matriz A
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];                                                       //Armazena o elemento da multiplicacao na matriz resultado
            }
        }
    }

}

//Funcao para fazer a multiplicacao de matrizes, tendo matrizes 6x6 e 6x2
void multiplica_matriz_auxiliar01(float matrizA[ROWS][COLUMNS], float matrizB[COLUMNS][H_ROWS], float resultado[ROWS][H_ROWS]){
    int i, j, k;

    //Calcula a multiplicacao das matrizes
    for(i = 0; i < ROWS; i++){                                                                                          //Percorre linhas das matrizes
        for(j = 0; j < H_ROWS; j++){                                                                                    //Percorre colunas da matriz B
            resultado[i][j] = 0;                                                                                        //Inicializa elemento da matriz resultado com zero, para noa ter lixo
            for(k = 0; k < COLUMNS; k++){                                                                               //Percorre colunas da matriz A
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];                                                       //Armazena o elemento da multiplicacao na matriz resultado
            }
        }
    }

}

//Funcao para fazer a multiplicacao de matrizes, tendo matrizes 2x6 e 6x2
void multiplica_matriz_auxiliar02(float matrizA[H_ROWS][COLUMNS], float matrizB[ROWS][H_ROWS], float resultado[H_ROWS][H_ROWS]){
    int i, j, k;

    //Calcula a multiplicacao das matrizes
    for(i = 0; i < H_ROWS; i++){                                                                                          //Percorre linhas das matrizes
        for(j = 0; j < H_ROWS; j++){                                                                                    //Percorre colunas da matriz B
            resultado[i][j] = 0;                                                                                        //Inicializa elemento da matriz resultado com zero, para nao ter lixo
            for(k = 0; k < COLUMNS; k++){                                                                               //Percorre colunas da matriz A
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];                                                       //Armazena o elemento da multiplicacao na matriz resultado
            }
        }
    }

}

//Realiza a transposicao de matriz quadrada 6x6
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
