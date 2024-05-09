
#ifndef MAIN_C_FKE_H
#define MAIN_C_FKE_H

void jacobiano(float x_res[ROWS][X_COLUMNS]);                                                                                                             //Matriz jacobiana
void extended_kalman(float x[ROWS][X_COLUMNS], float F[ROWS][COLUMNS], float P[ROWS][COLUMNS], float Ft[COLUMNS][ROWS], float Q[ROWS][COLUMNS]);          //Algoritmo de Kalman

#endif
