clear; clc;

valuesMeanCPP = [0, csvread('tiemposPromedio/Ejercicio5CPP.csv')];
valuesMeanML = [0, csvread('tiemposPromedio/Ejercicio5ML.csv')];
valuesMeanPYTHON = [0, csvread('tiemposPromedio/Ejercicio5PYTHON.csv')];
valuesMeanJAVA = [0, csvread('tiemposPromedio/Ejercicio5JAVA.csv')];

dims = [0, (100:20:1000)];

figure, plot(dims, valuesMeanCPP, '-r', dims, valuesMeanML, '-b', dims, valuesMeanPYTHON, '-k', dims, valuesMeanJAVA, '-g');
%figure, plot(dims, valuesMeanCPP, '-r', dims, valuesMeanML, '-b', dims, valuesMeanPYTHON, '-k');
title('Comparativa tiempo promedio Double-Secuencial');
legend({'C++','MATLAB', 'PYTHON', 'JAVA'}, 'Location', 'NorthWest');
%legend({'C++','MATLAB', 'PYTHON'}, 'Location', 'NorthWest');
ylabel('Tiempo promedio (s)');
xlabel('Dimensiones matriz cuadrada');
grid();