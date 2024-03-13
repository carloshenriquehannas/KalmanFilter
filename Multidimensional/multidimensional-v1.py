import matplotlib.pyplot as plt
import numpy as np

################################## INICIALIZACAO #######################################################################

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

################################ FILTRO DE KALMAN MULTIDIMENSIONAL #####################################################

posicaoEstimadaX = []
posicaoEstimadaY = []
posicaoMedidaX = []
posicaoMedidaY = []

#Laco de repeticao para medicao e estimacao j vezes
for j in range(0, 30):
    x = F @ x                   #Predicao da estimativa
    P = F @ P @ Ft + Q          #Predicao da covariancia

    z = np.zeros((2, 1))  #Criar uma nova matriz z 2x1 para armazenar os valores medidos

    for i in range(0, 2):
        z[i, 0] = float(input(f'Valor medido para a posicao ({i+1}, 1): '))             #Entrada da medicao pelo usuario

    #Expressao matematica do Ganho de Kalman K: K = P*Ht*(H*P*Ht + R)^(-1);
    K = P @ Ht @ np.linalg.inv(H @ P @ Ht + R)  #Predicao do Ganho de Kalman
    Kt = np.transpose(K)                        #Atualizacao da transposta de K

    #Expressao matematica da atualizacao de estimativa x: x = x + K*(z - H*x)
    x = x + K @ (z - H @ x)                                             #Atualizacao da matriz de estimativa

    #Expressao matematica da atualizacao de covariancia P: P = (I - K*H)*P*(transpose(I - K*H)) + K*R*Kt
    P = (I - K @ H) @ P @ (np.transpose(I - K @ H)) + K @ R @ Kt        #Atualizacao da matriz de covariancia

    posicaoEstimadaX.append(x[0])      #Armazena as posicoes estimadas no eixo X (primeiro indice do vetor coluna x)
    posicaoEstimadaY.append(x[3])      #Armazena as posicoes estimadas no eixo Y (quarto indice do vetor coluna y)

    posicaoMedidaX.append(z[0])        #Armazena as posicoes medidas no eixo X (primeiro indice do vetor coluna z)
    posicaoMedidaY.append(z[1])        #Armazena as posicoes medidas no eixo Y (segundo indice do vetor coluna z)

plt.plot(posicaoEstimadaX, posicaoEstimadaY)
plt.plot(posicaoMedidaX, posicaoMedidaY, 'go')
plt.xlabel('Posicao X(m)')
plt.ylabel('Posicao Y(m)')
plt.title('Estimativa vs Medicao da posicao XY')
plt.show()
