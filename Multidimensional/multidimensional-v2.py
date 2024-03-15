#import matplotlib.pyplot as plt
import numpy as np

#################################################### INICIALIZACAO ##############################################

#Constantes
sigma = 20
deltaT = 0.25                                               #Variacao de tempo
epsilon = 0.1
gravidade = 9.8
aceleracao = 30

#Predicao da posicao e tempo: x = Fx + Gu
x = np.zeros((2, 1))                                        #Inicializacao da matriz x 2x1 de estimativas

F = np.zeros((2, 2))                                        #Inicializacao da matriz F 2x2
for j in range(0, 2):
    F[j, j] = 1                                             #Preenche diagonal principal com 1
F[0, 1] = deltaT

G = np.zeros((2, 1))                                        #Inicializacao da matriz G 1x2
G[0, 0] = 0.5*(deltaT**2)
G[1, 0] = deltaT

#u = aceleracao + gravidade                                  #Inicializacao da matriz u 1x1 de controle
u = 0

#Predicao da covariancia: P = FP(F^T)+Q
P = np.zeros((2, 2))                                        #Inicializacao de uma covariancia arbitraria
for j in range(0, 2):
    P[j, j] = 500

Q = np.zeros((2, 2))                                        #Inicializacao da matriz Q 2x2
Q[0, 0] = (deltaT**4)/4
Q[0, 1] = Q[1, 0] = (deltaT**3)/2
Q[1, 1] = deltaT**2
Q = Q*(epsilon**2)

R = [sigma**2]                                              #Inicializacao do vetor R

H = np.zeros((1, 2))                                         #Inicializacao da matriz H
H[0, 0] = 1

I = np.zeros((2, 2))                                        #Inicializacao da matriz identidade I 2x2
for j in range(0, 2):
    I[j, j] = 1

Ft = np.transpose(F)                                        #Inicializacao da matriz transposta de F
Ht = np.transpose(H)                                        #Inicializacao da matriz transposta de H

######################################## FILTRO DE KALMAN MULTIDIMENSIONAL ######################################

for j in range(0, 30):
    x = F @ x + G * u  # Predicao da estimativa
    P = F @ P @ Ft + Q                                          #Predicao da covariancia

    K = P @ Ht @ np.linalg.inv(H @ P @ Ht + R)                  #Predicao do Ganho de Kalman
    Kt = np.transpose(K)                                        #Matriz transposta de K

    z = float(input('Medicao da posicao z: '))                  #Input do usuario
    u = float(input('Medicao do controle u: '))                 #Input do usuario

    u = u - gravidade                                           #Correcao do controle, devido ao acelerometro

    x = x + K @ (z - H @ x)                                         #Atualizacao da matriz de estimativas
    P = (I - K @ H) @ P @ (np.transpose(I - K @ H)) + K * R @ Kt    #Atualizacao da matriz de covariancias

