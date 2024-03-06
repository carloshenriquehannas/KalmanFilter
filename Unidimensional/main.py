import matplotlib.pyplot as plt

############################# SISTEMA ESTATICO #########################################################################
def sistema_estatico(VetMedido, VetEstimado, estimado):
    for i in range(0, 10):
        medido = float(input('Valor medido: '))

        K = (1)/(i+1)                                                                   #Ganho
        estimado = estimado + K*(medido - estimado)                                     #Algoritmo de estimacao

        VetMedido.insert(i, medido)                                                     #Insere valor medido no vetor
        VetEstimado.insert(i, estimado)                                                 #Insere valor estimado no vetor

########################################################################################################################

#############################SISTEMA DINAMICO###########################################################################
def sistema_dinamico(VetMedido, VetEstimado, estimado):
    velocidade = float(input('Velocidade estimada: '))
    aceleracao = float(input('Aceleracao estimada: '))
    tempo = 5                                                                           #Constante de tempo
    alpha = 0.5                                                                         #Constante de ganho alpha
    beta = 0.4                                                                          #Constante de ganho beta
    gama = 0.1                                                                          #Constante de ganho gama

    for i in range(0, 10):
        medido = float(input('Valor medido: '))

        estimado = estimado + velocidade*tempo + aceleracao*(tempo**2/2)                #Predicao de posicao
        velocidade = velocidade + aceleracao*tempo                                      #Predicao de velocidade

        estimado = estimado + alpha*(medido - estimado)                                 #Atualizacao da posicao
        velocidade = velocidade + beta*((medido - estimado)/tempo)                      #Atualizacao da velocidade
        aceleracao = aceleracao + gama*((medido - estimado)/tempo)

        VetMedido.insert(i, medido)                                                     #Insere valor medido no vetor
        VetEstimado.insert(i, estimado)                                                 #Insere valor estimado no vetor

########################################################################################################################

#####################FILTRO DE KALMAN EM UMA DIMENSAO###################################################################

def kalman_1d(VetMedido, VetEstimado, estimado):
    p = float(input('Covariancia estimada p: '))                                        #Constante inicial estimada
    r = float(input('Covariancia medida r: '))                                          #Constante medida pelo usuario
    q = float(input('Constante de ruido q: '))                                          #Constante estimada pelo usuario

    #Algoritmo de Kalman, para 10 iteracoes
    for i in range(0, 10):
        medido = float(input('Valor medido: '))

        p = p + q                                                                       #Covariancia, considerando ruido
        K = (p)/(p+r)                                                                   #Ganho de Kalmann
        estimado = (1-K)*estimado + K*medido                                            #Algoritmo de estimacao

        p = (1 - K)*p                                                                   #Atualizacao da nova covariancia

        VetMedido.insert(i, medido)                                                     #Insere valor medido no vetor
        VetEstimado.insert(i, estimado)                                                 #Insere valor estimado no vetor

########################################################################################################################

############################## MAIN ####################################################################################

print('1 - Sistema Estatico')
print('2 - Sistema Dinamico')
print('3 - Filtro Kalman em 1 dimensao')

opcao = int(input('Digite a opcao que desejar: '))

estimado = float(input('Valor inicial estimado: '))                                     #Constante inicial estimada

VetMedido = []                                                                          #Armazena de dados medidos
VetEstimado = []                                                                        #Armazena de dados estimados

match opcao:                                                                            #Opcao escolhida pelo usuario
    case 1:
        sistema_estatico(VetMedido, VetEstimado, estimado)
    case 2:
        sistema_dinamico(VetMedido, VetEstimado, estimado)
    case 3:
        kalman_1d(VetMedido, VetEstimado, estimado)
    case default:
        print('Default')

#Geracao de grafico em imagem
plt.plot(VetMedido, 'go')
plt.plot(VetEstimado)
plt.xlabel('Tempo')
plt.ylabel('Medicao')
plt.show()

########################################################################################################################