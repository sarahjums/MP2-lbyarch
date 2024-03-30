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

void run_dot_product(n) {

	srand(time(NULL));
	printf("Running for: %d\n", n);
	double sdot = 0;

	double* A = (double*)malloc(n * sizeof(double));
	double* B = (double*)malloc(n * sizeof(double));

	for (int i = 0; i < n; i++) {
		A[i] = generate_random_double();
		B[i] = generate_random_double();
	}
	
	sdot = dot_prod_c(A, B, n);
	printf("C - Dot Product: %lf\n", sdot);

	sdot = dot_prod_asm(A, B, n);
	printf("ASM - Dot Product: %lf\n", sdot);

	free(A);
	free(B);
}

int main() {
	double A[] = { 2.5, 3, 4.5 };
	double B[] = { 1, 1, 1 };
	long long int n = 3;
	double sdot = 0; //for this, sdot should be equal to 10 (2.5*1+3*1+4.5*1=10)

	// 1048576 = 2^20
	run_dot_product(1048576);
	// 16777216 = 2^24
	run_dot_product(16777216);
	// 1073741824 = 2^30
	run_dot_product(1073741824);

	
	return 0;
}

