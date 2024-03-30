#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "cfunc.c"

extern double dot_prod_asm(double A[], double B[], long long int n);

int main() {
	double A[] = { 2.5, 3, 4.5 };
	double B[] = { 1, 1, 1 };
	long long int n = 3;
	double sdot = 0; //for this, sdot should be equal to 10 (2.5*1+3*1+4.5*1=10)

	sdot = dot_prod_c(A, B, n);
	printf("C - Dot Product: %lf\n", sdot);

	sdot = dot_prod_asm(A, B, n);
	printf("ASM - Dot Product: %lf\n", sdot);
	return 0;
}