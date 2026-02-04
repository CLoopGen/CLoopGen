#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern  float beta;
extern float *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Change memory access to strided pattern by unrolling and accessing every second element
    for (i = 0; i < N; i++) {
        int idx;
        // Process even j indices first with stride 2
        for (j = 0; j <= i; j += 2) {
            idx = ldc * i + j;
            C[idx] *= beta;
        }
        // Process odd j indices separately, creating a strided access pattern
        for (j = 1; j <= i; j += 2) {
            idx = ldc * i + j;
            C[idx] *= beta;
        }
    }
}
