clear all

%Gera trajetoria no plano

posx(1) = 400;
posy(1) = -300;

velx(1) = 0;
vely(1) = 0;

acelx = 0;
acely = 0;

med_r(1) = 0;
med_phi(1) = 0;

delta_tempo = 1;
sigma_acel = 0.2;
sigma_medicao_posicao = 5;
sigma_medicao_angulo = 0.0087;

for i = 1:1:99
    velx(i+1) = velx(i) + (acelx + randn(1)*sigma_acel)*delta_tempo;
    vely(i+1) = vely(i) + (acely + randn(1)*sigma_acel)*delta_tempo;

    posx(i+1) = posx(i) + velx(i)*delta_tempo;
    posy(i+1) = posy(i) + vely(i)*delta_tempo;

    med_r(i+1) = sqrt(posx(i+1)^2 + posy(i+1)^2) + randn(1)*sigma_medicao_posicao;
    med_phi(i+1) = atan(posx(i+1)/posy(i+1)) + + randn(1)*sigma_medicao_angulo;

end

save medidas_extended01.mat med_r med_phi;