
#ifndef MAIN_C_FKE_H
#define MAIN_C_FKE_H

void estimate_state(float z[Z_ROWS][Z_COLUMNS], float H[H_ROWS][H_COLUMNS], float K[ROWS][dHt_COLUMNS], float x_res[ROWS][X_COLUMNS], float estimate_x[ROWS][X_COLUMNS]);                                                        //Estimativa final do estado                                                                                                     //Estimativa de estado
void estimate_predict(float R[R_ROWS][R_COLUMNS], float K[ROWS][dHt_COLUMNS], float Kt[dHt_COLUMNS][ROWS], float dH[H_ROWS][COLUMNS], float I[ROWS][COLUMNS], float P_res[ROWS][COLUMNS], float estimate_P[ROWS][COLUMNS]);     //Estimativa final da covariancia
void jacobiano(float x_res[ROWS][X_COLUMNS], float H[H_ROWS][H_COLUMNS], float dH[H_ROWS][COLUMNS], float dHt[COLUMNS][H_ROWS]);                                                                                                //Algoritmo do jacobiano                                                                                                         //Matriz jacobiana
void extended_kalman(float x[ROWS][X_COLUMNS], float F[ROWS][COLUMNS], float P[ROWS][COLUMNS], float Ft[COLUMNS][ROWS], float Q[ROWS][COLUMNS], float R[R_ROWS][R_COLUMNS], float I[ROWS][COLUMNS]);                           //Algoritmo de Kalman

#endif