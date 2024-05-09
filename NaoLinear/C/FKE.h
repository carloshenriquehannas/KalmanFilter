
#ifndef MAIN_C_FKE_H
#define MAIN_C_FKE_H

void multiplica_matriz_quadrada(float matrizA[ROWS][COLUMNS], float matrizB[ROWS][COLUMNS], float resultado[ROWS][COLUMNS]);                              //Multiplicacao de matrizes (matriz quadrada)
void multiplica_matriz_coluna(float matrizA[ROWS][COLUMNS], float matrizB[ROWS][X_COLUMNS], float resultado[ROWS][X_COLUMNS]);                                  //Multiplicacao de matrizes (matriz coluna)
void extended_kalman(float x[ROWS][X_COLUMNS], float F[ROWS][COLUMNS], float P[ROWS][COLUMNS], float Ft[COLUMNS][ROWS], float Q[ROWS][COLUMNS]);          //Algoritmo de Kalman

#endif
