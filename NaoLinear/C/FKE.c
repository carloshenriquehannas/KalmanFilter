#include <stdio.h>

#include "initialize.h"
#include "FKE.h"

float multiplica_matriz_coluna(float matrizA[ROWS][X_COLUMNS], float matrizB[ROWS][COLUMNS]){
    int i, j, k;
    float resultado[COLUMNS][ROWS];

    //Inicializa a matriz resultado com zeros
    for (i = 0; i < ROWS; i++){                                                                                         //Percorre linhas da matriz
        for (j = 0; j < X_COLUMNS; j++){                                                                                //Percoore colunas da matriz
            resultado[i][j] = 0;                                                                                        //Preenche a matriz com zeros
        }
    }

    //Calcula a multiplicação das matrizes
    for(i = 0; i < ROWS; i++){                                                                                          //Percorre linhas das matrizes
        for(j = 0; j < COLUMNS; j++){                                                                                   //Percorre colunas da matriz B
            for(k = 0; k < X_COLUMNS; k++){                                                                             //Percorre colunas da matriz A
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];                                                       //Armazena o resultado da multiplicacao
            }
        }
    }

    return resultado[ROWS][X_COLUMNS];
}

void extended_kalman(float x[ROWS][X_COLUMNS], float F[ROWS][COLUMNS], float P[ROWS][COLUMNS], float Ft[COLUMNS][ROWS], float Q[ROWS][COLUMNS]){

    x[ROWS][X_COLUMNS] = multiplica_matriz_coluna(x, F);

    //CONTINUAR A PARTIR DA PREDICAO DA COVARIANCIA

}