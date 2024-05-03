#include <stdio.h>

#define ROWS 6                                                                                                          //Linhas das matrizes
#define COLUMNS 6                                                                                                       //Colunas das matriZES
#define X_COLUMNS 1                                                                                                     //Colunas da matriz x


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
    F[0][2] = (delta_tempo*delta_tempo)/2;
    F[3][5] = (delta_tempo*delta_tempo)/2;

}

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

initialize_Q(float Q[ROWS][COLUMNS], float delta_tempo, float sigma_acel){
    int i, j;

    for(i = 0; i < ROWS; i++){                                                                                          //Percorre linhas da matriz
        for(j = 0; j < COLUMNS; j++){                                                                                   //Percorre colunas da matriz
            Q[i][j] = 0;                                                                                                //Preenche matriz com zeros
        }
    }

    Q[0][0] = (delta_tempo * delta_tempo * delta_tempo * delta_tempo) / 4;
    Q[0][1] = (delta_tempo * delta_tempo * delta_tempo) / 2;
    Q[0][2] = (delta_tempo * delta_tempo) / 2;
    Q[1][0] = (delta_tempo * delta_tempo * delta_tempo) / 2;
    Q[1][1] = (delta_tempo * delta_tempo);
    Q[1][2] = delta_tempo;
    Q[2][0] = (delta_tempo * delta_tempo) / 2;
    Q[2][1] = delta_tempo;
    Q[2][2] = 1;
    Q[3][3] = (delta_tempo * delta_tempo * delta_tempo * delta_tempo) / 4;
    Q[3][4] = (delta_tempo * delta_tempo * delta_tempo) / 2;
    Q[3][5] = (delta_tempo * delta_tempo) / 2;
    Q[4][3] = (delta_tempo * delta_tempo * delta_tempo) / 2;
    Q[4][4] = (delta_tempo * delta_tempo);
    Q[4][5] = delta_tempo;
    Q[5][3] = (delta_tempo * delta_tempo) / 2;
    Q[5][4] = delta_tempo;
    Q[5][5] = 1;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            Q[i][j] *= (sigma_acel * sigma_acel);                                                                       //Multiplica Q por (sigma_acel)^2
        }
    }

}

int main() {
    float sigma_acel = 0.2;                                                                                             //Constante de desvio da aceleracao
    float sigma_medicao_posicao = 5;                                                                                    //Desvio da medicao de posicao
    float sigma_medicao_angulo = 0.0087;                                                                                //Desvio da medicao do angulo
    float delta_tempo = 1;                                                                                              //Variacao do tempo

    //Matriz x de estimativas
    float x[ROWS][X_COLUMNS];                                                                                           //Matriz x de estimativas
    initialize_x(x);                                                                                                    //Inicializa a matriz x com os valores

    float F[ROWS][COLUMNS];                                                                                             //Matriz F de transicao de estados
    initialize_F(F, delta_tempo);                                                                                       //Inicializa a matriz F com os valores
    //FAZER transpose(F)

    float P[ROWS][COLUMNS];                                                                                             //Matriz P de covariancia
    initialize_P(P);                                                                                                    //Inicializa a matriz P com os valores

    float Q[ROWS][COLUMNS];                                                                                             //Matriz Q de ruido da covariancia
    initialize_Q(Q, delta_tempo, sigma_acel);                                                                           //Inicializa a matriz Q com os valores

    return 0;
}
