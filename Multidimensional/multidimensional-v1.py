import matplotlib.pyplot as plt
import numpy as np

################################## INICIALIZACAO ###################################################################

sigma_acel = 0.2                    #Desvio padrao da aceleracao
sigma_medicao = 3                   #Desvio padrao da medicao
tempo = 1                           #Variacao de tempo

x = np.zeros((6, 1))                #Inicia a matriz 6x1 de estimativa com zeros

F = np.zeros((6, 6))                #Inicia a matriz F 6x6 e a preenche com os respectivos valores
for j in range(0, 6):
    F[j, j] = 1                     #Preenche a diagonal principal
F[0, 1] = F[1, 2] = F[3, 4] = F[4, 5] = tempo
F[0, 2] = F[3, 5] = 0.5 * (tempo ** 2)

Q = np.zeros((6, 6))                #Inicia a matriz Q 6x6 e a preenche com os respectivos valores
Q[0, 0] = Q[3, 3] = (tempo**4)/4
Q[0, 1] = Q[1, 0] = Q[3, 4] = Q[4, 3] = (tempo**3)/2
Q[0, 2] = Q[2, 0] = Q[3, 5] = Q[5, 3] = (tempo**2)/2
Q[1, 1] = Q[4, 4] = tempo**2
Q[1, 2] = Q[2, 1] = Q[4, 5] = tempo
Q[2, 2] = Q[5, 5] = 1
Q = Q * (sigma_acel**2)

R = np.zeros((2, 2))                #Inicia a matriz R 2x2 e a preenche com os respectivos valores
R[0, 0] = R[1, 1] = sigma_medicao**2

P = np.zeros((6, 6))                #Inicia a matriz P 6x6 e a preenche com valores arbitrarios
for j in range(0, 6):
    P[j, j] = 500                   #Preenche a diagonal principal

H = np.zeros((2, 6))                #Inicia a matriz H 2x6 e a preenche com valores arbitrarios
H[0, 0] = H[1, 3] = 1

I = np.zeros((6, 6))                #Inicia a matriz I identidade 6x6 e a preenche com os respectivos valores
for j in range(0, 6):
    I[j, j] = 1

Ft = np.transpose(F)                #Inicia a matriz transposta de F
Ht = np.transpose(H)                #Inicia a matriz transposta de H

z = np.zeros((2, 1))                #Inicia a matriz z 2x1 de medicao

################################FILTRO DE KALMAN MULTIDIMENSIONAL ##################################################

#Laco de repeticao para medicao e estimacao j vezes
for j in range(0, 2):
    x = np.dot(F, x)                    #Predicao da estimativa
    P = np.dot(np.dot(F, P), Ft) + Q    #Predicao da covariancia

    for i in range(0, 2):
        z[i, 0] = float(input(f'Valor medido para a posicao ({i+1}, 1): '))                     #Entrada da medicao pelo usuario

    #Expressao matematica do Ganho de Kalman K: K = P*Ht*(H*P*Ht + R)^(-1);
    K = np.dot(np.dot(P, Ht), np.linalg.inv(np.dot(np.dot(H, P), Ht) + R))  #Predicao do Ganho de Kalman
    Kt = np.transpose(K)                                                    #Atualizacao da transposta de K

    #Expressao matematica da atualizacao de estimativa x: x = x + K*(z - H*x)
    x = x + np.dot(K, z - np.dot(H, x))                                     #Atualizacao da matriz de estimativa

    #Expressao matematica da atualizacao de covariancia P: P = (I - K*H)*P*(transpose(I - K*H)) + K*R*Kt
    P = np.dot(np.dot(I - np.dot(K, H), P), np.transpose(I - np.dot(K, H))) + np.dot(np.dot(K, R), Kt)

