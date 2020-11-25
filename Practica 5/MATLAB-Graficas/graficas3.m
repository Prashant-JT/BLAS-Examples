clear; clc;

valuesSeq = csvread('tiemposGFLOPS/Ejercicio2.csv');
valuesPara = csvread('tiemposGFLOPS/Ejercicio3.csv');

dims = (100:20:1000);

figure, plot(dims, valuesSeq, '-r', dims, valuesPara, '-b');
title('Comparativa GFLOPS tipo Double');
legend({'Secuencial','Paralelo'});
ylabel('GFLOPS');
xlabel('Dimensiones matriz cuadrada');
grid();

axes('position',[.65 .175 .25 .25]);
box on;
zoomIndex = (dims < 1000) & (dims > 600);
plot(dims(zoomIndex), valuesSeq(zoomIndex), '-r', dims(zoomIndex), valuesPara(zoomIndex), '-b');
grid();
axis tight;
