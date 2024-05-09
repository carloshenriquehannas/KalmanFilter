#include <stdio.h>
#include <math.h>

#include "initialize.h"
#include "functions.h"
#include "FKE.h"

void jacobiano(float x_res[ROWS][X_COLUMNS]){
    float r_aux, r, phi;
    float H[H_ROWS][H_COLUMNS];                                                                                         //Matriz H de observacao
    float dH[H_ROWS][COLUMNS];                                                                                          //Matriz jacobiana dH (jacobiano de H)
    float dHt[COLUMNS][H_ROWS];                                                                                         //Matriz transposta de dH

    r_aux = pow(x_res[0][0], 2) + pow(x_res[3][0], 2);
    r = sqrt(r_aux);

    phi = atan(x_res[3][0] / x_res[0][0]);

    initialize_H(H, r, phi);                                                                                            //Inicializa a matriz H de observacao
    initialize_dH(dH, x_res, r, r_aux);                                                                                 //Inicializa a matriz dH (jacobiano)
    transpose_H(dH, dHt);                                                                                               //Inicializa a matriz tranposta de dH: dHt

}

void extended_kalman(float x[ROWS][X_COLUMNS], float F[ROWS][COLUMNS], float P[ROWS][COLUMNS], float Ft[COLUMNS][ROWS], float Q[ROWS][COLUMNS]){
    float P_aux[ROWS][COLUMNS];                                                                                         //Matriz auxiliar para predicao
    float x_res[ROWS][X_COLUMNS];                                                                                       //Matriz de resultado para estimativa

    //Predicao da estimativa: x_res = F * x
    multiplica_matriz_coluna(F, x, x_res);

    //Predicao da covariancia: P = F * P * Ft + Q
    multiplica_matriz_quadrada(P, Ft, P_aux);                                                                           //P_aux = P * Ft
    multiplica_matriz_quadrada(F, P_aux, P);                                                                            //P = F * P_aux
    P[ROWS][COLUMNS] = P[ROWS][COLUMNS] + Q[ROWS][COLUMNS];                                                             //P = P + Q

    jacobiano(x_res);

}