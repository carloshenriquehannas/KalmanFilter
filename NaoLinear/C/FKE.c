#include <stdio.h>

#include "initialize.h"
#include "FKE.h"

//Funcao para fazer a multiplicacao de matrizes, tendo matrizes quadradas
void multiplica_matriz_quadrada(float matrizA[ROWS][COLUMNS], float matrizB[ROWS][COLUMNS], float resultado[ROWS][COLUMNS]){
    int i,j,k;

    //Calcula a multiplicacao das matrizes
    for(i = 0; i < ROWS; i++){
        for(j = 0; j < COLUMNS; j++){
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

void extended_kalman(float x[ROWS][X_COLUMNS], float F[ROWS][COLUMNS], float P[ROWS][COLUMNS], float Ft[COLUMNS][ROWS], float Q[ROWS][COLUMNS]){
    float P_aux[ROWS][COLUMNS];                                                                                         //Matriz auxiliar para predicao
    float x_res[ROWS][X_COLUMNS];                                                                                       //Matriz de resultado para estimativa

    //Predicao da estimativa: x_res = F * x
    multiplica_matriz_coluna(F, x, x_res);

    //Predicao da covariancia: P = F * P * Ft + Q
    multiplica_matriz_quadrada(P, Ft, P_aux);                                                                           //P_aux = P * Ft
    multiplica_matriz_quadrada(F, P_aux, P);                                                                            //P = F * P_aux
    P[ROWS][COLUMNS] = P[ROWS][COLUMNS] + Q[ROWS][COLUMNS];

    /*for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLUMNS; j++){
            printf("%f\t", P[i][j]);
        }
        printf("\n");
    }*/

}