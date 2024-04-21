close all
clear all

%Gera medidas do sistema

sigma_med_pos = 0.01;
L = 0.5;

for i=1:1:99
    theta = rand()*2*pi;                                                   %Gera angulo theta entre 0 e 2*pi
    med_ang(i) = (L*sin(theta) + randn(1))*sigma_med_pos;                  %Posicao em relacao ao angulo
end
 
save medidas_extended02.mat med_ang;