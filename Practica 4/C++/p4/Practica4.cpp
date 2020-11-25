#include <cstdlib>
#include <cstdio>

#include <mkl_cblas.h>

void printMatrix(double* mat, int m, int n) {
	for (int i = 0; i < m; i++)
	{
		printf("%4.1f\t", mat[i]);
		if ((i + 1) % n == 0) {
			printf("\n\t\t");
		}
	}
	printf("\n");
}

void funcion1() {
	MKL_INT m, k, n, alpha, beta, lda, ldb, ldc;
	CBLAS_LAYOUT layout;
	CBLAS_TRANSPOSE transA;
	CBLAS_TRANSPOSE transB;
	layout = CblasRowMajor;
	transA = CblasNoTrans;
	transB = CblasNoTrans;
	m = 3;
	k = 3;
	n = 3;
	alpha = 1;
	beta = 0;
	lda = k;
	ldb = n;
	ldc = n;
	
	double A[9] = {-5.0, 7.0, 11.0, 1.0, -14.0, 3.0, -9.0, 5.0, 16.0};
	double B[9] = {8.0, 15.0, 1.0, -5.0, 16.0, -4.0, 4.0, 10.0, -19.0};
	double C0[9] = {8.0, 9.0, -7.0, 17.0, -3.0, 8.0, -1.0, 4.0, 1.0};

	printf("\tCalculo de A*B:\n\t\t");
	cblas_dgemm(layout, transA, transB, m, n, k, alpha, A, lda, B, ldb, beta, C0, ldc);
	printMatrix(C0, m*n, n);		

	double C1[9] = { 8.0, 9.0, -7.0, 17.0, -3.0, 8.0, -1.0, 4.0, 1.0 };
	transB = CblasTrans;

	printf("\tCalculo de A*Bt':\n\t\t");
	cblas_dgemm(layout, transA, transB, m, n, k, alpha, A, lda, B, ldb, beta, C1, ldc);
	printMatrix(C1, m*n, n);

	double C2[9] = { 8.0, 9.0, -7.0, 17.0, -3.0, 8.0, -1.0, 4.0, 1.0 };
	transB = CblasNoTrans;
	alpha = 2;
	beta = 3;

	printf("\tCalculo de 2*A*B + 3*C:\n\t\t");
	cblas_dgemm(layout, transA, transB, m, n, k, alpha, A, lda, B, ldb, beta, C2, ldc);
	printMatrix(C2, m*n, n);
}

void funcion2() {
	MKL_INT m, k, n, alpha, beta, lda, ldb, ldc;
	CBLAS_LAYOUT layout;
	CBLAS_TRANSPOSE transA;
	CBLAS_TRANSPOSE transB;
	layout = CblasRowMajor;
	transA = CblasNoTrans;
	transB = CblasNoTrans;
	m = 5;
	k = 2;
	n = 5;
	alpha = 6;
	beta = -6;
	lda = k;
	ldb = n;
	ldc = n;

	//Operacion: 6 * M1(5x2) * M2(2x5) - 6 * M3(5x5)
	double M1[10] = { 2.0, -5.0, -4.0, 3.0, 3.0, 3.0, -4.0, -8.0, 7.0, 9.0 };
	double M2[10] = { 5.0, 6.0, -9.0, 6.0, 4.0, -3.0, -6.0, -5.0, 7.0, 2.0 };
	double M3[25] = { -2.0, 3.0, -5.0, -5.0, 3.0, -2.0, 7.0, 6.0, -5.0, 0.0, -2.0, 
		5.0, -5.0, 8.0, 7.0, -1.0, 9.0, -5.0, -6.0, 2.0, -1.0, 0.0, 3.0, 5.0, -3.0 };

	printf("\tCalculo de 6*M1*M2 -6*M3:\n\t\t");
	cblas_dgemm(layout, transA, transB, m, n, k, alpha, M1, lda, M2, ldb, beta, M3, ldc);
	printMatrix(M3, m * n, n);
}


int main(int argc, char* argv[]) {

	printf("Ejercicio 1:\n");
	funcion1();
	printf("Ejercicio 2:\n");
	funcion2();

	char a = std::getchar();
	return 0;
}
