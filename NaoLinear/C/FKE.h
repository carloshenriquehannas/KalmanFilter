
#ifndef MAIN_C_FKE_H
#define MAIN_C_FKE_H

float multiplica_matriz_coluna(float matrizA[ROWS][X_COLUMNS], float matrizB[ROWS][COLUMNS]);                           //Multiplicacao de matrizes (matriz coluna)
void extended_kalman(float x[ROWS][X_COLUMNS], float F[ROWS][COLUMNS], float P[ROWS][COLUMNS], float Ft[COLUMNS][ROWS], float Q[ROWS][COLUMNS]);      //Algoritmo de Kalman

#endif
