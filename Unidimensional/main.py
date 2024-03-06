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
        print("teste 1")
        #sistema_estatico(VetMedido, VetEstimado, estimado)
    case 2:
        print("teste 2")
        #sistema_dinamico(VetMedido, VetEstimado, estimado)
    case 3:
        print("teste 3")
        #kalman_1d(VetMedido, VetEstimado, estimado)
    case default:
        print('Default')