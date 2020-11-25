clear; clc;

%first();
%second();
fifth();

function X = randomMatrix(m, n)
    X = double(rand(m,n));
end

function first()
    disp("Primer ejercicio:");
    disp(" ");
    A = randomMatrix(3, 3);
    disp(A);
    B = randomMatrix(3, 3);
    disp(B);
    C = randomMatrix(3, 3);
    disp(C);
    disp(" ");
end

function second()
    max = 250;
    min = 2;
    nOps = 100;
    opTimes = zeros(1, 100);
    disp("Segundo ejercicio");
    disp(" ");
    
    for i = min:max
        tic;
        for j = 1:nOps
            res = randomMatrix(i, i)*randomMatrix(i, i);
        end
        opTimes(i) = toc/nOps;
        fprintf("El tiempo para [%dX%d] es: %4.6f s.\n", i, i, opTimes(i));
    end
end

function fifth()
    max = 1000;
    min = 100;
    jump = 20;
    nOps = 100;
    opTimes = zeros(1, 45);
    cont = 1;
    disp("Quinto ejercicio");
    disp(" ");
    
    for i = min:jump:max
        tic;
        for j = 1:nOps
            res = randomMatrix(i, i)*randomMatrix(i, i);
        end
        opTimes(cont) = toc/nOps;
        % fprintf("El tiempo para [%dX%d] es: %4.6f s.\n", i, i, opTimes(cont));
        cont = cont +1;
    end
    csvwrite('Ejercicio5ML.csv', opTimes);
end
