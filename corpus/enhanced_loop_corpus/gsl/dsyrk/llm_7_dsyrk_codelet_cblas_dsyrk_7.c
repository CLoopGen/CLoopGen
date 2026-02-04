#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  double alpha;
extern  double *A;
extern  int lda;
extern double *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double *temp_arr = (double*)calloc(N * N, sizeof(double));
if (!temp_arr) return;
for (i = 0; i < N; i++) {
    for (j = 0; j <= i; j++) {
        double temp = 0.;
        for (k = 0; k < K; k++) {
            temp += A[k * lda + i] * A[k * lda + j];
        }
        temp_arr[i * N + j] = temp;
    }
}
for (i = 0; i < N; i++) {
    for (j = 0; j <= i; j++) {
        C[i * ldc + j] += alpha * temp_arr[i * N + j];
    }
}
free(temp_arr);
}
