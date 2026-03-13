#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1024

double A[N][N];
double B[N][N];
double C[N][N];

int main(){
	int i,j,k;
	clock_t start, end;
	double total_time;

	//populate the matrices with random values between 0.0 and 1.0

	for (i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			A[i][j] = (double) rand() / (double) RAND_MAX;
			B[i][j] = (double) rand() / (double) RAND_MAX;
			C[i][j] = 0;
		}
	}

	start = clock();
	//matrix multipication
	for(i = 0; i < N; i++){
		for(j = 0;  j < N; j++){
			for(k = 0; k < N; k++){
				C[i][j] += A[i][k]*B[k][j];
			}
		}
	}
	end = clock();
	total_time = (double)(end-start) / CLOCKS_PER_SEC;
	printf("Elapsed time in seconds : %.3lf \n",total_time);
}  