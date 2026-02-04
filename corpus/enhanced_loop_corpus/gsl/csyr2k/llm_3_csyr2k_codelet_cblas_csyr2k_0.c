#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *C;
extern  int ldc;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access - traverse column-major like pattern with fixed stride
    float *C_base = (float *)C;
    int stride = 2 * ldc;  // Stride in terms of float elements per row
    for (j = 0; j < N; j++) {  // Outer loop over columns
        for (i = 0; i <= j; i++) {  // Inner loop over rows up to diagonal
            int idx = 2 * (ldc * i + j);
            C_base[idx]     = 0.0f;
            C_base[idx + 1] = 0.0f;
        }
    }
}
