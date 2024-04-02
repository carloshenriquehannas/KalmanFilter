clear all

% Gera trajetoria no plano

acelx = 0.3;
acely = 0.3;

posx(1) = 0;
posy(1) = 0;

velx(1) = 0;
vely(1) = 0;

medx(1) = 0;
medy(1) = 0;

DT = 1;

for i=1:1:99
    velx(i+1) = velx(i) + (acelx + randn(1)*0.2)*DT;
    vely(i+1) = vely(i) + (acely + randn(1)*0.2)*DT;
    
    posx(i+1) = posx(i) + velx(i)*DT;
    posy(i+1) = posy(i) + vely(i)*DT;
    
    medx(i+1) = posx(i+1) + randn(1)*3;
    medy(i+1) = posy(i+1) + randn(1)*3;
end

save medidas_v1.mat medx medy;

    
