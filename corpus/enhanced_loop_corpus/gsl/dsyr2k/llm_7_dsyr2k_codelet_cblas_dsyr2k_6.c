#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  int K;
extern  double alpha;
extern  double *A;
extern  int lda;
extern  double *B;
extern  int ldb;
extern double *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
double *temp_arr = (double*)calloc(N, sizeof(double));
if (!temp_arr) return;
for (j = 0; j < N; j++) {
    for (i = j; i < N; i++) {
        double temp = 0.0;
        for (k = 0; k < K; k++) {
            temp += A[i * lda + k] * B[j * ldb + k] + B[i * ldb + k] * A[j * lda + k];
        }
        temp_arr[i] = alpha * temp;
    }
    for (i = j; i < N; i++) {
        C[i * ldc + j] += temp_arr[i];
    }
}
free(temp_arr);
}
