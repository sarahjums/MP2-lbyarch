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

	double* A = (double*)malloc(n * sizeof(double));
	double* B = (double*)malloc(n * sizeof(double));

	for (long long int i = 0; i < n; i++) {
		A[i] = generate_random_double();
		B[i] = generate_random_double();
	}

	clock_t start_c, start_asm;
	clock_t end_c, end_asm;

	double time_taken_c, time_taken_asm;

	double total_time_c = 0.0;
	double total_time_asm = 0.0;

	double c_sdot = 0.0;
	double asm_sdot = 0.0;

	for (long long int i = 0; i < 30; i++){//run 30 times
		start_c = clock();
		c_sdot = dot_prod_c(A, B, n);
		end_c = clock();
		time_taken_c = ((double)(end_c - start_c)) / CLOCKS_PER_SEC;
		total_time_c += time_taken_c;


		start_asm = clock();
		asm_sdot = dot_prod_asm(A, B, n);
		end_asm = clock();
		time_taken_asm = ((double)(end_asm - start_asm)) / CLOCKS_PER_SEC;
		total_time_asm += time_taken_asm;
	}

	double avg_time_c = total_time_c / 30;
	double avg_time_asm = total_time_asm / 30;

	printf("C - Dot Product: %lf (Time: %lf seconds)\n", c_sdot, avg_time_c);
	printf("x86-64 ASM - Dot Product: %lf (Time: %lf seconds)\n\n", asm_sdot, avg_time_asm);

	free(A);
	free(B);
}

int main() {
	// 1048576 = 2^20
	run_dot_product(1048576);
	// 16777216 = 2^24
	run_dot_product(16777216);
	// 1073741824 = 2^30
	run_dot_product(1073741824);

	
	return 0;
}

