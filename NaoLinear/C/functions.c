#include <stdio.h>
#include <math.h>

#include "initialize.h"
#include "functions.h"

//Funcao para somar matrizes. Matrizes 6x6
void soma_matriz_quadrada_6x6(float matrizA[ROWS][COLUMNS], float matrizB[ROWS][COLUMNS], float resultado[ROWS][COLUMNS]){
    int i, j, k;

    //Calcula a soma das matrizes
    for(i = 0; i < ROWS; i++){                                                                                          //Percorre linhas da matriz A
        for(j = 0; j < COLUMNS; j++){                                                                                   //Percorre colunas da matriz B
            resultado[i][j] = 0;                                                                                        //Inicializa elemento da matriz resultado com zero, para nao ter lixo
            resultado[i][j] = matrizA[i][j] + matrizB[i][j];                                                            //Armazena o elemento da soma na matriz resultado
        }
    }

}

//Funcao para somar matrizes. Matrizes 2x2
void soma_matriz_quadrada_2x2(float matrizA[H_ROWS][dHt_COLUMNS], float matrizB[H_ROWS][dHt_COLUMNS], float resultado[H_ROWS][dHt_COLUMNS]){
    int i, j, k;

    //Calcula a soma das matrizes
    for(i = 0; i < H_ROWS; i++){                                                                                        //Percorre linhas da matriz A
        for(j = 0; j < dHt_COLUMNS; j++){                                                                               //Percorre colunas da matriz B
            resultado[i][j] = 0;                                                                                        //Inicializa elemento da matriz resultado com zero, para nao ter lixo
            resultado[i][j] = matrizA[i][j] + matrizB[i][j];                                                            //Armazena o elemento da soma na matriz resultado
        }
    }

}

//Funcao para fazer a multiplicacao de matrizes, tendo matrizes quadradas 6x6
void multiplica_matriz_quadrada_6x6(float matrizA[ROWS][COLUMNS], float matrizB[ROWS][COLUMNS], float resultado[ROWS][COLUMNS]){
    int i,j,k;

    //Calcula a multiplicacao das matrizes
    for(i = 0; i < ROWS; i++){                                                                                          //Percorre linhas da matriz A
        for(j = 0; j < COLUMNS; j++){                                                                                   //Percorre colunas da matriz B
            resultado[i][j] = 0;                                                                                        //Inicializa elemento da matriz resultado com zero
            for(k = 0; k < COLUMNS; k++){                                                                               //Percorre colunas da matriz A
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];                                                       //Armazena o elemento da multiplicacao na matriz resultado
            }
        }
    }

}

//Funcao para fazer a multiplicacao de matrizes, tendo uma matrizes 6x6 e 6x1
void multiplica_matriz_coluna(float matrizA[ROWS][COLUMNS], float matrizB[ROWS][X_COLUMNS], float resultado[ROWS][X_COLUMNS]){
    int i, j, k;

    //Calcula a multiplicacao das matrizes
    for(i = 0; i < ROWS; i++){                                                                                          //Percorre linhas da matriz A
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
    for(i = 0; i < ROWS; i++){                                                                                          //Percorre linhas da matriz A
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
    for(i = 0; i < H_ROWS; i++){                                                                                        //Percorre linhas da matriz A
        for(j = 0; j < H_ROWS; j++){                                                                                    //Percorre colunas da matriz B
            resultado[i][j] = 0;                                                                                        //Inicializa elemento da matriz resultado com zero, para nao ter lixo
            for(k = 0; k < COLUMNS; k++){                                                                               //Percorre colunas da matriz A
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];                                                       //Armazena o elemento da multiplicacao na matriz resultado
            }
        }
    }

}

//Funcao para fazer a multiplicacao de matrizes, tendo matrizes 6x2 e 2x2
void multiplica_matriz_auxiliar03(float matrizA[COLUMNS][H_ROWS], float matrizB[H_ROWS][dHt_COLUMNS], float resultado[COLUMNS][dHt_COLUMNS]){
    int i, j, k;

    //Calcula a multiplicacao das matrizes
    for(i = 0; i < COLUMNS; i++){                                                                                       //Percorre linhas da matriz A
        for(j = 0; j < dHt_COLUMNS; j++){                                                                               //Percorre colunas da matriz B
            resultado[i][j] = 0;                                                                                        //Inicializa elemento da matriz resultado com zero, para nao ter lixo
            for(k = 0; k < H_ROWS; k++){                                                                                //Percorre colunas da matriz A
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];                                                       //Armazena o elemento da multiplicacao na matriz resultado
            }
        }
    }

}

//Realiza a transposicao de matriz quadrada 6x6
void transpose_matriz_6x6(float principal[ROWS][COLUMNS], float transposta[COLUMNS][ROWS]){
    int i, j;

    for(i = 0; i < ROWS; i++){                                                                                          //Percorre linhas da matriz
        for(j = 0; j < COLUMNS; j++){                                                                                   //Percorre colunas da matriz
            transposta[j][i] = principal[i][j];                                                                         //Transpoe linha por coluna
        }
    }

}

//Realiza a transposicao de matriz quadrada 6x2
void transpose_matriz_6x2(float principal[ROWS][dHt_COLUMNS], float transposta[dHt_COLUMNS][ROWS]){
    int i, j;

    for(i = 0; i < ROWS; i++){                                                                                          //Percorre linhas da matriz
        for(j = 0; j < dHt_COLUMNS; j++){                                                                               //Percorre colunas da matriz
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

//Realiza inversao de matriz 2x2
void inversa_matriz_2x2(float inversa[H_ROWS][dHt_COLUMNS]){
    float det, inv_det, aux;

    det = inversa[0][0] * inversa[1][1] - inversa[0][1] * inversa[1][0];                                                //Calculo do determinante da matriz inicial
    inv_det = 1 / det;                                                                                                  //Inverso do determinante

    aux = inversa[0][0];                                                                                                //Armazena o valor da primeira posicao

    //Calcula, valor por valor, da matriz inversa 2x2
    inversa[0][0] = inv_det * inversa[1][1];
    inversa[0][1] = inv_det * inversa[0][1] * (-1);
    inversa[1][0] = inv_det * inversa[1][0] * (-1);
    inversa[1][1] = inv_det * aux;

}
