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
    // Variant 2: Strided memory access - traverse column-wise with fixed stride for better vectorization potential
    float *C_base = (float *)C;
    int stride = 2 * ldc; // Stride in terms of float elements between rows
    for (j = 0; j < N; j++) {
        for (i = 0; i <= j; i++) { // Access only lower triangular part (i <= j)
            int idx = 2 * (ldc * i + j);
            C_base[idx] = 0.;
            C_base[idx + 1] = 0.;
        }
    }
}
