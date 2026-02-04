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
for (i = 0; i < n1; i += 2) {
    for (j = 0; j < n2; j += 2) {
        for (k = 0; k < K; k++) {
            double f_val = F[ldf * k + i];
            double f_val_i1 = (i+1 < n1) ? F[ldf * k + i + 1] : 0.;
            double g_val = G[ldg * j + k];
            double g_val_j1 = (j+1 < n2) ? G[ldg * (j+1) + k] : 0.;

            if (i < n1 && j < n2)
                C[ldc * i + j] += alpha * f_val * g_val;
            if (i+1 < n1 && j < n2)
                C[ldc * (i+1) + j] += alpha * f_val_i1 * g_val;
            if (i < n1 && j+1 < n2)
                C[ldc * i + (j+1)] += alpha * f_val * g_val_j1;
            if (i+1 < n1 && j+1 < n2)
                C[ldc * (i+1) + (j+1)] += alpha * f_val_i1 * g_val_j1;
        }
    }
}
}
