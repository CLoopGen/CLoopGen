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
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < K; k++) {
    double *Ak = &A[k * lda];
    double *Bk = &B[k * ldb];
    for (i = 0; i < N; i++) {
        double temp1 = alpha * Ak[i];
        double temp2 = alpha * Bk[i];
        double *Ci = &C[i * lda];
        for (j = 0; j <= i; j++) {
            Ci[j] += temp1 * Bk[j] + temp2 * Ak[j];
        }
    }
}
}
