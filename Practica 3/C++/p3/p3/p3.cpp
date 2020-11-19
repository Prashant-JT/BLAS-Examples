# include <cstdlib>
# include <cstdio>
#include <mkl_cblas.h>


void funcion1()
{
	MKL_INT m, n, alpha, lda, incx, beta, incy;
	CBLAS_LAYOUT layout;
	CBLAS_TRANSPOSE trans;
	layout = CblasRowMajor;
	trans = CblasNoTrans;
	m = 3;
	n = 3;
	alpha = 1;
	lda = 3;
	incx = 1;
	beta = 0;
	incy = 1;

	double A[9] = { 7.0, -3.0, 12.0, 2.0, 15.0, -9.0, -4.0, -19.0, 5.0 };
	double x[3] = { -3.0, 9.0, 2.0 };
	double y[3] = { 5.0, 17.0, 11.0 };

	printf("Ejercicio 1: A * x\n");
	cblas_dgemv(layout, trans, m, n, alpha, A, lda, x, incx, beta, y, incy);
	printf("%4.1f\n%4.1f\n%4.1f\n", y[0], y[1], y[2]);

	printf("\nEjercicio 1: 3*A * x + 4 * y\n");
	double Y[3] = { 5.0, 17.0, 11.0 };
	alpha = 3;
	beta = 4;
	cblas_dgemv(layout, trans, m, n, alpha, A, lda, x, incx, beta, Y, incy);
	printf("%4.1f\n%4.1f\n%4.1f\n", Y[0], Y[1], Y[2]);
}

void funcion2()
{
	MKL_INT m, n, alpha, lda, incx, beta, incy;
	CBLAS_LAYOUT layout;
	CBLAS_TRANSPOSE trans;
	layout = CblasColMajor;
	trans = CblasTrans;
	m = 3;
	n = 3;
	alpha = 3;
	lda = 3;
	incx = 1;
	beta = 4;
	incy = 1;

	double A[9] = { 7.0, -3.0, 12.0, 2.0, 15.0, -9.0, -4.0, -19.0, 5.0 };
	double x[3] = { -3.0, 9.0, 2.0 };
	double y[3] = { 5.0, 17.0, 11.0 };

	printf("\nEjercicio 2: Efecto de layout: por columnas y transposicion: si\n");
	cblas_dgemv(layout, trans, m, n, alpha, A, lda, x, incx, beta, y, incy);
	printf("%4.1f\n%4.1f\n%4.1f\n", y[0], y[1], y[2]);

	printf("\nEjercicio 2: Efecto de layout: por columnas y transposicion: no\n");
	double Y1[3] = { 5.0, 17.0, 11.0 };
	layout = CblasColMajor;
	trans = CblasNoTrans;
	cblas_dgemv(layout, trans, m, n, alpha, A, lda, x, incx, beta, Y1, incy);
	printf("%4.1f\n%4.1f\n%4.1f\n", Y1[0], Y1[1], Y1[2]);

	printf("\nEjercicio 2: Efecto de layout: por filas y transposicion: si\n");
	double Y2[3] = { 5.0, 17.0, 11.0 };
	layout = CblasRowMajor;
	trans = CblasTrans;
	cblas_dgemv(layout, trans, m, n, alpha, A, lda, x, incx, beta, Y2, incy);
	printf("%4.1f\n%4.1f\n%4.1f\n", Y2[0], Y2[1], Y2[2]);
}

int main(int argc, char* argv[]) 
{
	funcion1();
	printf("<---------------------------->");
	funcion2();
	//optativo

}