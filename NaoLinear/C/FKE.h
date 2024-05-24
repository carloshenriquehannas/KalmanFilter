
#ifndef MAIN_C_FKE_H
#define MAIN_C_FKE_H

void estimate_state(float z[Z_ROWS][Z_COLUMNS], float H[H_ROWS][H_COLUMNS], float K[ROWS][dHt_COLUMNS]);                                                                                                          //Estimativa de estado
void jacobiano(float x_res[ROWS][X_COLUMNS], float H[H_ROWS][H_COLUMNS], float dH[H_ROWS][COLUMNS], float dHt[COLUMNS][H_ROWS]);                                                      //Algoritmo do jacobiano                                                                                                         //Matriz jacobiana
void extended_kalman(float x[ROWS][X_COLUMNS], float F[ROWS][COLUMNS], float P[ROWS][COLUMNS], float Ft[COLUMNS][ROWS], float Q[ROWS][COLUMNS], float R[R_ROWS][R_COLUMNS]);          //Algoritmo de Kalman

#endif