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
for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j++) {
        double temp = 0.;
        const int base_idx_f = ldf * i;
        const int base_idx_c = ldc * i + j;
        for (k = 0; k < K; k++) {
            temp += F[base_idx_f + k] * G[ldg * j + k];
        }
        C[base_idx_c] += alpha * temp;
    }
}
}
