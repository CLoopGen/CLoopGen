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
    for (k = 0; k < K; k++) {
        const float temp = alpha * F[ldf * i + k];
        if (temp != 0.) {
            float * restrict c_row = &C[ldc * i];
            const float * restrict g_row = &G[ldg * k];
            for (j = 0; j < n2; j++) {
                c_row[j] += temp * g_row[j];
            }
        }
    }
}
}
