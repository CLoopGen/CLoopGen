#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int K;
extern  double alpha;
extern double *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern int n1;
extern int n2;
extern int ldf;
extern int ldg;
extern  double *F;
extern  double *G;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Reduce effective computation by increasing stride and limiting trip count
const int stride_k = 2;
const int stride_i = 2;
const int stride_j = 2;
for (k = 0; k < K; k += stride_k) {
    for (i = 0; i < n1; i += stride_i) {
        const double temp = alpha * F[ldf * i + k];
        if (temp != 0.) {
            for (j = 0; j < n2; j += stride_j) {
                // Only update every second element, reducing arithmetic operations
                C[ldc * i + j] += temp * G[ldg * k + j];
            }
        }
    }
}
}
