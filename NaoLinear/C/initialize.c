#include <math.h>

#include "initialize.h"

//Inicializa a matriz x
void initialize_x(float x[ROWS][X_COLUMNS]){
    int i, j;

    for(i = 0; i < ROWS; i++){                                                                                          //Percorre linhas da matriz
        for(j = 0; j < X_COLUMNS; j++){                                                                                 //Percorre colunas da matriz
            x[i][j] = 0;                                                                                                //Preenche matriz com zeros
        }
    }

    x[0][0] = 400;                                                                                                      //Posicao x inicial
    x[0][3] = -300;                                                                                                     //Posicao y inicial

}

//Inicializa a matriz F
void initialize_F(float F[ROWS][COLUMNS], float delta_tempo){
    int i, j;

    for(i = 0; i < ROWS; i++){                                                                                          //Percorre linhas da matriz
        for(j = 0; j < COLUMNS; j++){                                                                                   //Percorre colunas da matriz
            F[i][j] = 0;                                                                                                //Preenche matriz com zeros
            if(i == j){
                F[i][j] = 1;                                                                                            //Preenche diagonal principal com 1
            }
        }
    }

    F[0][1] = delta_tempo;
    F[1][2] = delta_tempo;
    F[3][4] = delta_tempo;
    F[4][5] = delta_tempo;
    F[0][2] = (pow(delta_tempo, 2))/2;
    F[3][5] = (pow(delta_tempo, 2))/2;

}

//Inicializa a matriz P
void initialize_P(float P[ROWS][COLUMNS]){
    int i, j;

    for(i = 0; i < ROWS; i++){                                                                                          //Percorre linhas da matriz
        for(j = 0; j < COLUMNS; j++){                                                                                   //Percorre colunas da matriz
            P[i][j] = 0;                                                                                                //Preenche matriz com zeros
            if(i == j){
                P[i][j] = 500;                                                                                          //Preenche diagonal principal com 500
            }
        }
    }

}

//Inicializa a matriz Q
initialize_Q(float Q[ROWS][COLUMNS], float delta_tempo, float sigma_acel){
    int i, j;

    for(i = 0; i < ROWS; i++){                                                                                          //Percorre linhas da matriz
        for(j = 0; j < COLUMNS; j++){                                                                                   //Percorre colunas da matriz
            Q[i][j] = 0;                                                                                                //Preenche matriz com zeros
        }
    }

    Q[0][0] = (pow(delta_tempo, 4)) / 4;
    Q[0][1] = (pow(delta_tempo, 3)) / 2;
    Q[0][2] = (pow(delta_tempo, 2)) / 2;
    Q[1][0] = (pow(delta_tempo, 3)) / 2;
    Q[1][1] = pow(delta_tempo, 2);
    Q[1][2] = delta_tempo;
    Q[2][0] = (pow(delta_tempo, 2)) / 2;
    Q[2][1] = delta_tempo;
    Q[2][2] = 1;
    Q[3][3] = (pow(delta_tempo, 4)) / 4;
    Q[3][4] = (pow(delta_tempo, 3)) / 2;
    Q[3][5] = (pow(delta_tempo, 2)) / 2;
    Q[4][3] = (pow(delta_tempo, 3)) / 2;
    Q[4][4] = pow(delta_tempo, 2);
    Q[4][5] = delta_tempo;
    Q[5][3] = (pow(delta_tempo, 2)) / 2;
    Q[5][4] = delta_tempo;
    Q[5][5] = 1;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            Q[i][j] *= (pow(sigma_acel, 2));                                                                            //Multiplica Q por (sigma_acel)^2
        }
    }

}

//Inicializa a matriz R
initialize_R(float R[R_ROWS][R_COLUMNS], float sigma_medicao_posicao, float sigma_medicao_angulo){
    R[0][0] = pow(sigma_medicao_posicao, 2);
    R[0][1] = 0;
    R[1][0] = 0;
    R[1][1] = pow(sigma_medicao_angulo, 2);

}

//Inicializa a matriz I
initialize_I(float I[ROWS][COLUMNS]){
    int i, j;

    for(i = 0; i < ROWS; i++){                                                                                          //Percorre linhas da matriz
        for(j = 0; j < COLUMNS; j++){                                                                                   //Percorre colunas da matriz
            I[i][j] = 0;                                                                                                //Preenche a matriz com zeros
            if(i == j){
                I[i][j] = 1;                                                                                            //Preenche diagonal principal com 1
            }
        }
    }
}

//Realiza a transposicao de matriz
void transpose(float principal[ROWS][COLUMNS], float transpose[COLUMNS][ROWS]){
    int i, j;

    for(i = 0; i < ROWS; i++){                                                                                          //Percorre linhas da matriz
        for(j = 0; j < COLUMNS; j++){                                                                                   //Percorre colunas da matriz
            transpose[j][i] = principal[i][j];                                                                          //Transpoe linha por coluna
        }
    }
}