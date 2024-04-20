close all

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

%Matriz F, jacobiano de F (dF) e transposta de dF
F = [x(1)+x(2)*delta_tempo ; 
     x(2) - (g/L)*sin(x(1))*delta_tempo];

dF = [1 delta_tempo ; 
     (-g/L)*cos(x(1))*delta_tempo 1];

dFt = transpose(dF);

%Matriz H, jacobiano de H (dH) e transposta de dH
H = L*sin(x(1)); 

dH = [L*cos(x(1)) 0];

dHt = transpose(dH);

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

for i=1:1:10

    F = [x(1)+x(2)*delta_tempo ; 
         x(2) - (g/L)*sin(x(1))*delta_tempo];
    dF = [1 delta_tempo ; 
         (-g/L)*cos(x(1))*delta_tempo 1];
    dFt = transpose(dF);
    
    x = F;                                                                 %Predicao da estimativa
    
    P = dF*P*dFt + Q;                                                      %Predicao da covariancia
    
    z = input(sprintf('Digite z: '));                                      %Dado de medicao da posicao                                     
    
    H = L*sin(x(1));
    dH = [L*cos(x(1)) 0];
    dHt = transpose(dH);
    
    K = P*dHt*(dH*P*dHt + R)^(-1);                                         %Atualizacao do Ganho de Kalman
    Kt = transpose(K);
    
    x = x + K*(z - H);                                                     %Atualizacao da estimativa
    
    P = (I - K*dH)*P*(transpose(I - K*dH)) + K*R*Kt;                       %Atualizacao da covariancia

end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

