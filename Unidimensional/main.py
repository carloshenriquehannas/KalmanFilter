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

############################## MAIN ####################################################################################

print('1 - Sistema Estatico')
print('2 - Sistema Dinamico')
print('3 - Filtro Kalman em 1 dimensao')

opcao = int(input('Digite a opcao que desejar: '))

estimado = float(input('Valor inicial estimado: '))                                     #Constante inicial estimada

VetMedido = []                                                                          #Armazena de dados medidos
VetEstimado = []                                                                        #Armazena de dados estimados

match opcao:
    case 1:
        sistema_estatico(VetMedido, VetEstimado, estimado)
    case 2:
        print("teste 2")
        #sistema_dinamico(VetMedido, VetEstimado, estimado)
    case 3:
        print("teste 3")
        #kalman_1d(VetMedido, VetEstimado, estimado)
    case default:
        print('Default')

plt.plot(VetMedido, 'go')
plt.plot(VetEstimado)
plt.xlabel('Tempo')
plt.ylabel('Medicao')
plt.show()