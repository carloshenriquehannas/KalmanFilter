%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% DADOS INICIAIS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%Constantes
sigma = 20;
tempo = 0.25;
epsilon = 0.1;
gravidade = 9.8;
aceleracao = 30;

%Equacao de predicao: x = Fx+Gu
x = zeros(2, 1);                                        %Inicializacao da matriz 2x1 de estimativa
F = [1 tempo ; 0 1];                                    %Inicializacao da matriz F
G = [0.5*tempo^2 ; tempo];                              %Inicializacao da matriz G
u = 0;                                                  %Inicializacao da variavel de input

%Equacao de predicao da covariancia: P = F*P*Ft+Q
P = [500 0 ; 0 500];                                    %Inicializacao de uma covariancia arbitraria
Q = [(tempo^4)/4 (tempo^3)/2 ; (tempo^3)/2 tempo^2]*epsilon^2;

H = eye(2)*1.5;

R = sigma^2;

I = eye(2);                                             %Matriz identidade 6x6

Ft = transpose(F);
Ht = transpose(H);

z = zeros(2, 1);                                        %Inicializacao da matriz 1x2 de medicao. z = [altura aceleracao]

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

estimados = zeros(2,10);                               %Inicializacao da matriz de estimativa, com x dados em i tempos
medidos = zeros(2,10);                                 %Inicializacao da matriz auxiliar de medicao, com x dados em i tempos

%Laco de repeticao para medicao e estimacao de i tempos
for i = 1:10

    x = F*x + G*u;                                      %Predicao da estimativa 
    P = F*P*Ft + Q;                                     %Predicao da covariancia
    K = P*Ht*(H*P*Ht + R)^(-1);                         %Predicao do ganho de Kalman

    %Entrada do usuario   
    z(1) = input(sprintf('Digite o valor da medicao z: '));         %Medicao da altura
    z(2) = input(sprintf('Digite o valor do input u: '));           %Medicao do controle

    z(2) = z(2) - gravidade;

    Kt = transpose(K);                                  %Atualizacao da matriz transposta do ganho de Kalman                                  
    x = x + K*(z - H*x);
    P = (I - K*H)*P*(transpose(I - K*H)) + K*R*Kt;      %Atualizacao da matriz de covariancia

    estimados(:,i) = x;                                 %Matriz de estimados recebe x, no tempo i
    medidos(:,i) = z;                                   %Matriz de medidos recebe z, no tempo i                               

end

estimado_altura = estimados(1,:);                              %Armazena as estimativas num vetor
estimado_velocidade = estimados(2,:);                          %Armazena as velocidadades num vetor
medido_altura = medidos(1,:);
medido_velocidade= medidos(2,:);

%Plot do grafico de altura
figure
plot(estimado_altura,'b')
hold on
plot(medido_altura,'r')
xlabel('Tempo (s)');
ylabel('Altura (m)');
title('Estimativa vs Medicao da altura');

%Plot do grafico de velocidade
figure
plot(estimado_velocidade,'b')
hold on
plot(medido_velocidade,'r')
xlabel('Tempo (s)');
ylabel('Velocidade (m)');
title('Estimativa vs Medicao da velocidade');
