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
    const float alpha_val = alpha;
    const int f_base = ldf * k;
    const int g_base = ldg * k;
    for (i = 0; i < n1; i++) {
        const float f_val = F[f_base + i];
        if (f_val != 0.) {
            const float temp = alpha_val * f_val;
            float * restrict c_row = &C[ldc * i];
            const float * restrict g_row = &G[g_base];
            for (j = 0; j < n2; j++) {
                c_row[j] += temp * g_row[j];
            }
        }
    }
}
}
