%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% DADOS INICIAIS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

sigma_acel = 0.2*0.2;                                   %Constante
sigma_medicao = 3*3;                                    %Constante

x = zeros(6, 1);                                        %Inicializacao da matriz 6x1 de estimativa

Q = [0.25 0.5 0.5 0 0 0 ; 0.5 1 1 0 0 0 ; 0.5 1 1 0 0 0 ; 0 0 0 0.25 0.5 0.5 ; 0 0 0 0.5 1 1 ; 0 0 0 0.5 1 1]*(sigma_acel);

P = [500 0 0 0 0 0 ; 0 500 0 0 0 0 ; 0 0 500 0 0 0 ; 0 0 0 500 0 0 ; 0 0 0 0 500 0 ; 0 0 0 0 0 500];

F = [1 1 0.5 0 0 0 ; 0 1 1 0 0 0 ; 0 0 1 0 0 0 ; 0 0 0 1 1 0.5 ; 0 0 0 0 1 1 ; 0 0 0 0 0 1];

H = [1 0 0 0 0 0 ; 0 0 0 1 0 0 ];

R = [sigma_medicao 0 ; 0 sigma_medicao];

I = eye(6);                                             %Matriz identidade 6x6

Ft = transpose(F);
Ht = transpose(H);

z = zeros(2, 1);                                        %Inicializacao da matriz 2x1 de medicao

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

load medidas_v1.mat
N = length(medx);

estimados = zeros(6, N);                               %Inicializacao da matriz de estimativa, com x dados em i tempos
medidos = zeros(2, N);                                 %Inicializacao da matriz auxiliar de medicao, com x dados em i tempos

%Laco de repeticao para medicao e estimacao de i tempos
for i = 1:N

    x = F*x;                                            %Predicao da estimativa 
    P = F*P*Ft + Q;                                     %Predicao da covariancia

    %Entrada da matriz z pelo usuario                   
    z(1) = medx(i);
    z(2) = medy(i);

    K = P*Ht*(H*P*Ht + R)^(-1);                         %Predicao do ganho de Kalman
    Kt = transpose(K);                                  %Atualizacao da matriz transposta do ganho de Kalman                                  

    x = x + K*(z - H*x);                                %Atualizacao da matriz de estimativa
    P = (I - K*H)*P*(transpose(I - K*H)) + K*R*Kt;      %Atualizacao da matriz de covariancia

    estimados(:,i) = x;                                 %Matriz de estimados recebe x, no tempo i
    medidos(:,i) = z;                                   %Matriz de medidos recebe z, no tempo i                               

end

estimadoX = estimados(1,:);                              %Armazena as estimativas da posicao X
estimadoY = estimados(4,:);                              %Armazena as estimativas da posicao Y 
medidoX = medidos(1,:);
medidoY = medidos(2,:);

%Plot do grafico de estimativa da posicao XY
figure
plot(estimadoX, estimadoY, 'b')
hold on
scatter(medidoX,medidoY,'r')

xlabel('Posicao X (m)');
ylabel('Posicao Y (m)');
title('Estimativa vs Medicao da posicao XY');
legend('estimado','medido');
grid on;
