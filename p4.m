% Definir tres matrices (A, B y C) de dimension 3x3 y realizar las operaciones
A = [-5.0 7.0 11.0; 1.0 -14.0 3.0; -9.0 5.0 16.0];
B = [8.0 15.0 1.0; -5.0 16.0 -4.0; 4.0 10.0 -19.0];
C = [8.0 9.0 -7.0; 17.0 -3.0 8.0; -1.0 4.0 1.0];

% A*B
AB = A*B

% A*Bt
ABt = A*transpose(B)

% 2*A*B + 3*C
ABC = 2*A*B + 3*C

% [OPTATIVO] Realizar una operacion que implique matrices no cuadradas, y que genere como resultado una matriz de 5x5
M1 = [2.0 -5.0; -4.0 3.0; 3.0 3.0; -4.0 -8.0; 7.0 9.0];
M2 = [5.0 6.0 -9.0 6.0 4.0; -3.0 -6.0 -5.0 7.0 2.0];
%M3 =  [-2.0 3.0; 5.0 -5.0];

% 2*M3*M2 + 4*M1
opt = 2*M1*3*M2