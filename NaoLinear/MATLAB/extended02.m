close all
clear all

%Sistema dinamico nao-linear: Pendulo de corda L

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% DADOS INICIAIS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

sigma_acel_ang = 1;                                                        %Constante de desvio da aceleracao (rad/s^2)
sigma_med_pos = 0.01;                                                      %Desvio da medicao de posicao (m)
g = 9.8;                                                                   %Valor da gravidade g (m/s^2)
delta_tempo = 0.05;                                                        %Variacao no tempo (s)
L = 0.5;                                                                   %Valor da corda L (m)


%Matriz 2x1 de estimativas. [angulo ; velocidade_angular]
x = zeros(2, 1); 
x(1) = 0.0873;

%Matriz P 2x2 de covariancia de posicao
P = zeros(2,2);          
for i = 1:1:2           
    P(i,i) = 5;                                                            %Preenche a diagonal principal da matriz P
end

%Matriz Q de ruido da covariancia
Q = [(delta_tempo^4)/4 (delta_tempo^3)/2 ; 
     (delta_tempo^3)/2 delta_tempo^2]*sigma_acel_ang^2 ;

%Matriz R de covariancia de ruido da medicao 
R = sigma_med_pos^2; 

%Matriz identidade
I = eye(2);        

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% ALGORITMO DE KALMAN %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

load medidas_extended02.mat
N = length(med_ang);


estimados = zeros(2, N);                                                   %Matriz auxiliar de estimativa
medidos = zeros(1, N);                                                     %Matriz auxiliar de medicao

for i=1:1:N

    [F, dF, dFt] = f(x, g, L, delta_tempo);                                %Calculo da matriz F e jacobiano de F
    
    x = F;                                                                 %Predicao da estimativa
    P = dF*P*dFt + Q;                                                      %Predicao da covariancia
    
    z = med_ang(i);                                                        %Dado de medicao do angulo                               

    [H, dH, dHt] = h(x, L);                                                %Calculo da matriz H e jacobiano de H
    
    K = P*dHt*(dH*P*dHt + R)^(-1);                                         %Atualizacao do Ganho de Kalman
    Kt = transpose(K);
    
    x = x + K*(z - H);                                                     %Atualizacao da estimativa
    P = (I - K*dH)*P*(transpose(I - K*dH)) + K*R*Kt;                       %Atualizacao da covariancia

    estimados(:,i) = x;                                                    %Matriz auxiliar recebe x, no tempo i
    medidos(:,i) = z;                                                      %Matriz auxiliar recebe z, no tempo i

end

estimado = estimados(1,:);                                                 %Armazena as estimativas do angulo 
medido = medidos(1,:);                                                     %Armazena as medicoes do angulo

%Plot do grafico da posicao 
figure
plot(estimado, 'b')                                                        %Dados estimados
hold on
plot(medido, 'ro')                                                         %Dados medidos
ylabel('Ângulo (rad)');
ylim([-0.15, 0.15])                                                        %Intervalo de limites do eixo y
title('Estimativa vs Medicao do ângulo');
legend('estimado','medido');
grid on;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% CALCULO DO JACOBIANO %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%Calculo de F, jacobiano de F (dF)
function [F, dF, dFt] = f(x, g, L, delta_tempo)
    F = [x(1) + x(2) * delta_tempo ; 
         x(2) - (g/L) * sin(x(1)) * delta_tempo];
    
    dF = [1 delta_tempo ; 
         (-g/L) * cos(x(1)) * delta_tempo 1];

    dFt = transpose(dF);
end

%Calculo de H, jacobiano de H (dH)
function [H, dH, dHt] = h(x, L)
    H = L * sin(x(1));

    dH = [L * cos(x(1)) 0];

    dHt = transpose(dH);
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
