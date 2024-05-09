
#ifndef FKE_H_FUNCTIONS_H
#define FKE_H_FUNCTIONS_H

void multiplica_matriz_quadrada(float matrizA[ROWS][COLUMNS], float matrizB[ROWS][COLUMNS], float resultado[ROWS][COLUMNS]);                                    //Multiplicacao de matrizes (matriz quadrada)
void multiplica_matriz_coluna(float matrizA[ROWS][COLUMNS], float matrizB[ROWS][X_COLUMNS], float resultado[ROWS][X_COLUMNS]);                                  //Multiplicacao de matrizes (matriz coluna)
void transpose_quadrada(float principal[ROWS][COLUMNS], float transposta[COLUMNS][ROWS]);                                                                       //Calcula matriz transposta (matriz quadrada)
void transpose_H(float principal[H_ROWS][COLUMNS], float transposta[COLUMNS][H_ROWS]);
#endif
