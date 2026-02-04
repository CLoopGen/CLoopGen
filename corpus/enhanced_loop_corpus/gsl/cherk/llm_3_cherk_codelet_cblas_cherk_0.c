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
    // Variant 2: Strided memory access - traverse column-wise with fixed stride, unrolling to access multiple rows per iteration
    float *C_base = (float *)C;
    int stride = 2 * ldc;  // Stride in float elements between consecutive rows
    for (j = 0; j < N; j++) {
        for (i = 0; i <= j; i++) {  // Access only lower triangular part via transposed condition
            int base_idx = 2 * (ldc * i + j);
            C_base[base_idx]     = 0.;
            C_base[base_idx + 1] = 0.;
        }
    }
}
