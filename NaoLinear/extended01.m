%Exemplo de sistema dinamico linear, mas com medicao nao-linear

clear all
close all

%%%%%%%%%%%%%%%%%%%%%% DADOS INICIAIS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

sigma_acel = 0.2;                  %Constante de desvio da aceleracao 
sigma_medicao_posicao = 5;         %Desvio da medicao de posicao
sigma_medicao_angulo = 0.0087;     %Desvio da medicao do angulo
delta_tempo = 1;                   %Variacao do tempo

%Matriz x 6x1 de estimativas
x = zeros(6, 1); 
x(1) = 400;                         %Posicao x inicial 
x(4) = -300;                        %Posicao y inicial

%Matriz F e transposta Ft de transicao de estados. Linear neste exemplo
F = [1, delta_tempo, (delta_tempo^2)/2, 0, 0, 0; 
     0, 1, delta_tempo, 0, 0, 0;
     0, 0, 1, 0, 0, 0;
     0, 0, 0, 1, delta_tempo, (delta_tempo^2)/2;
     0, 0, 0, 0, 1, delta_tempo;
     0, 0, 0, 0, 0, 1];
Ft = transpose(F);

%Matriz P 6x6 de covariancia de posicao
P = zeros(6,6);          
for i = 1:1:6           
    P(i,i) = 500;       %Preenche a diagonal principal da matriz P
end

%Matriz Q de ruido da covariancia
Q = [(delta_tempo^4)/4, (delta_tempo^3)/2, (delta_tempo^2)/2, 0, 0, 0; 
     (delta_tempo^3)/2, delta_tempo^2, delta_tempo, 0, 0, 0;
     (delta_tempo^2)/2, delta_tempo, 1, 0, 0, 0;
     0, 0, 0, (delta_tempo^4)/4, (delta_tempo^3)/2, (delta_tempo^2)/2;
     0, 0, 0, (delta_tempo^3)/2, delta_tempo^2, delta_tempo;
     0, 0, 0, (delta_tempo^2)/2, delta_tempo, 1];
Q = Q*(sigma_acel^2);

%Matriz R de covariancia de ruido da medicao 
R = [sigma_medicao_posicao^2 0 ; 0 sigma_medicao_angulo^2]; 

%Define as constantes r e phi da matriz H. VERIFICAR O SINAL DE PHI
r = x(1)^2 + x(4)^2;
phi = atan(x(4)/x(1));
H = [sqrt(r);
     -phi];

%Define as matrizes jacobiana dH e sua transposta
dH = [x(1)/sqrt(r) 0 0 x(4)/sqrt(r) 0 0 ;
      -x(4)/r 0 0 x(1)/r 0 0];
dHt = transpose(dH);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%% PRIMEIRA ITERACAO %%%%%%%%%%%%%%%%%%%%%%%%%%%

x = F * x;                                  %Predicao da estimativa

P = F * P * Ft + Q;                         %Predicao da covariancia

z = [502.55 ;
     -0.93616];

K = P * dHt * (dH * P * dHt + R)^(-1);      %Atualizacao do Ganho de Kalman


