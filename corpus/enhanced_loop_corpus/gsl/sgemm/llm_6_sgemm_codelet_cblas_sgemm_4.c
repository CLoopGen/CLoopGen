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
    float temp_cache[K];
    for (i = 0; i < n1; i++) {
        for (k = 0; k < K; k++) {
            temp_cache[k] = alpha * F[ldf * k + i];
        }
        for (k = 0; k < K; k++) {
            if (temp_cache[k] != 0.) {
                for (j = 0; j < n2; j++) {
                    C[ldc * i + j] += temp_cache[k] * G[ldg * k + j];
                }
            }
        }
    }
}
