clear; clc;

valuesDoubleSeq = csvread('tiemposGFLOPS/Ejercicio2.csv');
valuesDoublePara = csvread('tiemposGFLOPS/Ejercicio3.csv');

valuesFloatSeq = csvread('tiemposGFLOPS/Ejercicio4Seq.csv');
valuesFloatPara = csvread('tiemposGFLOPS/Ejercicio4Para.csv');

dims = (100:20:1000);

figure, plot(dims, valuesDoubleSeq, '-r', dims, valuesFloatSeq, '-b');
title('Comparativa GFLOPS en Secuencial');
legend({'Tipo Double','Tipo Float'});
ylabel('GFLOPS');
xlabel('Dimensiones matriz cuadrada');
grid();

axes('position',[.65 .175 .25 .25]);
box on;
zoomIndex = (dims < 1000) & (dims > 600);
plot(dims(zoomIndex), valuesDoubleSeq(zoomIndex), '-r', dims(zoomIndex), valuesFloatSeq(zoomIndex), '-b');
grid();
axis tight;

figure, plot(dims, valuesDoublePara, '-r', dims, valuesFloatPara, '-b');
title('Comparativa GFLOPS en Paralelo');
legend({'Tipo Double','Tipo Float'});
ylabel('GFLOPS');
xlabel('Dimensiones matriz cuadrada');
grid();

axes('position',[.65 .175 .25 .25]);
box on;
zoomIndex = (dims < 1000) & (dims > 600);
plot(dims(zoomIndex), valuesDoublePara(zoomIndex), '-r', dims(zoomIndex), valuesFloatPara(zoomIndex), '-b');
grid();
axis tight;