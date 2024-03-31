#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

static double dot_prod_c(double A[], double B[], long long int n) {
	double res = 0;
	for (int i = 0; i < n; i++) {
		res = res + (A[i] * B[i]);
	}
	return res;
}