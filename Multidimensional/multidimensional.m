%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% DADOS INICIAIS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

sigma_acel = 0.2*0.2;
sigma_medicao = 3*3;

x = zeros(6, 1);                                        %Inicializacao da matriz de estimativa

Q = [0.25 0.5 0.5 0 0 0 ; 0.5 1 1 0 0 0 ; 0.5 1 1 0 0 0 ; 0 0 0 0.25 0.5 0.5 ; 0 0 0 0.5 1 1 ; 0 0 0 0.5 1 1]*(sigma_acel);

P = [500 0 0 0 0 0 ; 0 500 0 0 0 0 ; 0 0 500 0 0 0 ; 0 0 0 500 0 0 ; 0 0 0 0 500 0 ; 0 0 0 0 0 500];

F = [1 1 0.5 0 0 0 ; 0 1 1 0 0 0 ; 0 0 1 0 0 0 ; 0 0 0 1 1 0.5 ; 0 0 0 0 1 1 ; 0 0 0 0 0 1];

H = [1 0 0 0 0 0 ; 0 0 0 1 0 0 ];

R = [sigma_medicao 0 ; 0 sigma_medicao];

I = eye(6);                                             %Matriz identidade 6x6

Ft = transpose(F);
Ht = transpose(H);

z = zeros(2, 1);                                        %Inicializacao da matriz de medicao

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%Laco de repeticao para medicao e estimacao de i fatores
for i = 1:2

    x = F*x;                                            %Predicao da estimativa 
    P = F*P*Ft + Q;                                     %Predicao da covariancia

    Entrada da matriz z pelo usuario
    for j = 1:2
        z(j) = input(sprintf('Digite o valor para a posição (%d, 1) da matriz: ', j));
    end                       

    K = P*Ht*(H*P*Ht + R)^(-1);                         %Predicao do ganho de Kalman
    Kt = transpose(K);                                  %Atualizacao da matriz transposta do ganho de Kalman                                  

    x = x + K*(z - H*x);                                %Atualizacao da matriz de estimativa
    P = (I - K*H)*P*(transpose(I - K*H)) + K*R*Kt;      %Atualizacao da matriz de covariancia

    disp(x)                                             %Print da matriz de estimativa

end
