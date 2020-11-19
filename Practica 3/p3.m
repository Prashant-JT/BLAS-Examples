clear; clc;
% Operaciones a realizar con A = Matriz; X,Y = vector:
% A*X
% 3*A*X + 4*Y

global A X Y;
A = [7.0 -3.0 12.0; 2.0 15.0 -9.0; -4.0 -19.0 5.0];
X = [-3.0 9.0 2.0];
Y = [5.0 17.0 11.0];

disp("Ejercicio 1:");
first();
disp(" ");
disp("Ejercicio 2:");
second();

function first()
    global A X Y;    
    aRes = A*X';
    bRes = 3*A*X' + 4*Y';
    
    disp("A*X =");
    disp("{");
    fprintf("%4.1f\n ", aRes);
    disp("}");      
    disp(" ");
    disp("3*A*X + 4*Y =");
    disp("{");
    fprintf("%4.1f\n", bRes);
    disp("}");
end

%{
Matlab recorre por filas, por lo que en el primer
ejercicio se experimentó con la matriz no transpuesta
y por filas.
Por tanto, si se transpone la matriz, y además se 
recorre por columnas, se estaría realizando la misma
operación que en el primer apartado.
Así que lo que se realizará en este ejercicio será
transponer la matriz y recorrer por filas, con lo que
se obtiene nuevos valores que coinciden con los obtenidos
en CBLAS. Además, si la matriz no es transpuesta pero se
recorre por columnas, entonces se obtiene el mismo 
resultado que la prueba anterior.
Así que basta con transponer la matriz para cubrir 
dos de las cuatros posibilidades. Mientras las otras
dos ya han sido cubiertas en el apartado anterior.
%}
function second()
    global A X Y;
    
    bRes = 3*A'*X' + 4*Y';
    
    disp("3*A*X + 4*Y =");
    disp("{");
    fprintf("%4.1f\n", bRes);
    disp("}");
end

