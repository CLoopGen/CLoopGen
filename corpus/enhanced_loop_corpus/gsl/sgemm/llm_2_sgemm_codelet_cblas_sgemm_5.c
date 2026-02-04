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
for (i = 0; i < n1; i++) {
    for (j = 0; j < n2; j++) {
        float temp = 0.;
        int base_idx_f = i;
        int base_idx_g = ldg * j;
        int idx_c = ldc * i + j;
        for (k = 0; k < K; k++) {
            temp += F[base_idx_f + ldf * k] * G[base_idx_g + k];
        }
        C[idx_c] += alpha * temp;
    }
}
}
