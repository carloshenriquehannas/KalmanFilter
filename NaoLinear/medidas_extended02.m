close all
clear all

%Gera medidas do sistema

sigma_med_pos = 0.01;
theta =  0.0873;
L = 0.5;

for i=1:1:99
    med_pos(i) = (L*sin(theta) + randn(1))*sigma_med_pos;
end
 
save medidas_extended02.mat med_pos;