clear all

%Gera trajetoria no plano

posx(1) = 400;
posy(1) = -300;

velx(1) = 0;
vely(1) = 0;

acelx = 0;
acely = 0;

medx(1) = 0;
medy(1) = 0;

for i = 1:1:99
    velx(i+1) = velx(i) + (acelx + randn(1)*sigma_acel)*delta_tempo;
    vely(i+1) = vely(i) + (acely + randn(1)*sigma_acel)*delta_tempo;

    posx(i+1) = posx(i) + velx(i)*delta_tempo;
    posy(i+1) = posy(i) + vely(i)*delta_tempo;

    %REALIZAR MEDICAO DE R E PHI, A PARTIR DO ARQUIVO PRESENTE
end

save medidas_v1.mat r1 theta