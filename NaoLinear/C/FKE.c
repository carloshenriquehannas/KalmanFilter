#include <stdio.h>
#include <math.h>

#include "initialize.h"
#include "functions.h"
#include "FKE.h"

//Funcao para atualizar a estimativa do estado: x = x + K*(z - H)
void estimate_state(float z[Z_ROWS][Z_COLUMNS], float H[H_ROWS][H_COLUMNS], float K[ROWS][dHt_COLUMNS], float x_res[ROWS][X_COLUMNS], float estimate_x[ROWS][X_COLUMNS]){
    int i;
    float aux[Z_ROWS][Z_COLUMNS];                                                                                       //Matriz auxiliar
    float aux_res[ROWS][Z_COLUMNS];                                                                                     //Matriz auxiliar

    //aux = z - H
    for(i = 0; i < Z_ROWS; i++){
        aux[i][0] = z[i][0] - H[i][0];
    }

    multiplica_matriz_auxiliar06(K, aux, aux_res);                                                                      //aux_res = K * aux

    //estimate_x = x_res + aux_res
    for(i = 0; i < ROWS; i++){
        estimate_x[i][0] = x_res[i][0] + aux_res[i][0];
    }

}

//Funcao para atualizar a estimativa da predicao
void estimate_predict(float R[R_ROWS][R_COLUMNS], float K[ROWS][dHt_COLUMNS], float Kt[dHt_COLUMNS][ROWS]){
    float aux01[R_ROWS][ROWS];                                                                                          //Matriz auxiliar
    float aux02[ROWS][ROWS];
    //float aux03[][] = I - K*dH

    multiplica_matriz_auxiliar07(R, Kt, aux01);                                                                         //aux01 = R * Kt
    multiplica_matriz_auxiliar08(K, aux01, aux02);                                                                      //aux02 = K * aux01
    //aux03t = transpose(aux03)
    //aux04 =  P * aux03t
    //estimate_P = aux03 * aux04
    //estimate_P = estimate_P + aux02

    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < ROWS; j++){
            printf("%f\t", aux02[i][j]);
        }
        printf("\n");
    }
}


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
    float estimate_x[ROWS][X_COLUMNS];                                                                                  //Matriz de estimativa final de estado
    float x_res[ROWS][X_COLUMNS];                                                                                       //Matriz auxiliar para estado
    float z[Z_ROWS][Z_COLUMNS];                                                                                         //Matriz z de medicoes
    float H[H_ROWS][H_COLUMNS];                                                                                         //Matriz H de observacao
    float dH[H_ROWS][COLUMNS];                                                                                          //Matriz jacobiana dH (jacobiano de H)
    float dHt[COLUMNS][H_ROWS];                                                                                         //Matriz transposta de dH
    float inov[H_ROWS][dHt_COLUMNS];                                                                                    //Matriz auxiliar pra calcular ganho
    float inov_res[H_ROWS][dHt_COLUMNS];
    float inov_aux[ROWS][dHt_COLUMNS];
    float K[ROWS][dHt_COLUMNS];                                                                                         //Matriz K do ganho de Kalman
    float Kt[dHt_COLUMNS][ROWS];                                                                                        //Matriz transposta de K
    float K_aux[COLUMNS][dHt_COLUMNS];                                                                                  //Matriz auxiliar para calcular ganho

    //Predicao da estimativa: x_res = F * x
    multiplica_matriz_auxiliar02(F, x, x_res);

    //Predicao da covariancia: P_res = F * P * Ft + Q
    multiplica_matriz_auxiliar01(P, Ft, P_aux);                                                                         //P_aux = P * Ft
    multiplica_matriz_auxiliar01(F, P_aux, P);                                                                          //P = F * P_aux
    soma_matriz_quadrada_6x6(P, Q, P_res);                                                                              //P_res = P + Q

    jacobiano(x_res, H, dH, dHt);                                                                                       //Calculo do jacobiano

    //Atualizacao do ganho de Kalman: K = P*dHt*(dH*P*dHt + R)^(-1);
    multiplica_matriz_auxiliar03(P, dHt, inov_aux);                                                                     //inov_aux = P * dHt
    multiplica_matriz_auxiliar04(dH, inov_aux, inov);                                                                   //inov = dH * inov_aux
    soma_matriz_quadrada_2x2(inov, R, inov_res);                                                                        //inov_res = inov + R
    inversa_matriz_2x2(inov_res);                                                                                       //inov_res = (inov_res)^(-1)
    multiplica_matriz_auxiliar05(dHt, inov_res, K_aux);                                                                 //K_aux = dHt * inov_res
    multiplica_matriz_auxiliar03(P, K_aux, K);                                                                          //K = P * K_aux

    transpose_matriz_6x2(K, Kt);                                                                                        //Matriz Kt (transposta de K)

    /*INICIALIZAR A MATRIZ Z COM DADO*/
    z[0][0] = 501.1395;
    z[1][0] = -0.9379;

    //Atualizacao das estimativas de estado e covariancia
    estimate_state(z, H, K, x_res, estimate_x);                                                                         //Atualizacao da estados: x = x + K*(z - H)
    estimate_predict(R, K, Kt);


}