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
for (k = 0; k < K; k++) {
    for (i = 0; i < n1; i++) {
        const double temp = alpha * F[ldf * i + k];
        if (temp != 0.) {
            j = 0;
            // Unroll loop by factor of 4 for higher computational intensity
            int remainder = n2 % 4;
            for (; j < n2 - remainder; j += 4) {
                C[ldc * i + j]     += temp * G[ldg * k + j];
                C[ldc * i + j + 1] += temp * G[ldg * k + j + 1];
                C[ldc * i + j + 2] += temp * G[ldg * k + j + 2];
                C[ldc * i + j + 3] += temp * G[ldg * k + j + 3];
            }
            // Handle remaining elements
            for (; j < n2; j++) {
                C[ldc * i + j] += temp * G[ldg * k + j];
            }
        }
    }
}
}
