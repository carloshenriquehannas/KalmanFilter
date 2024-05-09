#include <stdio.h>

#include "initialize.h"
#include "functions.h"
#include "FKE.h"

int main() {
    float sigma_acel = 0.2;                                                                                             //Constante de desvio da aceleracao
    float sigma_medicao_posicao = 5;                                                                                    //Desvio da medicao de posicao
    float sigma_medicao_angulo = 0.0087;                                                                                //Desvio da medicao do angulo
    float delta_tempo = 1;                                                                                              //Variacao do tempo

    float x[ROWS][X_COLUMNS];                                                                                           //Matriz x de estimativas
    initialize_x(x);                                                                                                    //Inicializa a matriz x com os valores

    float F[ROWS][COLUMNS];                                                                                             //Matriz F de transicao de estados
    float Ft[COLUMNS][ROWS];                                                                                            //Matriz transposta de F
    initialize_F(F, delta_tempo);                                                                                       //Inicializa a matriz F com os valores
    transpose_quadrada(F, Ft);                                                                                          //Inicializa a matriz Ft (transposta de F)

    float P[ROWS][COLUMNS];                                                                                             //Matriz P de covariancia
    initialize_P(P);                                                                                                    //Inicializa a matriz P com os valores

    float Q[ROWS][COLUMNS];                                                                                             //Matriz Q de ruido da covariancia
    initialize_Q(Q, delta_tempo, sigma_acel);                                                                           //Inicializa a matriz Q com os valores

    float R[R_ROWS][R_COLUMNS];                                                                                         //Matriz R de ruido da covariancia medida
    initialize_R(R, sigma_medicao_posicao, sigma_medicao_angulo);                                                       //Inicializa a matriz R com os valores

    float I[ROWS][COLUMNS];                                                                                             //Matriz I identidade
    initialize_I(I);                                                                                                    //Inicializa a matriz I com os valores

    extended_kalman(x, F, P, Ft, Q, R);                                                                                    //Algoritmo de Kalman

    return 0;
}
