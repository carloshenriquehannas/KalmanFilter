
#ifndef FKE_H_FUNCTIONS_H
#define FKE_H_FUNCTIONS_H

void soma_matriz_quadrada_6x6(float matrizA[ROWS][COLUMNS], float matrizB[ROWS][COLUMNS], float resultado[ROWS][COLUMNS]);                                                                                                                       //Soma de matrizes 2x2
void soma_matriz_quadrada_2x2(float matrizA[H_ROWS][dHt_COLUMNS], float matrizB[H_ROWS][dHt_COLUMNS], float resultado[H_ROWS][dHt_COLUMNS]);                        //Soma de matrizes (2x2 e 2x2)
void multiplica_matriz_auxiliar01(float matrizA[ROWS][COLUMNS], float matrizB[ROWS][COLUMNS], float resultado[ROWS][COLUMNS]);                                      //Multiplicacao de matrizes (6x6 e 6x6)
void multiplica_matriz_auxiliar02(float matrizA[ROWS][COLUMNS], float matrizB[ROWS][X_COLUMNS], float resultado[ROWS][X_COLUMNS]);                                  //Multiplicacao de matrizes (6x6 e 6x1)
void multiplica_matriz_auxiliar03(float matrizA[ROWS][COLUMNS], float matrizB[COLUMNS][H_ROWS], float resultado[ROWS][H_ROWS]);                                     //Multiplicacao de matrizes (6x6 e 6x2)
void multiplica_matriz_auxiliar04(float matrizA[H_ROWS][COLUMNS], float matrizB[ROWS][H_ROWS], float resultado[H_ROWS][H_ROWS]);                                    //Multiplicacao de matrizes (2x6 e 6x2)
void multiplica_matriz_auxiliar05(float matrizA[COLUMNS][H_ROWS], float matrizB[H_ROWS][dHt_COLUMNS], float resultado[COLUMNS][dHt_COLUMNS]);                       //Multiplicacao de matrizes (6x2 e 2x2)
void multiplica_matriz_auxiliar06(float matrizA[ROWS][dHt_COLUMNS], float matrizB[Z_ROWS][Z_COLUMNS], float resultado[ROWS][Z_COLUMNS]);                            //Multiplicacao de matrizes (6x2 e 2x1)
void multiplica_matriz_auxiliar07(float matrizA[R_ROWS][R_COLUMNS], float matrizB[dHt_COLUMNS][ROWS], float resultado[R_ROWS][ROWS]);                               //Multiplicacao de matrizes (2x2 e 2x6)
void multiplica_matriz_auxiliar08(float matrizA[ROWS][dHt_COLUMNS], float matrizB[R_ROWS][ROWS], float resultado[ROWS][ROWS]);                                      //Multiplicacao de matrizes (6x2 e 2x6)
void transpose_matriz_6x6(float principal[ROWS][COLUMNS], float transposta[COLUMNS][ROWS]);                                                                         //Calcula matriz transposta (6x6)
void transpose_matriz_6x2(float principal[ROWS][dHt_COLUMNS], float transposta[dHt_COLUMNS][ROWS]);                                                                 //Calcula matriz transposta (6x2)
void transpose_H(float principal[H_ROWS][COLUMNS], float transposta[COLUMNS][H_ROWS]);                                                                              //Calcula matriz transposta (2x6)
void inversa_matriz_2x2(float inversa[H_ROWS][dHt_COLUMNS]);                                                                                                        //Calcula a matriz inversa (2x2)

#endif
