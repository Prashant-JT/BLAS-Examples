#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>

#include <cmath>
#include <ctime>
#include <mkl.h>

using namespace::std;

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

double* generateMatrixDouble(int m, int n) {
	double *X = (double*)mkl_malloc((double)(m*n) * sizeof(double), 64);

	if (X == NULL) { 
		perror("Error malloc"); 
		exit(1); 
	}

	for (int i = 0; i < m*n; i++) {
		X[i] = (double)rand() / (double)RAND_MAX;
	}

	return X;
}

float* generateMatrixFloat(int m, int n) {
	float* X = (float*)mkl_malloc((float)(m*n) * sizeof(float), 32);

	if (X == NULL) {
		perror("Error malloc");
		exit(1);
	}

	for (int i = 0; i < m * n; i++) {
		X[i] = (float)rand() / (float)RAND_MAX;
	}

	return X;
}

void funcion1() {
	double *A = generateMatrixDouble(3, 3);
	double *B = generateMatrixDouble(3, 3);
	double *C = generateMatrixDouble(3, 3);

	printMatrix(A, 3, 3);
	printMatrix(B, 3, 3);
	printMatrix(C, 3, 3);

	mkl_free(A);
	mkl_free(B);
	mkl_free(C);
}

double* funcion2() {
	MKL_INT m, k, n, alpha, beta, lda, ldb, ldc;
	CBLAS_LAYOUT layout;
	CBLAS_TRANSPOSE transA;
	CBLAS_TRANSPOSE transB;
	layout = CblasRowMajor;
	transA = CblasNoTrans;
	transB = CblasNoTrans;
	alpha = 1;
	beta = 0;

	double start, fin = dsecnd();
	double* totalTime = new double[1000/20];
	int p = 0;
	// crea matrices 
	for (int i = 20; i <= 1000; i+=20) {
		m = i;
		k = i;
		n = i;
		lda = k;
		ldb = n;
		ldc = n;
		double* A = generateMatrixDouble(i, i);
		double* B = generateMatrixDouble(i, i);
		double* C = generateMatrixDouble(i, i);


		start = dsecnd();
		// operacion x100
		for (int j = 0; j < 100; j++) {
			cblas_dgemm(layout, transA, transB, m, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
		}
		fin = (dsecnd() - start);
		totalTime[p] = (100/fin)/1e9;		

		printf("Tiempo de ejecucion: ");
		printf("%4.8f para %d x %d \n", totalTime[p], m,n);
		//printMatrix(B, m, n);
		//printf("\n");

		mkl_free(A);
		mkl_free(B);
		mkl_free(C);
		p++;
	}
	return totalTime;
}

double* funcion3() {
	MKL_INT m, k, n, alpha, beta, lda, ldb, ldc;
	CBLAS_LAYOUT layout;
	CBLAS_TRANSPOSE transA;
	CBLAS_TRANSPOSE transB;
	layout = CblasRowMajor;
	transA = CblasNoTrans;
	transB = CblasNoTrans;
	alpha = 1;
	beta = 0;

	double start, fin = dsecnd();
	double* totalTime = new double[1000 / 20];
	int p = 0;
	// crea matrices 
	for (int i = 20; i <= 1000; i += 20) {
		m = i;
		k = i;
		n = i;
		lda = k;
		ldb = n;
		ldc = n;
		double* A = generateMatrixDouble(i, i);
		double* B = generateMatrixDouble(i, i);
		double* C = generateMatrixDouble(i, i);


		start = dsecnd();
		// operacion x100
		for (int j = 0; j < 100; j++) {
			cblas_dgemm(layout, transA, transB, m, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
		}
		fin = (dsecnd() - start);
		totalTime[p] = (100 / fin) / 1e9;

		printf("Tiempo de ejecucion: ");
		printf("%4.8f para %d x %d \n", totalTime[p], m, n);
		//printMatrix(B, m, n);
		//printf("\n");

		mkl_free(A);
		mkl_free(B);
		mkl_free(C);
		p++;
	}
	return totalTime;
}

double* funcion4() {
	MKL_INT m, k, n, alpha, beta, lda, ldb, ldc;
	CBLAS_LAYOUT layout;
	CBLAS_TRANSPOSE transA;
	CBLAS_TRANSPOSE transB;
	layout = CblasRowMajor;
	transA = CblasNoTrans;
	transB = CblasNoTrans;
	alpha = 1;
	beta = 0;

	double start, fin = dsecnd();
	double* totalTime = new double[1000/20];
	int p = 0;

	// crea matrices 
	for (int i = 20; i <= 1000; i+=20) {
		m = i;
		k = i;
		n = i;
		lda = k;
		ldb = n;
		ldc = n;
		float* A = generateMatrixFloat(i, i);
		float* B = generateMatrixFloat(i, i);
		float* C = generateMatrixFloat(i, i);


		start = dsecnd();
		// operacion x100
		for (int j = 0; j < 100; j++) {
			cblas_sgemm(layout, transA, transB, m, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
		}
		fin = (dsecnd() - start);
		totalTime[p] = (100 / fin) / 1e9;

		printf("Tiempo de ejecucion: ");
		printf("%4.8f para %d x %d \n", totalTime[p], m, n);
		//printMatrix(B, m, n);
		//printf("\n");

		mkl_free(A);
		mkl_free(B);
		mkl_free(C);
		p++;
	}
	return totalTime;
}

void saveFile(int size, double* vect, string name) {
	ofstream myfile(name);
	if (myfile.is_open())
	{
		for (int x = 0; x < size; x++) {
			if (x == size - 1) {
				myfile << vect[x];
			} else {
				myfile << vect[x] << ", ";
			}
		}
		myfile.close();
	}
}

double* funcion5() {
	MKL_INT m, k, n, alpha, beta, lda, ldb, ldc;
	CBLAS_LAYOUT layout;
	CBLAS_TRANSPOSE transA;
	CBLAS_TRANSPOSE transB;
	layout = CblasRowMajor;
	transA = CblasNoTrans;
	transB = CblasNoTrans;
	alpha = 1;
	beta = 0;

	double start, fin = dsecnd();
	double* totalTime = new double[1000 / 20];
	int p = 0;
	// crea matrices 
	for (int i = 20; i <= 1000; i += 20) {
		m = i;
		k = i;
		n = i;
		lda = k;
		ldb = n;
		ldc = n;
		double* A = generateMatrixDouble(i, i);
		double* B = generateMatrixDouble(i, i);
		double* C = generateMatrixDouble(i, i);


		start = dsecnd();
		// operacion x100
		for (int j = 0; j < 100; j++) {
			cblas_dgemm(layout, transA, transB, m, n, k, alpha, A, lda, B, ldb, beta, C, ldc);
		}
		totalTime[p] = (dsecnd() - start) / 100;

		printf("Tiempo de ejecucion: ");
		printf("%4.8f para %d x %d \n", totalTime[p], m, n);
		//printMatrix(B, m, n);
		//printf("\n");

		mkl_free(A);
		mkl_free(B);
		mkl_free(C);
		p++;
	}
	return totalTime;
}

int main(int argc, char* argv[]) {
	srand((unsigned int)time(NULL));
	/*
	printf("Ejercicio 1:\n");	
	funcion1();
	
	printf("Ejercicio 2:\n");
	double* timeDouble = funcion2();
	saveFile(1000/20, timeDouble, "Ejercicio2.csv");
	*/
	
	printf("Ejercicio 3:\n");
	double* timeDoubleParallel = funcion3();
	saveFile(1000/20, timeDoubleParallel, "Ejercicio3.csv");
	
	/*
	printf("Ejercicio 4:\n");
	double* timeFloat = funcion4();
	saveFile(1000/20, timeFloat, "Ejercicio4.csv");
	
	printf("Ejercicio 5:\n");
	double* timeDoubleMean = funcion5();
	saveFile(1000 / 20, timeDoubleMean, "Ejercicio5.csv");
	*/
	char a = std::getchar();
	return 0;
}