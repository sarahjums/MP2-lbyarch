#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "cfunc.c"

extern double dot_prod_asm(double A[], double B[], long long int n);

double generate_random_double() {
	int random_int = rand() % 1000;
	double random_double = (double)random_int / 100.0;
	return random_double;
}

int main() {
	double A[] = { 2.5, 3, 4.5 };
	double B[] = { 1, 1, 1 };
	long long int n = 3;
	double sdot = 0; //for this, sdot should be equal to 10 (2.5*1+3*1+4.5*1=10)

	srand(time(NULL));



	// 1048576 = 2^20
	double* A20 = (double*)malloc(1048576 * sizeof(double));
	double* B20 = (double*)malloc(1048576 * sizeof(double));

	for (int i = 0; i < 1048576; i++) {
		A20[i] = generate_random_double();
		B20[i] = generate_random_double();
	}

	// run and time the algos here

	free(A20);
	free(B20);



	// 16777216 = 2^24
	double* A24 = (double*)malloc(16777216 * sizeof(double));
	double* B24 = (double*)malloc(16777216 * sizeof(double));

	for (int i = 0; i < 16777216; i++) {
		A24[i] = generate_random_double();
		B24[i] = generate_random_double();
	}

	// run and time the algos here

	free(A24);
	free(B24);



	// 1073741824 = 2^30
	double* A30 = (double*)malloc(1073741824 * sizeof(double));
	double* B30 = (double*)malloc(1073741824 * sizeof(double));

	for (int i = 0; i < 1073741824; i++) {
		A30[i] = generate_random_double();
		B30[i] = generate_random_double();
	}

	// run and time the algos here

	printf("Vector A: ");
	for (int i = 0; i < 1073741824; i++) {
		printf("%lf ", A30[i]);
	}
	printf("\n");

	free(A30);
	free(B30);


	sdot = dot_prod_c(A, B, n);
	printf("C - Dot Product: %lf\n", sdot);

	sdot = dot_prod_asm(A, B, n);
	printf("ASM - Dot Product: %lf\n", sdot);
	return 0;
}

