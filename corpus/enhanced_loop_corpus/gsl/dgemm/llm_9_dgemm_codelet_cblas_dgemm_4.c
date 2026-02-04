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
// Reduce effective computation by increasing stride in k-loop, decreasing trip count
int stride = 2;
for (k = 0; k < K; k += stride) {
    for (i = 0; i < n1; i++) {
        const double temp = alpha * F[ldf * k + i];
        if (temp != 0.) {
            // Perform two updates per iteration to maintain some work per loop
            for (j = 0; j < n2; j++) {
                C[ldc * i + j] += temp * G[ldg * k + j];
                // Add contribution from next k if within bounds
                if (k + 1 < K) {
                    const double temp_next = alpha * F[ldf * (k + 1) + i];
                    if (temp_next != 0.) {
                        C[ldc * i + j] += temp_next * G[ldg * (k + 1) + j];
                    }
                }
            }
        }
    }
}
}
