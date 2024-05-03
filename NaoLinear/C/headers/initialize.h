#ifndef EXTENDED01_C_INITIALIZE_H
#define EXTENDED01_C_INITIALIZE_H

#define ROWS 6                                                                                                          //Linhas das matrizes
#define R_ROWS 2                                                                                                        //Linha da matriz R
#define R_COLUMNS 2                                                                                                     //Coluna da matriz R
#define X_COLUMNS 1                                                                                                     //Coluna da matriz x
#define COLUMNS 6                                                                                                       //Colunas das matrizes


void initialize_x(float x[ROWS][X_COLUMNS]);
void initialize_F(float F[ROWS][COLUMNS], float delta_tempo);
void initialize_P(float P[ROWS][COLUMNS]);
initialize_Q(float Q[ROWS][COLUMNS], float delta_tempo, float sigma_acel);
initialize_R(float R[R_ROWS][R_COLUMNS], float sigma_medicao_posicao, float sigma_medicao_angulo);
initialize_I(float I[ROWS][COLUMNS]);

#endif
