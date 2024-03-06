%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% DADOS INICIAIS %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

sigma_acel = 0.2*0.2;
sigma_medicao = 3*3;

x = [0 ; 0 ; 0 ; 0 ; 0 ; 0];

Q = [0.25 0.5 0.5 0 0 0 ; 0.5 1 1 0 0 0 ; 0.5 1 1 0 0 0 ; 0 0 0 0.25 0.5 0.5 ; 0 0 0 0.5 1 1 ; 0 0 0 0.5 1 1]*(sigma_acel);

P = [500 0 0 0 0 0 ; 0 500 0 0 0 0 ; 0 0 500 0 0 0 ; 0 0 0 500 0 0 ; 0 0 0 0 500 0 ; 0 0 0 0 0 500];

F = [1 1 0.5 0 0 0 ; 0 1 1 0 0 0 ; 0 0 1 0 0 0 ; 0 0 0 1 1 0.5 ; 0 0 0 0 1 1 ; 0 0 0 0 0 1];

H = [1 0 0 0 0 0 ; 0 0 0 1 0 0 ];

R = [sigma_medicao 0 ; 0 sigma_medicao];

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% PREDICOES %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

Ft = transpose(F);
Ht = transpose(H);

x = F*x;

P = F*P*Ft + Q;

z = [301.5 ; -401.46];

K = P*Ht*(H*P*Ht + R)^(-1);
