#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int K;
extern  float alpha;
extern float *C;
extern  int ldc;
extern int i;
extern int j;
extern int k;
extern int n1;
extern int n2;
extern int ldf;
extern int ldg;
extern  float *F;
extern  float *G;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < K; k++) {
    for (j = 0; j < n2; j++) {
        const float temp_g = G[ldg * k + j];
        if (alpha != 0. && temp_g != 0.) {
            for (i = 0; i < n1; i++) {
                C[ldc * i + j] += alpha * F[ldf * i + k] * temp_g;
            }
        } else if (alpha != 0.) {
            for (i = 0; i < n1; i++) {
                C[ldc * i + j] += alpha * F[ldf * i + k] * temp_g;
            }
        }
    }
}
}
