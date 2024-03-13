import matplotlib.pyplot as plt
import numpy as np

sigma_acel = 0.2                    #Desvio padrao da aceleracao
sigma_medicao = 3                   #Desvio padrao da medicao
tempo = 1                           #Variacao de tempo

x = np.zeros((6, 1))                #Inicia a matriz 6x1 de estimativa com zeros

F = np.zeros((6, 6))                #Inicia a matriz F 6x6 e a preenche com os respectivos valores
for i in range(0, 6):
    F[i, i] = 1                     #Preenche a diagonal principal
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
for i in range(0, 6):
    P[i, i] = 500                   #Preenche a diagonal principal

H = np.zeros((2, 6))                #Inicia a matriz H 2x6 e a preenche com valores arbitrarios
H[0, 0] = H[1, 3] = 1

I = np.zeros((6, 6))                #Inicia a matriz I identidade 6x6 e a preenche com os respectivos valores
for i in range(0, 6):
    I[i, i] = 1

Ft = np.transpose(F)                #Inicia a matriz transposta de F
Ht = np.transpose(H)                #Inicia a matriz transposta de H

