#include <cstdio>
#include <cstdlib>
#include <cmath>

#include <mkl_cblas.h>

//Vector1 (3.0,-1.0,-3.0), Vector2 (4.0,3.0,3.0)
void funcion1() {
	MKL_INT inc, n;

	n = 3;
	inc = 1;

	double v1[3] = { 3.0, -1.0, -3.0 };
	double v2[3] = { 4.0, 3.0, 3.0 };

	double res = cblas_ddot(n, v1, inc, v2, inc);

	printf("\tV1: {%1.1f, %1.1f, %1.1f}\n\tV2: {%1.1f, %1.1f, %1.1f}\n", v1[0], v1[1], v1[2], v2[0], v2[1], v2[2]);
	printf("\tResultado del producto escalar: %1.1f\n", res);

	if (res == 0.0) {
		printf("\tLos vectores son ortogonales");
	}
	else {
		printf("\tLos vectores no son ortogonales");
	}

}


double* convert(char* str) {
	double* res = new double[11];

	for (int i = 0; i < 11; i++) {
		res[i] = (double)str[i];
	}
	return res;
}

void funcion2() {
	MKL_INT n, inc, mult;
	n = 11;
	inc = 1;
	mult = 3;

	/**
	** Se usa la funci�n axpy(), ax + y,
	** "a" es el escalar (3); "x" es el
	** vector "surname"; e "y" es el vector
	** "name". El resultado final se 
	** sobreescribe en el vector "name".
	**/
	char nameC[11] = "jose maria"; //Caracter nulo al final +1.
	double* name = convert(nameC); 
	char surnameC[11] = "jeswani000"; 
	double* surname = convert(surnameC);

	cblas_daxpy(n, mult, surname, inc, name, inc);
	
	int op;

	/**
	** Min�sculas ASCII => 97=a, 122=z => 122-97=25 caracteres.
	** Se realiza el m�dulo, y se desplaza 97 para obtener un
	** valor correcto en el rango (91, 122).
	**/
	printf("\tValores resultantes de las operaciones (valor=>ASCII):\n\t\t{");
	for (int a = 0; a < n; a++) {
		op = (int(name[a]) % (122 - 97)) + 97;;
		printf("%d=>%d", int(name[a]), op);
		if (a != 10) printf(", ");
	}
	printf("}\n");

	printf("\tValores ASCII mapeados en 'a'..'z':\n\t\t{");
	for (int a = 0; a < n; a++) {
		op = (int(name[a]) % (122 - 97)) + 97;;
		printf("%c", op);
		if (a != 10) printf(", ");
	}
	printf("}");
}

/**
** Ejercicio 4:
** El incremento especifica el espacio guardado entre �ndice
** e �ndice, por tanto, si se especifica un incremento de 1,
** el array ser� recorrido secuencialmente empezando por el 
** primer elemento; si se especifica un 2, el array ser� 
** recorrido dando saltos de 2 en 2, �ndice 0, �ndice 2, 
** �ndice 4... Sin embargo, el incremento tambi�n modifica el
** valor m�ximo hasta el que se recorre: (1 + (n -1)*abs (incx)),
** donde "n" es el n�mero de elementos del vector, e "incx" el 
** incremento, por tanto, si �ste �ltimo es 1, el m�ximo coincide 
** con el n�mero de elementos del vector, pero si �ste es 2 
** el m�ximo ser� el doble del n�mero de elementos menos 1. Por ello,
** se debe tener cuidado al especificar este valor pues puede generar
** c�lculos err�neros accediendo a posiciones de memoria incorrectos.
**
** Por ejemplo, si en este ejercicio se especifica un incremento
** distinto a 1 sin modificar el n�mero de elementos, se obtiene un
** valor muy grande que es incorrecto. Si se desea iterar sobre los 
** �ndices pares (2), entonces el n�mero de elementos debe reducirse
** a la mitad (4).
** Si se especifica un incremento de 0, entonces se realiza la norma
** �nicamente del primer elemento del vector (date[0] = 2.0).
**/

void funcion3() {
	MKL_INT n, inc;
	n = 8;
	inc = 1;

	double date[8] = {2.0, 4.0, 0.0, 2.0, 1.0, 9.0, 9.0, 9.0};

	double norm2 = cblas_dnrm2(n, date, inc);

	printf("\tEL valor de la norma 2 es: %f\n", norm2);

	double res = std::fmod(norm2, 11.0);

	printf("\tLa nota final de MNC es: %f", res);
}


int main(int argc, char* argv[]) {

	printf("Ejercicio 1:\n");
	funcion1();
	printf("\n\nEjercicio 2:\n");
	funcion2();
	printf("\n\nEjercicio 3:\n");
	funcion3();

	char a = std::getchar();
	return 0;
}