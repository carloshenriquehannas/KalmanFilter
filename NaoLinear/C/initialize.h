#ifndef EXTENDED01_C_INITIALIZE_H
#define EXTENDED01_C_INITIALIZE_H

#define ROWS 6                                                                                                          //Linhas das matrizes
#define R_ROWS 2                                                                                                        //Linha da matriz R
#define R_COLUMNS 2                                                                                                     //Coluna da matriz R
#define X_COLUMNS 1                                                                                                     //Coluna da matriz x
#define COLUMNS 6                                                                                                       //Colunas das matrizes

void initialize_x(float x[ROWS][X_COLUMNS]);                                                                            //Matriz x de estimativas
void initialize_F(float F[ROWS][COLUMNS], float delta_tempo);                                                           //Matriz F de transicao de estados
void initialize_P(float P[ROWS][COLUMNS]);                                                                              //Matriz P de covariancia
initialize_Q(float Q[ROWS][COLUMNS], float delta_tempo, float sigma_acel);                                              //Matriz Q de ruido da covariancia
initialize_R(float R[R_ROWS][R_COLUMNS], float sigma_medicao_posicao, float sigma_medicao_angulo);                      //Matriz R de ruido da covariancia medida
initialize_I(float I[ROWS][COLUMNS]);                                                                                   //Matriz I identidade

void transpose(float principal[ROWS][COLUMNS], float transpose[COLUMNS][ROWS]);                                         //Calcula matriz transposta

#endif
