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
for (i = 0; i < N; i++) {
    for (j = 0; j <= i; j++) {
        double temp = 0.;
        const double *Ai = &A[i]; // Base pointer for column i
        const double *Aj = &A[j]; // Base pointer for column j
        for (k = 0; k < K; k++) {
            temp += Ai[k * lda] * Aj[k * lda];
        }
        C[i * ldc + j] += alpha * temp;
    }
}
}
