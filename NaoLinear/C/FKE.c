#include <stdio.h>
#include <math.h>

#include "initialize.h"
#include "functions.h"
#include "FKE.h"

//Funcao para calcular o jacobiano de H
void jacobiano(float x_res[ROWS][X_COLUMNS], float H[H_ROWS][H_COLUMNS], float dH[H_ROWS][COLUMNS], float dHt[COLUMNS][H_ROWS]){
    float r_aux, r, phi;

    r_aux = pow(x_res[0][0], 2) + pow(x_res[3][0], 2);
    r = sqrt(r_aux);

    phi = atan(x_res[3][0] / x_res[0][0]);

    initialize_H(H, r, phi);                                                                                            //Inicializa a matriz H de observacao
    initialize_dH(dH, x_res, r, r_aux);                                                                                 //Inicializa a matriz dH (jacobiano)
    transpose_H(dH, dHt);                                                                                               //Inicializa a matriz tranposta de dH: dHt

}

//Funcao do algoritmo de Kalman
void extended_kalman(float x[ROWS][X_COLUMNS], float F[ROWS][COLUMNS], float P[ROWS][COLUMNS], float Ft[COLUMNS][ROWS], float Q[ROWS][COLUMNS], float R[R_ROWS][R_COLUMNS]){
    float P_res[ROWS][COLUMNS];                                                                                         //Matriz de resultada para predicao
    float P_aux[ROWS][COLUMNS];                                                                                         //Matriz auxiliar para predicao
    float x_res[ROWS][X_COLUMNS];                                                                                       //Matriz de resultado para estimativa
    float H[H_ROWS][H_COLUMNS];                                                                                         //Matriz H de observacao
    float dH[H_ROWS][COLUMNS];                                                                                          //Matriz jacobiana dH (jacobiano de H)
    float dHt[COLUMNS][H_ROWS];                                                                                         //Matriz transposta de dH
    float inov[H_ROWS][dHt_COLUMNS];                                                                                    //Matriz auxiliar pra calcular ganho
    float inov_res[H_ROWS][dHt_COLUMNS];
    float inov_aux[ROWS][dHt_COLUMNS];

    //Predicao da estimativa: x_res = F * x
    multiplica_matriz_coluna(F, x, x_res);

    //Predicao da covariancia: P_res = F * P * Ft + Q
    multiplica_matriz_quadrada(P, Ft, P_aux);                                                                           //P_aux = P * Ft
    multiplica_matriz_quadrada(F, P_aux, P);                                                                            //P = F * P_aux
    soma_matriz_quadrada01(P, Q, P_res);                                                                                //P_res = P + Q

    jacobiano(x_res, H, dH, dHt);                                                                                       //Calculo do jacobiano

    //Atualizacao do ganho de Kalman: K = P*dHt*(dH*P*dHt + R)^(-1);
    multiplica_matriz_auxiliar01(P, dHt, inov_aux);                                                                     //inov_aux = P * dHt
    multiplica_matriz_auxiliar02(dH, inov_aux, inov);                                                                   //inov = dH * inov_aux
    soma_matriz_quadrada02(inov, R, inov_res);                                                                          //inov_res = inov + R

    //FAZER inov_res^(-1)

}