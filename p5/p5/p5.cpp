#include <cstdlib>
#include <cstdio>

#include <cmath>
#include <ctime>
#include <mkl.h>

void printMatrix(double* mat, int m, int n) {
	printf("\t");
	for (int i = 0; i < m*n; i++)
	{
		printf("%4.5f\t", mat[i]);
		if ((i + 1) % n == 0) {
			printf("\n\t");
		}
	}
	printf("\n");
}

double* generateMatrix(int m, int n) {
	double *X = (double*)mkl_malloc(m*n* sizeof(double), 64);

	if (X == NULL) { 
		perror("Error malloc"); 
		exit(1); 
	}

	for (int i = 0; i < m*n; i++) {
		X[i] = (double)rand() / (double)RAND_MAX;
	}

	return X;
}

void funcion1() {
	double *A = generateMatrix(3, 3);
	double *B = generateMatrix(3, 3);
	double *C = generateMatrix(3, 3);

	printMatrix(A, 3, 3);
	printMatrix(B, 3, 3);
	printMatrix(C, 3, 3);

	mkl_free(A);
	mkl_free(B);
	mkl_free(C);
}

void funcion2() {
	MKL_INT m, k, n, alpha, beta, lda, ldb, ldc;
	CBLAS_LAYOUT layout;
	CBLAS_TRANSPOSE transA;
	CBLAS_TRANSPOSE transB;
	layout = CblasRowMajor;
	transA = CblasNoTrans;
	transB = CblasNoTrans;
	alpha = 1;
	beta = 0;

	clock_t start, fin;
	double totalTime = 0;

	// crea matrices 
	for (int i = 2; i < 1000; i++) {
		m = i;
		k = i;
		n = i;
		lda = k;
		ldb = n;
		ldc = n;
		double* A = generateMatrix(i, i);
		double* B = generateMatrix(i, i);
		double* C = generateMatrix(i, i);


		start = clock();
		// operacion x100
		for (int j = 0; j < 100; j++) {
			cblas_dgemm(layout, transA, transB, m, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
		}
		fin = clock();
		totalTime = (fin - start) / (float)CLOCKS_PER_SEC;

		printf("Tiempo de ejecucion: ");
		printf("%f para %d x %d \n", totalTime/100, m,n);
		//printMatrix(B, m, n);
		//printf("\n");

		mkl_free(A);
		mkl_free(B);
		mkl_free(C);
	}

}


int main(int argc, char* argv[]) {
	printf("Ejercicio 1:\n");
	srand((unsigned int)time(NULL));
	funcion1();
	
	printf("Ejercicio 2:\n");
	funcion2();

	char a = std::getchar();
	return 0;
}