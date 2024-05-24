#ifndef EXTENDED01_C_INITIALIZE_H
#define EXTENDED01_C_INITIALIZE_H

#define ROWS 6                                                                                                          //Linhas das matrizes
#define COLUMNS 6                                                                                                       //Colunas das matrizes
#define H_ROWS 2                                                                                                        //Coluna da matriz H
#define H_COLUMNS 1                                                                                                     //Linha da matriz H
#define dHt_COLUMNS 2                                                                                                   //Coluna da matriz dHt
#define R_ROWS 2                                                                                                        //Linha da matriz R
#define R_COLUMNS 2                                                                                                     //Coluna da matriz R
#define X_COLUMNS 1                                                                                                     //Coluna da matriz x
#define Z_ROWS 2                                                                                                        //Linha da matrix z
#define Z_COLUMNS 1                                                                                                     //Coluna da matriz Z

void initialize_x(float x[ROWS][X_COLUMNS]);                                                                            //Matriz x de estimativas
void initialize_F(float F[ROWS][COLUMNS], float delta_tempo);                                                           //Matriz F de transicao de estados
void initialize_P(float P[ROWS][COLUMNS]);                                                                              //Matriz P de covariancia
void initialize_Q(float Q[ROWS][COLUMNS], float delta_tempo, float sigma_acel);                                         //Matriz Q de ruido da covariancia
void initialize_R(float R[R_ROWS][R_COLUMNS], float sigma_medicao_posicao, float sigma_medicao_angulo);                 //Matriz R de ruido da covariancia medida
void initialize_I(float I[ROWS][COLUMNS]);                                                                              //Matriz I identidade
void initialize_H(float H[H_ROWS][H_COLUMNS], float r, float phi);                                                      //Matriz H de observacao
void initialize_dH(float dH[H_ROWS][COLUMNS], float x[ROWS][X_COLUMNS], float r, float r_aux);                          //Matriz dH: jacobiano de H

#endif
