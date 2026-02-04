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
    float temp_storage[256]; // Local storage to modify data dependency pattern
    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            temp_storage[j] = 0.0f; // Initialize per-row, introduces WAR if parallelized
            for (k = 0; k < K; k++) {
                temp_storage[j] += F[ldf * k + i] * G[ldg * j + k];
            }
        }
        for (j = 0; j < n2; j++) {
            C[ldc * i + j] += alpha * temp_storage[j]; // Write out after full row computation
        }
    }
}
